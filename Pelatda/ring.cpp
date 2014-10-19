#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef vector<int> VI;

int n;

bitset<100> bs;

void rek(VI v, int num, int step) {
    //printf("\n");
    if(step==n-1) {
        if( bs[ v[step] + v[0]] ) {
            for(int i=0; i<n; i++) printf("%d%c", v[i], i==n-1?'\n':' ');
        }
        return ;
    }
    R(i,2,n+1) {
        if(bs[ v[step]+i ]) {
            bool udah = 0;
            R(j,0,step+1) if(v[j]==i) udah=1;
            if(!udah) {
                VI x = v; x.push_back(i);
                rek(x, i, step+1);
            }
        }
    }
}

int main() {
    int kasus = 1;
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=50; i++)
      for(int j=i*i; j<=50; j+=i) bs[j]=0;

    while(scanf("%d", &n)>0) {
        if(kasus!=1) printf("\n");
        VI v; v.push_back(1);
        printf("Case %d:\n", kasus++);
        rek(v,1,0);
        
    }
}

