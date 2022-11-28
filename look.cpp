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
    int head, nd;
    cout << "Enter the head position and no. of disks" << endl;
    cin >> head >> nd;
    int later[10];
    int first[10];
    int k = 0, l = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] >= head)
            later[k++] = arr[i];
        else
            first[l++] = arr[i];
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < k - i; j++)
        {
            if (later[j] > later[j + 1])
            {
                int temp = later[j];
                later[j] = later[j + 1];
                later[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = l; j >= i; j--)
        {
            if (first[j] > first[j - 1])
            {
                int temp = first[j];
                first[j] = first[j - 1];
                first[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        cout << first[i] << " ";
    }
    int temp = later[0] - head;
    for (int i = 0; i < k - 1; i++)
    {
        temp += abs(later[i] - later[i + 1]);
    }
    // temp += (nd - 1) - later[k - 1];
    temp += later[k - 1] - first[0];
    for (int i = 0; i < l - 1; i++)
    {
        temp += abs(first[i] - first[i + 1]);
    }
    cout << temp;
}