#include <stdio.h>
#include <string.h>

#define MAX 100  // maximum number of books

// structure to store book details
struct book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

// function declarations
void addbook(struct book library[], int *count);
void displaybook(struct book library[], int count);
void searchbook(struct book library[], int count);

int main() {
    struct book library[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n====== LIBRARY MANAGEMENT SYSTEM ======\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addbook(library, &count);
                break;

            case 2:
                displaybook(library, count);
                break;

            case 3:
                searchbook(library, count);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// function to add new book
void addbook(struct book library[], int *count) {
    if (*count >= MAX) {
        printf("Library is full! Cannot add more.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[*count].id);
    getchar(); // clear newline from input buffer

    printf("Enter Book Title: ");
    fgets(library[*count].title, sizeof(library[*count].title), stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0'; // remove newline

    printf("Enter Author Name: ");
    fgets(library[*count].author, sizeof(library[*count].author), stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = '\0'; // remove newline

    printf("Enter Quantity: ");
    scanf("%d", &library[*count].quantity);

    (*count)++;
    printf("Book added successfully!\n");
}

// function to display all books
void displaybook(struct book library[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Qty");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-20s %-10d\n",
               library[i].id, library[i].title, library[i].author, library[i].quantity);
    }
}

// function to search a book by ID
void searchbook(struct book library[], int count) {
    int id, found = 0;

    if (count == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n",
                   library[i].id, library[i].title, library[i].author, library[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found!\n");
}
