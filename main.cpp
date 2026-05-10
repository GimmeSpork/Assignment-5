/******************************************************************************
# Author:           Lucy Price
# Assignment:       Assignment 5 - Pizza Party Statistics Program
# Date:             April 30, 2026
# Description:      This program will take the amount of people, avg number of
#                   slices and cost of pizza from user, calculate the cost, tax,
#                   delivery cost, and total cost of as many times as the user
#                   wants. Then it will calculate the number of entries, total
#                   number of pizzas, average number of pizzas, maximum people,
#                   and maximum cost of pizzas. It will output all of these to
#                   the users.
# Input:            userChoice as char, numPeople as int, avgSlicesPerPerson and
#                   costPerPizza as doubles. 
# Output:           numPizzas, totalEntries, totalPizzas, maxPeople as ints, 
#                   maxTotalCost, costOfPizzas, tax, delivery, totalCost as
#                   doubles.
# Sources:          Assignement 5 resources, recorded zoom of class and
#                   zybooks, chapter 5.
#******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Main function
int main() {

//Declare variables
const int SLICES_PER_PIZZA = 8;
const double DECI_SALES_TAX = 0.07;
const double DECI_DELIVERY_CHARGE = 0.2;
int numPeople = 0;
int totalEntries = 0;
int totalPizzas = 0;
int maxPeople = 0;
int totalSlicesNeeded = 0;
int numPizzas = 0;
double maxTotalCost = 0.0;
double avgSlicesPerPerson = 0.0;
double costPerPizza = 0.0;
double costOfPizzas = 0.0;
double tax = 0.0;
double costIncludingTax = 0.0;
double delivery = 0;
double totalCost = 0;
char userChoice = '\0';
bool next = true;

cout << fixed << setprecision(2);
cout << "Welcome to the Pizza Party Statistics Program!" << endl;
cout << endl;

do {
  cout << "Do you want to enter more? (y/n): ";
  cin >> userChoice; 

    if (userChoice == 'y') {
      cout << "\nEnter the number of people, average number of slices per person, " 
      "and the cost of a pizza separated by a space: ";
      cin >> numPeople >> avgSlicesPerPerson >> costPerPizza;

      totalSlicesNeeded = numPeople * avgSlicesPerPerson;
      numPizzas = ceil(static_cast<float>(totalSlicesNeeded) / SLICES_PER_PIZZA);
      
      costOfPizzas = numPizzas * costPerPizza;
      tax = costOfPizzas * DECI_SALES_TAX;
      costIncludingTax = costOfPizzas + tax;
      delivery = costIncludingTax * DECI_DELIVERY_CHARGE;
      totalCost = costIncludingTax + delivery;

      cout << "\nNumber of pizzas: " << numPizzas << endl;
      cout << "Cost of pizzas: $" << costOfPizzas << endl;
      cout << "Tax: $" << tax << endl;
      cout << "Delivery: $" << delivery << endl;
      cout << "Total Cost: $" << totalCost << endl;
      cout << endl;
      totalEntries += 1;
      totalPizzas += numPizzas;

      if (numPeople > maxPeople) {
          maxPeople = numPeople;
      }
      if (totalCost > maxTotalCost) {
          maxTotalCost = totalCost;
      }
    } else {
      next = false;
    }
}while (next);

cout << endl;
cout << "Number of entries: " << totalEntries << endl;
cout << "Total number of pizzas: " << totalPizzas << endl;
cout << "Average number of pizzas: " << (totalEntries > 0 ? static_cast<float>(totalPizzas) / totalEntries : 0) << endl;
cout << "Maximum number of people: " << maxPeople << endl;
cout << "Maximum cost of pizzas: $" << maxTotalCost << endl;

cout << "\nThank you for using my program!" << endl;

  return 0;
}