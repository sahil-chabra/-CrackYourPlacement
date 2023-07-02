// only storing the function
#include <bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
       unordered_set<char>open = {'(','{','['};
      

       stack<char> st;

       for(char ch:s){
           if(open.count(ch)>0) st.push(ch);
           else{
               if(st.empty()) return false;
               if((ch == ')' && st.top()!='(') || (ch == '}' && st.top()!='{') || (ch == ']' && st.top()!='[')) return false;
               st.pop();
           }
           
       }
       return st.empty();
}

int main(){
    string str; cin>>str;


    if(isValid(str)) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}