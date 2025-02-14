#include<iostream>
#include<stack>
using namespace std;

bool findRedBrackets(string &str){
    stack<int>st;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }else{
            // ch is either ')' or any alphabet
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return  true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string str = "((a+b)/f)";
    if(findRedBrackets(str)){
        cout<<"Redundant brackets are there!"<<endl;
    }else{
        cout<<"Redundant brackets are not there!"<<endl;
    }
}