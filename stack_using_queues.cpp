#include <iostream>
#include <queue>
using namespace std;
class Stack
{
public:
queue<int> q1;
queue<int> q2;
void push(int x)
{
q2.push(x);
while (!q1.empty())
{
q2.push(q1.front());
q1.pop();
}
swap(q1, q2);
}
void pop()
{
if (q1.empty())
{
cout << "Stack is empty" << endl;
return;

}
q1.pop();
}
void top()
{
if (q1.empty())
{
cout << "Stack is empty" << endl;
}
cout << q1.front() << endl;
}
};
int main()
{
Stack st;
st.push(1);
st.push(2);
st.push(3);
st.top();
st.pop();
st.pop();
st.top();
st.pop();
st.top();
return 0;
}