/* File :- Rational Number Calculator
Purpose :-The purpose of this code is to implement a rational number calculator. It allows the user to input fractions or integers along with an arithmetic operation (addition, subtraction, multiplication, or division) and calculates the result.
 The program ensures that the input format is correct and handles cases where denominators are zero.
 Additionally, the code includes functionality to simplify the resulting fraction by finding the greatest common divisor of the numerator and denominator. It also prompts the user to calculate again or exit after each calculation.
Author :-
         Author 1: Dareen Elsayed Ragab
         Author 2: Nayera Shaaban Rashad
         Author 3: Anan Hamdi Ali
Section :- S11,12
Emails :-

           1- dareenelsayed443@gmail.com
           2- nayerashaaban54@gmail.com
           3- ananhamdi2@gmail.com

IDs :-
           1- 20231052 she did validation input by regex , organized the output and make a funtion that find the greatest common divisor(gcd).
           2- 20231196 she did validation (from Denominator cannot be zero and if the user not enter number as fraction).  
           3- 20231117 she did the mathematical operations(addtion, subtration, multiplication and division) and while loop to calculate again.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <cstdlib> 

using namespace std;

bool regstr(string &input) {
    regex p(R"(\s*[\+\-]?\d+\s*(?:/\s*[\+\-]?\d+)?\s[-\\+\\*\\/]\s*[\+\-]?\d+\s*(?:/\s*[\+\-]?\d+)?)");
    
    if (regex_match(input, p)) 
        return true;
    else 
        return false;
}

int gcd(int a, int b ) {
    int g = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            g = i;
        }
    }
    return g;
}

int main() {
    long long a, b=1 , c, d=1 , e, f;
    char ch, operation;
    string user_input;
    cout << "*** Welcome to the fraction calculator ***\n\n";//welcome message 
    while (true) {
        while (true) {
            cout << "Enter the fractions and the operation separated by space (e.g., a/b + c/d):" << endl;
            getline(cin, user_input);// get the input in one line
            if (!regstr(user_input)) {// verify valid input by regex
                cout << "Input doesn't match the pattern." << '\n';// if the input not match, print the Input doesn't match the pattern.
                continue;
            } else { // if the input match the program will break the loop
                break;
            }
        }

        stringstream ss(user_input);// covert the input from string to intger 
        ss >> a >> ch >> b >> operation >> c >> ch >> d;
        // Initialize b and d to 1 if not provided by the user
       if (ss.fail()) {
            b = 1;
            ss.clear();
            ss.str(user_input); // Reset stringstream
            ss >> a >> operation >> c >> ch >> d;
        }

        // Set d to 1 if it's not provided
        if (ss.fail()) {
            d = 1;
            ss.clear();
            ss.str(user_input); // Reset stringstream
            ss >> a >> ch >> b >> operation >> c;
        }
        if (b == 0 || d == 0) {// if denominator in fration 1 and 2 equal 0 print Denominator cannot be zero. Please enter a non-zero number.
            cout << "Denominator cannot be zero. Please enter a non-zero number." << endl;
            continue;// get valid input again
        }
        
    
        

        e = d * b;
        if (operation == '+') {// make all process to this program (addtion, subtration, multiplication and division)
            f = (a * d) + (c * b);
        } else if (operation == '-') {
            f = (a * d) - (c * b);
        } else if (operation == '*') {
            f = a * c;
            e = b * d;
        } else if (operation == '/') {
            if (c == 0)
            {
                cout<< "invalid input, denominator cannot be zero !\n";
                continue;
            }
            else{
            f = a * d;
            e = b * c;

            }
        }

        int gcd_value = gcd(abs(f), abs(e)); // to find the greatest common divisor
        f /= gcd_value; // Simplify the numerator
        e /= gcd_value; // Simplify the denominator

        // output 
        if (f % e == 0) 
            cout << "The final answer = " << f / e << '\n';// simplify if the numerator divided by the denominator
        else 
            cout << "The final answer = " << f << "/" << e << '\n';
        

        while (true) {// make loop if the user wants to again or not
            cout << "Do you want to calculate again? (yes/no)" << endl;
            string choice;
            getline(cin, choice);

            if (choice == "yes" || choice == "Yes") {
                break;
            } else if (choice == "no" || choice == "No") {
                cout << "Thank you for using our fraction calculator!" << endl;
                exit(EXIT_SUCCESS);
            } else {
                cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
            }
        }
    }
}   
    

/*
            Algorithm of Task 3 (Rational Number Calculator)

1- welcome message 
2- get the input in one line
3- verify valid input by regex
4- if the input not match, print the Input doesn't match the pattern.
5- if the input match the program will break the loop.
6- covert the input from string to intger.
7- if denominator in fration 1 and 2 equal 0 print Denominator cannot be zero. Please enter a non-zero number.
8- get valid input again.
9- Set b to 1 if it's not provided.
10- Reset stringstream.
11- Set d to 1 if it's not provided.
12- Reset stringstream.
13- make all process to this program (addtion, subtration, multiplication and division).
14- find the greatest common divisor.
15- Simplify the numerator.
16- Simplify the denominator.
17- simplify if the numerator divided by the denominator.
18- make loop if the user wants to again or not.
19- print "Thank you for using our fraction calculator!" , if the user doesn't want to repeat.
20- verify valid input as a choice.


*/