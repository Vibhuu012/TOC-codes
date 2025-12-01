//Design a PDA and write a program for simulating the machine which accepts the language {anbn  where n>0, S= {a, b}}.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

using namespace std;

class PDA {
private:
    vector<string> states;
    vector<string> alphabet;
    vector<string> stack_alphabet;
    string start_state;
    string accept_state;
    vector<string> stack;
    map<tuple<string, string, string>, pair<string, vector<string>>> transitions;

public:
    PDA() {
        states = {"q0", "q1", "q2"};
        alphabet = {"a", "b"};
        stack_alphabet = {"Z0", "a"};
        start_state = "q0";
        accept_state = "q2";
        stack = {"Z0"};  // Initial stack with bottom marker

        // Define transitions
        transitions[make_tuple("q0", "a", "Z0")] = make_pair("q0", {"a", "Z0"});  // Push 'a'
        transitions[make_tuple("q0", "", "Z0")] = make_pair("q1", {"Z0"});        // Epsilon to q1
        transitions[make_tuple("q1", "b", "a")] = make_pair("q1", {});            // Pop 'a'
        transitions[make_tuple("q1", "", "Z0")] = make_pair("q2", {"Z0"});       // Epsilon to q2
    }

    bool simulate(const string& input_string) {
        string current_state = start_state;
        vector<string> current_stack = stack;
        size_t i = 0;  // Input pointer

        while (i <= input_string.length()) {
            // Get current input symbol (empty string for epsilon)
            string symbol = (i < input_string.length()) ? string(1, input_string[i]) : "";
            string stack_top = current_stack.empty() ? "" : current_stack.back();

            // Find transition
            auto key = make_tuple(current_state, symbol, stack_top);
            if (transitions.find(key) != transitions.end()) {
                auto [new_state, new_stack] = transitions[key];
                // Update stack: pop top if exists, then push new elements
                if (!current_stack.empty()) {
                    current_stack.pop_back();
                }
                for (const auto& item : new_stack) {
                    current_stack.push_back(item);
                }
                current_state = new_state;
                if (!symbol.empty()) {
                    i++;  // Advance input only if not epsilon
                }
            } else {
                return false;  // No valid transition
            }
        }

        // Accept if in accept state
        return current_state == accept_state;
    }
};

int main() {
    PDA pda;
    vector<string> test_strings = {"ab", "aabb", "aaabbb", "a", "b", "aab", "abb", "aaaab"};
    for (const auto& s : test_strings) {
        bool result = pda.simulate(s);
        cout << "String '" << s << "': " << (result ? "Accepted" : "Rejected") << endl;
    }
    return 0;
}
