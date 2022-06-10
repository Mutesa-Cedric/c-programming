//including all needed libraries

#include<stdio.h>

#include<stdlib.h>

#include<time.h>


int main() {
        //creating function for randomising a number

        srand(time(NULL));

        //section of all variables used

        char userName[30];

        int hiddenNumber = rand() % 21; //making hidden number random

        int guessedNumber;

        int guessCount = 0;

        int guessLimit = 5;

        int outOfGuess = 0;

        int remainingGuesses = 5;

        char gender, choice;


        printf("welcome to our GUESSING GAME\n\n developer:MUTESA Cedric\n\n");

        //getting and storing user name and gender

        printf("enter your user name:");

        fgets(userName, 30, stdin);

        printf("select your gender(M / F) :");

        scanf(" %c", & gender);

        //showing game rules to the user

        if (gender == 'M' || gender == 'm') {
                printf("hello Mr %s \n GAME RULES:\n __________ \n\n 1.you must guess a number between 0-20\n\n 2.guess limit is 5 times\n\n", userName);
        } else if (gender == 'F' || gender == 'f') {

                printf("hello Ms %s \n GAME RULES:\n __________ \n\n 1.you must guess a number between 0-20\n\n 2.guess limit is 5 times\n\n", userName);
        } else {
                printf("hello  %s\n with unknown gender \n \nGAME RULES:\n __________ \n\n 1.you must guess a number between 0-20\n\n 2.guess limit is 5 times\n\n", userName);
        }
        printf("enjoy the game!\n\n");

        //entering the loop for guessing

        /* here, the loop will continue until the user guesses a number or when he not out of guesses(the program will continue asking the user to enter a number)*/

        while (hiddenNumber != guessedNumber && outOfGuess == 0) {

                if (guessCount < guessLimit && guessedNumber <= 20) {

                        printf("\n you have %d chances left\n\n", remainingGuesses);

                        printf("guess number:\n\n");

                        scanf("%d", & guessedNumber);

                        guessCount++;

                        remainingGuesses--;


                } else {
                        outOfGuess = 1;

                         //this will stop the loop because outOfGuess is no longer equal to zero
                }
        }

        //output section

        if (guessedNumber > 20) {
                printf("\a invalid guess!!\n \n you have violated our game rules by entering a number greater than 20\n \n");
        } else if (outOfGuess == 1) {
                printf("\a  oops! sorry %s you are out of guesses\n\n", userName);
        } else if (gender == 'm' || gender == 'M' && guessedNumber == hiddenNumber) {
                printf("\n\a  congratulations Mr %s \n you are the winner!\n\n", userName);
        } else {
                printf("\n\a congratulations Ms %s \n you are the winner!\n\n", userName);

        }
        printf("thank you for playing our game\n\n");

        printf("do you need to see the statistics? (Y/N) :\n\n");

        scanf(" %c", & choice);

        if (choice == 'Y' || choice == 'y' && guessedNumber == hiddenNumber) {
                printf("your statstics:\n_______________\n");

                printf("\n 1. you have tried %d times.\n\n 2.result: you won the game.\n\n ", 5 - remainingGuesses);

                switch (remainingGuesses) {

                case 4:
                        printf("3. Your score percentage is 100% %.Excellent! \n \n");

                        break;

                case 3:
                        printf("3. your score percentage is 85% %.\n very good! \n \n");

                        break;

                case 2:
                        printf("3. your score percentage is 70% %.\n good! \n \n");

                        break;

                case 1:
                        printf("3. your score percentage is 60% %.\n not bad! \n \n");

                        break;

                case 0:
                        printf("3. your score percentage is 50% %.\n almost failed! \n \n");

                        break;

                default:
                        printf(" ");
                }

        } else if (choice == 'y' || choice == 'Y' && guessedNumber != hiddenNumber) {
                printf("your statstics:\n_______________\n");

                printf("\n 1. you have tried %d times.\n\n 2. result:you lost the game\n\n sorry!!\n\n", 5 - remainingGuesses);
        } else {

                printf("\n thank you for your collaboration!");
        }

        return 0;

}
