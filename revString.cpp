// Using stl, we will solve

// Logic : Stack always reverses the elements inserted in it.

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s;
    string str = "Avdhut";
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"Ans is "<<ans<<endl;
}