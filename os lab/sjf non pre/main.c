//PROGRAM FOR SHORTEST-JOB-FIRST(SJF) "CPU SCHEDULING ALGORITHM" WITHOUT PRE_EMPTION
 #include<stdio.h>
 #include<conio.h>
 int main()
 {
   int at[10], bt[10], ct[10], wt[10], ta[10], tat[10];
   int n, i, k, pc=0, pointer = 0, tn =0, c;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   printf("Enter <ArrivalTime> <BurstTime>\n");
   for(i=0;i<n;i++)
     scanf("%d %d",&at[i],&bt[i]);
   for(i=0; i<n; i++)
   {
     ct[i] = -1;
     ta[i] = bt[i];
   }
   while(pc!=n)
   {
     c = 0;
     for(i=0; i<n; i++)
       if(ct[i]<0 && at[i]<=tn)
         c++;
     if(c==0)
       tn++;
     else
     {
       pointer = 0;
       while(at[pointer]>tn || ct[pointer]>0)
         pointer++;
       for(k=pointer+1; k<n; k++)
         if(at[k]<=tn && ct[k]<0 && bt[pointer]>bt[k])
           pointer = k;
       if(ct[pointer]<0)
       {
         tn=tn+bt[pointer];
         bt[pointer] = 0;
         ct[pointer] = tn;
         wt[pointer] = ct[pointer] - ( at[pointer]+ ta[pointer] );
         tat[pointer] = ct[pointer] - at[pointer];
         pc++;
       }
     }
   }
   printf("AT\tBT\tCT\tWT\tTAT\n");
   for(i=0;i<n;i++){
     printf("%d\t%d\t%d\t%d\t%d\n",at[i],ta[i],ct[i],wt[i],tat[i]);
     c=c+wt[i];
   }
   printf("Average Waiting time : %f",(float)c/n-0.1);
   return 0;
 }
