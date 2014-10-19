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

int a, b, awal, akhir;
int m[4000000];
int main() {
    
    m[1]=1;
    
    for(int i=2; i<=1000000; i++) {
        long long x = i, step=1;
        if(m[x]==0){
          while(x>1) {
            if(x%2) x=3*x+1;
            else x/=2;
            if(x < 1000000) if(m[x]!=0) { step += m[x]; break; }
            step++;
          }
        }
        m[i]=step;
    }
    while(scanf("%d%d", &a, &b)>0) {
        int maks = -1;
        if(a > b) awal = b, akhir=a;
        else awal = a, akhir=b;
        R(i,awal,akhir+1) maks = max(maks, m[i]);
        printf("%d %d %d\n", a, b, maks);
    }
    return 0;
}
