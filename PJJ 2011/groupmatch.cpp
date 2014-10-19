#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

struct tabel {
    short a[15];
} ;

typedef vector<int> VI;
typedef vector<VI> VII;

VII all[7];

tabel t;

int teskes,n,ntanding,npossible;

void rek(int k, tabel t) {
    if(k==ntanding) {
        int x=0; VI skor(n,0);
        R(i,0,n) R(j,i+1,n) {
            if(t.a[x]==0) skor[j]+=3;
            else if(t.a[x]==1) skor[i]++,skor[j]++;
            else skor[i]+=3;
            x++;
        }
        all[n].push_back(skor);
        return ;
    }
    t.a[k]=0; rek(k+1, t);
    t.a[k]=1; rek(k+1, t);
    t.a[k]=2; rek(k+1, t);
}

int main() {
    // Pause here
    // store all permutation of 2-5 players
    R(i,2,6){
        n=i;
        ntanding=n*(n-1)/2;
        rek(0,t);
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        VI skor;
        R(i,0,n) {
            int num;
            scanf("%d", &num);
            skor.push_back(num);
        }
        sort(skor.begin(),skor.end());
        bool ada=0;
        while(next_permutation(skor.begin(),skor.end()) ) {
            ada=binary_search(all[n].begin(),all[n].end(),skor);
            if(ada) break;
        }
        if(ada) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
