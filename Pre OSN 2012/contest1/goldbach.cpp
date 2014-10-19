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

int n;
bitset<1200000> bs;
int main() {
    bs.set(); bs[0]=0; bs[1]=0; bs[2]=0;
    for(int i=2; i*i<=1200000; i++)
      for(int j=i*i; j<=1200000; j+=i) bs[j]=0;
    scanf("%d", &n);
    
    while(n!=0) {
        bool dapet = 0;
        for(int i=3; i<=n; i++) {
            if(bs[i] and bs[n-i]) {
                dapet = 1;
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
        if(!dapet) printf("Goldbach's conjecture is wrong.\n");
        scanf("%d", &n);
    }
    return 0;
}
