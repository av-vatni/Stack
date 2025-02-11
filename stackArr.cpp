// Stack implementation using array
#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];;
        top = -1;
    }

    void push(int element){
        // Check if space is available....
        if(size-top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Staack overflow!!"<<endl;
        }
    }
    void pop(){
        // Check if stack is empty....
        if(top >= 0){
            top--;
            cout<<"Stack underflow!!"<<endl;
        }else{
            cout<<"Stack underflow!!"<<endl;
        }
    }
    int peek(){
        // Check if stack is empty....
        if(top >= 0){
            return  arr[top];
        }else{
            cout<<"Stack is empty!!"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return  false;
        }
    }
};

int main(){
    Stack s(3);
    s.push(12);
    s.push(24);
    s.push(36);

    cout<<"Top element in stack is "<<s.peek()<<endl;

    s.pop();
    cout<<"Top element in stack is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element in stack is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element in stack is "<<s.peek()<<endl;

    if(s.isEmpty()){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"stack is Not empty"<<endl;
    }

}
