#include <iostream>
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
    int InputKeyCode = 0;

    cout << "화면에 그림을 그리는 프로그램입니다.\n" << "학번 : 202202034\n" << "이름 : 서현석\n" << endl;
    while (true)
    {
        cout << "화면에 그릴 물체 코드를 입력하세요 -> ";
        cin >> InputKeyCode;

        if (InputKeyCode & MASK::EXIT || InputKeyCode > 64)
        {
            if (InputKeyCode == MASK::EXIT)
                break;
            if (InputKeyCode > 64 || InputKeyCode <= 0)
            {
                cout << "제대로 된 값을 입력하세요(1~64 사이 정수값). " << endl;
                continue;
            }
        }
        if (InputKeyCode & MASK::WHITE)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::White) << "m" << endl;
            block();
        }
        if (InputKeyCode & MASK::RED)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::Red) << "m" << endl;
            block();
        }
        if (InputKeyCode & MASK::GREEN)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::Green) << "m" << endl;
            block();
        }
        if (InputKeyCode & MASK::YELLOW)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::Yellow) << "m" << endl;
            block();
        }
        if (InputKeyCode & MASK::CYAN)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::Cyan) << "m" << endl;
            block();
        }
        if (InputKeyCode & MASK::MAGENTA)
        {
            cout << "\x1b[" << static_cast<int>(ForeColour::Magenta) << "m" << endl;
            block();
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    cout << "프로그램을 종료합니다." << endl;
}