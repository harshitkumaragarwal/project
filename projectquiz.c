#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//colour define kar rahe h 
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

// this code checking the input sholud be only alphabatic;
int isAlpha(char str[]){
    
    for(int i=0; str[i] !='\0';i++){
        if(!((str[i] >'A' && str[i] <='Z') || (str[i] >= 'a' && str[i] <='z')))

        return 0;

    }
    return 1;
}

// check number only in input

int isNumber(char str[]){

    for(int i=0; str[i] !='\0';i++){
        if(str[i] < '0' || str[i] > '9')

        return 0;
    }
    return 1;
}

// function declare kar rahe h 
void startQuiz(struct question q[], int total, char topic[], char name[], FILE *fp);

// quiz with file handling 
void startQuiz(struct question q[], int total, char topic[], char name[], FILE *fp) {

    printf(blue "\n========== QUIZ STARTED ==========\n" reset);
    printf(green "Topic: %s\n" reset, topic);
    printf(blue "==================================\n" reset);

    fprintf(fp, "\n========== QUIZ STARTED ==========\n");
    fprintf(fp, "Topic: %s\n", topic);
    fprintf(fp, "==================================\n");

    int score = 0;

    for(int i = 0; i < total; i++) {

        printf(yellow "\n%d. %s\n" reset, i+1, q[i].question);
        fprintf(fp, "\n%d. %s\n", i+1, q[i].question);

        for(int option = 0; option < 4; option++) {
            printf(" %d) %s\n", option + 1, q[i].options[option]);
            fprintf(fp, " %d) %s\n", option + 1, q[i].options[option]);
        }

        int ans;
        printf("Enter your answer (1 to 4): ");
        scanf("%d", &ans);

        fprintf(fp, "User Answer: %d\n", ans);

        if (ans == q[i].correct) {
            printf(green "Correct!\n" reset);
            fprintf(fp, "Result: Correct\n");
            score++;
        } else {
            printf(red "Wrong!\n" reset);
            fprintf(fp, "Result: Wrong (Correct = %d)\n", q[i].correct);
        }
    }

    printf(blue "\n============== QUIZ ENDED ============\n" reset);
    printf(green "Final Score: %d / %d\n" reset, score, total);

    fprintf(fp, "\n============== QUIZ ENDED ============\n");
    fprintf(fp, "Final Score: %d / %d\n", score, total);
}


