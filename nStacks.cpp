// N stacks in an array
#include<iostream>
#include<stack>
using namespace std;

class nStacks{
    int *arr;
    int *top;
    int *next;
    int S;
    int N;
    int freeSpot;

    public:
    nStacks(int N, int S){
        this->N = N;
        this->S = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        // Initialise TOP
        for(int i=0; i<N; i++){
            top[i] = -1;
        }
        // Initialise NEXT
        for(int i=0; i<S; i++){
            next[i] = S+1;
        }
        // Update last value of next to -1
        next[S-1] = -1;

        // Free spot
        freeSpot = 0;
    }

    bool push(int x, int m){
        if(freeSpot == -1){
           return false; 
        }
        // Find index
        int index = freeSpot;

        // Update free spot
        freeSpot =  next[index];

        // insert ele
        arr[index]= x;

        // update next
        next[index] = top[m-1];
        
        // Update top
        top[m-1] = index;

        return true;
    }
    bool pop(int m){
        if(top[m-1] == -1){
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main(){
// Test again test cases on coding platforms
}