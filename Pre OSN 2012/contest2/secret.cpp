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

char s[2000000];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        if(strcmp(s, "1")==0 or strcmp(s, "4")==0 or strcmp(s,"78")==0) printf("+\n");
        else if(len >=3 and s[len-1]=='5' and s[len-2]=='3') printf("-\n");
        else if(len>=3 and s[0]=='9' and s[len-1]=='4') printf("*\n");
        else printf("?\n");
    }
    return 0;
}










