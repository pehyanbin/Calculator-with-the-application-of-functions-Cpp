// This is a calculator program using the application of functions in C++ which acts like a normal calculator. 
// You can perform as many calculations as you want and you can also switch operation in the middle and it will show you the output everytime you perform a calculation. 
#include <iostream>
#include <cmath> 
#include <limits>
using namespace std;

double add(double num1, double num) {
    num1 += num;
    return num1;
}

double subtract(double num1, double num) {
    num1 -= num;
    return num1;
}

double multiply(double num1, double num) {
    num1 *= num;
    return num1;
}

double divide(double num1, double num) {
    num1 /= num;
    return num1;
}

double power(double num1, double num) {
    num1 = pow(num1, num);
    return num1; 
}

double square_root(double num1) {
    num1 = sqrt(num1); // pow(num1, 0.5) ; 0.5 is a constant. 
    return num1; 
}

double cube_root(double num1) {
    num1 = cbrt(num1); // pow(num1, 1.0/3.0) ; 1.0/3.0 is a constant, which is 0.33333333.
    return num1; 
}

void start_operation(string &new_operation) {
    cout << "New operation ? Type Y/y for yes and N/n for no. " << endl; 
    cin >> new_operation; 
}

void endprogramui() {
    cout << "==========================================================" << endl; 
    cout << "                     END OF PROGRAM.                      " << endl; 
    cout << "==========================================================" << endl; 
}

int main() {
    string start = "Y";

    // start_operation(start);

    while (start == "Y" || start == "y") {
        double num1;
        cout << "Num : " << endl;
        cin >> num1;

        if (cin.fail()) {
            cout << "Try again with a normal number. ( Relaunch the software again )" << endl;
        }
        else {

            while (true) {
                cout << "Operation : " << "\n" << "================================" << "\n" << "[1] +\n[2] -\n[3] *\n[4] /\n[5] power\n[6] square root\n[7] cube root\n"
                    << "[0] break\n\n";
                int operation;
                if (cin >> operation && cin.peek() == '\n') {
                    cout << endl;
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. \n\n" << endl;
                    continue;
                }

                if (operation == 0) {
                    break;
                }

                double num;

                if (operation == 6 || operation == 7) { 
                    cout << endl; // num value in operation 6 and 7 is a constant. (0.5 and 0.333 respectively) 
                }
                else {
                    cout << "Next num : " << endl;
                    if (cin >> num && cin.peek() == '\n') {
                        cout << endl;
                    }
                    else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a normal number again. \n" << endl;
                        continue;
                    }
                }

                switch (operation) {
                case 1:
                    num1 = add(num1, num);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 2:
                    num1 = subtract(num1, num);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 3:
                    num1 = multiply(num1, num);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 4:
                    num1 = divide(num1, num);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 5:
                    num1 = power(num1, num);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 6:
                    num1 = square_root(num1);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                case 7:
                    num1 = cube_root(num1);
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                default:
                    cout << "Invalid operation" << endl;
                    cout << "\nOutput : " << num1 << "\n" << endl;
                    break;
                }

            }
            cout << "\n\nOutput : " << num1 << "\n" << endl;
            cout << "\nEnd operation \n\n\n" << endl;

        }

        start_operation(start);

    }

    endprogramui();


    return 0;
}