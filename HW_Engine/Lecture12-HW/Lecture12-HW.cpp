﻿#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	int count = 0;

	chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	int delay_time_ms = 0;

	while (count < 100000)
	{
		//시작시간과 끝시간
		prev_end = end;
		end = chrono::steady_clock::now();

		//시간차 구하기
		chrono::steady_clock::duration diff = end - prev_end;
		delay_time_ms = chrono::duration_cast<chrono::milliseconds>(diff).count() - 1000;

		//출력
		count++;
		cout << count << "   dur:" << delay_time_ms << endl;

		//슬립
		this_thread::sleep_for(chrono::milliseconds(delay_time_ms));

	}
}