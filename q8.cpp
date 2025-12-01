//Design a PDA and write a program for simulating the machine which accepts the language {wXwr| w is any string over S={a, b} and wr is reverse of that string and X is a special symbol }.//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

enum State { Q0, Q1, Q2 };

bool simulatePDA(const string& input) {
    stack<char> stk;
    State currentState = Q0;
    bool seenX = false;
    
    for (char ch : input) {
        if (currentState == Q0) {
            if (ch == 'a' || ch == 'b') {
                stk.push(ch);
                
            } else if (ch == 'X') {
                if (seenX) {
                    return false; 
                }
                seenX = true;
                currentState = Q1;
            } else {
                return false; 
            }
        } else if (currentState == Q1) {
            if (ch == 'a' || ch == 'b') {
                if (!stk.empty() && stk.top() == ch) {
                    stk.pop();
                    
                } else {
                    return false; 
                }
            } else {
                return false; 
            }
        }
    }
    
    
    if (currentState == Q1 && seenX && stk.empty()) {
        currentState = Q2; 
        return true;
    }
    
    return false;
}

int main() {
    string input;
    cout << "Enter a string over {a, b, X}: ";
    cin >> input;
    
    if (simulatePDA(input)) {
        cout << "String accepted by the PDA." << endl;
    } else {
        cout << "String rejected by the PDA." << endl;
    }
    
    return 0;
}


//OUTPUT
//Enter a string over {a, b, X}: abba X abba
//String rejected by the PDA.
//Enter a string over {a, b, X}: ab X ba
//String rejected by the PDA.
