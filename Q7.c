#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at the end
void insert(struct Node** head, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (!*head) *head = newNode;
    else {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Count nodes
int count(struct Node* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
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
        printf("\n1. Insert  2. Count  3. Display  4. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Enter value: "); scanf("%d", &val); insert(&head, val); }
        else if (ch == 2) printf("Total nodes: %d\n", count(head));
        else if (ch == 3) display(head);
    } while (ch != 4);
    
    return 0;
}
