//By: Daniel Lifchitz (107719163)
#include <stdio.h>
#include <stdlib.h>


struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};




/********************************************************************
Milestones 1 to 4  prototypes, definitions and etc...*/
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
const double TAX = 0.13;
void welcome(void);
void prnTitle(void);
void prnFooter(double gTotal);
void pause(void);
void clrKyb(void);
int getInt(void);
double getDbl(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDblLimited(double lowerLimit, double upperLimit);
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int *index);
void GrocInvSys(void);
int menu(void);
/* ipc_ms2 prototype*/
int yes(void);  // ms2

				/*End of Student Milestone 3 definitions and prototypes
				*************************************************************/

				/*************************************************************
				Milestone 4 defintions and prototypes:*/
				// write the define statements here:

#define MAX_ITM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

				// function prototypes in order of implementation:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);

/*End of milestone 1 to 4 stuff
*********************************************************************/



/********************************************************************
Milestone 5 prototypes*/


#define MAX_ITEM_NO 500   
#define DATAFILE "ipc_ms5_short.txt"
//#difine DATAFILE "test.txt"

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

/*End of milestone 5 prototypes
*********************************************************************/




/**************************************************************************
TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR
TT       EE         SS             TT       EE          RR     RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
TT       EE               SS       TT       EE          RR  RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
***************************************************************************
Tester for saveItem, loadItem, saveItems and loadItems:
uncomment this to test your functions prior to putting all the code together by adding a * and / here: */


//
//void prnFile() {
//	FILE* tp = fopen("test.txt", "r");
//	char ch;
//	if (tp) {
//		for (; fscanf(tp, "%c", &ch) == 1; 
//			putch(ch));
//		fclose(tp);
//	}
//	else {
//		printf("text.txt not found\n");
//	}
//}
//
//
//int main(void) {
//int i, n;
//struct Item GI[3] = {
//{ 4.4,275,0,10,2,"Royal Gala Apples" },
//{ 5.99,386,0,20,4,"Honeydew Melon" },
//{ 3.99,240,0,30,5,"Blueberries" },
//};
//struct Item I;
//struct Item IN[3];
//printf("***********Testing saveItem:\n");
//printf("Your saveItem saved the following in test.txt: \n");
//FILE* tp = fopen("test.txt", "w");
//if (tp) {
//for (i = 0; i < 3; i++)
//saveItem(GI[i], tp);
//fclose(tp);
//prnFile();
//}
//printf("*******************************\nThey have to match the following:\n");
//printf("275,10,2,4.40,0,Royal Gala Apples\n");
//printf("386,20,4,5.99,0,Honeydew Melon\n");
//printf("240,30,5,3.99,0,Blueberries\n");
//printf("***********END Testing saveItem!\n\n\n");
//pause();
//printf("***********Testing loadItem:\n");
//printf("Your loadItem loaded the following from test.txt: \n");
//tp = fopen("test.txt", "r");
//if (tp) {
//for (i = 0; i < 3; i++) {
//loadItem(&I, tp);
//dspItem(I, LINEAR);
//}
//fclose(tp);
//tp = fopen("test.txt", "w");
//fclose(tp);
//}
//printf("*******************************\nThey have to match the following:\n");
//printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
//printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
//printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
//printf("***********END Testing loadItem!\n\n\n");
//pause();
//printf("***********Testing saveItems:\n");
//printf("Your saveItems saved the following in test.txt: \n");
//saveItems(GI, "test.txt", 3);
//prnFile();
//printf("*******************************\nThey have to match the following:\n");
//printf("275,10,2,4.40,0,Royal Gala Apples\n");
//printf("386,20,4,5.99,0,Honeydew Melon\n");
//printf("240,30,5,3.99,0,Blueberries\n");
//printf("***********END Testing saveItems!\n\n\n");
//pause();
//printf("***********Testing loadItems:\n");
//printf("Your loadItems loaded the following from test.txt: \n");
//loadItems(IN, "test.txt", &n);
//for (i = 0; i < n; i++) {
//dspItem(IN[i], LINEAR);
//}
//printf("*******************************\nThey have to match the following:\n");
//printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
//printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
//printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
//printf("***********END Testing loadItems!\n\n\n");
//pause();
//printf("Done!\n");
//return 0;
//}

