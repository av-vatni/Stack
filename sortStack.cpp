#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int num){
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    // Recursive call
    sortedInsert(s, num);
    
    s.push(n);
}
void stackSort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();

    // Recursive call
    stackSort(s);

    sortedInsert(s, num);
}
int main(){
    stack<int>s;
    s.push(-100);
    s.push(48);
    s.push(30);
    s.push(57);

    stackSort(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}