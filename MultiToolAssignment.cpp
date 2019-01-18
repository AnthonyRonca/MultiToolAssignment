/* Anthony Ronca
 * CIT133 12:30
 * HW7_chap6 due 11/1
 *
 *	3 hours
 *
 *	VARIABLES USED:
 *	choice  -   sentinel value which accesses a function or exits loop
 *	first   -   used in switch 2 to calulate
 *	second  -   used in switch 2 to calulate
 *	third   -   used in switch 2 to calulate
 *
 *
 *
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std; //cin,cout

void displayMenu(); // Displays user interface
void pattern(); // creates desired pattern
int calculate(int a, int b, int c); // multiplies user input by increments
double average();   // Averages test scores
// Calculates consulting charges
double consultingCosts(double income, double consultingTime,
                       double regRate, double retRate);
void five(); // Getter method for consultingCosts

int main() {

    int choice; // sentinel value for DisplayMenu / switches
    int first;  //  holds int
    int second; // holds int
    int third;  // holds int

    // Display options
    displayMenu();
    // Get menu choice
    cin >> choice;

    // Sentinel loop while user does not exit
    while (choice != 0) {

        switch (choice){

            case 1:
                pattern();
                break;

            case 2:
                // GET VALUES
                cout << " Enter first value: ";
                cin >> first;

                cout << " Enter second value: ";
                cin >> second;

                cout << " Enter third value: ";
                cin >> third;

                // place input into parameters
                calculate(first, second, third);
                break;

            case 3:
                // average test scores
                average();
                break;

            case 4:
                // run function five for consulting costs
                five();
                break;

        } // end switch

        displayMenu();
        cin >> choice;
    }

    return 0;

}

void displayMenu(){

    // DISPLAY MENU
    cout << "\n";
    cout << "	0	-	EXIT " << endl;
    cout << "	1	-	Create Pattern " << endl;
    cout << "	2	-	Calculate Algorithm" << endl;
    cout << "	3	-	Average Test Sccores " << endl;
    cout << "	4	-	Calculate Consulting Charges " << endl;
    cout << "_____________________________________________" << endl;
    cout << "\n";
    cout << "Enter a choice: ";

}

void pattern(){

    // GET rows
    int rows;

    cout << "How many rows?: ";
    cin >> rows;
    cout << endl;

    // prep nested for loop
    int j = rows;

    // Validate input data
    if (( rows > 10 ) || ( rows < 0 )){

        cout << "ERROR - MUST BE INTEGER BETWEEN 1 - 10";

    } else {

        //Nested for loop
        //loops for rows
        for(int i = 0; i <= rows; i++){

            // loops for numbers inside rows
            for(int i = j; i > 0; i--){
                cout << i << " ";
            }

            // decrement each row
            j--;
            cout << endl;
        }
    } // else

} // pattern()

int calculate(int a, int b, int c){

    int product = 1;

    if ( a > b ){

        cout << "ERROR - First value must be less than second.";

        product = -999;
        cout << product;

    } else {

        for( int i = a; i <= b; (i += c)){

            product *= i;

        }

        cout << product;

    }

    return 0;
} // calculate()

double average() {

    // initialize variables
    int num;
    int count = 1;
    double score;
    double total = 0;
    double average;

    //get num
    cout << " Amount of tests to average: ";
    cin >> num;

    // validate user input
    if ((num < 0 )){

        cout << "Error - Return -1";
        num = -1;
        return num;

        // loop for each test
    } else {
        for (int i = 0; i < num; i++) {

            cout << "Test score " << count << ":  ";
            cin >> score;

            //increment count and sum of total
            total += score;
            count++;
        }

        //calculate based on increment of count and sum of total
        average = total / num;
        cout << "\n" << average;

        return average;

    } // else
} // average


void five(){

    // initialize static variable that are called in another class
    static double income;
    static double consultingTime;
    static double regRate;
    static double retRate = 0;
    static char client;

    //get income
    cout << "Enter income: $";
    cin >> income;

    //get consultingTime
    cout << "Enter consulting minutes: ";
    cin >> consultingTime;

    // get regRate
    cout << "Enter regular rate: $";
    cin >> regRate;

    //get client
    cout << "Are you a returning client?( y or n ): ";
    cin >> client;

    // if return client alter rate to return rate
    if ( client == 'y' || client == 'Y'){

        cout << "Enter return rate: $";
        cin >> retRate;

    }

    consultingCosts(income, consultingTime, regRate, retRate);

}

double consultingCosts(double income, double consultingTime,
        double regRate, double retRate){

    double charges;

    //determing if client is lower/upper income threshold
    if ( income <= 25000 ){

        //if under 3- then there are no charges.
        if ( consultingTime > 30 ){

            // if return client then alter rate
            if ( retRate != 0)
                regRate = retRate;

            //calcaulate charges based on rate and time
            consultingTime = (consultingTime - 30)/60 ;
            charges = (regRate *.40) * consultingTime;

            //Display
            cout << "Charges: $" << charges << endl;
            return charges;

        } else {

            //no charges under 30 mins
            charges = 0;
            cout << "\n" << "No charges." << endl;
            return charges;

        } // else


    } else {

        // if upper threshold
        if ( consultingTime > 20 ){

            // if return client alter regRate to return rate
            if ( retRate != 0)
                regRate = retRate;

            //calculate amount of hours
            consultingTime = (consultingTime - 30)/60 ;
            // calculate charges by hours * rate
            charges = (regRate *.70) * consultingTime;

            // Display
            cout << "Charges: $" << charges << endl;
            return charges;

        } else {

            // no charges under 20 minutes
            charges = 0;
            cout << "No charges." << endl;
            return charges;

        } // else

    }

}



