#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f,*fc,*f1,*f2;
    int a,w=0,l=0,c1=0;
    char c[]="d2.txt", /*line = NULL,*/h ,g,ch,e[]="move1.txt";;
    //size_t len=0;
    f=fopen("s.txt","r");
    fc=fopen("d1.txt","w");
    g=fgetc(f);
    while(g!= EOF) {

    printf("%c",g);
    g=fgetc(f);
    if(g==' ' || g=='.' ||g=='\n') {
       w++;
    }
    else {
        c1++;
    }
    if(g=='\n') {
      l++;
    }

    }
    printf("\nWords = %d Lines = %d Charcaters = %d",w,l,c1);
    rewind(f);
    h=fgetc(f);
    while(h!= EOF) {

    h=  fgetc(f);
      fputc(h, fc);
    }
    fclose(f);
    fclose(fc);

    a=remove(c);
    if(a==0)
        printf("\nFile deleted successfully");
   f1=fopen("move1.txt","r");
    f2=fopen("move2.txt","w");
  while((ch=getc(f1))!=EOF)
   putc(ch,f2);
  printf(" One File moved");
  fclose(f2);
    fclose(f1);
  remove(e);

    return 0;
}


