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

int n, a[102000];

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    LLD jum = 0;
    int ans = 0;
    R(i,0,n) {
        jum += a[i]+1;
        if(jum >=n) { ans = i; break; }
    }
    printf("%d\n", ans+1);
    
    return 0;
}














