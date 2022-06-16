// Merge sort with cases of time complexity
#include <bits/stdc++.h>
using namespace std;

void merge(long long int arr[], long long int low, long long int mid, long long int high)
{
    long long int i = low, j = mid + 1, k = low, aux[high + 1] = {0};
    while ((i <= mid) && (j <= high))
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }
    if (i > mid)
    {
        for (; j <= high; j++)
        {
            aux[k++] = arr[j];
        }
    }
    else
    {
        for (; i <= mid; i++)
        {
            aux[k++] = arr[i];
        }
    }
    for (k = low; k <= high; k++)
    {
        arr[k] = aux[k];
    }
    return;
}

void merge_sort(long long int arr[], long long int low, long long int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return;
}

int main()
{
    long long int n = 0, i = 0;
    clock_t start, end;
    start = clock();
    cout << "Enter the size of an array:" << endl;
    cin >> n;
    long long int arr[n] = {0}, choice = 0;
    cout << "Enter choice:\n\n1.Best case\n2.Worst case\n3.Average case\n4.Exit\n"
         << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        for (i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        break;
    case 2:
        for (i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
        break;
    case 3:
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        break;
    case 4:
        exit(0);
    }
    long long int low = 0, high = n - 1;
    merge_sort(arr, low, high);
    low = 0, high = n - 1;
    cout << "The sorted elements are:" << endl;
    for (i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    end = clock();
    cout << endl;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    cout << endl;
    return 0;
}
