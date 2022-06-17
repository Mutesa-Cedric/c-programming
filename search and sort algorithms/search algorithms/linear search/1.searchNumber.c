
#include <stdio.h>

/*

we are going to ask the user to enter the
array of numbers, length of array , and the number to search.

then, we will tell him the index of the number which  he is searching for.

*/

int main()
{
        int arr[100], n, search, i;

        printf("Enter the length of an array:");
        scanf("%d",n);

        printf("Enter the array members:");

        //storing numbers in the array.

        for(i = 0; i < n; i++){
                scanf("%d",&arr[i]);
        }

        printf("Enter the number you need to search:");
        scanf("%d",&search);

        for(i=0;i<n;i++){
                if(arr[i]==search){
                   printf("%d have entered is located at position : %d",search,i+1);
                   break;     
                }

                if(search==n){
                        printf("%d is not found!",search);
                        return 0;
                }
        }
}
