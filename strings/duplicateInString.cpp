#include<bits/stdc++.h>
using namespace std;

void listDuplicates(string &str){
    int count[26];
    memset(count,0,sizeof(count));

    for(char ch:str){
        count[ch-'a']++;
    }

    for(int i=0;i<26;i++){
        if(count[i]>1) {
            cout<<(char)('a' + i)<<" count: "<<count[i]<<"\n";
        }
    }
    return;
}


int main(){
    string str;
    cin>>str;


    listDuplicates(str);

    return 0;
}