#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct person
{
    char name[20];
    char address[20];
    char dob[20];
    char gender;
    float principal;
    float rate;
    float time;
    float emi;
    float totalAmount;

} p1;

int main()
{

    // variables
    float months;
    float years;
    float rate;
    // variables

    // name of a user
    printf("Enter name \t:");
    fgets(p1.name, sizeof(p1.name), stdin);
    printf("Entered name:  %s", p1.name);
    // name of a user

    // address of a user
    printf("\nEnter  address :");
    fgets(p1.address, sizeof(p1.address), stdin);
    printf("Entered address:  %s", p1.address);
    // address of a user

    // dob of a user
    printf("\nEnter the DOB  in the format dd/mm/yyyy  :");
    fgets(p1.dob, sizeof(p1.dob), stdin);
    printf("Entered dob:  %s", p1.dob);
    // dob of a user

    // gender of a user
    printf("\nEnter the gender :");
    scanf("%c", &p1.gender);
    printf("Entered gender: %c", p1.gender);
    // gender of a user

    // getting principal amount
    printf("\nEnter the principal  amount in Rwf \t:");
    scanf("%f", &p1.principal);
    printf("Entered principal amount: %.2f", p1.principal);
    // getting principal amount

    // getting rate of interest
    printf("\nEnter the rate of interest in percentage \t:");
    scanf("%f", &rate);
    printf("Entered interest rate: %.1f", rate);
    // getting rate of interest

    // getting time
    printf("\nEnter the time in years \t:");
    scanf("%f", &years);
    printf("Entered time: %.1f", years);
    // getting time

    // calculations

    p1.time = years * 12;
    p1.rate = rate / (12 * 100);
    p1.emi = p1.principal * p1.rate * pow((1 + p1.rate), p1.time) / (pow((1 + p1.rate), p1.time) - 1);
    p1.totalAmount = p1.emi * p1.time;
    // calculations

    // Borrower basic information

    printf("\n\nBorrower basic information\n");
    printf("=============================== \n\n");

    printf("Name: %s \n", p1.name);
    printf("Address: %s \n", p1.address);
    printf("DOB: %s \n", p1.dob);
    printf("Gender : %c \n\n", p1.gender);

    // Borrower basic information

    // Payment information

    printf("\n\nPayment information");
    printf("\n=============================== \n\n");

    printf("monthly EMI is Rwf %.3f", p1.emi);
    printf("\nTotal amount to be payed in %.1f months is Rwf %.3f", p1.time, p1.totalAmount);
    // Payment information
    
    // writing to a file
    FILE *fptr; 
    if ((fptr = fopen("loans.txt", "a")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    fputs("\n\nBorrower basic information\n", fptr);
    fputs("=============================== \n\n", fptr);
    fputs("Name: ", fptr);
    fputs(p1.name, fptr);
    fputs("\nAddress: ", fptr);
    fputs(p1.address, fptr);
    fputs("\nDOB: ", fptr);
    fputs(p1.dob, fptr);
    fputs("\nGender : ", fptr);
    fputc(p1.gender, fptr);
     
    fputs("\nPayment Information",fptr);
    fputs("\n=========================",fptr);

    fputs("\nMonthly EMI :",fptr);
    fprintf(fptr,"%.3f",p1.emi);
    fputs("\ntotalAmount:",fptr);
    fprintf(fptr,"%.3f",p1.totalAmount);
    fclose(fptr);

    return 0;
}
