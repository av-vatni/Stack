#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
    // Base case
    if(count == size/2){
        inputStack.pop();
        return;
    }

    // Storing all the elements above the middle
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    solve(inputStack, count+1, size);

    // Again pushed the elements stored above
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int n){
    int count = 0;
    solve(inputStack, count, n);    
}
int main(){
    stack<int> s;
    s.push(15);
    s.push(30);
    s.push(45);
    s.push(60);
    s.push(75);

    deleteMiddle(s, 5);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

}