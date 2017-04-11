#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,burst[10],arrival[10],wait[10],turn[10],i,finish[10],sum=0;
    printf("\nEnter no. of Processes : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
            printf("\n Enter the burst time and arrival time of %d program : ",i+1);
        scanf("%d",&arrival[i]);
        scanf("%d",&burst[i]);
        finish[i] = finish[i-1]+burst[i];
        finish[0]= burst[0];
        turn[i]=abs(finish[i]-arrival[i]);
        wait[i]=abs(turn[i]-burst[i]);

    }
    wait[0]=0;

    printf("\nS.no\tA.T\tB.T\tF.T\tT.A.T\tW.T");
    for(i=0;i<n;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d",i+1,arrival[i],burst[i],finish[i],turn[i],wait[i]);
        sum+=wait[i];
    }
    printf("Average waiting time= %f",(float)(sum/n));
    return 0;
}
