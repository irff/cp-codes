#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef unsigned long long LLU;

int len;
LLD na = 0, no =  0;
string s;
LLD rek(int ki, int ka) {
    if(len==1) {
        if(s[0]=='A') na++;
        else if(s[0]=='O') no++;
    } else {
        for(int pos=1; pos<len; pos+=2) {
            string now = "";
            char next = 'X';
            now.push_back(s[pos-1]); now.push_back(s[pos]); now.push_back(s[pos+1]);
                 if(now=="AIA") next = 'A';
            else if(now=="AIO") next = 'O';
            else if(now=="OIA") next = 'A';
            else if(now=="OIO") next = 'O';
            
            else if(now=="AEA") next = 'A';
            else if(now=="AEO") next = 'A';
            else if(now=="OEA") next = 'O';
            else if(now=="OEO") next = 'A';
            
            else if(now=="AUA") next = 'A';
            else if(now=="AUO") next = 'O';
            else if(now=="OUA") next = 'A';
            else if(now=="OUO") next = 'A';
            string x = s.substr(0,pos-1);
            x.push_back(next);
            x = x + s.substr(pos+2,string::npos);
            //cout << s << "\n";
            rek(len-2,x);
        }
    }
}
int main() {
    scanf("%d", &len);
    cin >> s;
    rek(len, s);
    printf("%lld ", na);
    printf("%lld\n", no);
    return 0;
}
