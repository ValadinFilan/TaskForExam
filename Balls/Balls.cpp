#include <iostream>
#include <string>
using namespace std;
int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++)
		result *= i;
	return result;
}
int getInt(string massage) {
	cout << massage;
	int result;
	cin >> result;
	return result;
}
int* replace(int k1, int k2, int* a, int n) {
	int* m = new int[n + 1];
	for (int i = 1; i <= n; i++)
		m[i] = a[i];
	int t = m[k1];
	m[k1] = m[k2];
	m[k2] = t;
	return m;
}

int Moving(int n, int m, int* a) {
	int result = 0;
	for (int i = m; i <= n; i++)
		if (a[i] == m)
			result += factorial(n - m);
		else
			result += Moving(n, m + 1, replace(m, i, a, n));
	return result;
}
int main()
{
	int n = getInt("n: ");
	int* a = new int[n+1];
	for (int i = 1; i <= n; i++)
		a[i] = i;
	cout << Moving(n, 1, a) << endl;
}
