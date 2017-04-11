#include <iostream>

using namespace std;
bool visit[100];

int main()
{
    int n, time[100], cycle[100], mn, pos;
    double sum = 0, w = 0, avg = 0, t = 0, sum1 = 0;
    cout << "Enter the no of process: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time : ";
        cin >> time[i];
        cout << "Enter the CPU cycles : ";
        cin >> cycle[i];
    }
    visit[0] = 1;
    sum = cycle[0] + time[0];
    t = cycle[0];
    sum1 += t;
    //sum += 0.4;
    cout << "Process\tWaiting Time\tTurn around time\n";
    cout << "1\t0\t\t" << t << "\n";
    for(int i = 1; i < n; i++)
    {
        mn = 1000000;
        pos = -1;
        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && time[j] <= sum)
            {
                if(cycle[j] < mn)
                {
                    mn = cycle[j];
                    pos = j;
                }
            }
        }
        visit[pos] = 1;
        w = sum - time[pos];
        if(w < 0)
        {
            sum -= w;
            w = 0;
        }
        avg += w;
        t = w + cycle[pos];
        sum1 += t;
        cout << pos + 1 << "\t" << w << "\t\t" << t << endl;
        sum += cycle[pos];
        //sum += 0.4;
    }
    cout << "Average Waiting Time: " << avg * 1.0 / n << endl;
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
