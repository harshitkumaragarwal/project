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

#define TOTAL_QUESTION 20
struct question {
    char question[200];
    char options[4][100];
    int correct; // give option in the question 

};

  // ✅ Function declaration
void startQuiz(struct question q[], int total, char topic[], char name[]);
    
 
// this strcut is for programming purpose
int main(){
    srand(time(0));
    struct question cprog[TOTAL_QUESTION] ={
        {"which header file is used for input and output ?",{"stdio.h","string.h","time.h","stdlib.h" }}, // question 1 for programming

        {"which keyword is used to declare  a constant variable in c?",{"int","const","string","int main"}}, // question 2 for programming 

        {"What is the index of the first element in an array?",{"1","0","2","none"}},  // question 3 for programming 

        {"Which operator is used to get the address of a variable?",{"#","*","&","$"}}, // question 4 for programming

        {"Which keyword is used to terminate a loop or switch statement?",{"break","continue","switch","both 1 and 2"}}, // question 5 for programming 

        {"Which function is used to find the length of a string?",{"strlen","string.h","stdlib.h","none"}}, // question 6 for programming 

        {"Which symbol is used to start a single-line comment in C?",{"/","/n","\n","//"}}, // question 7 for programming

        {"What is the output if a C program modifies a string literal?",{"compilation error","undefined behavior","program print modified string ","runtime over"}}, // question 8 for programming 

        {"What happens when a variable is declared as static inside a function?",{"It is reinitialized every time the function runs","It keeps its value between function calls","It can be accessed from other functions","It becomes a global variable"}}, // question 9 for programming 

        {"What happens if a function in C does not return a value but is declared to return int?",{"Compiler error","Undefined behavior","0 is automatically returned","Function returns garbage value"}}, // question 10 for programming  
        
    };

    struct question physic [TOTAL_QUESTION] ={
        {"what do you mean by laser",{"amplification of light","amplification of ray","amplification of wave","amplification of "}}, // question 1 of physic

        {"what do you mean by stimulate emission",{"forced release","forced intake","force zero","none of this"}},// question 2 of physic 

        {"Which of the following is NOT a property of laser light?",{"Monochromatic","coherent","divergence","directional"}}, // question 3 of physic

        {"The process responsible for laser action is?:",{" Spontaneous emission","Stimulated emission","Reflection","refraction"}},//question4 of physic

        {"Population inversion means?:",{"More atoms in the lower energy state","Equal number of atoms in both states",") More atoms in the higher energy state","No atoms in excited state"}},//question 5 for physic

        {"The first laser was made using?",{"Helium-Neon gas","Ruby crystal"," Carbon dioxide gas","Semiconductor diode"}},// question 6 for physic

        {"Which type of laser is commonly used in laser printers and CD players?",{"Ruby laser","He-Ne laser","Semiconductor laser","CO₂ laser"}},// question 7 for physic

        {"Which of the following is an application of laser?",{"Welding and cutting","Holography","Medical surgery","All of the above"}},// question 8 for physic

        {"Which of the following lasers operates in the infrared region?",{"Ruby laser","He-Ne laser","CO₂ laser","Nitrogen laser"}},// question 9 for physic

        {"The light emitted by a laser is?",{"Incoherent and monochromatic","Coherent and monochromatic","Incoherent and polychromatic","Coherent and polychromatic"}},//question 10 for physic 
        
    };



}

