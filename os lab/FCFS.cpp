#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *f;
	int n,i,j;
	f=fopen("fcfs.txt","r");
	fscanf(f, "%d",&n);
	printf("No. of processes is %d.\n",n);
	int b[n],w[n],tat[n];
	float tt=0,tw=0;
	for(i=0;i<n;i++)
	{
		
		fscanf(f,"%d",&b[i]);
		printf("P[%d] : %d\n",i+1,b[i]);
		
	}
	w[0]=0;
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++) {
		w[i]=0;
		for(j=0;j<i;j++) {
			w[i]+=b[j];
		}
		tat[i]=w[i]+b[i];
		tw+=w[i]; tt+=tat[i];
		printf("P[%d]\t\t%d\t\t%d\t\t%d\n",i+1,b[i],w[i],tat[i]);
	}
	printf("Average Waiting Time is %f.\t",tw/n);
	printf("Average Turnaruond Time is %f.\t",tt/n);
	fclose(f);
	return 0;
	
}

