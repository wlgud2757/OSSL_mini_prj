2020-1 OSSL CRUD mini project
==============================
CVS product management system
------------------------------
## 1. Introduction
This program is a **CVS product management system** built on **CRUD**.
Data is managed by storing the product name, company, and price information.
You can add data by entering the keyboard input or reading .txt file, and you can also freely update information of product or delete the product data.
Using dynamic memory allocation in a program can be effective in using memory.

## 2. Data information
	1. company
	2. price 
	3. name
  
## 3. Function implementation
### 3.1. int load_a_product(Record *records[], int count)
This function will read the file, allocate memory space, and save the contents of the product stored in the file.
A variable called "count" remembers how large the product has been stored so far, and then allows the product to be stored.

### 3.2. int add_a_product(Record *records[], int count)
This function for adding products. "malloc" allocates memory space to add one product.
Then, you enter and save the contents of the product from the user.

### 3.3. void print_specific_products(Record *records[], int count)
This function prints a specific stored product.
After receiving the company information from the user, the product will be printed if the product information matches the company information entered by the user. 

### 3.4. void print_all_product(Record *records[], int count)
This function prints out all stored products.
The "count" variable checks the number of stored products and prints the product information through a loop statement.

### 3.5. void save_all_product(Record *records[], int count)
This function stores all stored products in a .txt file through File IO.
Open the file with 'wt' and save it as a ‘fprint’ through a repeating statement because you need to save it as a file.

### 3.6. int reset_original_data(Record *records[], int count)
This function deletes all stored products and stores them newly from .txt.
It initializes all products through "free" and reads them through file IO.
Use "malloc" to allocate memory space for products to be stored.
Then change the last character from name to '\0' to handle it so that no errors are made.

### 3.7. void change_information_product(Record *records[], int count)
This function changes the information of a specific product.
Receive product numbers and options from the user.
Options determine what information you can change, and you receive information you want to replace with keyboard input.

### 3.8. void apply_sale_product(Record *records[], int count)
This function applies the sale option by accessing the price information of all products through a loop statement.

### 3.9. void delete_specific_product(Record *records[], int count)
This function receives product number input from user.
The code is to delete the product number through 'free'.
The product number starts with 1, but the structure array starts with zero the means option-1 in source code.

### 3.10. int delete_all_product(Record *records[], int count)
This function’s loop statement is activated by a count variable that remembers the number of stored goods.
And it's a code that removes all stored goods through 'free'. 

## 4. Extra
### 4.1. Dynamic memory allocation
This program manages data through **Dynamic Memory allocation**.
It creates memory space that will create or read data whenever needed through **malloc**, and also removes it from memory space when deleting data through **free**.
Through this, memory management can be done efficiently when the program is running.

