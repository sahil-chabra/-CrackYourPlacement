#include<bits/stdc++.h>
using namespace std;
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(string str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }

        vector<vector<string>> res;
        for(auto itr:mp){
            res.push_back(itr.second);
        }
        return res;
    }
int main(){
    int n; cin>>n;
    vector<string>strs;

    for(int i=0;i<n;i++){
        string temp; cin>>temp;
        strs.push_back(temp);
    }


   vector<vector<string>> res = groupAnagrams(strs);

   for(auto v: res) {for(string str: v) cout<<str<<" "; cout<<endl;}
   cout<<"\n";

    return 0;
}

