#include<bits/stdc++.h>
using namespace std;
 string simplifyPath(string path) {
        stack<string>st;
      
      
        int itr = 0;
        while(itr<path.size()){
           
            if(path[itr]=='/'){  
                while(itr < path.size() && path[itr]=='/') itr++;
            }
            else if(path[itr]=='.'){
                
                string dots = "";
               
                while(itr < path.size() && path[itr]!='/') {   
                    dots.push_back(path[itr]);
                    
                    itr++;
                }
                if(dots == "..") {
                    if(!st.empty()) st.pop(); 
                }
                else if(dots!=".") st.push(dots);
            }
            else{
                string dir = "";
                while(itr<path.size() && path[itr]!='/'){
                    dir.push_back(path[itr]);
                    itr++;
                }
                st.push(dir); 
            }
            //  if(itr >= 21) cout<<itr<<" "<<path[itr]<<" "<<st.top()<<"\n";
        }

        string ans = "";
        if (st.size()==0){
            ans = "/";
            return ans;
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
int main(){
    string str; cin>>str;


    cout<<simplifyPath(str)<<"\n";

    return 0;
}

