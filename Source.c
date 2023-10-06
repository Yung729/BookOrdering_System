#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable:4996)

//define constant value
#define RATE1 0.05	//discout for purchase above 500
#define RATE2 0.10	//discout for purchase above 300
#define RATE3 0.15	//discout for purchase above 200
#define BOOK_A "A: Beginning with Programming Logic and Design"
#define BOOK_B "B: JavaScript: The Definitive Guide"
#define BOOK_C "C: Fullstack Vue: The Complete Guide to Vue.js"
#define BOOK_D "D: Web Design With HTML, CSS, JavaScript and jQuery Set"
#define BOOK_E "E: Clean Code"
#define BOOK_F "F: The DevOps Handbook"
#define BOOK_G "G: Beginning C++ Through Game Programming"
#define BOOK_H "H: Game Programming Patterns"
#define BOOK_I "I: Game Engine Architecture"
#define USERNAME "admin"	//username for login function
#define PASSWORD "1234"		//password for login function

const float priceBook[9] = { 69.00,70.00,55.50,58.00,65.00,89.00,73.50,80.00,50.00 };


//design code
void purple() {
	printf("\033[1;35m");
}
void yellow() {
	printf("\033[0;33m");
}
void green() {
	printf("\033[0;32m");
}
void red() {
	printf("\033[0;31m");
};
void blue() {
	printf("\033[0;34m");
}
void defaultcolor() {
	printf("\033[0m");
};
void delay(float number_of_seconds) {
	float milli_seconds = 1000 * number_of_seconds;

	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds);
}
void screen() {
	red();
	printf("\t\t\t\t\t%s\n", "                      _");
	delay(0.2);

	yellow();
	printf("\t\t\t\t\t%s\n", "      _   _ _ __ ___ | |_");
	delay(0.2);

	blue();
	printf("\t\t\t\t\t%s\n", "     | | | | '_ ` _ \\| __|");
	delay(0.2);

	green();
	printf("\t\t\t\t\t%s\n", "     | |_| | | | | | | |_");
	delay(0.2);

	purple();
	printf("\t\t\t\t\t%s\n", "      \\__,_|_| |_| |_|\\__|");
	delay(0.2);
	defaultcolor();
}


//declare function
void logo();
void heading();
void sales();
void menu();
void bookmenu();
char startOrder();
void errorMesage();
void orderList();
void storeSummaryData(int qty[], float totalBookPrice[], float* subtotal, float* finalTotal, float* discount, int* totalQuantity, int mode);
int storeOrderNo(int mode);
void receipt();
void orderReceipt(float subTotal, float discount, float finalTotal);
int bookField(char book1[], char book2[], char book3[], float price1, float price2, float price3);
void offer(float subtotal, float* finalTotal, float* discount);
int login();
void zero(int qty[], float totalBookPrice[], float* subtotal, float* finalTotal, float* discount);
char comfirmOrder();

//validation function
char getBookChoice();
char nextChoice(char message[]);
int getQty();




void main()
{
	screen();
	menu();
}

void menu() {
	int choice, exit;


	exit = login();   //to get id from user to loin the program if wrong 3 time will end program
	if (exit < 3) {
		do
		{
			choice = 0;
			system("cls");
			heading();
			printf("\n%16s %43s %36s", "|", "1.Views Menu", "|");
			printf("\n%16s %80s\n", "|", "|");
			printf("%16s %44s %35s", "|", "2.Sales Order", "|");
			printf("\n%16s %80s\n", "|", "|");
			printf("%16s %47s %32s", "|", "3.Summary report", "|");
			printf("\n%16s %80s\n", "|", "|");
			printf("%16s %37s %42s", "|", "4.Exit", "|");
			printf("\n%16s %80s\n", "|", "|");
			printf("%16s================================================================================\n", "");
			printf("\n\t\t\t\t\t\tEnter your Choice >");

			rewind(stdin);

			scanf("%d", &choice);

			switch (choice) {
			case 1:
				bookmenu();  //view menu
				break;
			case 2:
				sales();	//order
				break;
			case 3:
				receipt(); //receipt
				break;
			case 4:
				break;		//exit
			default:
				errorMesage();		//error message
			}
		} while (choice != 4);
	}
	else {
		printf("\n\n\n\n\n\n\n%84s\n\n\n\n\n", "Invalid Id or password 3 times and will closing system ");
		system("pause");
	}
}

