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

NODE insert_end(NODE first, int item) {
    NODE new_end, current;
    new_end = getnode();
    new_end->value = item;
    new_end->next = NULL;

    if (first == NULL) {
        return new_end;
    }
    current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_end;
    return first;
}

NODE insert_pos(NODE first, int item, int pos) {
    NODE new, prev, current;
    new = getnode();
    new->value = item;
    new->next = NULL;
    int count = 1;
    current = first;
    prev = NULL;
    while (current != NULL && count != pos) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == NULL && count != pos) {
        printf("Invalid position\n");
        return first;
    }
    if (prev != NULL) {
        prev->next = new;
    } else {
        first = new;
    }
    new->next = current;
    return first;
}

NODE del_beg(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    NODE temp;
    temp = first;
    first = temp->next;
    free(temp);
    return first;
}

NODE del_end(NODE first) {
    NODE prev, last;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    if (first->next == NULL) {
        free(first);
        return NULL;
    }
    prev = NULL;
    last = first;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
    return first;
}

NODE del_value(NODE first, int value) {
    NODE prev, current;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    prev = NULL;
    current = first;
    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found\n");
        return first;
    }
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        first = current->next;
    }
    free(current);
    return first;
}

void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    temp = first;
    while (temp != NULL) {
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    NODE first;
    first = NULL;
    int choice, val, pos;
    while (1) {
        printf("---MENU---\n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion at end\n");
        printf("3. Insertion at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete the given value\n");
        printf("7. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                first = insert_beg(first, val);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                first = insert_end(first, val);
                break;
            case 3:
                printf("Enter the value to be inserted and the position: ");
                scanf("%d%d", &val, &pos);
                first = insert_pos(first, val, pos);
                break;
            case 4:
                first = del_beg(first);
                break;
            case 5:
                first = del_end(first);
                break;
            case 6:
                printf("Enter the value to be deleted: ");
                scanf("%d", &val);
                first = del_value(first, val);
                break;
            case 7:
                display(first);
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
    return 0;
}
