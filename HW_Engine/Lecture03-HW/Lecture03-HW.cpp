#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

enum MASK {
    WHITE = 0b1,
    RED = 0b10,
    GREEN = 0b100,
    YELLOW = 0b1000,
    CYAN = 0b10000,
    MAGENTA = 0b100000,
    EXIT = 0b1000000
};

void block()
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 5; x++)
            cout << "#";
        cout << endl;
    }
    cout << endl;
}

void main()
{
    /*
    흰색 블록을 그리는 키코드 : 1 (1)
    빨강색 블록을 그리는 키코드 : 2 (10)
    녹색 블록을 그리는 키코드 : 4 (100)
    노란색 블록을 그리는 키코드 : 8 (1000)
    청록색 블록을 그리는 키코드 : 16 (10000)
    마젠타색 블록을 그리는 키코드 : 32 (100000)
    프로그램 종료 : 64 (1000000)
    */
    string input;
    int number = 0;

    cout << "화면에 그림을 그리는 프로그램입니다.\n" << "학번 : 202202034\n" << "이름 : 서현석\n" << endl;
    while (true)
    {
        cout << "화면에 그릴 물체 코드를 입력하세요 -> ";
        getline(cin, input);
        istringstream stream(input);
        if (stream >> number)
        {
            if (number & MASK::EXIT)
            {
                if (number == MASK::EXIT)
                    break;
                else if (number > MASK::EXIT || number <= 0)
                {
                    cout << "1~64 사이의 값을 입력하세요. " << endl;
                    continue;
                }
            }
            if (number & MASK::WHITE)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::White) << "m" << endl;
                block();
            }
            if (number & MASK::RED)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::Red) << "m" << endl;
                block();
            }
            if (number & MASK::GREEN)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::Green) << "m" << endl;
                block();
            }
            if (number & MASK::YELLOW)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::Yellow) << "m" << endl;
                block();
            }
            if (number & MASK::CYAN)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::Cyan) << "m" << endl;
                block();
            }
            if (number & MASK::MAGENTA)
            {
                cout << "\x1b[" << static_cast<int>(ForeColour::Magenta) << "m" << endl;
                block();
            }
        }
        else
        {
            cin.clear();
            cout << "정수를 입력하세요. " << endl;
            continue;
        }
        
    }
    cout << "프로그램을 종료합니다." << endl;
}