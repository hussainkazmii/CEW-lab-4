#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to convert a linked list to an array
int* linkedListToArray(struct Node* head, int* size) {
    // Find the size of the linked list
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Allocate memory for the array
    int* array = (int*)malloc(count * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy elements from the linked list to the array
    current = head;
    for (int i = 0; i < count; i++) {
        array[i] = current->data;
        current = current->next;
    }

    // Set the size variable
    *size = count;

    return array;
}

// Function to display an array
void displayArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for a linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create a linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Display the original linked list
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    int size;
    int* array = linkedListToArray(head, &size);

    printf("Array: ");
    displayArray(array, size);

    freeList(head);
    free(array);

    return 0;
}
