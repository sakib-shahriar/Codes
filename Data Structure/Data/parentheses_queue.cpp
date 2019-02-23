#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    queue<char> q;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            q.push(str[i]);
    }
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(str[i]==')' && q.front()=='(')
                q.pop();
            else if(str[i]=='}' && q.front()=='{')
                q.pop();
            else if(str[i]==']' && q.front()=='[')
                q.pop();
            else{
                cout<<"Unbalanced";
                break;
            }
        }
        if(i==0)
            cout<<"Balanced";
    }
    return 0;
}

