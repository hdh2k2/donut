#include<iostream>
#include<math.h>
#include<stdio.h>
#include <windows.h>

extern int WidthConsole = 0;
extern int HeightConsole = 0;

void usleep(__int64 usec) {
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}

void textColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void fullScreen() {
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
void removeScrollBar() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}
void getWHConsole() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    WidthConsole = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    HeightConsole = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void gotoXY(int x, int y) {
    COORD co = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}


void hideCur() {
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

using namespace std;

int main() {
    fullScreen();
    removeScrollBar();
    SetConsoleTitle(L"__HHD");
    hideCur();

    textColor(5);
                                float A = 0,
                        B = 0;float i, j;int k;float 
                   z[1760];char b[1760];cout << "\x1b[2J";
              for (;;) {memset(b, 32, 1760);memset(z, 0, 7040);
          for (j = 0; j < 6.28; j += 0.07) {for (i = 0; i < 6.28; i += 
        0.02) {float c = sin(i);float d = cos(j);float e = sin(A);float
       f=sin(j);float g = cos(A);float h = d + 2;float D = 1 / (c * h * 
      e + f * g + 5);float l = cos(i);float m = cos(B);float n = sin(B);
      float t = c * h * g - f * e;           int x = 40 + 30 * D * (l * h 
      * m - t * n);int y = 12 + 15            * D * (l * h * n + t * m);int 
      o = x + 80 * y;int N = 8 *              ((f * e - c * d * g) * m - c
      * d * e - f * g - l * d * n);            if (22 > y && y > 0 && x > 
          0 && 80 > x && D > z[o]){           z[o] = D;b[o] = ".,-~:;=!*#$@"
          [N > 0 ? N : 0];}}}  cout << "\x1b[H";for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);A += 0.00004;B += 0.00002;}usleep
                                (30000);}return 0;
}