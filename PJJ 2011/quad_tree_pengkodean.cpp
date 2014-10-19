#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef deque<int> VI;
typedef deque<VI> VVI;

int bar, kol, m[200][200], n;
int pangkat[16], max_step=0;
VVI ans;
void rek(VI v, int a, int b, int step) {

    bool nol=1, satu=1;
    int pan = pangkat[max_step-step];
    int pin = pangkat[max_step-step-1];

    R(i,a,a+pan) {
        R(j,b,b+pan) {
            if(m[i][j]==0) satu = 0;
            if(m[i][j]==1) nol=0;
        }
    }
    //printf("%d %d\n", a+pan, b+pan);
    //if(step>1) return ;
    //printf("%d %d\n", a, b);
    //printf("%d %d %d -- %d %d\n", nol, satu, pan, a, b);
    //printf("%d\n", pan);
    if(satu) {
        v.push_front(1);
        ans.push_back(v);
    } else if(nol) {
    
    } else {
        v.push_back(0);
        rek(v, a, b, step+1);
        v.pop_back();
        v.push_back(1);
        rek(v, a, b+pin, step+1);
        v.pop_back();
        v.push_back(2);
        rek(v, a+pin, b, step+1);
        v.pop_back();
        v.push_back(3);
        rek(v, a+pin, b+pin, step+1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    pangkat[0]=1;
    for(int i=1; i<=10; i++) pangkat[i]=pangkat[i-1]*2;
    
    R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
    //R(i,0,bar) { R(j,0,kol) printf("%d ", m[i][j]); printf("\n"); }
    n = max(bar, kol);
    for(int i=0; i<=10; i++) {
        if(pangkat[i]>=n) {
            max_step = i;
            n = pangkat[i];
            break;
        }
    }
    VI x;
    rek(x, 0, 0, 0);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    printf("END\n");
    return 0;
}
