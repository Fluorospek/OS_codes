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
    int temp = 0;
    for (int i = 0; i < 9; i++)
    {
        temp += abs(arr[i] - arr[i + 1]);
    }
    cout << temp;
}