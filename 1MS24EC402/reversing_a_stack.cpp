#include<iostream>
#include<stack>
using namespace std;
int main(){
   int n;
   cin >> n;
   stack<int> st;
   for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        st.push(temp);
    }
    cout << "Original Stack order : " << endl;
    stack<int> reversed;
    for(int i=0; i<n; i++){
        cout << st.top() << endl;
        reversed.push(st.top());
        st.pop();
    }
    cout << "Reversed Stack : " << endl;
    for(int i=0; i<n; i++){
        cout << reversed.top() << endl;
        reversed.pop();
    }
    return 0;
}