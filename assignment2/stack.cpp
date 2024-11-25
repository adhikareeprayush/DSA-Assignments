#include <iostream>
#include <stack>    
using namespace std;
int main() {
    stack <int> S;
    S.push(1);
    S.push(2);
    cout << S.top() << endl;
    S.pop();
    cout << "Stack is empty: " << S.empty() << endl;
    S.push(3);
    cout << "Size of stack: " << S.size() << endl;
    return 0;
}