
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
    int N;
    int A = getInt("Enter A: ");
    int B = getInt("Enter B: ");
    int C = getInt("Enter C: ");
    double temp = (C - A) / B;
    N = round(temp);
    if (N > temp)
        N--;
    cout << N;
}
