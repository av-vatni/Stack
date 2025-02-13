#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, element);

    s.push(num);
}
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, num);
}
int main(){
    stack<int>s;
    s.push(48);
    s.push(36);
    s.push(24);
    s.push(12);
    
    reverseStack(s);
    cout<<"After reverse: "<<endl;

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}