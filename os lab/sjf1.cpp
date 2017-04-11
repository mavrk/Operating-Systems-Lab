#include<stdio.h>
#include<stdlib.h>

int n;

int main() {
	printf("Enter the no. of processes: ");
    scanf("%d",&n);
	int i,j,temp,temp1,b[n],p[n],w[n],ta[n];
	float tw=0,tt=0;
	printf("Enter the burst time of the processes: \n");
	for(i=0;i<n;i++) {
	printf("P[%d]: ",i+1);
	scanf("%d",&b[i])	; p[i]=i+1;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(b[i]<b[j]) {
				temp=b[i]; temp1=p[i];
				b[i]=b[j]; p[i]=p[j];
				b[j]=temp; p[j]=temp1;
			}
		}
	}
	w[0]=0;
	for(i=0;i<n;i++) {
		w[i]=0;
		for(j=0;j<i;j++) {
			w[i]+=b[j];
		}
		ta[i]=w[i]+b[i];
		tw+=w[i];
		tt+=ta[i];
	}
	printf("Processes\tBurst Time\t Waiting Time\t Turnaround Time\n");
	for(i=0;i<n;i++) {
		printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],b[i],w[i],ta[i]);
	}
	printf("Average waiting time is %f.\n",tw/n);
	printf("Average turnaround time is %f.",tt/n);
	return 0;
}
