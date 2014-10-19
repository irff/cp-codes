#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
string s[1200];
int main() {
    scanf("%d", &n);
    getline(cin,s[1001]);
    R(i,0,n) {
        getline(cin,s[i]);
        int len =s[i].length();
        R(j,0,len) if(s[i][j]>='A' and s[i][j]<='Z') s[i][j]=s[i][j]-'A'+'a';
        string tmp = s[i];
        sort(s,s+i+1);
        R(j,0,i+1) {
            if(tmp == s[j]) {
                printf("%d\n", j+1);
                break;
            }
        }
    }

    return 0;
}
