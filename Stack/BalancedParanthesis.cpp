#include<bits/stdc++.h>

using namespace std;

bool arePair(char open,char close){
    if (open=='['&& close==']')return true;
    else if (open=='{'&& close=='}')return true;
    else if (open=='('&& close==')')return true;
	
    return false;
}

bool BalancedParanthesis(string exp){
	stack <char > s;
	
	for(int i =0;i<exp.length();i++){

        if(exp[i]=='(' ||exp[i]=='['||exp[i]=='{' )
            s.push(exp[i]);
        else if(exp[i]==')' ||exp[i]==']'||exp[i]=='}'){
            if(s.empty()|| !arePair(s.top(),exp[i])){
				
                return false;
            }
            else
                s.pop(); 

        }
    }
	return s.empty()?true:false;
}

int main(){

    


    string exp;
    cin>>exp;
	if(BalancedParanthesis(exp))
		cout<<"balanced";
	else
		cout<<"not balanced";
	
}