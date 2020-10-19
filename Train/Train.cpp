#include <iostream>
using namespace std;
int getInt(string message) {
    int Input;
    cout << message;
    cin >> Input;
    return Input;
}
int main()
{
    int N = getInt("N : ");
    int temp = 0;
    int a[9];
    for (int i = 0; i < 9; i++)
        a[i] = 0;
    for (int i = 0; i < N; i++)
    {
        temp = getInt("");
        if (temp <= 36)
            a[(temp - 1) / 4]++;
        else if (temp > 36 && temp <= 54)
            a[(54 - temp) / 2]++;
    }
    int Interval = 0;
    int TempInterval = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 6)
            TempInterval++;
        else {
            if (TempInterval > Interval)
                Interval = TempInterval;
            TempInterval = 0;
        }
    }
    cout << Interval;
}