// main function
int main() {
    srand(time(0));

// file open in quiz_report.txt the final answer
    FILE *fp = fopen("quiz_report.txt", "w"); // fp mean file file 

    if(fp == NULL) {
        printf(red "Error opening file!\n" reset);
        return 1;
    }

    struct question cprog[TOTAL_QUESTION] = { 
        {"Which header file is used for input and output?", // question1  
            {"stdio.h","string.h","time.h","stdlib.h"},1}, // answer

        {"Which keyword is used to declare a constant variable in C?", // question 2
            {"int","const","string","int main"}, 2}, // answer

        {"What is the index of the first element in an array?", // question 3
            {"1","0","2","none"}, 2}, // answer

        {"Which operator gets the address of a variable?", // question 4
            {"#","*","&","$"}, 3}, //answer

        {"Which keyword terminates a loop?", // question 5 
            {"break","continue","switch","none"}, 1},// answer

        {"Function to find length of string?", // question 6
            {"strlen","string.h","stdlib.h","none"}, 1},// answer

        {"Symbol for single-line comment?", // question 7
            {"/*","//","\n","#"}, 2},// answer

        {"What happens if a string literal is modified?", // question 8
            {"compilation error","undefined behavior","prints modified","runtime error"}, 2},// answer

        {"Static variable inside function means?", // question 9
            {"reinitialized every time","keeps value","accessed globally","becomes global"}, 2}, // answer

        {"If a function returns int but no return?", // question 10
            {"compiler error","undefined behavior","0 returned","garbage value"}, 3} // answer
    };

    struct question physic[TOTAL_QUESTION] = {
        {"What do you mean by laser?", //question 1
            {"amplification of light","amplification of ray","amplification of wave","none"}, 1}, // answer

        {"Stimulated emission means?", // question 2
            {"forced release","forced intake","zero force","none"}, 1}, // answer

        {"NOT a property of laser?",  // question 3
            {"monochromatic","coherent","divergence","directional"}, 3}, // answer

        {"Process for laser action?",  // question 4
            {"spontaneous","stimulated","reflection","refraction"}, 2}, // answer

        {"Population inversion means?", // question 5
            {"more atoms lower state","equal atoms","more atoms higher state","none"}, 3}, // answer

        {"First laser made using?", // question 6
            {"He-Ne gas","Ruby crystal","CO2 gas","semiconductor"}, 2}, // answer

        {"Laser used in CD players?",  // question 7
            {"ruby","He-Ne","semiconductor","CO2"}, 3}, // answer

        {"Laser application?", // question 8
            {"welding","holography","surgery","all"}, 4}, // answer

        {"Which laser works in IR region?", // question 9
            {"ruby","He-Ne","CO2","nitrogen"}, 3},// answer

        {"Laser light is?",  // question 10 
            {"incoherent mono","coherent mono","incoherent poly","coherent poly"}, 2} // answer
    };

    char name[50], branch[50];

    int choice, sapid,  startoption;

    char sapid_str[20];

    printf(blue "\n========== QUIZ PORTAL ==========\n" reset); // interface starting 

    // Interactive interface taken help from chat gpt 
printf(blue "\n\n*******************************************************\n" reset);
printf(blue   "*                                                     *\n" reset);
printf(yellow "*            W E L C O M E   T O   T H E              *\n" reset);
printf(green  "*                                                     *\n" reset);
printf(green  "*            >>>   QUIZ  PORTAL  SYSTEM   <<<         *\n" reset);
printf(yellow "*                                                     *\n" reset);
printf(blue   "*******************************************************\n\n" reset);

printf(red    "-------------------------------------------------------\n" reset);
printf(yellow " This quiz contains:                                   \n" reset);
printf(yellow "   2 Topics (C Programming, Physics)                   \n" reset);
printf(yellow "   10 Questions in each topic                          \n" reset);
printf(yellow "   Automatic Result Evaluation                         \n" reset);
printf(yellow "   Report Saved in File (quiz_report.txt)              \n" reset);
printf(red    "-------------------------------------------------------\n\n" reset);

printf(green "       Get Ready To Test Your Knowledge! \n" reset);
printf(blue  "-------------------------------------------------------\n" reset);

printf(yellow "\nPress ENTER to continue..." reset);
getchar();
getchar();   // to pause the screen


    while(1){
    printf(green "Enter your name: " reset);
    scanf("%s", name);

    if(isAlpha(name)) break;
    printf(red"Error ! name must be alphabetic only \n"reset);
    }

    while(1){
    printf(green "Enter your SAP ID: " reset);
    scanf("%s", sapid_str);

    if(isNumber(sapid_str)){
        sapid=atoi(sapid_str); // atoi convert a string into number
        break;
    }
    printf(red"Error! SAP ID must contain digit only"reset);
}

    printf(green "Enter your branch: " reset);
    scanf("%s", branch);

    // Write details to file of name sapid and branch,
    fprintf(fp, "STUDENT DETAILS:\n");

    fprintf(fp, "Name: %s\n", name);

    fprintf(fp, "SAP ID: %d\n", sapid);

    fprintf(fp, "Branch: %s\n", branch);

    fprintf(fp, "--------------------------------------------\n");

    printf(yellow "\nPress 1 to START the Quiz: " reset); // to start the quiz

    scanf("%d", &startoption);

    if(startoption != 1) {
        printf(red "Quiz not started. Exiting...\n" reset);

        fprintf(fp, "Quiz not started.\n");

        fclose(fp);
        return 0;
    }

    // choose any 1 topic from given 2 option 
    
    printf("\nChoose your topic: ");

    printf("\n1) C Programming\n");

    printf("2) Physics Quiz\n");

    printf("Enter your choice: ");

    scanf("%d", &choice);

    if(choice == 1) {
        fprintf(fp, "Topic Selected: C Programming\n");

        startQuiz(cprog, TOTAL_QUESTION, "C Programming", name, fp);
    }
    else if(choice == 2) {
        fprintf(fp, "Topic Selected: Physics\n");

        startQuiz(physic, TOTAL_QUESTION, "Physics Quiz", name, fp);
    }
    else {
        printf(red "Invalid Choice!\n" reset);

        fprintf(fp, "Invalid Topic Selected\n");
    }

    fclose(fp);

    printf(green "\nQuiz report saved in 'quiz_report.txt'\n" reset);

    return 0;
}
