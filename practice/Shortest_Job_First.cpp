#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, min, d, tt;
    float avgtat = 0, avgwt = 0, stat = 0, swt = 0;
    cout << "Enter number of processes: " << endl;
    cin >> n;
    int *arr = new int[n];
    int *bt = new int[n];
    int *tat = new int[n];
    int *wt = new int[n];
    int *e = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": " << endl;
        cin >> arr[i];
        cout << "Enter Burst Time of process " << i + 1 << ": " << endl;
        cin >> bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            d = i;
        }
    }
    tt = min;
    e[d] = tt + bt[d];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != min)
        {
            e[i] = bt[i] + tt;
            tt = e[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = e[i] - arr[i];
        stat = stat + tat[i];
        wt[i] = tat[i] - bt[i];
        swt = swt + wt[i];
    }
    avgtat = stat / n;
    avgwt = swt / n;
    cout << "Process Arrival-time(s) Burst-time(s) Waiting-time(s) Turnaround-time(s)\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << " " << arr[i] << " " << bt[i] << " " << wt[i] << " " << tat[i] << endl;
    }
    cout << "awt=" << avgwt << " atat=" << avgtat;
}