//Finite Automata (FA) that accepts language L1, over S={a, b}, comprising of all strings (of length 4 or more) having first two characters same as the last two. 

#include <iostream>
using namespace std;

class FA{
    public:
        void state1(string str, int index){
            //initial state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state2(str, index+1);
                }
                else{
                    state9(str, index+1);
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
                    state6(str, index+1);
                }
            }
        }
        void state3(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state4(str, index+1);
                }
                else{
                    state3(str, index+1);
                }
            }
        }
        void state4(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state5(str, index+1);
                }
                else{
                    state3(str, index+1);
                }
            }
        }
        void state5(string str, int index){
            //final state
            if(str.length()==index){
                cout<<"String Accepted!"<<endl;
            }
            else{
                if(str[index] == 'a'){
                    state5(str, index+1);
                }
                else{
                    state3(str, index+1);
                }
            }
        }
        void state6(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state7(str, index+1);
                }
                else{
                    state6(str, index+1);
                }
            }
        }
        void state7(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state7(str, index+1);
                }
                else{
                    state8(str, index+1);
                }
            }
        }
        void state8(string str, int index){
            //final state
            if(str.length()==index){
                cout<<"String Accepted!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state7(str, index+1);
                }
                else{
                    state6(str, index+1);
                }
            }
        }
        void state9(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state10(str, index+1);
                }
                else{
                    state13(str, index+1);
                }
            }
        }
        void state10(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state10(str, index+1);
                }
                else{
                    state11(str, index+1);
                }
            }
        }
        void state11(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state12(str, index+1);
                }
                else{
                    state11(str, index+1);
                }
            }
        }
        void state12(string str, int index){
            //final state
            if(str.length()==index){
                cout<<"String Accepted!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state10(str, index+1);
                }
                else{
                    state11(str, index+1);
                }
            }
        }
        void state13(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state13(str, index+1);
                }
                else{
                    state14(str, index+1);
                }
            }
        }
        void state14(string str, int index){
            //transition state
            if(str.length()==index){
                cout<<"String Rejected!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state13(str, index+1);
                }
                else{
                    state15(str, index+1);
                }
            }
        }
        void state15(string str, int index){
            //final state
            if(str.length()==index){
                cout<<"String Accepted!"<<endl;
                return;
            }
            else{
                if(str[index] == 'a'){
                    state13(str, index+1);
                }
                else{
                    state15(str, index+1);
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