//Finite Automata (FA) that accepts language EVEN-EVEN over S={a, b}.

#include <iostream>
using namespace std;


class FA{
    public:
        void state1(string str, int index){
            //initial state & Final State
            if(str.length()==index){
                cout<<"String Accepted!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state4(str, index+1);
                }
                else{
                    state2(str, index+1);
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
                if(str[index] == 'a'){
                    state3(str, index+1);
                }
                else{
                    state1(str, index+1);
                }
            }
        }
        void state3(string str, int index){
            //transition state
            if(str.length() == index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state2(str, index+1);
                }
                else{
                    state4(str, index+1);
                }
            }
        }
        void state4(string str, int index){
            //transition state
            if(str.length() == index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state1(str, index+1);
                }
                else{
                    state3(str, index+1);
                }
            }
        }
            
};

int main(){
    string str;
    cout<<"Enter your string: "<<endl;
    getline(cin,str);

    FA f;
    f.state1(str,0);



    return 0;
}