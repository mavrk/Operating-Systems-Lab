#include <stdio.h>
#include <stdlib.h>
int r=0,pf=0;
int main()
{
    int f[20],s[20],f1,s1,i,j,found;
     scanf("%d",&f1);
      scanf("%d",&s1);
      for(i=0;i<s1;i++) {
         scanf("%d",&s[i]);
      }
      for(i=0;i<f1;i++) {
         f[i]=s[i];
      }

      for(j=f1;j<s1;j++) {
            found=0;
            printf("Loop %d\t ",j);
            for(i=0;i<f1;i++) {

            if(s[j]==f[i]) {

                found++;

        } }
        printf("Found at %d\t",found);
        if(found==0) {
                f[r]=s[j];
      printf("f[r]: %d\t",f[r]);
                printf("REplacing %d %d\t",j,found);
                pf++; r++;
                if(r>=f1) {
                    r=0;
                }
        }
            }



      printf("PAge faults: %d",pf);
       return 0;
}