/* End MS5 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************/


/********************************************************************
Main function to run the application
uncomment this to test your functions after putting all the code together by adding a * and / here:

int main(void) {
GrocInvSys();
return 0;
}

/* End Main function
********************************************************************/





/********************************************************************
Milestone 5 functions*/



int main(void) {
	GrocInvSys();
	return 0;
}

void saveItem(struct Item item, FILE* dataFile) {  //writes content of an item to the data file
	/*dataFile = fopen("items.txt", "w");*/
	if (dataFile != NULL) {
		//scanf("%d,%d,%d,%.2lf,%d,%s\n", &item.sku, &item.quantity, &item.minQuantity, &item.price, &item.isTaxed, &item.name);
		fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);

	}
	else {
		printf("Error to open the file.\n");
	}
	/*fclose(dataFile);*/
}
int loadItem(struct Item* item, FILE* dataFile) { // reads all fields of an Item and stores info into item structure via item pointer
	int i = 0;
	if (dataFile != NULL) {
		if (fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]s", &(*item).sku, &(*item).quantity, &(*item).minQuantity, &(*item).price, &(*item).isTaxed, (*item).name) == 6) {
			i = 1;
		}
		else {
			i = 0;
		}
	}
	else {
		printf("Error to open the file.\n");
	}
	return i;
}

int saveItems(struct Item* item, char fileName[], int NoOfRecs) { // writes an entire array of items into a file
	FILE *dataFile = NULL;
	int i = 0;
	dataFile = fopen(fileName, "w");

	if (dataFile != NULL) {
		for (i = 0; i < NoOfRecs; i++) {
			saveItem(item[i], dataFile);

		}
		fclose(dataFile);
		return 1;
	}
	else {
		printf("Error to open the file.\n");
		return 0;
	}
}
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr) { // reads all records saved in a file and set the target of a pointer to the number of items read from a file. 
	FILE *dataFile = NULL;
	int i = 0;
	dataFile = fopen(fileName, "r");

	if (dataFile != NULL) {
		while (loadItem(item, dataFile)) {
			i++;
		}
		*NoOfRecsPtr = i;
		rewind(dataFile);
		for (i = 0; i < *NoOfRecsPtr; i++) {
			loadItem(&item[i], dataFile);
		}

		fclose(dataFile);
		return 1;
	}
	else {
		printf("Error to open the file.\n");
		return 0;
	}

}




