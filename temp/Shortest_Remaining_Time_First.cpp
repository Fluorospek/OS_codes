#include <iostream>
using namespace std;
int main()
{
    int at[10], bt[10], rt[10], endTime, i, smallest, endtime;
    int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;
    cout << "Enter no. of Process: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter arrival time for process: ";
        cin >> at[i];
        cout << "Enter burst time for Process: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }
    cout << "\n\nProcess\t|Turnaround Time| Waiting Time\n\n";
    rt[9] = 9999;
    for (time = 0; remain != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
            {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            remain++;
            endtime = time + 1;
            cout << "\np[" << smallest + 1 << "]\t"
                 << "\t" << endtime - at[smallest] << "\t" << endtime - bt[smallest] - at[smallest] << "\n";
            sum_wait += endtime - bt[smallest] - at[smallest];
            sum_turnaround += endtime - at[smallest];
        }
    }
    cout << "\n\nAverage waiting time: " << (sum_wait * 1.0) / n;
    cout << "\nAverage turnaround time: " << (sum_turnaround * 1.0) / n << endl;
    return 0;
}
