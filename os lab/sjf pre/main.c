#include<stdio.h>
 #include<conio.h>
 int main()
 {
   int n,at[10], bt[10], ct[10], wt[10], tn =0, c, ta[10],tat[10];
   int i, k, tot, pc=0, pointer = 0, lp=-1;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   printf("Enter <ArrivalTime> <BurstTime>\n");
   for(i=0;i<n;i++)
     scanf("%d%d",&at[i],&bt[i]);
   for(i=0; i<n; i++)
   {
       ct[i] = -1;
       ta[i] = bt[i];
   }
   while(pc!=n)
   {
     k=0;
     c = 0;
     for(i=0; i<n; i++)
     {
       if(ct[i]<0 && at[i]<=tn)
         c++;
     }
     if(c==0)
       tn++;
     else
     {
       pointer = 0;
       while(at[pointer]>tn || ct[pointer]>0)
         pointer++;
       for(k=pointer+1; k<n; k++)
         if( (at[k]<=tn && ct[k]<0) &&
           ( (bt[pointer]==bt[k] && k==lp) || bt[pointer]>bt[k] ) )
             pointer = k;
       if(ct[pointer]<0)
       {
         bt[pointer]--;
         tn++;
         if(bt[pointer]==0)
         {
           ct[pointer] = tn;
           wt[pointer] = ct[pointer] - ( at[pointer]+ ta[pointer] );
           tat[pointer] = ct[pointer] - at[pointer];
           pc++;
         }
       }
       lp = pointer;
     }
   }
   c=0;
   printf("\nAT\tBT\tCT\tWT\tTAT\n");
   for(i=0;i<n;i++){
     printf("%d\t%d\t%d\t%d\t%d\n",at[i],ta[i],ct[i],wt[i],tat[i]);
     c+=wt[i];
   }
   printf("Aerage Waiting time : %f",(float)c/n);
   return 0;
 }