/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/
//void searchTest() {
// printf("================Search Test:\n");
// printf("Enter 731: \n");
// search(GI, GNoOfRecs);
// printf("Enter 222: \n");
// search(GI, GNoOfRecs);
//}
//void updateTest() {
// struct Item I = { 11.11,111,1,11,1,"Ones!" };
// printf("================Update Test:\n");
// printf("Enter the follwoing: \n");
// printf(
// "         SKU: 111\n"
// "        Name: Grape\n"
// "      Price : 22.22\n"
// "   Quantity : 22\n"
// "Minimum Qty : 2\n"
// "   Is Taxed : y\n"
// "Overwrite old data? (Y)es/(N)o: n\n");
// updateItem(&I);
// printf("Unchanged Item Data:\n");
// dspItem(I, FORM);
// printf("Enter the follwoing: \n");
// printf(
// "         SKU: 111\n"
// "        Name: Grape\n"
// "      Price : 22.22\n"
// "   Quantity : 22\n"
// "Minimum Qty : 2\n"
// "   Is Taxed : y\n"
// "Overwrite old data? (Y)es/(N)o: y\n");
// updateItem(&I);
// printf("Updated Item: \n");
// dspItem(I, FORM);
//}
//void addTest() {
// printf("================Add Test:\n");
// printf("Total items in Storage: %d, Max no: %d\n", GNoOfRecs, MAX_ITEM_NO);
// printf("Enter the follwoing: \n");
// printf(
// "         SKU: 222\n"
// "        Name: Grape\n"
// "      Price : 22.22\n"
// "   Quantity : 22\n"
// "Minimum Qty : 2\n"
// "   Is Taxed : y\n"
// "Add Item? (Y)es/(N)o: n\n");
// addItem(GI, &GNoOfRecs, 222); //n
// printf("Garbage here! Nothing is added, No of items in storage: %d\n", GNoOfRecs);
// dspItem(GI[GNoOfRecs], FORM);
// printf("Enter the follwoing: \n");
// printf(
// "         SKU: 222\n"
// "        Name: Grape\n"
// "      Price : 22.22\n"
// "   Quantity : 22\n"
// "Minimum Qty : 2\n"
// "   Is Taxed : y\n"
// "Add Item? (Y)es/(N)o: y\n");
// addItem(GI, &GNoOfRecs, 222); //y
// printf("New item is added, No of itemsinstorage: %d\n", GNoOfRecs);
// dspItem(GI[GNoOfRecs - 1], FORM);
// printf("Adding 333: \n");
// addItem(GI, &GNoOfRecs, 333);
//}
//void addOrUpdateTest() {
// GNoOfRecs = MAX_ITEM_NO;
// printf("================AddOrUpdate Test:\n");
// printf("Enter 731 and then \'n\':\n");
// addOrUpdateItem(GI, &GNoOfRecs); // n
// printf("Enter 731, \'y\' and then:\n"
// "       Name: Apple\n"
// "      Price: 1.80\n"
// "   Quantity: 101\n"
// "Minimum Qty: 11\n"
// "   Is Taxed: n\n"
// "Overwrite old data? (Y)es/(N)o: y\n");
// addOrUpdateItem(GI, &GNoOfRecs); // yes new data Yes
// printf("Updated Item: \n");
// dspItem(GI[16], FORM);
// printf("Enter 444: \n");
// addOrUpdateItem(GI, &GNoOfRecs); //n
//}
//
//void adjustQtyTest() {
// printf("================AdjustQty Test:\n");
// printf("Invalid SKU Test; Enter 444:\n");
// adjustQty(GI, GNoOfRecs, STOCK);
// printf("Aborting Entry test; Enter 731 and then 0:\n");
// adjustQty(GI, GNoOfRecs, CHECKOUT);
// printf("Checking out with low quantity warning; Enter 731 and then 90:\n");
// adjustQty(GI, GNoOfRecs, CHECKOUT);
// printf("Stocking; Enter 731 and then 50:\n");
// adjustQty(GI, GNoOfRecs, STOCK);
// dspItem(GI[16], FORM);
//}

/* End test functions
*********************************************************************/


/********************************************************************
Milestone 3 functions*/


void GrocInvSys(void) {   // prints initial grocery inventory system
	struct Item Items[MAX_ITEM_NO];
	int k = 0;
	int i = 0;
	int DONE = 0;
	int SEL;

	welcome();

	i = loadItems(Items, DATAFILE, &k);
	if (i == 0) {
		printf("Could not read from %s.\n", DATAFILE);
	}
	else if (i == 1) {


		//SEL = menu();
		while (DONE == 0) {
			SEL = menu();
			switch (SEL) {
			case 1:
				listItems(Items, k);
				//printf("List Items!\n");
				pause();
				break;
			case 2:
				search(Items, k);
				//printf("Search Items!\n");
				pause();
				break;
			case 3:
				adjustQty(Items, k, CHECKOUT);
				i = saveItems(Items, DATAFILE, k);
				if (i == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}
				//printf("Checkout Items!\n");
				pause();
				break;
			case 4:
				adjustQty(Items, k, STOCK);
				i = saveItems(Items, DATAFILE, k);
				if (i == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}
				//printf("Stock Item!\n");
				pause();
				break;
			case 5:
				addOrUpdateItem(Items, &k);
				i = saveItems(Items, DATAFILE, k);
				if (i == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}
				//printf("Add/Update Item!\n");
				pause();
				break;
			case 6:
				printf("Not implemented!\n");
				pause();
				/*printf("Delete Item!\n");
				pause();*/
				break;
			case 7:
				printf("Not implemented!\n");
				pause();
				/*printf("Search by name!\n");
				pause();*/
				break;
			case 0:
				printf("Exit the program? (Y)es/(N)o): ");
				DONE = yes();
				/*default :*/

			}
		}
	}
}

