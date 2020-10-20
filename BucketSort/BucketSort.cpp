#include <iostream>
using namespace std; 
int getInt(string message) {
    int Input;
    cout << message;
    cin >> Input;
    return Input;
}
int* AddElementToArray(int* a, int n, int Element) {
    int l = n + 1;
    int* result = new int[l];
    for (int i = 0; i < n; i++)
        result[i] = a[i];
    result[n] = Element;
    return result;
}
int* SumArray(int* a, int len_a, int* b, int len_b) {
    int len = len_a + len_b;
    int* sum = new int[len];
    for (int i = 0; i < len_a; i++)
        sum[i] = a[i];
    int t = 0;
    for (int i = 0; i < len_b; i++) {
        t = len_a + i;
        sum[t] = b[i];
    }
    return sum;
}
int* BucketSort(int* a, int n) {
    int* NewArray = new int[n];
    for (int i = 0; i < n; i++)
        NewArray[i] = a[i];
    int** buckets;
    int bucketCount = n - 1;
    int max = NewArray[0];
    int min = NewArray[0]; 
    int scale = 0;
    int* result = {};
    for (int i = 0; i < n; i++)
    {
        if (NewArray[i] > max) max = NewArray[i];
        if (NewArray[i] < min) min = NewArray[i];
    }

    if (bucketCount > 0) {
        scale = (max-min)/bucketCount;
        int** buckets = new int* [bucketCount,1];
        int* counter = new int[bucketCount];
        for (int i = 0; i < bucketCount; i++) counter[i] = 0;

        /*Распределение элементов массива по корзинам*/
        for (int i = 0; i < n; i++) {
            buckets[(NewArray[i] - min) / scale] = AddElementToArray(buckets[NewArray[i] / scale], counter[(NewArray[i] - min) / scale], NewArray[i]);
            counter[(NewArray[i] - min) / scale]++;
        }
        for (int i = 0; i < bucketCount; i++)
            buckets[i] = BucketSort(buckets[i], counter[i]);

        for (int i = 0; i < bucketCount; i++)
            result = SumArray(result, n, buckets[i], scale);
    }
    return result;


}
int main()
{
    /*
    int N = getInt("N: ");
    int* user_array = new int[N];
    for (int i = 0; i < N; i++)
        cin >> user_array[i];*/

    int user_array_test[2] = { 2, 1 };
    int* user_array = user_array_test;
    int N = 2;
    user_array = BucketSort(user_array, N);
    for (int i = 0; i < N; i++)
        cout << user_array[i] << " ";
}
