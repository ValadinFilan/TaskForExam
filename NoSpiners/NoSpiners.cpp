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
    int N = getInt("N: ");
    int M = getInt("M: ");
    int result = (N+1)*(M+1)*N*M/4;
    cout << result;
}
