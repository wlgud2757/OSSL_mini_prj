#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
/*
void print_all_records(Record records[]){
	// TODO: Modify this function as you need
	printf("print_all_records(): this function needs to be implemented\n\n");
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_record(Record records[]){
	// TODO: Modify this function as you need
	printf("add_a_record(): this function needs to be implemented\n\n");
}
*/

// TODO: Add more functions to fulfill the requirements

int reset_original_data(Record *records[], int count){
	// TODO: Modify this function as you need
  if(count > 0)
    for(int i=0; i<count; i++) free(records[i]);
  count = 0;
  FILE *data;
  data = fopen("data.txt", "r");
  while(1) {
    records[count] = (Record *)malloc(sizeof(Record));
    fscanf(data, "%s", records[count]->company);
    if(feof(data)) break;
    fscanf(data, "%d", &records[count]->price);
    fgets(records[count]->name, sizeof(records[count]->name), data);
    records[count]->name[(strlen(records[count]->name))-1] = '\0';
    count++;
  }
  fclose(data);
  printf("\nReset Complete!\n\n");
  return count;
}

int add_a_product(Record *records[], int count){
	// TODO: Modify this function as you need
  records[count] = (Record *)malloc(sizeof(Record));
  printf("\nEnter a company, price : ");
  scanf("%s %d", records[count]->company, &records[count]->price);
  printf("Now, Enter a product name : ");
  getchar(); // remove '/n'
  fgets(records[count]->name, sizeof(records[count]->name), stdin);
  records[count]->name[(strlen(records[count]->name))-1] = '\0';
  printf("\nAdd a product Complete!\n\n");
  return count+1;
}

int load_a_product(Record *records[], int count){
	// TODO: Modify this function as you need
  FILE *data;
  data = fopen("add.txt", "r");
  while(1) {
    records[count] = (Record *)malloc(sizeof(Record));
    fscanf(data, "%s", records[count]->company);
    if(feof(data)) break;
    fscanf(data, "%d", &records[count]->price);
    fgets(records[count]->name, sizeof(records[count]->name), data);
    records[count]->name[(strlen(records[count]->name))-1] = '\0';
    count++;
  }
  fclose(data);
  printf("\nLoad a product Complete!\n\n");
  return count;
}

void print_all_product(Record *records[], int count){
	// TODO: Modify this function as you need
	//printf("print_all_product(): this function needs to be implemented\n\n");
  printf("\n");
  printf("Num  Name  Company  Price\n");
  for(int i=0; i<count; i++) {
    printf("No.%d %s %s %d", i+1, records[i]->name, records[i]->company, records[i]->price);
    printf("\n");  
  }
  printf("\n----------THE END----------\n\n");
}

void print_specific_products(Record *records[], int count){
	// TODO: Modify this function as you need
	char option[10];
  printf("Enter a specific company : ");
  scanf("%s", option);
  getchar();
  printf("Num  Name  Company  Price\n");
  for(int i=0; i<count; i++) {
    if(strcmp(option, records[i]->company) == 0)
      printf("No.%d %s %s %d", i+1, records[i]->name, records[i]->company, records[i]->price);
      printf("\n");
  }
  printf("\n----------THE END----------\n\n");
}

void change_information_product(Record *records[], int count){
  int number;
  int option;
  int price;
  print_all_product(records, count);
  printf("Enter product number of you want to change information: ");
  scanf("%d", &number);
  printf("\n1: company, 2: price, 3:name\n");
  printf("What do want to chage of information? ");
  scanf("%d", &option);
  if(option==1){
    printf("Enter change company: ");
    scanf("%s", records[number-1]->company);
    getchar();
  }
  else if(option==2){
    printf("Enter change price: ");
    scanf("%d", &records[number-1]->price);
    getchar();
    }
  else if(option==3){
    getchar();
    printf("Enter change name: ");
    fgets(records[number-1]->name, sizeof(records[number-1]->name), stdin);
    records[number-1]->name[(strlen(records[number-1]->name))-1] = '\0';
  }
  printf("\nchange lnformation Complete!\n\n");
}

void apply_sale_product(Record *records[], int count){
  float sale;
  printf("What is Sale percent? (0.1~0.9) : ");
  scanf("%f", &sale);
  for(int i=0; i<count; i++) {
    records[i]->price = records[i]->price - records[i]->price*sale;
  }
  printf("All product apply sale!\n\n");
  getchar();
  printf("\nApply sale product Complete!\n\n");
}

void save_all_product(Record *records[], int count){
	// TODO: Modify this function as you need
	FILE *save;
  save = fopen("save.txt", "wt");
  for(int i=0; i<count; i++) {
    fprintf(save, "company : %s | " , records[i]->company);
    fprintf(save, "price : %d \n" , records[i]->price);
    fprintf(save, "name : ");
    fputs(records[i]->name, save);
    fprintf(save, "\n\n");
  }
  fclose(save);
  printf("\nSave is complete.\n\n");
}

void delete_specific_product(Record *records[], int count){
  int option;
  print_all_product(records, count);
  printf("Enter product number of you want to change information: ");
  scanf("%d", &option);
  free(records[option-1]);
  printf("%d proudct deleted!.\n\n", option);
  getchar();
  printf("\n%d product deleted!\n\n", option);
}

int delete_all_product(Record *records[], int count){
  for(int i=0; i<count; i++) {
    free(records[i]);
  }
  count = 0;
  printf("\nAll product deleted!\n\n");
  return count;
}

