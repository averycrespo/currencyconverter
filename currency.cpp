#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <stdbool.h>

using namespace std;

/**
 * Learning C++ syntax and such through a concurrency converter calculator
 * Rates are based at a constant time at approx. 14:45 02/22/2023
 * from https://www.oanda.com/currency-converter/en/
 * @author Avery Crespo (ajcresp2)
*/

/** Constants for currencies */
const string currencies[10]  = { "USD", "EUR", "JPY", "GBP", "AUD", "CAD", "CHF", "CNH", "HKD", "NZD" };

/** Constants for conversion rates are the same order as listed */
const float convRates[10][10] =  { 
    //USD 0
    {1, 0.942945, 134.684, 0.829972, 1.45382, 1.34924 , 1.07, 6.89, 7.84552, 1.60455}, 
    //EUR 1
    {1.06041, 1, 142.965, 0.88088, 1.55545, 1.43545, 0.98835, 8.31975, 1.70148},
    //JBP 2
    {0.00742, 0.00699, 1, 0.00616, 0.01088, 0.01004, 0.00691, 0.05121, 0.05819, 0.0119}, 
    //GBP 3
    {1.20366, 1.13499, 162.276, 1, 1.7654, 1.62936, 1.12187, 8.31112, 9.44331, 1.93133},
    //AUD 4
    {0.68166, 0.64279, 91.9018, 0.56622, 1, 0.92275, 0.6353, 4.70681, 5.348, 1.09387},
    //CAD 5
    {0.73862, 0.69644, 99.5743, 0.61353, 1.08333, 1, 0.68838, 5.10009, 5.79485, 1.18515}, 
    //CHF 6
    {1.07275, 1.01157, 144.632, 0.89114, 1.57339, 1.45215, 1, 7.4072, 8.41625, 1.72127},
    //CNH 7
    {0.1448, 0.13653, 19.52, 0.12027, 0.21237, 0.19601, 0.134951, 1, 1.13599, 0.23233},
    //HKD 8
    {0.12745, 0.12018, 17.182, 0.10587, 0.18693, 0.17253, 0.11878, 0.88005, 1, 0.2045},
    //NZD 9
    {0.62305, 0.58747, 83.9945, 0.51754, 0.91392, 0.84341, 0.58067, 4.30211, 4.88817, 1},
};


/**
 * Prints out message at start
*/
void startUp() {
    cout << "Welcome to a C++ basic currency calculator" << endl;
    cout << "Enter the number associated with the currency to convert from: " << endl;

    cout << "(0)   US dollar (USD)" << endl;
    cout << "(1)   Euro (EUR)" << endl;
    cout << "(2)   Japanese yen (JPY)" << endl;
    cout << "(3)   Pound sterlin (GBP)" << endl;
    cout << "(4)   Australian dollar (AUD)" << endl;
    cout << "(5)   Canadian dollar (CAD)" << endl;
    cout << "(6)   Swiss franc (CHF)" << endl;
    cout << "(7)   Chinese renminbi (CNH)" << endl;
    cout << "(8)   Hong Kong dollar (HKD)" << endl;
    cout << "(9)   New Zealand dollar (NZD)" << endl;
}

//Function that prints out options 
void printOptions ( void ) {
    cout << "What to convert to" << endl;
}

//String from user
string getCurrency( void ) {
    string location;
    cin >> location;
    return location;
}


//Error checking for user input 
bool checkUserInput( string word ) {
    //More than 1 characters
    if( word.length() != 1) {
        return false; 
    } else if( !isdigit(word[0])) {
        return false;
    }
    return true;
}

/**
 * Funtion responsible for converting given value to new value
 * @param init_amount
 * @param source currency  to convert from
 * @param destination currency to convert to
 * @return final_value translated value given in float format
*/
float conversion(float init_amount, int source, int destination) {
    float convert_to = convRates[source][destination];
    return init_amount * convert_to;
}

/**
 * Main function for converting
 * return 0 if successful
*/
int main( int argc, char *argv[] ) {
    //Start up prompt
    startUp();

    //Get string from user
    string currencyFrom = getCurrency();

    //Check to validate user input 
    bool checkInput = checkUserInput( currencyFrom );
    if(checkInput == false) {
        cout << "Invalid, Use a number 0-9" << endl;;
        while ( 1 == 1 ) {
            currencyFrom = getCurrency();
            checkInput = checkUserInput( currencyFrom );
            if( checkInput ) {
                break;
            }
            cout << "Invalid, Try Again" << endl;;
        }
    }
    char a = currencyFrom[0];
    int currency_select_one = a - '0';

    //Retrieve money from user
    cout << "How much money will you like to convert" << endl;

    //Store variable
    float init_amount = 0;
    float converted_amount = 0; 
    cin >> init_amount;

    //Print out options to convert to 
    printOptions();
    //Retrieve second currency
    string currencyTo = getCurrency();

    //Check to validate user input 
    bool checkOutput = checkUserInput( currencyTo );
    if(checkOutput == false) {
        cout << "Invalid, Try Again" << endl;;
        while ( 1 == 1 ) {
            currencyTo = getCurrency();
            checkOutput = checkUserInput( currencyTo );
            if( checkOutput ) {
                break;
            }
            cout << "Invalid, Try Again" << endl;
        }
    }

    //Case where the user inputs the same currency
    if( currencyFrom == currencyTo) {
        //Satisfy compiler 'unused variable' -- not needed 
        converted_amount = converted_amount;
        cout << currencyFrom << endl;
    }

    //Convert string to numeric representation within arrays
    char b = currencyTo[0];
    int currency_select_two = b - '0';

    //Convert the total
    converted_amount = conversion(init_amount, currency_select_one, currency_select_two);

    cout << "Converted value in " << currencies[ currency_select_two ] << ": " << converted_amount << endl << "Goodbye!" << endl;

    //Exit successfully
    return 0;
}