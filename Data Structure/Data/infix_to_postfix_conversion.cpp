#include<bits/stdc++.h>
using namespace std;

stack<char> s;

struct temp
{
    char ope;
    int priority;
};

struct temp x[5];


int check_priority(char c)
{
    for(int i=0; i<5; i++)
    {
        if(x[i].ope==c)
            return x[i].priority;
    }
    return -1;
}

int main()
{
    char postfix[1000];
    string str;
    int i,j=0,k,p1,p2;

    x[0].ope='+';
    x[0].priority=1;
    x[1].ope='-';
    x[1].priority=1;
    x[2].ope='*';
    x[2].priority=2;
    x[3].ope='/';
    x[3].priority=2;
    x[4].ope='^';
    x[4].priority=3;

    cin>>str;

    for(i=0; i<str.length(); i++){
        if(isalpha(str[i])){
            postfix[j]=str[i];
            j++;
        }
        else{
            if(s.empty() || str[i]=='(' || s.top()=='(')
                s.push(str[i]);
            else{
                if(str[i]==')'){
                    while(s.top()!='('){
                        postfix[j]=s.top();
                        s.pop();
                        j++;
                    }
                    s.pop();
                }
                else{
                    p1=check_priority(str[i]);
                    p2=check_priority(s.top());

                    if(p1>p2)
                        s.push(str[i]);
                    else{
                        while(p1<=p2 && s.top()!='('){
                            postfix[j]=s.top();
                            s.pop();
                            j++;
                            if(s.top()!='(')
                                p2=check_priority(s.top());
                        }
                        s.push(str[i]);
                    }
                }
            }
        }
    }
    while(!s.empty())
    {
        postfix[j]=s.top();
        s.pop();
        j++;
    }
    postfix[j]='\0';
    cout<<postfix;
    return 0;
}
