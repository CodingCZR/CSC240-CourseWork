#include <stdio.h>
#include <time.h> // Used for Random Number
#include <stdlib.h> // Used for Random Number

// Function Declerations (prototypes)
void randomNumberDice(int *dice1,int *dice2);
void startGame(char playerOneName[], char playerTwoName[]);
int playerTurn(char playerName[], int *totalScore);

int main() {
    srand(time(NULL)); // Used to intialze the random number. 

    // initializing variables
    int playerOneScore = 0;
    int playerTwoScore = 0;
    char playerOneName[50];  // Allocatign enough space for the name
    char playerTwoName[50]; 

    // Prompt for the player One's name
    printf("Enter Player 1's name: ");
    scanf("%49s", playerOneName);  // Use %s for strings, limit input to prevent overflow

    // Prompt for Player Two's Name
    printf("Enter Player 2's name: ");
    scanf("%49s", playerTwoName);

    // Print out the entered name to verify
    printf("Player 1's name is: %s\n", playerOneName);
    printf("Player 2's name is: %s\n", playerTwoName);

    startGame(playerOneName, playerTwoName);

    return 0;
}

void startGame(char playerOneName[], char playerTwoName[]){
    // Initializing values at 0
    int playerOneScore = 0;
    int playerTwoScore = 0;

    // Main game loop
    while (playerOneScore < 100 && playerTwoScore < 100) {
        printf("\n%s's turn:\n", playerOneName);
        playerTurn(playerOneName, &playerOneScore);
        printf("%s's total score: %d\n", playerOneName, playerOneScore);

        if (playerOneScore >= 100) {
            printf("%s wins!\n", playerOneName);
            break;
        }

        printf("\n%s's turn:\n", playerTwoName);
        playerTurn(playerTwoName, &playerTwoScore);
        printf("%s's total score: %d\n", playerTwoName, playerTwoScore);

        if (playerTwoScore >= 100) {
            printf("%s wins!\n", playerTwoName);
            break;
        }
    }
}
int playerTurn(char playerName[], int *totalScore) {
    int dice1, dice2;
    int turnScore = 0;
    char choice;

    do {
        randomNumberDice(&dice1, &dice2); // Roll the dice
        printf("%s rolls %d and %d.\n", playerName, dice1, dice2);
        
        // Point System
        if (dice1 == 1 && dice2 == 1) {
            printf("Snake eyes! You earn 25 points!\n");
            turnScore += 25;
        } else if (dice1 == 1 || dice2 == 1) {
            printf("You rolled a 1! No points for this turn.\n");
            return 0;
        } else if (dice1 == dice2) {
            turnScore += 2 * (dice1 + dice2);
            printf("Doubles! You earn double the points: %d\n", 2 * (dice1 + dice2));
        } else {
            turnScore += dice1 + dice2;
            printf("Your total for this turn is %d.\n", turnScore);
        }

        // Ask the player if they want to continue rollin
        printf("Do you want to roll again (Y/N)? ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y'); // Continue rolling if the player chooses 'Y'

    *totalScore += turnScore; // Add turn score to total score
    return turnScore; // Return the score from this turn
}

 // Generate a random number between 1 and 6
void randomNumberDice(int *dice1, int *dice2) {
    *dice1 = rand() % 6 + 1; 
    *dice2 = rand() % 6 + 1;
}
