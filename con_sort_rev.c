#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode() {
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory is not allocated");
        return NULL;
    }
    return ptr;
}

NODE insert_beg(NODE first, int item) {
    NODE new;
    new = getnode();
    new->value = item;
    new->next = NULL;
    if (first == NULL) {
        return new;
    }
    new->next = first;
    return new;
}
void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    temp = first;
    while (temp != NULL) {
        printf("%d \t", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
NODE concatinate(NODE first1,NODE first2)
{
    if(first1==NULL&&first2==NULL)
        return NULL;
    if(first1==NULL)
        return first2;
    if(first2==NULL)
        return first1;
    NODE last;
    last=first1;
    while(last->next!=NULL)
        last=last->next;
    last->next=first2;
    return first1;
}

NODE reverse(NODE first)
{
    NODE current, temp;
    current=NULL;
    while(first!=NULL)
    {
        temp=first;
        first=first->next;
        temp->next=current;
        current=temp;
    }
    return current;
}
void sort(NODE first)
{
    int x;
    NODE temp1,temp2;
    temp1=first;
    temp2=first->next;
    while(temp1->next!=NULL)
    {
        while(temp2!=NULL)
        {
            if((temp1->value)>=(temp2->value))
            {
                x=temp1->value;
                temp1->value=temp2->value;
                temp2->value=x;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

int main() {
    NODE first1,first2;
    first1 = NULL;
    first2=NULL;
    int choice, val;
    while (1) {
        printf("---MENU---\n");
        printf("1. Insertion in Linked list 1\n");
        printf("2. Insertion in Linked list 2\n");
        printf("3. Concatination\n");
        printf("4. Reverse\n");
        printf("5. Sort\n");
        printf("6. Display linked list 1\n");
        printf("7. Display linked list 2\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                first1 = insert_beg(first1, val);
                break;
             case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                first2 = insert_beg(first2, val);
                break;
            case 3:
                first1=concatinate(first1,first2);
                break;
            case 4:
                first2=reverse(first2);
                break;
            case 5:
                sort(first2);
                break;
            case 6:
                display(first1);
                break;
            case 7:
                display(first2);
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
    return 0;
}

