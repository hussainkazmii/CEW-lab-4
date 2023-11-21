#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
struct Contact {
    char name[50];
    char email[50];
    char phone[15];
};

// Function to add a new contact to the address book
void addContact(struct Contact** addressBook, int* numContacts) {
    // Increment the number of contacts
    (*numContacts)++;

    // Reallocate memory for the updated number of contacts
    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

    // Prompt user for contact information
    printf("Enter name: ");
    scanf("%s", (*addressBook)[*numContacts - 1].name);
    printf("Enter email: ");
    scanf("%s", (*addressBook)[*numContacts - 1].email);
    printf("Enter phone number: ");
    scanf("%s", (*addressBook)[*numContacts - 1].phone);

    printf("Contact added successfully!\n");
}

// Function to delete a contact from the address book
void deleteContact(struct Contact** addressBook, int* numContacts) {
    if (*numContacts == 0) {
        printf("Address book is empty. No contacts to delete.\n");
        return;
    }

    // Display existing contacts
    printf("Existing contacts:\n");
    for (int i = 0; i < *numContacts; ++i) {
        printf("%d. %s\n", i + 1, (*addressBook)[i].name);
    }

    // Prompt user for the index of the contact to delete
    int index;
    printf("Enter the index of the contact to delete: ");
    scanf("%d", &index);

    // Validate the index
    if (index < 1 || index > *numContacts) {
        printf("Invalid index.\n");
        return;
    }

    // Move the last contact to the deleted position to maintain continuity in memory
    (*addressBook)[index - 1] = (*addressBook)[*numContacts - 1];

    // Decrement the number of contacts
    (*numContacts)--;

    // Reallocate memory for the updated number of contacts
    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

    printf("Contact deleted successfully!\n");
}

// Function to display all contacts in the address book
void displayContacts(const struct Contact* addressBook, int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty.\n");
        return;
    }

    printf("Contacts in the address book:\n");
    for (int i = 0; i < numContacts; ++i) {
        printf("%d. Name: %s, Email: %s, Phone: %s\n", i + 1,
               addressBook[i].name, addressBook[i].email, addressBook[i].phone);
    }
}

int main() {
    struct Contact* addressBook = NULL;
    int numContacts = 0;
    int choice;

    do {
        // Display menu
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&addressBook, &numContacts);
                break;
            case 2:
                deleteContact(&addressBook, &numContacts);
                break;
            case 3:
                displayContacts(addressBook, numContacts);
                break;
            case 4:
                // Free allocated memory before exiting the program
                free(addressBook);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
