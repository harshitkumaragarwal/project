#include<stdio.h>
int main(){
    float num1,num2,result;
    char operator,error;


    printf("enter num1:");
    scanf("%f",&num1);

    printf("enter num2:");
    scanf("%f",&num2);


    printf("enter operator:");
    scanf(" %c",&operator);

    if (operator=='+'){
    result=num1+num2; 
    printf("result=%f\n", result);  
 }
    else if (operator=='-'){
        result=num1-num2;

        printf("result=%f\n", result);
    }

    else if (operator=='*') {
        result=num1*num2;

        printf("result=%f\n", result);
    }
    else if(operator=='%'){
        result=fmod(num1,num2);

        printf("result=%f",result);
    }

    else if (operator='/'){ 

        if (num2==0){
        printf("Invalid Input");
        }
        else {
         result=num1/num2;

         printf("result=%f\n", result);
        }
          
        }

       else {
        printf("Invalid operator\n");
    }
      return main;

}