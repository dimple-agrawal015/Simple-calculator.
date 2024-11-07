#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;

// Function to display the calculator interface
void show_calculator(){
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"----                                                 ----"<<endl;
    cout<<"-                   SCIENTIFIC                          -"<<endl;
    cout<<"-                   CALCULATOR                          -"<<endl;
    cout<<"----                                                 ----"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-     +          |         -       |       *            -"<<endl;
    cout<<"-    Add         |     Subtract    |    Multiply        -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      /         |        m        |       L            -"<<endl;
    cout<<"-    Divide      |       Mode      |      Log           -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      S          |       C        |        P           -"<<endl;
    cout<<"-    Square       |      Cube      |      Power         -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      s          |      c         |      t             -"<<endl;
    cout<<"-     Sin         |     Cos        |     Tan            -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      r          |      k         |       .            -"<<endl;
    cout<<"-   sq root       |     Clear      |      Close         -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
}

// Function to display the current output
void display_output(double answer){
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-        Current                |        "<<endl;
    cout<<"-        Output is              |    "<<answer<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-     +          |         -       |       *            -"<<endl;
    cout<<"-    Add         |     Subtract    |    Multiply        -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      /         |        m        |       L            -"<<endl;
    cout<<"-    Divide      |       Mode      |      Log           -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      S          |       C        |        P           -"<<endl;
    cout<<"-    Square       |      Cube      |      Power         -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      s          |      c         |      t             -"<<endl;
    cout<<"-     Sin         |     Cos        |     Tan            -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"-      r          |      k         |       .            -"<<endl;
    cout<<"-   sq root       |     Clear      |      Close         -"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
}

int main(){
    double num1 = 0.0;
    double num2 = 0.0;
    double answer = 0.0;
    char inp = '\n';
    bool converter = 0;

    while(inp != '.'){
        if(converter == 1) {
            // If previous output is displayed, allow input for further operations
            display_output(answer);
            cout<<"Enter operation: ";
            cin>>inp;

            if(inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p'){
                num1 = answer;
                cout<<"Enter number 2: ";
                cin>> num2;
            }
            else if(inp == 'k' || inp == '.'){
                // Clear or close operation
            }
            else{
                num1 = answer;  // Use the previous answer for single input operations
            }
        } else {
            // If no output is displayed, start from the main calculator screen
            show_calculator();
            cout<<"Enter operation: ";
            cin>>inp;

            if(inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p'){
                cout<<"Enter number 1: ";
                cin>> num1;
                cout<<"Enter number 2: ";
                cin>> num2;
            }
            else if(inp == 'k' || inp == '.'){
                // Clear or close operation
            }
            else{
                cout<<"Enter number 1: ";
                cin>>num1;
            }
            converter = 1;  // Activate the result display mode
        }

        switch(inp){
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                if(num2 != 0)
                    answer = num1 / num2;
                else
                    cout<<"Error: Division by zero!"<<endl;
                break;
            case 'm':
                answer = int(num1) % int(num2);
                break;
            case 'L':
                answer = log(num1);
                break;
            case 'S':
                answer = num1 * num1;
                break;
            case 'C':
                answer = num1 * num1 * num1;
                break;
            case 'p':
                answer = pow(num1, num2);
                break;
            case 's':
                answer = sin(num1);
                break;
            case 'c':
                answer = cos(num1);
                break;
            case 't':
                answer = tan(num1);
                break;
            case 'r':
                answer = sqrt(num1);
                break;
            case 'k':
                converter = 0;  // Reset and go back to the main calculator screen
                break;
            case '.':
                break;
            default:
                cout<<"Invalid input! Please enter a valid operation."<<endl;
        }
        system("cls");  // Clear the screen for the next operation
    }

    return 0;
}