void search(const struct Item item[], int NoOfRecs) { // Function searches for the item using SKU and if SKU is found it requests the user whether it should be updated or not. 
	int sku;
	int foundIndex;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, NoOfRecs, sku, &foundIndex)) {
		dspItem(item[foundIndex], FORM);
	}
	else {
		printf("Item not found!\n");
	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs) { // Asks the user if they want to change the quantity based on SKU, depending if they want to add to stock or checkout.
	int sku;
	int foundIndex;
	//int abort = 0;
	//int isNew = 1;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, *NoOfRecs, sku, &foundIndex)) {
		dspItem(item[foundIndex], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes()) {
			updateItem(&item[foundIndex]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, sku);
	}
}

void updateItem(struct Item* itemptr) { // This function will add an item to the array of items.
	struct Item I;
	printf("Enter new data:\n");
	I = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes()) {
		*itemptr = I;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}

void addItem(struct Item item[], int *NoOfRecs, int sku) { // This function request the user to enter a SKU value, and attempts to find the the item in the array. If found, the item it updates the item. If not found, it asks the user if they want to add the item. 
	struct Item I;
	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		I = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		if (yes()) {
			item[*NoOfRecs] = I;
			(*NoOfRecs)++;
			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}


void adjustQty(struct Item item[], int NoOfRecs, int stock) { // Will increase/reduce the quantity of the selected item in the array by the value recieved from the user depending on STOCK OR CHECKOUT argument. 
	int sku;
	int foundIndex;
	int qty;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, NoOfRecs, sku, &foundIndex)) {
		dspItem(item[foundIndex], FORM);
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ",
			stock ? "to stock" : "to checkout"
			, stock ?
			MAX_QTY - item[foundIndex].quantity :
			item[foundIndex].quantity);
		qty = getIntLimited(0, stock ? MAX_QTY - item[foundIndex].quantity : item[foundIndex].quantity);
		if (qty) {
			if (stock)
				item[foundIndex].quantity += qty;
			else
				item[foundIndex].quantity -= qty;
			printf(stock ? "--== Stocked! ==--\n" : "--== Checked out! ==--\n");
			if (isLowQty(item[foundIndex])) {
				printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		printf("SKU not found in storage!\n");
	}
}



/*  ms3*/

double totalAfterTax(struct Item item) {  // Used to calculate the total price after tax based on the quanitity of specific items. 
	return item.price *(1 + item.isTaxed*TAX) * item.quantity;
}

int isLowQty(struct Item item) { // Function determines whether or not an item has less quantity then the specified minimum quantity.
	return item.quantity <= item.minQuantity;
}

struct Item itemEntry(int sku) {  // function recieves the SKU argument from user and returns the struct with the information pertaining to that SKU for that item.
	struct Item item;
	item.sku = sku;
	printf("        SKU: %d\n", item.sku);
	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	clrKyb();
	printf("      Price: ");
	item.price = getDblLimited(0.01, 10000.00);
	printf("   Quantity: ");
	item.quantity = getIntLimited(1, MAX_QTY);
	printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0, 100);
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	return item;
}

/*
SKU: 999
Name: Red Apples
Price: 4.54
Quantity: 50
Minimum Qty: 5
Is Taxed: n

SKU: 999
Name: Red Apples
Price: 4.54
Quantity: 50
Minimum Qty: 5
Is Taxed: No
WARNING: Quantity low, please order ASAP!!!


*/

