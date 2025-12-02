#include<stdio.h>
#include<string.h>

struct student{

    char name[10];
    int age;
    int id;

};

void sort(struct student s[], int n, int choice, int order){

struct student temp;

int i,j;

for(i=0;i<n-1;i++){
    for(j=1+1;j<n;j++){

        int compare=0;

        if(choice==1)
        compare=strcmp(s[i].name,s[j].name);

        else if(choice==2)
        compare=s[i].age -s[j].age;

        else if (choice==3)
        compare=s[i].id -s[j].id;

        if((order==1 && compare>0) || (order==2 && compare <0)){

            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
          }
        }
    }
}

int main(){

    int n,i,choice,order;

    printf("enter number of student ");
    scanf("%d",&n);

    struct student s[n];

    for(i=0;i<n;i++){

        printf("\n enter detail for student %d",i+1);

        printf("name");
        scanf("%s",s[i].name);

        printf("age");
        scanf("%d",s[i].age );

        printf("id");
        scanf("%d",s[i].id);
    }

    printf("\nsort by \n1.name\n2.age\n3.id\nenter choice");
    scanf("%d",&choice);

    printf("order \n1.ascending\n2.descending\nenter the order");
    scanf("%d",&order);

    sort(s,n,choice,order);

    printf("\n***sorted student lsit******\n");

    for(i=0;i<n;i++){

        printf("name %s,age %d,id %d\n",s[i].name,s[i].age,s[i].id);
    }

    return 0;
}