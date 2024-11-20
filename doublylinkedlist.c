
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create a doubly linked list
void createList(struct Node** head) {
    int size, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("List size must be greater than 0.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (*head == NULL) {
            *head = newNode;  // The first node
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// b) Insert a new node to the left of the node with specific value
void insertLeft(struct Node** head, int newData, int existingData) {
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == existingData) {
            struct Node* newNode = createNode(newData);
            newNode->next = temp;
            newNode->prev = temp->prev;

            if (temp->prev != NULL) {
                temp->prev->next = newNode;
            }

            temp->prev = newNode;

            if (temp == *head) {
                *head = newNode;  // Update head if inserting at the beginning
            }

            printf("Inserted %d before node with value %d.\n", newData, existingData);
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", existingData);
}

// c) Delete the node based on a specific value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (temp->data == value) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    while (temp != NULL) {
        if (temp->data == value) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", value);
}

// d) Display the contents of the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with switch-case
int main() {
    struct Node* head = NULL;
    int choice, data, existingData;

    do {
        // Display menu options
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create list\n");
        printf("2. Display list\n");
        printf("3. Insert node to the left of a node\n");
        printf("4. Delete node by value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the existing node value to insert before: ");
                scanf("%d", &existingData);
                insertLeft(&head, data, existingData);  // Pass head by reference
                break;
            case 4:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
