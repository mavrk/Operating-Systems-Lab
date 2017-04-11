#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio>
using namespace std;

typedef struct process
{
	int id,at,bt,st,ft,pr;
	float wt,tat;
}process;

process p[10],p1[10],temp;
queue<int> q1;

int accept(int ch);
void turnwait(int n);
void display(int n);
void ganttrr(int n);

int main()
{
	int i,n,ts,ch,j,x;
	p[0].tat=0;
	p[0].wt=0;
	n=accept(ch);
	ganttrr(n);
	//turnwait(n);
	display(n);
	return 0;
}

int accept(int ch)  //functions for accepting inputs from the user
{
	int i,n;
	printf("\nEnter the no. of process: ");
	scanf("%d",&n);
	if(n==0)
	{
		printf("\nInvalid no. of process");
		exit(1);
	}
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the arrival time for process P%d: ",i);
		scanf("%d",&p[i].at);
		p[i].id=i;
	}
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the burst time for process P%d: ",i);
		scanf("%d",&p[i].bt);
	}
	printf("\nInputs given by the user are:\n");
	printf("==============================================================");
	printf("\nProcess\tAT\tBT");
	for(i=1;i<=n;i++)
		printf("\nP%d\t%d\t%d",p[i].id,p[i].at,p[i].bt);
	printf("\n============================================================");	
	for(i=1;i<=n;i++)	// copying of one array into another array(dummy area)
		p1[i]=p[i];
	return n;
}
/* FUNCTION FOR DISPLAYING GANTT CHART FOR ROUND ROBIN SCHEDULING */ 
void ganttrr(int n)
{	
	int i,ts,m,nextval,nextarr;	
	nextval=p1[1].at;
	i=1;
	cout<<"\nEnter time slice: ";
	cin>>ts;
	printf("\n\nGantt chart is as follows\n\n");
	cout<<nextval;
	for(i=1;i<=n && p1[i].at<=nextval;i++)
		q1.push(p1[i].id);
	while(!q1.empty())	
	{	
		m=q1.front();
		q1.pop();
		if(p1[m].bt>=ts)
			nextval=nextval+ts;	
		else
			nextval=nextval+p1[m].bt;			
		cout<<"->P"<<p1[m].id<<"->"<<nextval;
		if(p1[m].bt>=ts)
			p1[m].bt=p1[m].bt-ts;	
		else
			p1[m].bt=0;			
		while(i<=n&&p1[i].at<=nextval)//processes are inserted into the queue(On the basis of arrival time) 
		{
			q1.push(p1[i].id);
			i++;
		}
		if(p1[m].bt>0)
			q1.push(m);
		if(p1[m].bt<=0)
			p[m].ft=nextval;
	}
}
/* FUNCTION FOR CALCULATING TURN AROUND TIME OR WAIT TIME */
void turnwait(int n)
{
	int i;	
	for(i=1;i<=n;i++)
	{
		p[i].tat=p[i].ft-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		p[0].tat=p[0].tat+p[i].tat;
		p[0].wt=p[0].wt+p[i].wt;
	}			
	p[0].tat=p[0].tat/n;
	p[0].wt=p[0].wt/n;
}
/* FUNCTION FOR DISPLAYING THE TABLE */
void display(int n)
{
	int i;	
	cout<<"\n\n-------------------TABLE----------------------------------\n";
	printf("\nProcess\tAT\tBT\tFT\tTAT\t\tWT");
	for(i=1;i<=n;i++)
		printf("\nP%d\t%d\t%d\t%d\t%f\t%f",p[i].id,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
	cout<<"\n\n-----------------------------------------------------------";
	printf("\nAverage Turn Around Time: %f",p[0].tat);
	printf("\nAverage Waiting Time: %f\n",p[0].wt);
}			

