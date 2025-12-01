Design a Finite Automata (FA) that accepts all strings over S={0, 1} having either exactly two 1's or 
exactly three 1's, not more nor less. Write a program to simulate this FA.

#include <iostream>
using namespace std;


class FA2{
    public:
        void state1(string str, int index){
            //initial state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == '1'){
                    state2(str, index+1);
                }
                else{
                    state1(str, index+1);
                }
            }
            
        }
        void state2(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == '1'){
                    state3(str, index+1);
                }
                else{
                    state2(str, index+1);
                }
            }
        }
        void state3(string str, int index){
            //final state
            if(str.length() == index){
                cout<<"String Accepted"<<endl;
                return;
            }
            else{
                if(str[index] == '1'){
                    state4(str, index+1);
                }
                else{
                    state3(str, index+1);
                }
            }
        }
        void state4(string str, int index){
            //final state
            if(str.length() == index){
                cout<<"String Accepted"<<endl;
                return;
            }
            else{
                if(str[index] == '1'){
                    state5(str, index+1);
                }
                else{
                    state4(str, index+1);
                }
            }
        }
        void state5(string str, int index){
            cout<<"String Rejected!"<<endl;
        }
};

int main(){
    string str;
    cout<<"Enter your string: "<<endl;
    getline(cin,str);

    FA2 f;
    f.state1(str,0);



    return 0;
}
