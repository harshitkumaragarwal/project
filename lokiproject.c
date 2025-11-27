#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// defining the colour 
#define green "\x1b[32m"
#define red "\x1b[31m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define reset "\x1b[0m"

#define TOTAL_QUESTION 10

struct question {
    char question[200];
    char options[4][100];
    int correct;
};

//  function declaration
void startQuiz(struct question q[], int total, char topic[], char name[], int *score);

void startQuiz(struct question q[], int total, char topic[], char name[], int *score) {

    printf(blue "\n========== QUIZ STARTED ==========\n" reset);
    printf(green "Topic: %s\n" reset, topic);

    for(int i = 0; i < total; i++) {

        printf(yellow "%d. %s\n" reset, i+1, q[i].question);

        for(int option = 0; option < 4; option++)
            printf(" %d) %s\n", option+1, q[i].options[option]);

        int ans;
        printf("Enter your answer (1 to 4): ");
        scanf("%d", &ans);

        if(ans == q[i].correct) {
            printf(green "Correct!\n" reset);
            (*score)++;  // Increase score using DMA
        }
        else {
            printf(red "Wrong!\n" reset);
        }
    }

    printf(blue "\n============== QUIZ ENDED ============\n" reset);
}




int main() {

    srand(time(0));

    // Dynamic memory for score
    int *score = (int*)malloc(sizeof(int));
    *score = 0;

    struct question cprog[TOTAL_QUESTION] = { 
        {"Which header file is used for input and output?", {"stdio.h","string.h","time.h","stdlib.h"}, 1},
        {"Which keyword is used to declare a constant variable in C?", {"int","const","string","int main"}, 2},
        {"What is the index of the first element in an array?", {"1","0","2","none"}, 2},
        {"Which operator gets the address of a variable?", {"#","*","&","$"}, 3},
        {"Which keyword terminates a loop?", {"break","continue","switch","none"}, 1},
        {"Function to find length of string?", {"strlen","string.h","stdlib.h","none"}, 1},
        {"Symbol for single-line comment?", {"/*","//","\n","#"}, 2},
        {"What happens if a string literal is modified?", {"compilation error","undefined behavior","prints modified","runtime error"}, 2},
        {"Static variable inside function means?", {"reinitialized every time","keeps value","accessed globally","becomes global"}, 2},
        {"If a function returns int but no return?", {"compiler error","undefined behavior","0 returned","garbage value"}, 3}
    };

    struct question physic[TOTAL_QUESTION] = {
        {"What do you mean by laser?", {"amplification of light","amplification of ray","amplification of wave","none"}, 1},
        {"Stimulated emission means?", {"forced release","forced intake","zero force","none"}, 1},
        {"NOT a property of laser?", {"monochromatic","coherent","divergence","directional"}, 3},
        {"Process for laser action?", {"spontaneous","stimulated","reflection","refraction"}, 2},
        {"Population inversion means?", {"more atoms lower state","equal atoms","more atoms higher state","none"}, 3},
        {"First laser made using?", {"He-Ne gas","Ruby crystal","CO2 gas","semiconductor"}, 2},
        {"Laser used in CD players?", {"ruby","He-Ne","semiconductor","CO2"}, 3},
        {"Laser application?", {"welding","holography","surgery","all"}, 4},
        {"Which laser works in IR region?", {"ruby","He-Ne","CO2","nitrogen"}, 3},
        {"Laser light is?", {"incoherent mono","coherent mono","incoherent poly","coherent poly"}, 2}
    };



    char name[50], branch[50];
    int sapid, choice, startoption;

    printf(blue "\n========== QUIZ PORTAL ==========\n" reset);

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your SAP ID: ");
    scanf("%d", &sapid);

    printf("Enter your branch: ");
    scanf("%s", branch);

    printf(yellow "\nPress 1 to START the Quiz: " reset);
    scanf("%d", &startoption);

    if(startoption != 1) {
        printf(red "Quiz not started. Exiting...\n" reset);
        return 0;
    }

    printf("\nChoose your topic\n");
    printf("1) C Programming\n");
    printf("2) Physics\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);


    if(choice == 1)
        startQuiz(cprog, TOTAL_QUESTION, "C Programming", name, score);

    else if(choice == 2)
        startQuiz(physic, TOTAL_QUESTION, "Physics", name, score);

    else {
        printf(red "Invalid choice!\n" reset);
        return 0;
    }



    // -----------------------------------------
    // SAVE RESULT TO quizscorecard.txt
    // -----------------------------------------
    FILE *fp = fopen("quizscorecard.txt", "a");

    if(fp != NULL) {

        fprintf(fp,
        "Name: %s   SAPID: %d   Branch: %s   Score: %d/%d\n",
        name, sapid, branch, *score, TOTAL_QUESTION);

        fclose(fp);

        printf(green "\nYour score has been saved in quizscorecard.txt\n" reset);
    }
    else {
        printf(red "Error opening quizscorecard.txt!\n" reset);
    }

    free(score);

    return 0;
}
