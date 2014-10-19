#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, nsoal, dengklek;
bool spes[2009][2009];
int skor[2009];

typedef struct {
    int id, skor, solved;
} student;

student p[2009];

bool cp(student a, student b) {
    if(a.skor == b.skor) {
        if(a.solved == b.solved) {
            return a.id < b.id; // ascending
        }
        return a.solved > b.solved; // descending
    }
    return a.skor > b.skor; // descending
}

int main() {
    scanf("%d%d%d", &n, &nsoal, &dengklek);
    R(i,0,n) {
        R(j,0,nsoal) {
            int x;
            scanf("%d", &x);
            spes[i][j]=x;
        }
    }
    R(i,0,nsoal) {
       int now = 0;
       R(j,0,n) {
           if(!spes[j][i]) now++;
       }
       skor[i]=now;
    }
    R(i,0,n) {
        int now = 0, ac = 0;
        R(j,0,nsoal) {
            if(spes[i][j]) {
                now+=skor[j]; ac++;
            }
        }
        p[i].id = i;
        p[i].skor = now;
        p[i].solved = ac;
    }
    sort(p, p+n, cp);
    R(i,0,n) {
        if(p[i].id == dengklek-1) {
            printf("%d %d\n", p[i].skor, i+1);
            break;
        }
    }
    return 0;
}
