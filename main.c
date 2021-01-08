#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random number generator

int main()
{
    //assigning variables
    int randomNumber = 0;
    int guess = 0;
    int numberOfGuesses;
    time_t t;

    //initialize random number generator
    srand((unsigned) time(&t));

    //get random number
    randomNumber = rand() % 21;

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 0 and 20 which you must guess. \n");

    for(numberOfGuesses = 5; numberOfGuesses > 0; --numberOfGuesses) //counting down guesses
    {
        printf("\nYou have %d tr%s left.", numberOfGuesses, numberOfGuesses == 1 ? "y" : "ies");
        printf("\nEnter a guess :");
        scanf("%d", &guess); //storing the users guess in the variable

        if(guess == randomNumber)
        {
            printf("\nCongratulations. You guessed my number!\n"); //if player guesses number
        }
        else if(guess < 0 || guess > 20) //checking for an invalid guess
            printf("Invalid number. Try between 0 and 20 like I said.\n");
        else if(randomNumber > guess) //guess is too low
            printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
        else if(randomNumber < guess) //guess is too high
            printf("Sorry, %d is wrong. My number is less than that.\n", guess);
    }

    printf("\nYou are out of tries! The number I guessed was %d\n.", randomNumber); //loser!

    return 0;
}
