#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10];
    cout << "Enter requests" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    int temp = 0;
    for (int i = 0; i < 9; i++)
    {
        temp += abs(arr[i] - arr[i + 1]);
    }
    cout << temp;
}