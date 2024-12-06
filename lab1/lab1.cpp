#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

double evaluate_postfix(string postfix_expression) {
    vector<string> inp1;
    string temp = "";

    // Splitting the string into tokens
    for (int i = 0; i < postfix_expression.size(); i++) {
        if (postfix_expression[i] == ' ') {
            if (!temp.empty()) { 
                inp1.push_back(temp);
                temp = "";
            }
        } else {
            temp += postfix_expression[i];
        }
    }
    if (!temp.empty()) {
        inp1.push_back(temp);
    }

    vector<string> operators{"*", "^", "-", "/", "+"};
    stack<double> myStack;

    for (int i = 0; i < inp1.size(); i++) {
        if (find(operators.begin(), operators.end(), inp1[i]) != operators.end()) {
            double a = myStack.top();
            myStack.pop();
            double b = myStack.top();
            myStack.pop();
            double result = 0;

            if (inp1[i] == "+") {
                result = b + a;
            } else if (inp1[i] == "-") {
                result = b - a;
            } else if (inp1[i] == "*") {
                result = b * a;
            } else if (inp1[i] == "/") {
                result = b / a;
            } else if (inp1[i] == "^") {
                result = pow(b, a);
            }

            myStack.push(result);
        } else {
            myStack.push(stod(inp1[i]));
        }
    }
    return myStack.top();
}

int main() {
    string postfix_expression = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
    cout << "Result: " << evaluate_postfix(postfix_expression) << endl;
    return 0;
}
