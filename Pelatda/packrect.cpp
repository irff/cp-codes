/*
    ID: irfan1
    LANG: C++
    TASK: packrec
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define p0 a[p[0]][ii]
#define p1 a[p[1]][ij]
#define p2 a[p[2]][ik]
#define p3 a[p[3]][il]
#define l0 a[p[0]][!ii]
#define l1 a[p[1]][!ij]
#define l2 a[p[2]][!ik]
#define l3 a[p[3]][!il]

int a[5][3];
int b[5][3];
int p[4];
bool m[250][250];
int mins = 2000111222;
int main() {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    R(i,0,4) { scanf("%d%d", &a[i][0], &a[i][1]); }
    R(i,0,4) p[i]=i;
    do {
        R(ii,0,2) R(ij,0,2) R(ik,0,2) R(il,0,2) {
            int pan = 0, leb = 0;
            
            //case1
            pan = max(p0,max(p1,max(p2,p3)));
            leb = l0+l1+l2+l3;
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case1");
            //case2
            pan = max(p0,p1+p2+p3);
            leb = l0+max(l1,max(l2,l3));
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case2");
            //case3
            pan = p1+max(p0, p2+p3);
            leb = max(l1,l0+max(l2,l3));
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case3");
            //case4
            pan = p1+p2+max(p0, p3);
            leb = max(l0+l3, max(l1, l2));
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case4");
            //case5
            pan = p0+p1+(max(p2,p3));
            leb = max(l0,max(l1,l2+l3));
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case5");
            //case 6
            pan = max(p0+p1, p2+p3);
            leb = max(l0+l2, l1+l3);
            if( pan < p0+p3 and leb < l0+l3) pan = p0+p3;
            if( pan < p1+p2 and leb < l1+l2) pan = p1+p2;
            mins = min(mins, pan*leb);
            m[pan][leb]=1;
            //if(pan*leb==36) printf("case6");
        }
    } while(next_permutation(p, p+4));
    printf("%d\n", mins);
    R(i,1,201) {
        R(j,i,201) {
            if((m[j][i] or m[i][j]) and i*j==mins) {
                printf("%d %d\n", i,j);
            }
        }
    }
    return 0;
}
