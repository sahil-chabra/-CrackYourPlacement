#include<bits/stdc++.h>
using namespace std;
    void helper(int open, int close, string ans,unordered_set<string>& st){
        if(open==0 && close == 0){
            st.insert(ans);
            return;
        }
        if(open == 0 && close!=0){
            while(close>0){
                ans.push_back(')');
                close--;
            }
            st.insert(ans);
            return;
        }
        if(close ==0 || close < open){
            return;
        }

       
        helper(open-1,close,ans+"(",st);
       
       
        helper(open, close-1,ans+")",st);
        
    }
    vector<string> generateParenthesis(int n) {
       string temp = "";
       

        vector<string>ans;
        unordered_set<string>st;
         helper(n,n,temp, st);
        for(auto str:st){
            ans.push_back(str);
        }

        return ans;
    }
int main(){
    int str; cin>>str;


    vector<string>ans = generateParenthesis(str);

    for(auto str:ans)cout<<str<<" ";
    cout<<endl;

    return 0;
}

