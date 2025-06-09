#include <stdio.h>
#include <stdbool.h>

int main() {

    // Display ASCII banner from file
    FILE *file;
    char line[256];

    file = fopen("src/ascii_art.txt", "r");  // open the ASCII file

    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Could not load ASCII art from 'src/banner.txt'\n");
    }


    float price = 10.00;
    int age = 0;
    bool card_membership = false; // +10% discount
    bool isStudent = false;       // +10% discount
    bool isSenior = false;        // +20% discount
    char response;

    // Welcome message
    printf("Hello! Welcome to our terminal cinema!\n");

    // Membership input
    printf("\nDo you own a card membership? (Y or N): ");
    scanf(" %c", &response);  

    if (response == 'Y' || response == 'y') {
        card_membership = true;
    } else if (response == 'N' || response == 'n') {
        card_membership = false;
    } else {
        printf("Invalid input for membership.\n");
    }

    // Age input
    printf("\nWhat is your age? ");
    scanf("%d", &age);

    if (age < 18) {
        isStudent = true;
    } else if (age >= 65) {
        isSenior = true;
    }

    // --------------------
    // DISCOUNT CALCULATION
    // --------------------
    float discount = 0.0;

    if (card_membership) {
        discount += 10;
    }
    if (isStudent) {
        discount += 10;
    }
    if (isSenior) {
        discount += 20;
    }

    // Cap discount at 30%
    if (discount > 30) {
        discount = 30;
    }

    // Apply discount
    if (discount > 0) {
        printf("\nYou get a discount of %.0f%%!\n", discount);
        price *= (1 - discount / 100.0);
    } else {
        printf("\nYou currently don't have any discounts.\n");
    }

    // Final price
    printf("The price of a ticket is $%.2f\n\n", price);

    return 0;
}
