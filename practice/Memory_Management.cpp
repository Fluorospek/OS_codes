#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// First Fit
void firstFit(int *prSize, int *holes, int n, int m)
{
    int ffit[n];
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (prSize[i] <= holes[j])
            {
                ffit[i] = j;
                holes[j] -= prSize[i];
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ffit[i] = -1;
        }
    }
    cout << "First Fit" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ffit[i] << " " << endl;
    }
}

// Best Fit
void bestFit(int *prSize, int *holes, int n, int m)
{
    int bfit[n];
    for (int i = 0; i < n; i++)
    {
        int space = -1;
        for (int j = 0; j < m; j++)
        {
            if (prSize[i] <= holes[j] && (space == -1 || holes[j] < holes[space]))
            {
                space = j;
            }
        }
        if (space == -1)
        {
            bfit[i] = -1;
        }
        else
        {
            bfit[i] = space;
            holes[space] -= prSize[i];
        }
    }
    cout << "Best Fit" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << bfit[i] << " ";
    }
    cout << endl;
}

// Worst Fit
void worstFit(int *prSize, int *holes, int n, int m)
{
    int wfit[n];
    for (int i = 0; i < n; i++)
    {
        int space = -1;
        for (int j = 0; j < m; j++)
        {
            if (prSize[i] <= holes[j] && (space == -1 || holes[j] >= holes[space]))
            {
                space = j;
            }
        }
        if (space == -1)
        {
            wfit[i] = -1;
        }
        else
        {
            wfit[i] = space;
            holes[space] -= prSize[i];
        }
    }
    cout << "Worst Fit" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << wfit[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes: " << endl;
    cin >> n;
    int *prSize = new int[n];
    cout << "Enter process size" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> prSize[i];
    }
    int m;
    cout << "Enter number of holes: " << endl;
    cin >> m;
    int *holes = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> holes[i];
    }
    int tPrSize[n], tHoles[m];
    for (int i = 0; i < n; i++)
    {
        tPrSize[i] = prSize[i];
    }

    for (int i = 0; i < m; i++)
    {
        tHoles[i] = holes[i];
    }

    firstFit(tPrSize, tHoles, n, m);

    for (int i = 0; i < n; i++)
    {
        tPrSize[i] = prSize[i];
    }

    for (int i = 0; i < m; i++)
    {
        tHoles[i] = holes[i];
    }

    bestFit(tPrSize, tHoles, n, m);

    for (int i = 0; i < n; i++)
    {
        tPrSize[i] = prSize[i];
    }

    for (int i = 0; i < m; i++)
    {
        tHoles[i] = holes[i];
    }

    worstFit(tPrSize, tHoles, n, m);
}