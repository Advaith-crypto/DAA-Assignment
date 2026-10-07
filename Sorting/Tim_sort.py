#include <iostream>
#include <vector>
#include <thread>
using namespace std;
const int RUN = 32;
void insertionSort(vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void mergeParts(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftPart(n1);
    vector<int> rightPart(n2);
    for (int i = 0; i < n1; i++)
        leftPart[i] = arr[left + i]
    for (int i = 0; i < n2; i++)
        rightPart[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (leftPart[i] <= rightPart[j])
        {
            arr[k] = leftPart[i];
            i++;
        }
        else
        {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}
void timSort(vector<int>& arr, int left, int right)
{
    for (int i = left; i <= right; i += RUN)
    {
        int end = i + RUN - 1;

        if (end > right)
            end = right;
        insertionSort(arr, i, end);
    }

    for (int size = RUN; size <= right - left; size = size * 2)
    {
        for (int start = left; start <= right; start += size * 2)
        {
            int mid = start + size - 1;
            int end = start + size * 2 - 1;
            if (mid >= right)
                continue;

            if (end > right)
                end = right;
            mergeParts(arr, start, mid, end);
        }
    }
}

void threadTimSort(vector<int>& arr, int left, int right)
{
    if (left <= right)
        timSort(arr, left, right);
}

int main()
{
    int n;
    int m;

    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of threads: ";
    cin >> m;
    if (m <= 0)
    {
        cout << "Number of threads must be greater than 0.\n";
        return 0;
    }

    if (m > n)
        m = n;
    vector<thread> threads;
    int baseSize = n / m;
    int extra = n % m;
    int start = 0;
    for (int i = 0; i < m; i++)
    {
        int currentSize = baseSize;

        if (i < extra)
            currentSize++;

        int end = start + currentSize - 1;

        threads.emplace_back(threadTimSort, ref(arr), start, end);

        start = end + 1;
    }

    for (int i = 0; i < m; i++)
        threads[i].join();
    int partSize = baseSize;
    if (extra > 0)
        partSize++;
    while (partSize < n)
    {
        int start = 0;

        while (start < n)
        {
            int mid = start + partSize - 1;

            if (mid >= n - 1)
                break;
            int end = start + partSize * 2 - 1;
            if (end >= n)
                end = n - 1;
            mergeParts(arr, start, mid, end);
            start = end + 1;
        }

        partSize = partSize * 2;
    }

    cout << "\nSorted array:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}