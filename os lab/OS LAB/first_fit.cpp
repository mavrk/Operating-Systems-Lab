#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, t[100], s[100], m, msize[100], cnt[100] = {0};
    cout << "Enter the no of jobs: ";
    cin >> n;

    cout << "Enter the job time & size: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> t[i] >> s[i];
    }

    cout << "Enter the no of memory blocks: ";
    cin >> m;
    cout << "Enter the size of memory blocks: \n";

    for(int i = 0; i < m; i++)
    {
        cin >> msize[i];
    }

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
    return 0;
}
