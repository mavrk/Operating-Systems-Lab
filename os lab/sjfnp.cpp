#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	FILE *f1;
	f1=fopen("sjf.txt","r");
	fscanf(f1,"%d",&n);
	printf("No. of processes: %d\n",n);
	int i,j,t1,t2,p[n],b[n],w[n],tat[n];
	float tt=0,tw=0;
	for(i=0;i<n;i++) {
		fscanf(f1,"%d",&b[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(b[i]<b[j]) {
				t1=b[i]; t2=p[i];
				b[i]=b[j]; p[i]=p[j];
				b[j]=t1; p[j]=t2;
			}
		}
	}
	w[0]=0;
	printf("Process\tBurst Time\tWaiting Time\tTurnaround time\n");
	for(i=0;i<n;i++) {
		w[i]=0;
		for(j=0;j<i;j++) {
			w[i]+=b[j];
		}
		tat[i]=w[i]+b[i];
		tt+=tat[i];
		tw+=w[i];
		printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],b[i],w[i],tat[i]);
	}
	printf("Average Waiting time is %f.  ",tw/n);
	printf("Average Turnaround time is %f.",tt/n);
	return 0;
}
