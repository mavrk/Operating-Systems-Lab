#include<stdio.h>
#include<stdlib.h>

struct process {
	int p,at,bt,wt,tt,st,ft;
	int flag=0;
};
int main() {
	int n,t;
	FILE *f=fopen("round.txt","r");
	fscanf(f,"%d %d",&n,&t);
	printf("No. of processes: %d. Time quantum: %d units.\n",n,t);
    struct process p[n],temp;
	for(i=0;i<n;i++) {
		fscanf(f,"%d %d",&p[i].at,&p[i].bt);
		p[i].p=i+1;
	}
	for(i=0;i<n;i++) {
	  for(j=0;j<n;j++) {
		if(p[i].at<p[j].at) {
			temp=p[i]; p[i]=p[j]; p[j]=temp;
		}
	}
   }
   int all=0,temp=0,cnt=0;
   while(all<n)
   for(i=0;i<n;i++) {
   	if(p[i].flag==0) {
   		
   		if(p[i].bt>t) {
   			p[i].bt=p[i].bt-t;
   		}
   		else { 
   			
   		}
   	}
   }
	
	return 0;
}
