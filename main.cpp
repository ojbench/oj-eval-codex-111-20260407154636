#include <bits/stdc++.h>
using namespace std;
#include "src.hpp"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    for(int i=0;i<n;i++){
        int op; cin>>op;
        if(op==1){
            string s1,s2; cin>>s1>>s2;
            vector<char> buf(s1.begin(), s1.end());
            buf.push_back('\0');
            vector<char> d(s2.begin(), s2.end());
            d.push_back('\0');
            char* p = strtok(buf.data(), d.data());
            while(p){
                cout<<p<<"\n";
                p = strtok(nullptr, d.data());
            }
        }
    }
    return 0;
}
