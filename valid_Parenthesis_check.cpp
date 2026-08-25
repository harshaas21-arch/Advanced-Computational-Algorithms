#include <iostream>
#include <stack>
using namespace std;
bool validParenthesis(string s)
{
int n = s.size();
bool valid = false;
stack<char> st;
for (char ch : s)
{
if (ch == '(' || ch == '{' || ch == '[')
{
st.push(ch);
}
else if (ch == ')' || ch == '}' || ch == '[')
{
if (st.empty())
return false;
if ((ch == ')' && st.top() == '(') ||
(ch == '}' && st.top() == '{') ||
(ch == ']' && st.top() == '['))
{
st.pop();
}
else
{
return false;
}
}
}
return st.empty();
}
int main()
{
string s;
cin >> s;
bool valid = validParenthesis(s);
cout << boolalpha;
cout << "The given string is: " << valid << endl;
return 0;
}