#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all_records(Record[]);
void add_a_record(Record[]);

// add fuction prototypes
int reset_original_data(Record *records[], int count);
int add_a_product(Record *records[], int count);
int load_a_product(Record *records[], int count);
void print_all_product(Record *records[], int count);
void print_specific_products(Record *records[], int count);
void save_all_product(Record *records[], int count);
void change_information_product(Record *records[], int count);
void apply_sale_product(Record *records[], int count);
void delete_specific_product(Record *records[], int count);
void delete_all_product(Record *records[], int count);

#endif
