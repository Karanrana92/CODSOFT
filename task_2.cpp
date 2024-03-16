#include<bits/stdc++.h>

using namespace std;

int main() {
    char op;
    double num1 , num2;

    cout << "Enter the first number : ";
    cin >> num1 ;

    cout << "Enter the second number : " ;
    cin >> num2 ;

    cout << "Enter the Operator ( +, - , * , /) : ";
    cin >> op;


    switch( op ) {
        case '+':
            cout << num1 << " + " << num2 << " = " << (num1 + num2);
            break;
        
        case '-':
            cout << num1 << " - " << num2 << " = " << (num1 - num2);
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << (num1 * num2);
            break;

        case '/':
            if(num2 != 0.0) 
                cout << num1 << " / " << num2 << " = " << (num1 / num2);
            else    
                cout << "Divide by zero situation";

            break;

        default:
            cout << op << " is an invalid operator.";

    }


}