//Design and simulate a Turing Machine that accepts the language anbncn where n >0.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum State { q0, q1, q2, q3, q_accept, q_reject };

class TuringMachine {
public:
    vector<char> tape;
    int head;
    State state;

    TuringMachine(string input) {
        tape.assign(input.begin(), input.end());
        tape.push_back('_');
        head = 0;
        state = q0;
    }

    void run() {
        while (state != q_accept && state != q_reject) {
            step();
        }
    }

    void step() {
        char symbol = tape[head];
        switch (state) {
            case q0:
                if (symbol == 'a') {
                    tape[head] = 'X';
                    state = q1;
                    head++;
                } else if (symbol == 'X' || symbol == 'Y' || symbol == 'Z') {
                    head++;
                } else if (symbol == '_') {
                    state = q_reject;  // For n > 0, empty string should reject
                } else {
                    state = q_reject;
                }
                break;
            case q1:
                if (symbol == 'X' || symbol == 'Y' || symbol == 'Z') {
                    head++;
                } else if (symbol == 'b') {
                    tape[head] = 'Y';
                    state = q2;
                    head++;
                } else {
                    state = q_reject;
                }
                break;
            case q2:
                if (symbol == 'X' || symbol == 'Y' || symbol == 'Z') {
                    head++;
                } else if (symbol == 'c') {
                    tape[head] = 'Z';
                    state = q3;
                    head--;
                } else {
                    state = q_reject;
                }
                break;
            case q3:
                if (symbol == '_') {
                    state = q0;
                    head++;
                } else {
                    head--;
                }
                break;
        }
        if (head < 0) {
            tape.insert(tape.begin(), '_');
            head = 0;
        }
        if (head >= tape.size()) {
            tape.push_back('_');
        }
    }

    bool accepts() {
        if (state == q0 && tape[head] == '_') {
            for (char c : tape) {
                if (c == 'X') return true;
            }
        }
        return false;
    }
};

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    TuringMachine tm(input);
    tm.run();
    if (tm.accepts()) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }
    return 0;
}

