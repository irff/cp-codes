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

char s[1000], ch;
int main() {
    while(scanf("%s%c", &s,&ch) > 0) {
        reverse(s,s+strlen(s));
        printf("%s", s);
        if(ch==' ') printf(" ");
        else if(ch=='\n') printf("\n");
    }
    return 0;
}
