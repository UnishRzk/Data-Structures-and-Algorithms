#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at a specified position
void insertAt(struct Node** head, int val, int pos) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;
    
    if (!temp) { free(newNode); return; }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void display(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int ch, val, pos;
    
    do {
        printf("\n1. Insert  2. Display  3. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { 
            printf("Enter value & position: ");
            scanf("%d %d", &val, &pos);
            insertAt(&head, val, pos);
        } else if (ch == 2) display(head);
    } while (ch != 3);

    return 0;
}
