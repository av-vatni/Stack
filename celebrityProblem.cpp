#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>>M, int a, int b, int n){
    if(M[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}

int celebrityProblem(vector<vector<int>>M){
    int size = M.size();
    stack<int> s;

    for(int i=0; i<size; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M, a, b, size)){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int ans = s.top();
    // Row check for all zeros
    int zeroCount = 0;
    for(int i = 0; i < size; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }
    if(zeroCount != size){
        return -1;
    }
    
    int oneCount = 0;
    for(int i = 0; i < size; i++){
        if(M[i][ans] == 1){
            oneCount++;
        }
    }
    if(oneCount != size-1){
        return -1;
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };
    int id = celebrityProblem(matrix);
    
    if(id == -1){
        cout << "Celebrity is not present!";
    }else{
        cout << "Celebrity ID " << id;
    }
    
}