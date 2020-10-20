#include <iostream>
using namespace std;
int getInt(string message) {
    int Input;
    cout << message;
    cin >> Input;
    return Input;
}
int* getIndexOfCebterOfMaxInterval(int* row, int n) {
    int range[2] = { 0, 0 };
    int a = 0;
    int b = 0;
    int MaxInterval = 0;
    int TempInterval = 0;
    int results[3];
    for (int i = 0; i < n; i++)
    {
        if (row[i] == 0) {
            TempInterval++;
            if (a == 0)
                a = i;
            b = i;
        }
        else {
            if (TempInterval != 0) {
                if (MaxInterval < TempInterval)
                {
                    range[0] = a;
                    range[1] = b;
                    MaxInterval = TempInterval;
                }
                TempInterval = 0;
                a = 0;
                b = 0;
            }
        }
    }
    int IndexOfCenter = range[0] + ((range[1] - range[0]) / 2);
    results[0] = IndexOfCenter;
    results[1] = IndexOfCenter - range[0];
    results[2] = range[1] - IndexOfCenter;
    return results;
}
int main()
{
    int n = getInt("n: ") + 2;
    int k = getInt("k: ");
    int* row = new int[n];
    row[0] = 1;
    row[n - 1] = 1;
    for (int i = 1; i < n - 1; i++)
        row[i] = 0; 
    int* results = new int[3];
    int* temp = new int[3];
    for (int i = 0; i < k; i++)
    {
        temp = getIndexOfCebterOfMaxInterval(row, n);
        for (int i = 0; i < 3; i++)
            results[i] = temp[i];
        row[getIndexOfCebterOfMaxInterval(row, n)[0]] = 1;
    }
    cout << endl;
    cout << results[1] << endl;
    cout << results[2];
}
