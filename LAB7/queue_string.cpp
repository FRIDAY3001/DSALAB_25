#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cout << "Enter length of string: ";
    cin >> n;

    string s1, s2;
    stack<char> stack, tempStack;

    cout << "Enter the string: ";
    cin >> s1;

    for (int i = 0; i < n; i++) {
        if (s1[i] != '+') {
            stack.push(s1[i]); 
        } else {
            if (!stack.empty()) {
                stack.pop();
            }

            
            while (!stack.empty()) {
                tempStack.push(stack.top());
                stack.pop();
            }

            
            while (!tempStack.empty()) {
                s2.push_back(tempStack.top());
                tempStack.pop();
            }
        }
    }


    while (!stack.empty()) {
        tempStack.push(stack.top());
        stack.pop();
    }
    while (!tempStack.empty()) {
        s2.push_back(tempStack.top());
        tempStack.pop();
    }

    cout << "Modified string: " << s2 << "\n";

    return 0;
}
