#include <iostream>

using namespace std;
bool visit[100];

int main()
{
    double n, time[100], cycle[100], sum = 0, wait[100] = {0}, cnt = 0, t, sum1 = 0, tmp[100];
    cycle[99] = 100000000;
    cout << "Enter the no of process: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time : ";
        cin >> time[i];
        cout << "Enter the CPU cycles : ";
        cin >> cycle[i];
        tmp[i] = cycle[i];
    }
    sum = 0;
    bool flag = 0;
    int prev;
    int j = 0;
    for(double i = time[0] + 1; cnt < n; i++)
    {
        cycle[j]--;
        if(cycle[j] == 0)
        {
            visit[j] = 1;
            cnt++;
            j = 99;
        }
        prev = j;
        flag = 0;
        for(int k = 0; k < n; k++)
        {
            if(!visit[k] && time[k] <= i)
            {
                if(j == 99 || cycle[j] > cycle[k])
                {
                    j = k;
                    flag = 1;
                }
            }
        }
        if(flag)
        {
            if(prev != 99)
            {
                time[prev] = i;
                //i += 0.4;
            }
            wait[j] += (i - time[j]);
        }
    }
    cout << "Process\tWaiting Time\tTurn around time\n";
    for(int i = 0; i < n; i++)
    {
        t = wait[i] + tmp[i];
        sum1 += t;
        cout << i + 1 << "\t" << wait[i] << "\t\t" << t << endl;
        sum += wait[i];
    }
    cout << "Average Waiting Time: " << sum * 1.0 / n << endl;
    cout << "Average turn around time: " << sum1 * 1.0 / n << endl;
    return 0;
}

/*
10
0 6
3 2
5 1
9 7
10 5
12 3
14 4
16 5
17 7
19 2
*/
