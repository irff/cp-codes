#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

string s, t;
char str[100];
LLD n, fak[30];
int teskes;
void rek(LLD n, string s) {
     if(s.length() == 0) return ;
     sort(s.begin(), s.end());
     LLD len = s.length();
     LLD x = n/fak[len-1];
     t = t + s[x];
     s.erase(x,1);
     rek(n%fak[len-1], s);
     
}

int main() {
    fak[0] = 1;
    R(i,1,21) fak[i] = fak[i-1]*i;
    scanf("%d", &teskes);
    gets(str);
    while(teskes--) {
        t = "";
        gets(str);
        s = str;
        cin >> n;
        gets(str);
        rek(n,s);
        cout << t << endl;
    }
    return 0;
}
