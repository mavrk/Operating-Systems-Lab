
#include<stdio.h>
#include<process.h>
#include<string.h>

int main()
{
char p[10][5],temp[5];
int tot=0,wt[10],pt[10],i,j,n,temp1;
float avg=0;

printf("enter no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process%d name:\n",i+1);
scanf("%s",&p[i]);
printf("enter process time");
scanf("%d",&pt[i]);
}for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(pt[i]>pt[j])
{
temp1=pt[i];
pt[i]=pt[j];
pt[j]=temp1;
strcpy(temp,p[i]);
strcpy(p[i],p[j]);
strcpy(p[j],temp);
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+pt[i-1];
tot=tot+wt[i];
}
avg=(float)tot/n;
printf("p_name\t P_time\t w_time\n");
for(i=0;i<n;i++)
printf("%s\t%d\t%d\n",p[i],pt[i],wt[i]);
printf("total waiting time=%d\n avg waiting time=%f",tot,avg);

return 0;
}

