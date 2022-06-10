#include <stdio.h>

typedef struct{
    char name[20];
    char age;
}mystruct;

mystruct person;

void asign(name,age){
   person.name=name;
   person.age=age;
}

void main(){
    char name[20];
    int age;
    printf("enter your name:");
    scanf("%s",name);
                          
    printf("enter your name:");
    scanf("%d",&age);

    asign(name,age);
                          
}