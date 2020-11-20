/*
Jared Weiss
CSCI 112 Lab 2
Completed August 28, 2020
*/ 

#include <stdio.h> // for I/O

// Constants
#define MILITARY_DISC 0.10
#define MILITARY_DISC_150 0.15
#define SALES_TAX 0.05 

// Function Declarations
double compute_discount(double charge); // calculates discount
int print_results(char is_military, double charge); // prints out results based on user input

// Main Function
int main(void) {
	// Variables
	double cost;
	char military; 

	// Input
	printf("Cost of purchase:\t\t$"); 
	scanf("%lf", &cost); // get the cost
	printf("In military (y or n)?\t\t"); 
	scanf(" %c", &military); // get military status
	return print_results(military, cost); // send that data to print_results
}

// Function to compute the discount
double compute_discount(double charge) {
	if ( charge > 150) {
		return MILITARY_DISC_150*charge; // if the cost is over $150, 15% discount
	}
	else {
		return MILITARY_DISC*charge; // otherwise 10% discount 
	}
}

// Function to print results to the console
int  print_results(char is_military, double charge) {
	if ( is_military == 'y' || is_military == 'Y') { // if they are in the military
		double discount = compute_discount(charge); // calculate their discount 
		int disc_percent; 
		if ( charge > 150 ) // for printing later
			disc_percent = 15;
		else
			disc_percent = 10;
		printf("Military discount (%d%%)\t\t$%.2lf\n", disc_percent, discount); 
		double discounted_total = charge-discount; // calculate discounted total
		printf("Discounted total\t\t$%.2lf\n", discounted_total); 
		double tax = discounted_total*SALES_TAX; // calculate sales tax
		printf("Sales tax (5%%)\t\t\t$%.2lf\n", tax);
		double total = discounted_total+tax; // calculate total
		printf("Total\t\t\t\t$%.2lf\n", total); 
		return 0; // all is good, return 0
	}
	else if ( is_military == 'n' || is_military == 'N' ) { // if they are not in the military
		double tax = charge*SALES_TAX; // calculate sales tax 
		printf("Sales tax (5%%)\t\t\t$%.2lf\n", tax);
		double total = charge + tax; // calculate the total 
		printf("Total\t\t\t\t$%.2lf\n", total);
		return 0; // all is good, return 0
	}
	else {
		printf("Error : please enter a valid character \n\tExample: \'y\' or \'n\'\n");
		return 1; // return an error code
	}
}
