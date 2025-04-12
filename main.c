#include<stdio.h>

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void viewFlights() {
    printf("\n--- Available Flights ---\n");
    printf("Flight No\tFrom\t\tTo\t\tSeats\n");
    printf("1001\t\tColombo\t\tLondon\t\t5\n");
    printf("1002\t\tColombo\t\tDubai\t\t3\n");
    printf("1003\t\tColombo\t\tTokyo\t\t4\n");
    printf("1004\t\tColombo\t\tNew York\t2\n");
    printf("1005\t\tColombo\t\tParis\t\t0\n"); // No seats available
    


    // Add a prompt to return to the main menu
    printf("\nPress any key to return to the main menu...");
    getchar(); // Wait for user input
}

int main() {
    int choice;

    while (1) { // Loop to repeatedly show the main menu
        printf("\n=============================================\n");
        printf("\n|  Welcome to the Flight Reservation System  |\n");
        printf("\n=============================================\n");
        printf("Please select an option:\n");
        printf("1. View Flights\n");
        printf("2. Book Flight\n");
        printf("3. Cancel Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer after scanf

        switch (choice) {
            case 1:
                viewFlights();
                break;
            case 2:
                printf("Booking flight...\n"); //call a  your function
                break;
            case 3:
                printf("Cancelling flight...\n"); //call a your function
                break;
            case 4:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
