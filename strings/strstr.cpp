#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vvll vector<vector<long long>>



   int strStr(string haystack, string needle) {
        
        int need = needle.size(), hay = haystack.size();

        if(need == 0) return 0;
        if(hay == 0 || hay < need) return -1;

        int d = 26;
        long fact=1;
        int p =15486703;
        long needhash = 0;
        long hashcode = 0;


        for(int i=0;i<need;i++){
            if(i!=need -1)
            fact = (fact*d)%p;
            needhash = (needhash*d + needle[i])%p;
            hashcode = (hashcode*d + haystack[i])%p;
        }
        

        
       
      
        
        for(auto s = 0; s< hay - need + 1;++s){
            if (hashcode < 0) hashcode += p;
            if(hashcode == needhash){
                if(needle == haystack.substr(s, need)) return s;
            }
           if(s < hay-need) hashcode = (d * (hashcode - haystack[s] * fact) + haystack[s + need]) % p;
        }
        return -1;
    }

int main(){
    string str1, str2;
    cin>>str1>>str2;


    cout<<strStr(str1, str2)<<"\n";

    return 0;
}