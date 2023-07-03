#include<bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
        vector<string>thousand = {"", "M", "MM", "MMM"};
        vector<string>hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC","CM"};
        vector<string>tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string>ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        stack<string>st;
        
        string ans = thousand[(num/1000)%10] + hundreds[(num/100)%10] + tens[(num/10)%10] + ones[num%10];

        return ans;
    }
int main(){
    int str; cin>>str;


    cout<<intToRoman(str)<<"\n";

    return 0;
}

