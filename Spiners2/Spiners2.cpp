#include <iostream>
#include <string>
using namespace std;

int getInt(string massage) {
    int Input;
    cout << massage;
    cin >> Input;
    return Input;
}
int main()
{
    int M = getInt("M: ");
    int four = 0;
    int three = 0;
    while ((M % 3 != 0) && (M > 0))
    {
        four++;
        M -= 4;
    }
    if ((M > 0 and M < 3 and four > 0) || M < 0)
        cout << 0 << endl << 0 << endl;
    else
    {
        three = M / 3;
        cout << three << endl << four << endl;
    }
}
