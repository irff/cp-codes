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

char sa[100], si[100];
int n, iter=0;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%s", &sa);
        int step = 0;
        strcpy(si,sa);
        reverse(si, si+strlen(si));
        while(strcmp(sa,si)!=0) {
            LLD x = atol(sa)+atol(si);
            memset(sa,0,sizeof sa);
            int ctr = 0;
            while(x>0) sa[ctr++]=x%10+'0',x/=10;
            strcpy(si,sa);
            reverse(si,si+strlen(si));
            step++;
        }
        printf("%d %s\n", step, sa);
        
    }
    return 0;
}
