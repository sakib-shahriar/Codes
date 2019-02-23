#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    stack<char> s;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
                if(str[i]==')' && s.top()=='(')
                    s.pop();
                else if(str[i]=='}' && s.top()=='{')
                    s.pop();
                else if(str[i]==']' && s.top()=='[')
                    s.pop();
                else{
                    cout<<"Unbalanced";
                    break;
                }
        }
        if(i==str.size()-1 && s.empty())
            cout<<"balanced";
        else if(i==str.size()-1 && !s.empty())
            cout<<"Unbalanced";
    }
    return 0;
}
