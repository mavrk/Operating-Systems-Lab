#include <iostream>

using namespace std;
int main()
{
    int n, time[100], tmp, cycle[100];
    double sum = 0, w = 0, avg = 0, sum1 = 0, t = 0;
    cout << "Enter the no of process: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the process arrival time: ";
        cin >> time[i];
        cout << "Enter the process CPU cycle: ";
        cin >> cycle[i];
    }
    cout << "Process\twaiting time\tturn around time\n";
    for(int i = 0; i < n; i++)
    {
        w = sum - time[i];
        if(w < 0)
        {
            sum -= w;
            w = 0;
        }
        avg += w;
        sum += cycle[i];
        t = sum - time[i];
        sum1 += t;
        cout << i + 1 << "\t" << w << "\t\t" << t << endl;
    }
    cout << "Average waiting time: " << avg * 1.0 / n << endl;
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
