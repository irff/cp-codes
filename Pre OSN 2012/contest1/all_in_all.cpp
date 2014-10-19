#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LLD;
int teskes;

char sa[1000200], si[1000200];
int main() {
    while(scanf("%s%s", &sa, &si)>0) {
        int leni = strlen(si), lena=strlen(sa);
        int ctr = 0;
        R(i,0,leni) {
            if(sa[ctr]==si[i]) {
                ctr++;
            }
        }
        if(ctr==lena) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
