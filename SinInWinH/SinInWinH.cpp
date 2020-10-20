#include <windows.h>
#include <iostream>
using namespace std;
void Line(HDC hdc, int x1, int y1, int x2, int y2) {
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}
int main() {
    int x = 300;
    int y = 150;
    HWND hWnd = GetConsoleWindow();
    HDC hDc = GetDC(hWnd);
    COLORREF color = RGB(255, 255, 255);
    HPEN pen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hDc, pen);/*
    for (int i = 0; i < 15; i++)
        cout << endl;
    for (int i = 0; i < 300; ++i)
        Line(hDc, 100, i, 600, i);
    color = RGB(0, 0, 0);
    pen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hDc, pen);*/
    Line(hDc, 300, 0, 300, 300);
    Line(hDc, 0, 150, 800, 150);
    for (double x1 = -150; x1 < 50; x1 += 0.001) {
        int y1 = sin(x1) * 30;
        SetPixel(hDc, x1 * 10 + x + 63, y - y1, color);
    }
    cin >> x;
}