void dspItem(struct Item item, int linear) { // Displays item info in linear format which is recieved by this function from main function. 
	if (linear == LINEAR) {
		printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|%s\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity,
			totalAfterTax(item), isLowQty(item) ? "***" : "");
	}
	else {
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		printf("   Is Taxed: %s\n", item.isTaxed ? "Yes" : "No");
		if (isLowQty(item)) printf("WARNING: Quantity low, please order ASAP!!!\n");
	}
}
/*
|999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|

SKU: 999
Name: Red Apples
Price: 4.54
Quantity: 50
Minimum qty: 5
Is Taxed: No

*/
void listItems(const struct Item item[], int NoOfItems) { // function lists item info in linear format and at the very end print the grand total price. 
	int i;
	double gTotal = 0;
	prnTitle();
	for (i = 0; i < NoOfItems; i++) {
		printf("%-4d", i + 1);
		dspItem(item[i], LINEAR);
		gTotal += totalAfterTax(item[i]);
	}
	prnFooter(gTotal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) { // This function attempts to locate a specific item via a SKU in the array which it recieves from another function. 
	
	int i = 0;
	int found = 0;
	while (!found && i < NoOfRecs) {
		if (item[i].sku == sku)
			found = 1;
		else
			i++;
	}
	if (found) *index = i;
	return found;
}


/*ipc ms1 and 2 functions: */

void welcome(void) { // Function prints the welcome title to the grocery inventory system.
	printf("---=== Grocery Inventory System ===---\n\n");
}
int menu(void) { //function prints menu options and and ensure valid int is entered.
	int i;
	//int k = 0;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	/*printf("6 - delete item\n");
	printf("7 - Search by name\n");*/
	printf("0- Exit program\n");
	printf("> ");
	do {
		scanf("%d", &i);
		clrKyb();

		if (i < 0 || i > 7) {
			printf("Invalid value, 0 < value < 7: ");
			/*i = getIntLimited(0, 7);*/
		}
	} while (i < 0 || i > 7);
	return i;
}
void prnTitle(void) { // prints the headings (columns)
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n"
		"----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void prnFooter(double gTotal) { // prints footer 
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal>0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
}
void clrKyb(void) { // prints footer 
	while (getchar() != '\n');
}
void pause(void) { // This functions calls the clearkyb() functions. It is a precursor to it.
	printf("Press <ENTER> to continue...");
	clrKyb();
}
int getInt(void) { // This function gets a valid user from the integer and will return it. Will print error message if the number entered not valid. 
	int val;
	char nl = 'x';
	while (nl != '\n') {
		scanf("%d%c", &val, &nl);
		if (nl != '\n') {
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	}
	return val;
}
double getDbl(void) { // Must recieve a double value , if it doesnt it prints an invalid number error message. 
	double val;
	char nl = 'x';
	while (nl != '\n') {
		scanf("%lf%c", &val, &nl);
		if (nl != '\n') {
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	}
	return val;
}

int getIntLimited(int lowerLimit, int upperLimit) { // Calls getint() only accepts a value between an upper and lower limit. 
	int val;
	do {
		val = getInt();
	} while ((val < lowerLimit || val > upperLimit) && printf("Invalid value, %d <= value <= %d: ", lowerLimit, upperLimit));
	return val;
}
double getDblLimited(double lowerLimit, double upperLimit) { // Must recieve a double value , if it doesnt it prints an invalid number error message. 
	double val;
	do {
		val = getDbl();
	} while ((val < lowerLimit || val > upperLimit) && printf("Invalid value, %lf <= value <= %lf: ", lowerLimit, upperLimit));
	return val;
}

int yes(void) { // function ensures user enters yes or no via y, Y, N, or n
	char ch = 'x';
	int res;
	do {
		ch = getchar();
		res = (ch == 'Y' || ch == 'y');
		clrKyb();
	} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N' && printf("Only (Y)es or (N)o are acceptable: "));
	return res;
}
