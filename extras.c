  
#include <stdio.h>
#include <string.h>
#include "extras.h"

#define MAX_RECORDS 1000

void erase_data(Record* records[], int count){
  for(int i = 0; i < 30; i++){
    records[count]->name[i] = 0;  //name erase
    records[count]->company[i] = 0;
  }
  records[count]->price = 0;
}

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: numbers of valid records. 0 if there's none
// - Leave a brief information about the function
int defragment(Record *records[], int count){
  //if there is a deleted record at the end of the array, erase it.
  for(int i = count - 1; strcmp(records[i]->name, "") == 0; i--){
    erase_data(records, i);
    count--;
  }
  //if there is a deleted record in the middle, erase it and slide the rest of the array one element to the front.
  for(int i = 0; i < count; i++){
    if(strcmp(records[i]->name, "") == 0){
      for(int j = i; j < count; j++){
        erase_data(records, j);
        strcpy(records[j]->name, records[j + 1]->name);
        strcpy(records[j]->company, records[j + 1]->company);
        records[j]->price = records[j + 1]->price;
      }
      count--;
    }
  }
	// TODO: Modify this function as you need
	printf("defragmentation complete! \n\n");
	return count;	// TODO: return numbers of valid records. 0 if there's none
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	// TODO: Modify this function as you need
	printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
}


// TODO: Add more functions to fulfill the optional requirements
