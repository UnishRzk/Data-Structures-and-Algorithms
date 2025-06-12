#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at the beginning
void insertBeg(struct Node** head, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// Delete from the beginning
void deleteBeg(struct Node** head) {
    if (!*head) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Display list
void display(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int ch, val;
    
    do {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Enter value: "); scanf("%d", &val); insertBeg(&head, val); }
        else if (ch == 2) deleteBeg(&head);
        else if (ch == 3) display(head);
    } while (ch != 4);

    return 0;
}
