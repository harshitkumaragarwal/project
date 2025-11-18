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

// function declaration
void startQuiz(struct question q[], int total, char topic[], char name[]);

// ---------------- MAIN --------------------
int main() {
    srand(time(0));

    struct question cprog[TOTAL_QUESTION] = { 
        {"Which header file is used for input and output?", 
            {"stdio.h","string.h","time.h","stdlib.h"}, 1},

        {"Which keyword is used to declare a constant variable in C?", 
            {"int","const","string","int main"}, 2},

        {"What is the index of the first element in an array?", 
            {"1","0","2","none"}, 2},

        {"Which operator gets the address of a variable?", 
            {"#","*","&","$"}, 3},

        {"Which keyword terminates a loop?", 
            {"break","continue","switch","none"}, 1},

        {"Function to find length of string?", 
            {"strlen","string.h","stdlib.h","none"}, 1},

        {"Symbol for single-line comment?", 
            {"/*","//","\n","#"}, 2},

        {"What happens if a string literal is modified?", 
            {"compilation error","undefined behavior","prints modified","runtime error"}, 2},

        {"Static variable inside function means?", 
            {"reinitialized every time","keeps value","accessed globally","becomes global"}, 2},

        {"If a function returns int but no return?", 
            {"compiler error","undefined behavior","0 returned","garbage value"}, 3}
    };

    struct question physic[TOTAL_QUESTION] = {
        {"What do you mean by laser?", 
            {"amplification of light","amplification of ray","amplification of wave","none"}, 1},

        {"Stimulated emission means?", 
            {"forced release","forced intake","zero force","none"}, 1},

        {"NOT a property of laser?", 
            {"monochromatic","coherent","divergence","directional"}, 3},

        {"Process for laser action?", 
            {"spontaneous","stimulated","reflection","refraction"}, 2},

        {"Population inversion means?", 
            {"more atoms lower state","equal atoms","more atoms higher state","none"}, 3},

        {"First laser made using?", 
            {"He-Ne gas","Ruby crystal","CO2 gas","semiconductor"}, 2},

        {"Laser used in CD players?", 
            {"ruby","He-Ne","semiconductor","CO2"}, 3},

        {"Laser application?", 
            {"welding","holography","surgery","all"}, 4},

        {"Which laser works in IR region?", 
            {"ruby","He-Ne","CO2","nitrogen"}, 3},

        {"Laser light is?", 
            {"incoherent mono","coherent mono","incoherent poly","coherent poly"}, 2}
    };

    char name[50], branch[50];
    int choice;
    int sapid;
    int startOption;

    // ------------------ INTERFACE --------------------
    printf(blue "\n========== QUIZ PORTAL ==========\n" reset);

    printf(green "Enter your Name: " reset);
    scanf("%s", name);

    printf(green "Enter your SAP ID: " reset);
    scanf("%d", &sapid);

    printf(green "Enter your Branch: " reset);
    scanf("%s", branch);

    printf(blue "\n==================================\n" reset);
    printf(yellow "Press 1 to START the Quiz: " reset);
    scanf("%d", &startOption);

    if(startOption != 1) {
        printf(red "Quiz not started. Exiting...\n" reset);
        return 0;
    }

    // ------------------ CHOOSE TOPIC ------------------
    printf(blue "\n======= SELECT QUIZ TOPIC =======\n" reset);
    printf("1) C Programming\n");
    printf("2) Physics Quiz\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        startQuiz(cprog, TOTAL_QUESTION, "C Programming", name);
    else if(choice == 2)
        startQuiz(physic, TOTAL_QUESTION, "Physics Quiz", name);
    else
        printf(red "Invalid choice!\n" reset);

    return 0;
}

// ---------------- QUIZ FUNCTION ---------------------
void startQuiz(struct question q[], int total, char topic[], char name[]) {

    printf(blue "\n---------------------\n" reset);
    printf(green "Welcome %s! Starting %s...\n" reset, name, topic);
    printf(blue "---------------------\n\n" reset);

    int asked[TOTAL_QUESTION] = {0}; 
    int score = 0;
    time_t start = time(NULL);

    for(int i=0;i<5;i++) {  
        int id;
        do {
            id = rand() % total;
        } while(asked[id] == 1);

        asked[id] = 1;

        printf(yellow "\nQ%d: %s\n" reset, i+1, q[id].question);
        for(int op=0; op<4; op++) {
            printf("  %d) %s\n", op+1, q[id].options[op]);
        }

        int ans;
        printf("Your answer: ");
        scanf("%d", &ans);

        if(ans == q[id].correct) {
            printf(green "Correct!\n" reset);
            score++;
        } else {
            printf(red "Wrong! Correct answer is %d\n" reset, q[id].correct);
        }
    }

    time_t end = time(NULL);
    int duration = end - start;

    printf(blue "\n------ QUIZ RESULT ------\n" reset);
    printf(green "Name: %s\n" reset, name);
    printf("Score: %d / 5\n", score);
    printf("Time taken: %d seconds\n", duration);
    printf(blue "-------------------------\n" reset);
}
