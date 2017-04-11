#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int w[12] = {10, 11, 104, 170, 73, 309, 185, 245, 246, 434, 458, 364};
	int mem, ans, page, n, pageno[50], inmem[50], success;
	while(1)
	{
	   	cout << "Menu\n";
	   	cout << "S.No\tMemory\tPage\n\n";
	   	cout << "1\t200\t100\n";
	   	cout << "2\t200\t20\n";
	   	cout << "3\t200\t200\n";
	   	cout << "4\t400\t100\n";
	   	cout << "5\t400\t20\n";
	   	cout << "6\t400\t200\n";
	   	cout << "Enter choice: \n";
	   	cin >> ans;
	   	switch(ans)
	   	{
	 	  	case 1:
	 	  		mem = 200; 
				page = 100;
				break;
		  	case 2:
		  		mem = 200; 
				page = 20;
		  		break;
		  	case 3:
		  		mem = 200; 
				page = 200;
		  		break;
		  	case 4:
		  		mem = 400; 
				page = 100;
		        break;
		  	case 5:
		  		mem = 400; 
				page = 20;
		        break;
		  	case 6:
		  		mem = 400; 
				page = 200;
		        break;
		  	case 7: 
		  		return 0;		
	   	}
	    n = mem / page;
		for(int i = 0; i < 12; i++)
		{
			pageno[i] = w[i] / page;
		}

		for(int i = 0; i < n; i++)
		{
			inmem[i] = -1;
		}
		bool flag = 0;
		int cur = 0;
		success = 0;
		for(int i = 0; i < 12; i++)
		{
			flag = 0;
			for(int j = 0; j < n; j++)
			{
				if(inmem[j] == pageno[i])
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				inmem[cur] = pageno[i];
				cur = (cur + 1) % n;
			}
			else
			{
				success++;
			}
	    }
		cout << "No Of Success: " << success << endl;
		cout << "Success Ratio: " << success * 1.0 / 12 << endl;
    }
	return 0;
}
