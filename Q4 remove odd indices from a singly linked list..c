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

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove elements with odd indices from the linked list
void removeOddIndices(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Nothing to remove if the list is empty or has only one element
    }

    struct Node* current = *head;
    struct Node* temp;

    // Remove the first node (index 1)
    *head = (*head)->next;
    free(current);

    current = *head;

    // Traverse the list and remove nodes with odd indices
    int index = 2; // Start with the second node (index 2)
    while (current != NULL && current->next != NULL) {
        if (index % 2 == 0) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
        index++;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
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
    struct Node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    // Display the original linked list
    printf("Original Linked List: ");
    displayList(head);

    // Remove elements with odd indices
    removeOddIndices(&head);

    // Display the modified linked list
    printf("Linked List after Removing Odd Indices: ");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
