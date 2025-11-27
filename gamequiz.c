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
    int correct; // give option in the question 

};

  //  function declaration
void startQuiz(struct question q[], int total, char topic[], char name[]);

void startQuiz(struct question q[], int total, char topic[], char name[]) {

    printf(blue "\n========== QUIZ STARTED ==========\n" reset);

    printf(green "Topic %s\n" reset,topic);

    printf(blue "======================\n"reset);

    for(int i=0;i<total;i++){

        printf(yellow "%d. %s\n" reset,i+1,q[i].question);

        for(int option=0;option<4;option++)
        printf(" %d %s\n",option +1,q[i].options[option]);

        int ans;

        printf("enter your anser (1 to 4)");
        scanf("%d",&ans);

        if(ans==q[i].correct)
        printf(green"correct\n" reset);

        else
        printf(red "wrong!\n"reset);

    }

    printf(blue "\n==============QUIZ ENDED ============\n" reset);
    
}




// this strcut is for programming purpose
int main(){
    srand(time(0));
    
    

     struct question cprog[TOTAL_QUESTION] = { 
        {"Which header file is used for input and output?", 
            {"stdio.h","string.h","time.h","stdlib.h"},1},

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
    int startoption;

     printf(blue "\n========== QUIZ PORTAL ==========\n" reset); // at the interference

     printf("Welcome to the Quiz Portal!\n");

     printf("Rules:\n");

     printf("1) Each correct answer = 1 point\n");

     printf("2) No negative marking\n");

     printf("3) You can view a hint if needed\n");
 
     printf("4) Answer only in numbers 1-4\n");



    printf( green"enter your name" reset); // enter your name

    scanf("%s",name);

    printf( green"enter your psid" reset);
    scanf("%d",&sapid);

    printf( green"enter your branch" reset);
    scanf("%s",branch);

     printf(blue "\n==================================\n" reset);

    printf(yellow "Press 1 to START the Quiz: " reset);

    scanf("%d", &startoption);

    if(startoption != 1) {
        printf(red "Quiz not started. Exiting...\n" reset);
        return 0;
    }


 
    printf("choose your topic"); // topic you want to chosse option 

    printf("1) c programming\n"); // first is programming

    printf("2) physic quiz\n"); // second is physic quiz

    printf("enter your choice"); // choose from given two

    scanf("%d",&choice);




    if(choice==1)
        startQuiz(cprog,TOTAL_QUESTION,"C programming",name);// if choose 1 then c programming

        else if(choice==2)

        startQuiz(physic,TOTAL_QUESTION,"physic Quiz",name); // if choose 2 then physic quiz

        else

        printf(red"invalid choice!\n "reset); // if above 2 choice does not match the situation then print invalid choice 

        
}


