#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int n;
string a[10000], s;
int main() {
    scanf("%d", &n);
    getline(cin, s);
    R(i,0,n) {
        getline(cin,s);
        int len = s.length();
        R(j,0,len) if(s[j] >= 'A' and s[j] <= 'Z') s[j]=s[j]-'A'+'a';
        R(j,0,i+1) {
            if(j==i or a[j] > s) {
                RV(k,i,j+1) a[k]=a[k-1];
                a[j] = s;
                printf("%d\n",j+1);
                break;
            }
        }
    }

    return 0;
}
