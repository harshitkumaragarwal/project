#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "playlist.txt"

// Structure for Song node
struct Song {
    char title[100];
    char artist[100];
    float duration;
    struct Song *next;
};

// Function declarations
void addSong(struct Song **head);
void displayPlaylist(struct Song *head);
void deleteSong(struct Song **head);
void savePlaylist(struct Song *head);
void loadPlaylist(struct Song **head);
void playNext(struct Song **current, struct Song *head);

// Main function
int main() {
    struct Song *head = NULL;
    struct Song *current = NULL;
    int choice;

    loadPlaylist(&head);
    current = head;

    while (1) {
        printf("\n==============================\n");
        printf("   🎵 MUSIC PLAYLIST MANAGER 🎵\n");
        printf("==============================\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Next Song\n");
        printf("4. Delete Song\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                addSong(&head);
                break;
            case 2:
                displayPlaylist(head);
                break;
            case 3:
                playNext(&current, head);
                break;
            case 4:
                deleteSong(&head);
                break;
            case 5:
                savePlaylist(head);
                printf("\n✅ Playlist saved successfully! Exiting...\n");
                exit(0);
            default:
                printf("\n❌ Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to add a song
void addSong(struct Song **head) {
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    if (!newSong) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter song title: ");
    fgets(newSong->title, sizeof(newSong->title), stdin);
    newSong->title[strcspn(newSong->title, "\n")] = 0;

    printf("Enter artist name: ");
    fgets(newSong->artist, sizeof(newSong->artist), stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = 0;

    printf("Enter duration (in minutes, e.g. 3.45): ");
    scanf("%f", &newSong->duration);
    getchar();

    newSong->next = NULL;

    if (*head == NULL) {
        *head = newSong;
    } else {
        struct Song *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
    }

    printf("\n🎶 Song added successfully!\n");
}

// Function to display playlist
void displayPlaylist(struct Song *head) {
    if (head == NULL) {
        printf("\n📭 Playlist is empty!\n");
        return;
    }

    printf("\n======= 🎧 PLAYLIST =======\n");
    struct Song *temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("%d. %s | %s | %.2f mins\n", i, temp->title, temp->artist, temp->duration);
        temp = temp->next;
        i++;
    }
}

// Function to delete a song
void deleteSong(struct Song **head) {
    if (*head == NULL) {
        printf("\nPlaylist is empty!\n");
        return;
    }

    char title[100];
    printf("\nEnter song title to delete: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    struct Song *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n❌ Song not found!\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("\n🗑️ Song deleted successfully!\n");
}

// Function to play next song
void playNext(struct Song **current, struct Song *head) {
    if (head == NULL) {
        printf("\nPlaylist is empty!\n");
        return;
    }

    if (*current == NULL)
        *current = head;
    else
        *current = (*current)->next ? (*current)->next : head;

    printf("\n▶️ Now Playing: %s by %s (%.2f mins)\n",
           (*current)->title, (*current)->artist, (*current)->duration);
}

// Function to save playlist to file
void savePlaylist(struct Song *head) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error saving file!\n");
        return;
    }

    struct Song *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%s|%s|%.2f\n", temp->title, temp->artist, temp->duration);
        temp = temp->next;
    }

    fclose(fp);
}

// Function to load playlist from file
void loadPlaylist(struct Song **head) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;

    struct Song *newSong;
    char line[200];

    while (fgets(line, sizeof(line), fp)) {
        newSong = (struct Song *)malloc(sizeof(struct Song));
        sscanf(line, "%[^|]|%[^|]|%f", newSong->title, newSong->artist, &newSong->duration);
        newSong->next = NULL;

        if (*head == NULL)
            *head = newSong;
        else {
            struct Song *temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newSong;
        }
    }

    fclose(fp);
    printf("\n📂 Playlist loaded from file!\n");
}
