#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int login();
void regUser();
void userFunc();

struct User {
	char name[100];
	char contact [15];
	char nic [20];
	char username[50];
	char password[50];
};

int login(){
	char username[50], password[50];
	struct User user;
	FILE *file = fopen("users.csv", "r");

	printf("\nEnter your username : ");
	scanf("%s",username);
	
	printf("Enter your password : ");
	scanf("%s",password);
	
while (fscanf(file,"%99[^,],%14[^,],%19[^,],%49[^,],%49[^\n]\n", user.name, user.contact, user.nic, user.username,user.password)!= EOF){
	
	if(strcmp(username, user.username)==0 && strcmp(password, user.password)==0){
		printf("\nLogin Successfull! \nWelcome %s. \n\n",user.username);
		fclose(file);
		return 1;
	}
		
}
fclose(file);
printf("Login Failed. No User Detected!\nPlease Register First.\n");
userFunc();
return 0;
}


//Registering a new user
void regUser(){
	printf("   \n\nRegistration Menu   \n");
	printf("=======================\n\n");
	
	struct User user;
	FILE *file = fopen("users.csv","a");
	
	getchar();	
	printf("Enter your full name       : ");
	fgets(user.name,sizeof(user.name),stdin);
	user.name[strcspn(user.name,"\n")]='\0';
	
	printf("Enter your Contact number  : ");
	scanf("%s",user.contact);
	
	printf("Enter the NIC number       : ");
	scanf("%s",user.nic);
	
	printf("Enter the desired Username : ");
	scanf("%s",user.username);
	
	printf("Enter the password         : ");
	scanf("%s",user.password);
	
	fprintf(file,"%s,%s,%s,%s,%s\n",user.name,user.contact,user.nic,user.username,user.password);
	fclose(file);
	
	printf("Registration Successfull !\n\n");
}

void userFunc(){
int choice;
printf("\n\n==== WELCOME TO SRI LANKAN AIRLINE ====\n\n");
printf("To continue Please Login to your account or Register as new ...\n\n");

while(1){
printf("Main Menu\n");
printf("---------------\n");
printf("    1. Login\n");
printf("    2. Register\n");
printf("    3. Quit\n\n");
printf("Enter your choice : ");
scanf("%d",&choice);

	switch (choice){
		case 1 :
			login();
			return;
		case 2 :
			regUser();
			break;
		case 3 :
			printf("Goodbye...\n\n");
			return;
		default :
			printf("Invalid Input ! \n\n");
	}	
}

}



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

    // First, display the login or registration page
    userFunc(); // Call userFunc to handle login or registration

    // After successful login, display the main menu
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
                printf("Booking flight...\n"); // Call your booking function here
                break;
            case 3:
                printf("Cancelling flight...\n"); // Call your cancel function here
                break;
            case 4:
                printf("Thanks for choosing us.....\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Pause before showing the main menu again
        printf("\nPress any key to continue...");
        getchar(); // Wait for user input
    }

    return 0;
}
















