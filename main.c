#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
int input_handler(char[], Record *[], int);
void display_menu();

// main function
int main(){
	Record *records[MAX_RECORDS]; // struct pointer
  int count = 0; // product count
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		count = input_handler(user_input, records, count);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
int input_handler(char input[], Record *records[], int count){

	// TODO: Modify this function as you need
	if(!strcmp(input, "0"))
		count = reset_original_data(records, count);
	else if(!strcmp(input, "1"))
		count = add_a_product(records, count);
	else if(!strcmp(input, "2"))
		count = load_a_product(records, count);
	else if(!strcmp(input, "3"))
		print_all_product(records, count);
	else if(!strcmp(input, "4"))
		print_specific_products(records, count);
	else if(!strcmp(input, "5"))
		change_information_product(records, count);	
	else if(!strcmp(input, "6"))
		apply_sale_product(records, count);
	else if(!strcmp(input, "7"))
		save_all_product(records, count);	
	else if(!strcmp(input, "8"))
		delete_specific_product(records, count);	
	else if(!strcmp(input, "9"))
		count = delete_all_product(records, count);	
	else if(!strcmp(input, "10"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);

  return count;
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" CVS product management system \n");
	printf("******************************\n");
        printf(" 0. Reset to original data\n");
	printf(" 1. Add a new product\n");
	printf(" 2. Load product by previous data\n");
	printf(" 3. Print all product\n");
	printf(" 4. Print specific products\n");
	printf(" 5. Change information of product\n");
	printf(" 6. Apply sale of all product\n");
	printf(" 7. Save all product\n");
	printf(" 8. Delete specific products\n");
	printf(" 9. Delete all product\n");
	printf(" 10. Quit\n");
}
