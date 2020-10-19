#include <iostream>
#include <string>
using namespace std;
int getInt(string massage) {
    int Input;
    cout << massage;
    cin >> Input;
    return Input;
}
double getDouble(string message) {
    double Input;
    cout << message;
    cin >> Input;
    return Input;
}
int main()
{
    int a = getInt("a: ");
    int b = getInt("a: ");
    int result = 0;
    for (int i = 0; i < a; i++)
    {
        for (int i = 0; i < b; i++)
        {
            result++;
        }
    }
    cout << result;
}
