#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double time[100], cycle[100], sum = 0, avg = 0, ctime[100], tmp[100], w, t, sum1 = 0;
    int n, cnt = 0;
    cout << "Enter the no of process: ";
    cin >> n;
    cout << "Enter the arrival time & burst time of all the process: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> time[i] >> cycle[i];
        tmp[i] = cycle[i];
    }
    double i = time[0];
    int k = 0, cnt1 = 0;
    while(cnt < n)
    {
        if(time[k] > i || cycle[k] == 0)
        {
            k = (k + 1) % n;
            cnt1++;
            if(cnt1 == n)
            {
                i += 1;
                cnt1 = 0;
            }
            continue;
        }
        if(cycle[k] <= 4 && cycle[k] > 0)
        {
            i += cycle[k];
            cycle[k] = 0;
            ctime[k] = i;
            cnt++;
            k = (k + 1) % n;
            cnt1 = 0;
        }
        else
        {
            i += 4;
            cycle[k] -= 4;
            k = (k + 1) % n;
            //i += 0.4;
            cnt1 = 0;
        }
    }
    cout << "Process\tWaiting time\tTurn around time\n";
    for(int i = 0; i < n; i++)
    {
        w = ctime[i] - time[i] - tmp[i];
        t = ctime[i] - time[i];
        sum1 += t;
        cout << i + 1 << "\t" << w << "\t\t" << t << endl;
        sum += w;
    }
    cout << "Average Waiting time: " << sum * 1.0 / n << endl;
    cout << "Average Turn around time: " << sum1 * 1.0 / n << endl;
    return 0;
}
