#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, avtat = 0, avwt = 0, i, j;
    cout << "Enter total number of processes: " << endl;
    cin >> n;
    int *bt = new int[n];
    int *wt = new int[n];
    int *tat = new int[n];
    cout << "Enter burst time of processes: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }
    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << i + 1 << "]"
             << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    avwt /= i;
    avtat /= i;
    cout << "\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avtat;
}