
#include <stdio.h>

struct complex{
    float real;
    float complex;
}first,second,sum;

void printSum(){
    sum.real=first.real+second.real;
    sum.complex=second.complex+first.complex;

    printf("the sum of real numbers is: %f\n",sum.real);
    printf("the sum of complex numbers is: %f\n",sum.complex);
}

void main(){

    printf("\n enter the first real number");
    scanf("%f",&first.real);

    printf("\n enter the first complex number");
    scanf("%f",&first.complex);

    printf("\n enter the second real number");
    scanf("%f",&second.real);

    printf("\n enter the second complex number");
    scanf("%f",&second.complex);

    printSum();

}