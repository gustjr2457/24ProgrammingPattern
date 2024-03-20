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

void DrawBlock()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
            cout << "#";
        cout << endl;
    }
}

void setColor(int color) {
    switch (color)
    {
    case 1:
        cout << "\x1b[" << static_cast<int>(ForeColour::White) << "m";
        break;
    case 2:
    case 10:
        cout << "\x1b[" << static_cast<int>(ForeColour::Red) << "m";
        break;
    case 4:
    case 100:
        cout << "\x1b[" << static_cast<int>(ForeColour::Green) << "m";
        break;
    case 8:
    case 1000:
        cout << "\x1b[" << static_cast<int>(ForeColour::Yellow) << "m";
        break;
    case 16:
    case 10000:
        cout << "\x1b[" << static_cast<int>(ForeColour::Cyan) << "m";
        break;
    case 32:
    case 100000:
        cout << "\x1b[" << static_cast<int>(ForeColour::Magenta) << "m";
        break;
    case 64:
    case 1000000:
        cout << "\x1b[" << static_cast<int>(ForeColour::Default) << "m";
        break;
    default:
        cout << "해당 키코드는 없습니다." << endl;
        break;
    }
}

int main()
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
    while (InputKeyCode != 64 && InputKeyCode != 1000000)
    {
        setColor(1);
        cout << "화면에 그릴 물체 코드를 입력하세요 -> ";
        cin >> InputKeyCode;
        setColor(InputKeyCode);
        if (InputKeyCode != 64 && InputKeyCode != 1000000)
            DrawBlock();
    }
    cout << "프로그램을 종료합니다." << endl;
    


}