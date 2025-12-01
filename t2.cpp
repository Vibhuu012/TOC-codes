//Design and simulate a Turing Machine which will increment the given binary number by 1.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum State { q0, q1, q2, q_accept, q_reject };

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
                if (symbol == '0' || symbol == '1') {
                    head++;
                } else if (symbol == '_') {
                    state = q1;
                    head--;
                } else {
                    state = q_reject;
                }
                break;
            case q1:
                if (symbol == '0') {
                    tape[head] = '1';
                    state = q_accept;
                } else if (symbol == '1') {
                    tape[head] = '0';
                    head--;
                } else if (symbol == '_') {
                    // If we reach blank while decrementing, need to add a 1 at the beginning
                    tape.insert(tape.begin(), '1');
                    head = 0;
                    state = q_accept;
                } else {
                    state = q_reject;
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

    string getResult() {
        string result;
        for (char c : tape) {
            if (c != '_') result += c;
        }
        return result;
    }
};

int main() {
    string input;
    cout << "Enter binary number: ";
    cin >> input;
    TuringMachine tm(input);
    tm.run();
    if (tm.state == q_accept) {
        cout << "Incremented: " << tm.getResult() << endl;
    } else {
        cout << "Invalid input" << endl;
    }
    return 0;
}

