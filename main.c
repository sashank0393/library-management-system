#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int available;
};

struct Book library[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", library[numBooks].title);
        printf("Enter author name: ");
        scanf(" %[^\n]", library[numBooks].author);
        library[numBooks].available = 1; // book is available when added
        numBooks++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void displayBooks() {
    if (numBooks == 0) {
        printf("No books in the library.\n");
    } else {
        printf("Books in the library:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("%d. Title: %s | Author: %s | %s\n", i + 1, library[i].title, library[i].author,
                   library[i].available ? "Available" : "Not Available");
        }
    }
}

void borrowBook() {
    displayBooks();

    if (numBooks > 0) {
        printf("Enter the number of the book you want to borrow: ");
        int bookNumber;
        scanf("%d", &bookNumber);

        if (bookNumber > 0 && bookNumber <= numBooks) {
            if (library[bookNumber - 1].available) {
                library[bookNumber - 1].available = 0; // mark as not available
                printf("You have successfully borrowed %s\n", library[bookNumber - 1].title);
            } else {
                printf("Sorry, the selected book is not available for borrowing.\n");
            }
        } else {
            printf("Invalid book number.\n");
        }
    }
}

void returnBook() {
    displayBooks();

    if (numBooks > 0) {
        printf("Enter the number of the book you want to return: ");
        int bookNumber;
        scanf("%d", &bookNumber);

        if (bookNumber > 0 && bookNumber <= numBooks) {
            if (!library[bookNumber - 1].available) {
                library[bookNumber - 1].available = 1; // mark as available
                printf("You have successfully returned %s\n", library[bookNumber - 1].title);
            } else {
                printf("This book is already available in the library.\n");
            }
        } else {
            printf("Invalid book number.\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting library management system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