void heading()
{
	time_t date = time(NULL);
	struct tm tm = *localtime(&date);

	logo();
	printf("\t\t\tDate : %d-%2d-%2d                            Time : %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("%16s================================================================================\n", "");
	printf("%16s %51s %28s\n", "|", "UMT BOOKSTORE POS SYSTEM", "|");
	printf("%16s================================================================================|", "|");
}

void logo() {
	printf("\t\t\t\t\t%s\n", "                      _");
	printf("\t\t\t\t\t%s\n", "      _   _ _ __ ___ | |_");
	printf("\t\t\t\t\t%s\n", "     | | | | '_ ` _ \\| __|");
	printf("\t\t\t\t\t%s\n", "     | |_| | | | | | | |_");
	printf("\t\t\t\t\t%s\n", "      \\__,_|_| |_| |_|\\__|");
}

//View List
void bookmenu() {
	int choice, exit;

	do
	{
		choice = 0;
		exit = 0;
		system("cls");
		heading();
		printf("\n%16s %50s %29s\n", "|", "Select A Field To View", "|");
		printf("%16s %80s", "|", "|");
		printf("\n%16s %41s %38s\n", "|", "1:Software Development Programming", "|");
		printf("%16s %24s %55s\n", "|", "2:Web Programming", "|");
		printf("%16s %37s %42s\n", "|", "3:Game Development Programming", "|");
		printf("%16s %80s\n", "|", "|");
		printf("%16s %26s %53s\n", "|", "4.Back To Main Menu", "|");
		printf("%16s %80s\n", "|", "|");
		printf("%16s================================================================================\n", "");

		//book field choice validation
		do
		{

			printf("\t\t\t%s", "Enter Your Choice     > ");
			rewind(stdin);

			scanf("%d", &choice);

			if (choice <= 0 || choice > 4)
			{
				printf("\n%25s==============", "");
				printf("\n%24s %s", "", "Invalid Input!");
				printf("\n%25s==============\n", "");
			}
		} while (choice <= 0 || choice > 4);

		switch (choice)
		{
		case 1:
			exit = bookField(BOOK_A, BOOK_B, BOOK_C, priceBook[0], priceBook[1], priceBook[2]);	//bookfield 1
			break;

		case 2:
			exit = bookField(BOOK_D, BOOK_E, BOOK_F, priceBook[3], priceBook[4], priceBook[5]);	//bookfield 2
			break;

		case 3:
			exit = bookField(BOOK_G, BOOK_H, BOOK_I, priceBook[6], priceBook[7], priceBook[8]);	//bookfield 3
			break;
		case 4:
			exit = 1;
			break;
		default:
			errorMesage();
		}
	} while (exit != 1);
}

int bookField(char book1[], char book2[], char book3[], float price1, float price2, float price3) {
	int choice, exit;

	do
	{
		exit = 0;
		system("cls");
		heading();
		printf("\n%15s|%80s|\n", "", "");
		printf("%14s |%22s %-57s|\n", "", "", "Software Development Programming");
		printf("%14s |================================================================================|\n", "");
		printf("%14s |%20s %-21s %20s %-16s|\n", "", "", "Book", "", "Price");
		printf("%14s |%-63s %-16.2f|\n", "", book1, price1);
		printf("%14s |%-63s %-16.2f|\n", "", book2, price2);
		printf("%14s |%-63s %-16.2f|\n", "", book3, price3);
		printf("%15s|%80s|\n", "", "");
		printf("%14s |================================================================================|\n", "");

		printf("%14s |%5s %-19s %10s %-12s %10s %-7s %11s|\n", "", "", "1.Back to Main Menu", "", "2.View Other", "", "3.Order", "");
		printf("%14s |================================================================================|\n", "");
		printf("\n\t\t\tEnter your choice > ");

		rewind(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			return 1;		//return 1 to bookmenu function for exit the bookmenu function
			break;
		case 2:
			return 0;		//return 0 to bookmenu function for loop again the bookmenu function
			break;
		case 3:
			sales();		//to the order function and after completed back to main menu
			return 1;
			break;
		default:
			exit = 1;
			errorMesage();
		}
	} while (exit == 1);
}

void sales() {

	char bookChoice, choice, start, comfirm, exit = 'A'; //set to any value to avoid can't execute when choose no in start order
	int qty, quantity[9], totalquantity;
	float totalBookPrice[9], subtotal, finalTotal, discount;

	do {

		system("cls");
		zero(quantity, totalBookPrice, &subtotal, &finalTotal, &discount); //initialize total value to 0 when loop back 		
		heading();
		storeOrderNo(1); //increase order number
		orderList();


		start = startOrder(); //start order or exit to main menu

		//if true start order
		if (start == 'Y') {

			do {
				bookChoice = getBookChoice(); //ask user which book want to purchase

				qty = getQty();	//ask user how many book want to purchase

				for (int i = 0; i < 9; i++)
				{
					if (toupper(bookChoice) == (char)i + 65) {
						quantity[i] += qty;
						break;
					}
				}
				choice = nextChoice("Any more book ? (Y= Yes / N= No) > ");

			} while (toupper(choice) != 'N');


			comfirm = comfirmOrder();

			//go to next page after comfirm order
			if (toupper(comfirm) == 'Y')
			{
				system("cls");
				heading();

				//calculate total per receipt and output order invoice
				for (int i = 0; i < 9; i++)
				{
					totalBookPrice[i] = quantity[i] * priceBook[i];
					subtotal += totalBookPrice[i];
					if (quantity[i] != 0)
					{
						printf("\n%16s %19s %c: %6d @ RM%6.2f \t=%25.2f\t|\n", "|", "Book", 65 + i, quantity[i], priceBook[i], totalBookPrice[i]);
						printf("%16s %80s", "|", "|");
					}
				}


				offer(subtotal, &finalTotal, &discount); //count discount and output the total value per order

				orderReceipt(subtotal, discount, finalTotal);//display part total of order receipt 

				storeSummaryData(quantity, totalBookPrice, &subtotal, &finalTotal, &discount, &totalquantity, 1); //store data to store function


				exit = nextChoice("Next Order? (Y/N) >");//start next order
			}
			else if (toupper(comfirm) == 'N')
				storeOrderNo(2);

		}
		else
			break; //Exit sales function

		if (toupper(exit) == 'N')
			receipt(); //display summary receipt after exit order


	} while (toupper(exit) == 'Y');


}

void zero(int quantity[], float totalBookPrice[], float* subtotal, float* finalTotal, float* discount) {
	*discount = 0.0;
	*subtotal = 0.0;
	*finalTotal = 0.0;
	for (int i = 0; i < 9; i++)
	{
		quantity[i] = 0;
		totalBookPrice[i] = 0.0;
	}
}

char getBookChoice() {
	char choice;
	do
	{
		printf("\t\t\t%s", "Enter Your Choice (A-I)  > ");
		rewind(stdin);
		scanf("%c", &choice);


		if (!(toupper(choice) >= 65 && toupper(choice) <= 73))
		{
			printf("\n%25s==============", "");
			printf("\n%24s %s", "", "Invalid Input");
			printf("\n%25s==============\n", "");
		}
	} while (!(toupper(choice) >= 65 && toupper(choice) <= 73));
	return choice;
}

char nextChoice(char message[]) {
	char choice;
	do
	{
		printf("\t\t\t%s", message);
		rewind(stdin);
		scanf("%c", &choice);

		if (toupper(choice) != 'Y' && toupper(choice) != 'N')
		{
			printf("\n%25s==============", "");
			printf("\n%24s %s", "", "Invalid Input");
			printf("\n%25s==============\n", "");
		}
	} while (toupper(choice) != 'Y' && toupper(choice) != 'N');
	return choice;
}

int getQty() {
	int qty;

	do
	{
		printf("\n\t\t\tEnter Quantity     > ");

		rewind(stdin);
		scanf("%d", &qty);

		if (qty <= 0)
		{
			printf("\n%25s==============", "");
			printf("\n%24s %s", "", "Invalid Input");
			printf("\n%25s==============\n", "");
		}

	} while (qty <= 0);
	return qty;

}

void orderList() {

	printf("\n%16s Sales Order No : %d %61s\n", "|", storeOrderNo(3), "|");

	printf("%16s================================================================================|\n", "|");
	printf("%16s %57s %22s\n", "|", "Software Development Programming", "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %53s %20.2f %5s\n", "|", BOOK_A, priceBook[0], "|");
	printf("%16s %42s %31.2f %5s\n", "|", BOOK_B, priceBook[1], "|");
	printf("%16s %53s %20.2f %5s\n", "|", BOOK_C, priceBook[2], "|");
	printf("%16s %80s\n", "|", "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %47s %32s\n", "|", "Web Programming", "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %62s %11.2f %5s\n", "|", BOOK_D, priceBook[3], "|");
	printf("%16s %20s %53.2f %5s\n", "|", BOOK_E, priceBook[4], "|");
	printf("%16s %29s %44.2f %5s\n", "|", BOOK_F, priceBook[5], "|");
	printf("%16s %80s\n", "|", "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %54s %25s\n", "|", "Game Development Programming", "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %48s %25.2f %5s\n", "|", BOOK_G, priceBook[6], "|");
	printf("%16s %35s %38.2f %5s\n", "|", BOOK_H, priceBook[7], "|");
	printf("%16s %34s %39.2f %5s\n", "|", BOOK_I, priceBook[8], "|");
	printf("%16s %80s\n", "|", "|");
	printf("%16s================================================================================\n", "");
}


void storeSummaryData(int qty[], float totalBookPrice[], float* subtotal, float* finalTotal, float* discount, int* totalQuantity, int mode) {

	static float summarySubtotal = 0.0, summaryFinalTotal = 0.0, summaryTotalDiscount = 0.0, summaryTtlPriceBook[9] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	static int summartQtyBook[9] = { 0,0,0,0,0,0,0,0,0 }, summaryTotalQuantity = 0;

	//mode 1 store value 
	//mode 2 get value
	if (mode == 1)
	{
		summarySubtotal += *subtotal;
		summaryFinalTotal += *finalTotal;
		summaryTotalDiscount += *discount;
		for (int i = 0; i < 9; i++)
		{
			summartQtyBook[i] += qty[i];
			summaryTtlPriceBook[i] += totalBookPrice[i];
			summaryTotalQuantity += qty[i];
		}

	}
	else
	{
		*subtotal = summarySubtotal;
		*finalTotal = summaryFinalTotal;
		*discount = summaryTotalDiscount;
		*totalQuantity = summaryTotalQuantity;
		for (int i = 0; i < 9; i++)
		{
			qty[i] = summartQtyBook[i];
			totalBookPrice[i] = summaryTtlPriceBook[i];
		}

	}


}

int storeOrderNo(int mode) {
	static int summaryOrderNo = 0;

	if (mode == 1) {
		summaryOrderNo++;	//mode 1 add order number
	}
	else if (mode == 2) {
		summaryOrderNo--;	//mode 2 deduct order number
	}
	else
	{
		return summaryOrderNo;	//mode 3 get order number from static value
	}
}

//summary report
void receipt()
{
	float summarySubtotal, summaryFinalTotal, summaryTotalDiscount, summaryTtlPriceBook[9];
	int summartQtyBook[9], summaryTotalQuantity;

	storeSummaryData(summartQtyBook, summaryTtlPriceBook, &summarySubtotal, &summaryFinalTotal, &summaryTotalDiscount, &summaryTotalQuantity, 2); //get data from store function
	system("cls");
	heading();
	printf("\n%16s %45s %34s", "|", "SUMMARY REPORT", "|");
	printf("\n%16s================================================================================|", "|");
	printf("\n%16s Order number = %d %63s\n", "|", storeOrderNo(3), "|");
	printf("%16s================================================================================|\n", "|");
	printf("%16s %10s %24s %20s %14s %8s\n", "|", "Book", "Quantity of books", "Price per book", "Total", "|");
	for (int i = 0; i < 9; i++)
	{
		printf("%16s %8c %19d %22.2f %19.2f %8s\n", "|", 65 + i, summartQtyBook[i], priceBook[i], summaryTtlPriceBook[i], "|");
	}
	printf("%16s================================================================================|\n", "|");
	printf("%16sTotal Sales %17d %42.2f %8s\n", "|", summaryTotalQuantity, summarySubtotal, "|");
	printf("%16sTotal Discount %57.2f %8s\n", "|", summaryTotalDiscount, "|");
	printf("%16s %64s %s %8s\n", "|", "", "======", "|");
	printf("%16sTotal Net Sales %56.2f %8s\n", "|", summaryFinalTotal, "|");
	printf("%16s %64s %s %8s\n", "|", "", "======", "|");
	printf("%16s================================================================================\n", "");
	printf("\n%40sTHANK YOU FOR YOUR ORDER! ^~^\n", "");

	system("pause");
}

void orderReceipt(float subtotal, float discount, float finalTotal) {
	printf("\n%16s %73s %6s\n", "|", "===============", "|");
	printf("%16s %14s Subtotal %23s=%25.2f %6s\n", "|", "", "", subtotal, "|");
	printf("%16s %14s Discount %23s=%25.2f %6s\n", "|", "", "", discount, "|");
	printf("%16s %73s %6s\n", "|", "===============", "|");
	printf("%16s %14s FinalTotal %21s=%25.2f %6s\n", "|", "", "", finalTotal, "|");
	printf("%16s================================================================================|", "|");
	printf("\n%16s %50s %29s\n", "|", "Thank you have a nice day", "|");
	printf("%16s================================================================================\n\n", "");
}

char startOrder() {
	char choice;

	do {

		printf("\t\t\tStart order? (Y=yes / N=no) >");
		rewind(stdin);
		scanf("%c", &choice);

		switch (toupper(choice))
		{
		case 'Y':
			return 'Y';
		case 'N':
			storeOrderNo(2);
			return 'N';
		default:
			printf("%24s=============\n", "");
			printf("%24sInvalid Input\n", "");
			printf("%24s=============\n", "");
		}
	} while (toupper(choice) != 'Y' && toupper(choice) != 'N');

}

void offer(float subtotal, float* finalTotal, float* discount) {

	//discount calculation
	if (subtotal > 500.00) {
		*finalTotal = subtotal - subtotal * RATE3;
		*discount = subtotal * RATE3;
	}
	else if (subtotal > 300.00)
	{
		*finalTotal = subtotal - subtotal * RATE2;
		*discount = subtotal * RATE2;
	}
	else if (subtotal > 200.00)
	{
		*finalTotal = subtotal - subtotal * RATE1;
		*discount = subtotal * RATE1;
	}
	else
	{
		*finalTotal = subtotal;
		*discount = 0.0;
	}
}

int login() {
	char username[30] = "", password[30] = "", pass;
	int login = 0, fail = 0;
	//username = "admin" 
	//password = "1234"
	do {
		system("cls");
		logo();
		printf("\n\n%50s Login Page\n\n", "");
		printf("%40s %-12s", "", "Username : ");
		gets(username);		//read username from users
		printf("\n\n");
		printf("%40s %-11s", "", "Password (4 digits only) :");

		for (int i = 0; i < 4; i++)
		{
			pass = getch();					//read password from users and display it in *
			password[i] = pass;
			pass = '*';
			printf("%c", pass);
		}


		printf("\n\n");

		//sting compare between user's input and value fixed
		if (strcmp(username, USERNAME) == 0)
		{
			if (strcmp(password, PASSWORD) == 0)
			{
				printf("%40s %-14s\n", "", "Login success");
				login = 0;
			}
			else {
				printf("%40s %-15s\n", "", "Wrong password");
				login = 1;
				fail++;
			}
		}
		else
		{
			printf("%40s %-16s\n", "", "Wrong user name");
			login = 1;
			fail++;
		}


		if (fail > 0)
		{
			printf("\n%50s %d chance left", "", 3 - fail);
		}

		delay(0.8);


	} while (login != 0 && fail < 3);

	return fail;
}

char comfirmOrder() {
	char choice;
	do
	{
		printf("\n\t\t\tComfirm order? (Y=comfirm N=Cancel) >");
		rewind(stdin);
		scanf("%c", &choice);

		if (toupper(choice) != 'Y' && toupper(choice) != 'N')
		{

			printf("\n%25s==============", "");
			printf("\n%24s %s", "", "Invalid Input");
			printf("\n%25s==============\n", "");
		}
	} while (toupper(choice) != 'Y' && toupper(choice) != 'N');

	return choice;
}

void errorMesage() {
	system("cls");
	printf("\n\n\n\n\n\n%40s==============================================", "");
	printf("\n\n%40sInvalid Input Press any key to go back.......\n\n", "");
	printf("%40s==============================================\n", "");
	system("pause");
}

