#include<bits/stdc++.h>
using namespace std;


int evaluate(string  exp){

    stack<int > s;

    for (int i =0;i<exp.length();i++){
        
        if(exp[i]==' '|| exp[i]==',' ) continue;

        else if(isdigit(exp[i])){
            int num=0;
            while(isdigit(exp[i])){
                num=num*10 + (int)(exp[i]-'0');
                i++;
               
            }
            
            i--;
            
            s.push(num);   
        }
        else{
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            int res=0;
            switch (exp[i])
            {
            case '+':
                res=op1+op2;
                break;
            
            case '-':
                res=op1-op2;
                break;
            
            case '*':
                res=op1*op2;
                break;
            
            case '/':
                res=op1/op2;
                break;
            
            }
           //cout<<"result "<<res;
            s.push(res);
        }

    }
    return s.top();

}

int main(){

    string exp;

    getline(cin,exp);

    cout<<evaluate(exp);
}