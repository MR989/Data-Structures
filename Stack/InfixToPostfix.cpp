#include<bits/stdc++.h>
using namespace std;
void Postfix(char *a)
{    stack <char> s;
    char output[50],t;
    for(int i=0;a[i]!='\0';i++)
    {   char ch = a[i];
        switch(ch)
        {
        case '^':
        case '-':
        case '+':
        case '/':
        case '*': s.push(ch);
                    break;
        case ')': t=s.top();//make t as top
                    s.pop();                 
  cout<<t;
                    break;
        }
        if (isalpha(ch))//checks if ch is alphabet or not
            cout<<ch;
    }
}
int main()
{
    char a[] = "((a+b)+(c/d))";
   Postfix(a);

}