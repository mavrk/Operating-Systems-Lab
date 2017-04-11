#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct mem
{
	int size;
	int rem;
	bool occupied;
    int id;
};

struct node
{
	int size;
	int time;
	int start;
	int end;
	int store;
};

mem mblock[100];
node job[100];

bool comp(node x, node y)
{
    return (x.size <= y.size);
}

int main()
{
    //freopen("in.txt", "r", stdin);
	int j, m;
    int fragment = 0;
	cout << "Enter no of jobs: ";
	cin >> j;
	cout << "Enter burst time and sizes of jobs: \n";
	for(int i = 0; i < j; i++)
	{
		cin >> job[i].time >> job[i].size;
		job[i].end = -1;
	}
    sort(job, job + j, comp);
    cout << "Enter no of size blocks: " << endl;
    cin >> m;

    cout<<"Enter sizes of all the size blocks: \n";
    for(int i = 0; i < m; i++)
    {
        cin >> mblock[i].size;
        mblock[i].rem = mblock[i].size;
        mblock[i].occupied = false;
        mblock[i].id = i + 1;
    }
    int cnt = 0, t = 0;

    int n = 0;
    bool flag = false;
    for(int i = 0; i < j; i++)
    {
    	for(int k = 0; k < m; k++)
    	{
    	 	if(job[i].size <= mblock[k].size)
    	 	{
    	 		flag = true;
    	 		break;
    	 	}
    	}
    	if(flag == true) 
            n++;
    	flag = false;
    }

    int sum = 0;
    cout << "Time\tWait Q Length\tI Fragmentation\n";
    while(cnt < n)
    {
        for(int i = 0; i < j; i++)
        {
            if(job[i].end == t)
            {
                mblock[job[i].store].rem += job[i].size;
                mblock[job[i].store].occupied = false;
            }
        }
        for(int i = 0; i < j; i++)
        {
            if(job[i].end == -1)
            {
                for(int k = 0; k < m; k++)
                {
                    if(mblock[k].rem >= job[i].size)
                    {
                        cnt++;
                        job[i].start = t;
                        job[i].end = t + job[i].time;
                        mblock[k].rem -= job[i].size;
                        job[i].store = k;
                        mblock[k].occupied=true;
                        break;
                    }
                }
            }
        }
        int frag = 0;
        int waitqlength = j - cnt;
        sum += waitqlength;
        for(int k = 0; k < m; k++)
        {
            if(mblock[k].occupied)
                frag += mblock[k].rem;
        }
        fragment += frag;
        cout << t << "\t\t" << waitqlength << "\t\t" << frag << endl;
        t++;
    }
    cout << endl << endl;
    cout << "Job\tMemory Block Used\tWaiting Time\n";
    int ttime = -1, wait = 0;
    for(int i = 0; i < j; i++)
    {
        ttime = max(ttime, job[i].end);
        cout << i + 1 << "\t\t";
        if(job[i].end != -1)
        {
            cout << job[i].store + 1 << "\t\t" << job[i].start << endl;
            wait += job[i].start;
        }
        else 
            cout << "Not done" << endl;
    }
    cout << endl;
    cout << "No of jobs completed: " << n << endl;
    cout << "Total time: " << ttime << endl;
    cout << "Throughput: " << n * 1.0 / ttime << endl;
    // cout << "Average Waiting Queue Length: " << sum * 1.0 / ttime << endl;
    // cout << "Average Waiting Time: " << wait * 1.0 / n << endl;
    // cout << "Average Internal Fragmentation: " << fragment * 1.0 / ttime << endl;
    return 0;
}

/*
10
9500
7000
4500
8500
3000
9000
1000
5500
1500
500

25
5 5760
4 4190
8 3290
2 2030
2 2550
6 6990
8 8940
10 740
7 3930
6 6890
5 6580
8 3820
9 9140
10 420
10 220
7 7540
3 3210
1 1380
9 9850
3 3610
7 7540
2 2710
8 8390
5 5950
10 760
*/
