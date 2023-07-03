#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int i, int j){
        if(i > j) return false;
        bool ans = true;
        for(int start = i;start<i + (j-i+1)/2;start++){
            if(str[start]!=str[j-(start-i)]) return false;
        }

        return ans;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;

        while(i<=j){
            if(s[i]==s[j]){
                i++, j--;
            }
            else{
                return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
            }
        }
        return true;
    }
int main(){
    string str; cin>>str;


    cout<<validPalindrome(str)<<"\n";

    return 0;
}

