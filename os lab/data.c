#include <stdio.h>
#include <stdlib.h>

int count1=0;
struct node {
 int data;
 struct node *ptr;
 } *front, *rear , *shift ,*shift1 ,*temp ;

 void create() {
 rear = front = NULL;
 }
 void insert(int d) {
  if(rear == NULL)
     {
        rear = (struct node*)malloc(1*sizeof(struct node));
        rear->data = d;
        front=rear;
        rear->ptr=NULL;
         count1++;

     }
     else {
        temp= (struct node*)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->data= d;
        temp->ptr=front;
        rear=temp;
         count1++;
     }
     }
     void dqueue()
     {
         shift=front;
         if(shift== NULL)
         {
             printf("Empty Queue");

         }
         else {
            if(shift->ptr!= NULL)
            {
                shift=shift->ptr;
                printf("Deleted value: %d",front->data);
                free(front);
                front=shift;
                count1--;
            }
            else {
                printf("Deleted value: %d",front->data);
                free(front);
                front= NULL;
                rear= NULL;
                count1--;
            }
         }

     }
int search(int s1) {
    printf("Size = %d",count1);
 int c = 0;
  shift=front;
 while(c<count1) {
        if(shift->data==s1) {

            return (c+1);
            break;
        }
        else {
             shift=shift->ptr;
             c++;
        }
 }
 return (c);

}
int reposition(int r1, int p1) {
    int earl,i=0,j=0,swap;
    earl=search(r1);
    if(earl==0) {
        printf("No such element found!");
        return;
    }
    else{
        shift=shift1=front;
        while(i<p1) {
            shift=shift->ptr;
            i++;
        }
        swap=shift->data;
        shift->data=r1;
        while(j<earl) {
            shift1=shift1->ptr;
            j++;
        }
        shift1->data=swap;
        return;

    }
}
void removal(int n12, int np1) {
 temp= (struct node*)malloc(1*sizeof(struct node));

 shift=front;
 int i=0;
 while(i<np1)
 {
     shift=shift->ptr;
     i++;
 }
 temp->ptr=shift->ptr->ptr;
 shift->ptr=temp;
 temp->data=n12;
}
void display() {
 shift = front;
 int s=0;
   while(s<count1)
    if ((shift == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (shift != rear)
    {
        printf("%d ", shift->data);
        shift = shift->ptr;
    }
    if (shift == rear)
        printf("%d", shift->data);
    s++;
}



int main()
{
    printf("Circular Queue\n 1.Insert\t 2.Delete\t 3.Search\t 4.Reposition\t 5.Removal \t 6.Exit");
    int ch,d1,s,r,p,n1,np,s3;
    while(1) {
       printf("\nEnter choice : ");
       scanf("%d",&ch);
       switch(ch) {
        case 1  : printf("Enter data : ");
                  scanf("%d",&d1);
                  insert(d1);


                  display();

                  break;
        case 2  : dqueue();
                  printf("New Queue: ");
                  display();
                  break;
        case 3  : printf("Enter the data to be searched :");
                  scanf("%d",&s);
                  s3=search(s);

                  if(s3==count1) {
                    printf("Not found");
                  }
                  else {
                    printf("Found in position %d ",s3);
                  }

                  break;
        case 4  : printf("Repositioning..");
                  printf("Enter the data :");
                  scanf("%d",&r);
                  printf("Enter the new position : ");
                  scanf("%d", &p);
                  reposition(r,p);

                  display();
                  break;
        case 5  : printf("Removal");
                  printf("Enter the new data: ");
                  scanf("%d",&n1);
                  printf("\t Enter the position");
                  scanf("%d",&np);
                  removal(n1,np);

                  display();
                  break;
        case 6  : exit(0);
        default : printf("Wrong choice");



        }
    }
    return 0;
}
