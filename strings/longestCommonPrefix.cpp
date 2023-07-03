#include<bits/stdc++.h>
using namespace std;
    class Node{
        public:
            int numChild = 0;
            char data;
            bool eow;
            Node* children[26];

            Node(char ch){
                data = ch;
                eow = false;
                for(int i=0;i<26;i++){
                    children[i] = NULL;
                }
                numChild = 0;
            }
    };
    class Trie{
        Node* root;
        void insertUtil(string word, int idx, Node* root){
            if(idx == word.size()){
                root->eow = true;
                return;
            }
            int child = word[idx] - 'a';
            Node* next;
            if(!root->children[child]){
                root->children[child] = new Node(word[idx]);
                root->numChild++;
            }
            next = root->children[child]; 

            insertUtil(word, idx+1, next);
        }

        public:
            Trie(){
                root = new Node('*');
            }

            void insert(string word){
                insertUtil(word, 0, root);
            }

            string lcp(vector<string>& strs){
                for(auto &str: strs){
                   insert(str);
                }

                Node* itr = root;
                string ans = "";
                string ref = strs[0];
                while(ref.size()>0 && itr->numChild <= 1){
              

                    if(itr->eow) break;
                    ans.push_back(ref[0]);

                  
                    itr = itr->children[ref[0]-'a'];
                    if(itr->eow) break;
                    
                    ref = ref.substr(1);
                   
                }

                return ans;
            }

    };
    
    string longestCommonPrefix(vector<string>& strs) {
       Trie tr;
       return tr.lcp(strs);
    }
int main(){
    int n; cin>>n;
    vector<string>strs;

    for(int i=0;i<n;i++){
        string temp; cin>>temp;
        strs.push_back(temp);
    }


    cout<<longestCommonPrefix(strs)<<"\n";

    return 0;
}

