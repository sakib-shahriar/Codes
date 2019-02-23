#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i]))
            s.push(str[i]- '0');
        else{
            int val1=s.top();
            s.pop();
            int val2=s.top();
            s.pop();
            if(str[i]=='+')
                s.push(val1+val2);
            else if(str[i]=='-')
                 s.push(val1-val2);
            else if(str[i]=='*')
                 s.push(val1*val2);
            else if(str[i]=='/')
                 s.push(val1/val2);
            else if(str[i]=='^')
                 s.push(pow(val1,val2));

        }
    }
    cout<<s.top();
    return 0;
}
