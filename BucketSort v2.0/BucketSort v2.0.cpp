#include <iostream>
#include <string>
using namespace std;
int getInt(string message) {
	int InputNum;
	cout << message;
	cin >> InputNum;
	return InputNum;
}
int* bucketSort(int* inputArray) {
	int n = inputArray[0];
	cout << "Enter";
	for (int i = 0; i < n; i++)
		cout << inputArray[i] << ' ';
	cout << endl;
	int *mass = new int[n];
	mass[0] = n;
	for (int i = 1; i < n; i++)
		mass[i] = inputArray[i];

	//fing min max
	int max = mass[1];
	int min = mass[1];
	for (int i = 2; i < n; i++) {
		if (max < mass[i]) max = mass[i];
		if (min > mass[i]) min = mass[i];
	}

	//create buckets
	int** buckets = new int*[n];
	for (int i = 0; i < n; i++)
		buckets[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			buckets[i][j] = 0;
	int *result = new int[n];
	for (int i = 0; i < n; i++)
		result[i] = 0;
	if (max != min) {
		//chose step
		int Step = ((max - min) / n) + 1;
		// here is error

		//filling buckets
		for (int i = 1; i < n; i++)
		{
			buckets[(mass[i] - min) / Step][0]++;
			buckets[(mass[i] - min) / Step][buckets[(mass[i] - min) / Step][0]] = mass[i];
		}
		for (int i = 0; i < n; i++)
			buckets[i][0]++;

		for (int i = 0; i < n; i++)
		{
			buckets[i] = bucketSort(buckets[i]);
			cout << "bucket " << i << " has been sorted: ";
			for (int j = 0; j <= buckets[i][0]; j++)
				cout << buckets[i][0] << ' ';
			cout << endl;
			for (int j = 1; j < buckets[i][0]; j++)
			{
				result[0]++;
				result[result[0]] = buckets[i][j];
				cout << buckets[i][j] << ' ';
			}
		}
		
		cout << "Fulled buckets" << endl;
		for (int i = 0; i < n; i++)
			cout << result[i];
		cout << endl;
		return result;
	}
	else for (int i = 0; i < n; i++) result[i] = mass[i];

	return result;
}
int main()
{
	int N = getInt("Enter N ") + 1;
	int* mass = new int[N];
	mass[0] = N;
	for (int i = 1; i < N; i++)
		mass[i] = getInt("");
	cout << endl;
	mass = bucketSort(mass);
	for (int i = 1; i <= mass[0]; i++)
		cout << mass[i] << ' ';
}
