#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

map<string,int> st;
string s[40];
ULL hasil=0ULL,num=0;
int numtmp=0,pkt=1,ke=0;
int main() {
    st["0"]=0; st["."]=1; st[".."]=2; st["..."]=3; st["...."]=4; st["-"]=5;
    int x=0;
    while(getline(cin,s[x]) > 0) x++;
    for(int i=x-2; i>=0; i--) {
        if(st[ s[i] ]!=5) {
            ke++;
            num+=st[ s[i] ];
            hasil+=(num*pkt);
            
            if(ke==2) pkt*=18;
            else pkt*=20;
            
            num=0;
        } else {
            num+=5;
        }
    }
    if(num!=0) hasil+=(num*pkt);
    printf("%llu\n", hasil);
    return 0;
}
