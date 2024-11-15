#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head, int value) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  
  newNode->data = value;
  newNode->next = *head; 
  *head = newNode;
}

void insertAtEnd(struct node **head, int value) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  struct node *temp;
   
  newNode->data = value;
  newNode->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
