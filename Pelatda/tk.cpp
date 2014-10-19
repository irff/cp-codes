#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int n; string s[200];

bool cp(string a, string b) {
    string x = a + b;
    string y = b + a;
    int lena=x.length();
    
    R(i,0,lena) {
        if(x[i]!=y[i]) {
            return x[i] < y[i];
        }
    }
    return x.length() < y.length();
}

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        cin >> s[i];
        while(s[i][0]=='0' and s[i].length()>1) s[i].erase(s[i].begin());
    }
    sort(s,s+n,cp);
    R(i,0,n) cout << s[i];
    cout << endl;
    return 0;
}
