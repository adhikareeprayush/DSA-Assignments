#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(string op) {
    if (op == "^") return 3;
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

bool isOperator(string op) {
    return op == "+" || op == "-" || op == "*" || op == "/" || op == "^";
}

string convertToPostfix(string infix_expression) {
    vector<string> tokens;
    string temp = "";

    for (int i = 0; i < infix_expression.size(); i++) {
        if (infix_expression[i] == ' ') {
            if (!temp.empty()) { 
                tokens.push_back(temp);
                temp = "";
            }
        } else {
            temp += infix_expression[i];
        }
    }
    if (!temp.empty()) {
        tokens.push_back(temp);
    }

    stack<string> opStack;   
    vector<string> postfix; 

    for (string token : tokens) {
        if (isOperator(token)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token)) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == "(") {
                opStack.pop();
            }
        } else {
            postfix.push_back(token);
        }
    }

    while (!opStack.empty()) {
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    string postfix_expression = "";
    for (string token : postfix) {
        postfix_expression += token + " ";
    }
    return postfix_expression;
}

int main() {
    string infix_expression;
    cout << "Enter an infix expression : ";
    getline(cin, infix_expression);
    string postfix = convertToPostfix(infix_expression);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
