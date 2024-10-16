#include<stdio.h>
#define QSIZE 5
void insert(int q[],int *rear, int ele)
{
    if(*rear==QSIZE-1)
    {
        printf("Queue Overflow! Queue is Full\n");
        return;
    }
    q[++(*rear)]=ele;
}
int delete(int q[],int *front, int *rear)
{
    if(*front>*rear)
    {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }
    return  q[(*front)++];
}
void display(int q[],int *front,int *rear)
{
    if(*front>*rear)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }
    printf("Queue elements are\n");
    for(int i=*front;i<=*rear;i++)
        printf("%d\t",q[i]);
}
void main()
{
    int rear=-1,front=0,q[QSIZE],choice,ele;
    while(1)
    {
        printf("\nMENU\n1.Insert\n2.Delete\n3.Display\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter an element\n");
                scanf("%d",&ele);
                insert(q,&rear,ele);
                break;
            case 2:
                ele=delete(q,&front,&rear);
                if(ele==-1)
                    {
                        printf("Queue is empty\n");
                        break;
                    }
               printf("Deleted item is %d",ele);
               break;
            case 3:
                display(q,&front,&rear);
                break;
            default: printf("Enter a valid choice\n");
                     break;
        }
    }

}
