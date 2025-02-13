#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();

    solve(s, element);

    s.push(num);
}
stack<int> pushAtBtm(stack<int>& myStack, int x){
    solve(myStack, x);
    return myStack;
}
int main(){
    stack<int>s;
    s.push(48);
    s.push(36);
    s.push(24);
    s.push(12);
    
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
    stack<int> ans = pushAtBtm(s, 60);

    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}