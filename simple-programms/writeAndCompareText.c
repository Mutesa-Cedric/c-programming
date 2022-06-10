#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int nOfNames;
    char nameOfFile[20];
    char name[20];
    printf("Enter the name of file you want to use: \n \n ");
    scanf("%s", nameOfFile);

    printf("how many names do you want to enter? \n ");
    scanf("%d", &nOfNames);

    // inserting into file
    FILE *fileStream = fopen(nameOfFile, "w");

    for (int i = 0; i < nOfNames; i++)
    {
        printf("--->");
        scanf("%s", name);
        fputs(name, fileStream);
        fputs("\n", fileStream);
    }

    fclose(fileStream);
    // inserting into file

    // reading from file

    FILE *namesFile = fopen(nameOfFile, "r");

    int i = 0;
    char nameRead[30];
    char readNames[nOfNames][20];
    while (fgets(nameRead, sizeof(nameRead), namesFile) != NULL)
    {
        strcpy(readNames[i], nameRead);
        i++;
    }


    char testName[30]="";

    for (int i = 0; i < nOfNames; i++)
    {
        if(!strncmp(testName, readNames[i], strlen(testName)))
        {
            printf("%s", readNames[i]);
        }
    }

    fclose(namesFile);
    // reading from file
}