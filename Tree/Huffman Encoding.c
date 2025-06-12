#include <stdio.h>
#include <stdlib.h>

// Define a Huffman Tree node
struct Node {
    char data;
    int freq;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Min-Heap structure
struct MinHeap {
    int size;
    struct Node* array[100];
};

// Swap two nodes
void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the min-heap
void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract minimum value node
struct Node* extractMin(struct MinHeap* heap) {
    struct Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Insert node into min-heap
void insertMinHeap(struct MinHeap* heap, struct Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Build the Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    heap->size = 0;

    for (int i = 0; i < size; i++) {
        heap->array[i] = createNode(data[i], freq[i]);
    }
    heap->size = size;

    for (int i = (heap->size - 2) / 2; i >= 0; --i) {
        minHeapify(heap, i);
    }

    while (heap->size > 1) {
        struct Node* left = extractMin(heap);
        struct Node* right = extractMin(heap);

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        insertMinHeap(heap, newNode);
    }

    return extractMin(heap);
}

// Print Huffman Codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];

    for (int i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &data[i], &freq[i]);
    }

    struct Node* root = buildHuffmanTree(data, freq, n);

    int arr[100], top = 0;
    printf("Huffman Codes are:\n");
    printCodes(root, arr, top);

    return 0;
}
