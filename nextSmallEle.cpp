// Finding next small element in given array using stack
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmall(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        // Storing the ans
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    int n = 4;

    vector<int> v =  {2, 1, 4, 3};
    cout<<"Entered vector: "<<endl;
    for (int element : v){
        cout << element << std::endl;
    }

    cout<<"Answer vector: "<<endl;
    vector<int> ansArr =  nextSmall(v, n);
    for (int element : ansArr) {
        cout << element << std::endl;
    }
}
