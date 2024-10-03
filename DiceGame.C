#include <stdio.h>
#include <time.h> // Used for Random Number
#include <stdlib.h> // Used for Random Number

// Function Declerations (prototypes)
void randomNumberDice(int *dice1,int *dice2);
void startGame(char playerOneName[], char playerTwoName[]);

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

}
void randomNumberDice(int *dice1, int *dice2) {
    *dice1 = rand() % 6 + 1;  // Generate a random number between 1 and 6
    *dice2 = rand() % 6 + 1;
}
