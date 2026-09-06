#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Ascending(stack<int> st, int n){
    vector<int> result;
    for(int i=0; i<n; i++){
    result.push_back(st.top());
    st.pop();
    }
    sort(result.begin(), result.end());
    return result;
}
vector<int> Descending(stack<int> st, int n){
    vector<int> result;
    for(int i=0; i<n; i++){
    result.push_back(st.top());
    st.pop();
    }
    sort(result.begin(), result.end(), greater<int>());
    return result;
}
int main(){
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0; i<n; i++){
    int temp;
    cin >> temp;
    st.push(temp);
    }
    vector<int> result;
    int choice;
    cout << "Enter 1 for Ascending and 2 for Descending : " << endl;
    cin >> choice;
    if(choice == 1){
        result = Ascending(st, n);
    }

    else if(choice == 2){
        result = Descending(st, n);
    }
    cout << "Original Stack: " << endl;
    for(int i=0; i<n; i++){
        cout << st.top() << endl;
        st.pop();
    }
    cout << "Sorted Stack: " << endl;
    for(int i : result){
        cout << i << endl;
    }
    return 0;
}