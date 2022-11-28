#include <iostream>
using namespace std;

void findWaitingTime(int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(n, bt, wt, quantum);
    findTurnAroundTime(n, bt, wt, tat);
    cout << "PN\t "
         << " \tBT "
         << " WT "
         << " \tTAT\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    // int processes[] = {1, 2, 3};
    // int n = sizeof processes / sizeof processes[0];
    // int burst_time[] = {10, 5, 8};
    // int quantum = 2;
    int n, time_quantum;
    cout << "Enter number of processes:" << endl;
    cin >> n;
    int *burst_time = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of process " << i + 1 << endl;
        cin >> burst_time[i];
    }
    findavgTime(n, burst_time, time_quantum);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, time, remain, temps = 0, time_quantum;
//     int wt = 0, tat = 0;
//     cout << "Enter the total number of processes: " << endl;
//     cin >> n;
//     remain = n;
//     int *arrt = new int[n];
//     int *bt = new int[n];
//     int *remt = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter arrivalt itme of process " << i + 1 << endl;
//         cin >> arrt[i];
//         cout << "Enter burst time of process " << i + 1 << endl;
//         cin >> bt[i];
//         remt[i] = bt[i];
//     }
//     cout << "Enter value of time quantum: " << endl;
//     cin >> time_quantum;
//     cout << "\n\nProcess\tTurnaround Time:Waiting Time\n\n";
//     for (int i = 0, time = 0; remain != 0;)
//     {
//         if (remt[i] <= time_quantum && remt[i] > 0)
//         {
//             time += remt[i];
//             remt[i] = 0;
//             temps = 1;
//         }
//         else if (remt[i] > 0)
//         {
//             remt[i] -= time_quantum;
//             time += time_quantum;
//         }
//         if (remt[i] == 0 && temps == 1)
//         {
//             remain--;
//             printf("Process{%d}\t:\t%d\t:\t%d\n", i + 1, time - arrt[i], time - arrt[i] - bt[i]);
//             cout << endl;
//             wt += time - arrt[i] - bt[i];
//             tat += time - arrt[i];
//             temps = 0;
//         }
//         if (i == n - 1)
//             i = 0;
//         else if (arrt[i + 1] <= time)
//             i++;
//         else
//             i = 0;
//     }
//     cout << "Average Waiting Time " << wt * 1.0 / n << endl;
//     cout << "Average turn around time " << tat * 1.0 / n << endl;
// }