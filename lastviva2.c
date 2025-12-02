#include <stdio.h>
#include <string.h>

struct student {
    char name[10];
    int age;
    int id;
};

void sort(struct student s[], int n, int choice, int order) {

    struct student temp;
    int i, j;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            int compare = 0;

            if(choice == 1)
                compare = strcmp(s[i].name, s[j].name);
            else if(choice == 2)
                compare = s[i].age - s[j].age;
            else if(choice == 3)
                compare = s[i].id - s[j].id;

            // Fix: compare was misspelled as comapre
            if((order == 1 && compare > 0) || (order == 2 && compare < 0)) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {

    int n, i, choice, order;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for(i = 0; i < n; i++) {

        printf("\nEnter detail for student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("ID: ");
        scanf("%d", &s[i].id);
    }

    printf("\nSort by:\n1. Name\n2. Age\n3. ID\nEnter choice: ");
    scanf("%d", &choice);

    printf("Order:\n1. Ascending\n2. Descending\nEnter the order: ");
    scanf("%d", &order);

    sort(s, n, choice, order);

    printf("\n*** Sorted Student List ***\n");
    for(i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, ID: %d\n", s[i].name, s[i].age, s[i].id);
    }

    return 0;
}
