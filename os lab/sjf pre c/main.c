#include <stdio.h>
#include <stdlib.h>

int main()
{
    //sjf preemptive
    int i,j,m=0;float burst[10],cpu1[10],arrival[10];int n,v,visit[10],mn,pos;float finish[10];
    float wait[10],tt=0,k=0;
   printf("\nEnter no of programs : ");
   scanf("%d",&n);
   for(i=0;i<n;i++){
    wait[i]=0;
    visit[i]=0;
    finish[i]=0;
    printf("\nEnter arrival time and burst time : ");
    scanf("%f %f",&arrival[i],&burst[i]);
    cpu1[i]=burst[i];
    v=v+cpu1[i];
   }
   int l=0,count=0;
   while(k<n){
         mn=10000;
         pos=-1;
        for(j=0;j<n;j++){
            if(!visit[j]&&tt>=arrival[j]&&mn>=burst[j]){
                mn=burst[j];
                pos=j;
            }
        }
        if(count==0){
            k=pos;
        }
   if(k!=pos){
    k=pos;
    tt+=0.4;
   }
        cpu1[pos]--;
        tt++;
        for(j=0;j<n;j++){
            if(!visit[j]&&cpu1[j]==0){
                    visit[j]=1;
                    finish[j]=tt;
                    wait[j]= tt-burst[j]-arrival[j];
                    k++;
            }
        }
   count++;
   }
   k=0;
    for(i=0;i<n;i++){
        printf("\n %d\t %f\t %f\t %f",i+1,arrival[i],burst[i],wait[i]);
        k=k+wait[i];
    }
    printf("\n %f",k/10);
    return 0;
}
