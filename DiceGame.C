#include <stdio.h>

// Function Declerations (prototypes)
void randomNUmberDice(int *die1,int *die2);

int main() {
    char playerOneName[50];  // Allocate enough space for the name
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

    return 0;
}



