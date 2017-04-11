#include<stdio.h>
#include<stdlib.h>

struct process {
	int p,at,bt,wt,tt;
	int f=0;
};
int main() {
	int n,i,j;
	FILE *f1=fopen("sjfp.txt","r");
	fscanf(f1,"%d",&n);
	printf("No. of processes: %d\n",n);
    struct process p[n],temp;
    printf("Process\tArrival Time\tBurst Time\n");
	for(i=0;i<n;i++) {
		fscanf(f1,"%d %d",&p[i].at,&p[i].bt);
		p[i].p=i+1;
		printf("P[%d]\t\t%d\t\t%d\n",p[i].p,p[i].at,p[i].bt);
	}
for(i=0;i<n;i++) {
	for(j=0;j<n;j++) {
		if(p[i].at<p[j].at) {
			temp=p[i]; p[i]=p[j]; p[j]=temp;
		}
	}
}	
     printf("Process\tArrival Time\tBurst Time\n");
     	for(i=0;i<n;i++) {
		printf("P[%d]\t\t%d\t\t%d\n",p[i].p,p[i].at,p[i].bt);
	}
	for(i=0;i<n;i++) {
		if(p[i].f==0) {
			if(p[i].bt>p[i+1].bt) {
				p[i].bt=p[i].bt-p[i-1].at;
			}
		}
	}
	
	return 0;
}
