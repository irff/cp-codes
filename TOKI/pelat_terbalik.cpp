#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
int d[15];
int dua[15];
int satu[15];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        R(i,0,10) scanf("%d", &d[i]);
        bool bisa = 0;
        R(i,0,15) dua[i] = 0, satu[i] = 0;
        if(d[9] > 0 and d[6] > 0) {
            dua[9] = min(d[9], d[6]);
            bisa = 1;
        }
        if(d[8] > 0) {
            dua[8] = d[8]/2;
            satu[8] = d[8]%2;
            bisa = 1;
        }
        if(d[1] > 0) {
            dua[1] = d[1]/2;
            satu[1] = d[1]%2;
            bisa = 1;
        }
        if(d[0] > 0) {
            dua[0] = d[0]/2;
            satu[0] = d[0]%2;
        }
        if(bisa) {
            R(i,0,dua[9]) printf("9");
            R(i,0,dua[8]) printf("8");
            R(i,0,dua[1]) printf("1");
            R(i,0,dua[0]) printf("0");
            if(satu[8]) printf("8");
            else if(satu[1]) printf("1");
            else if(satu[0]) printf("0");
            R(i,0,dua[0]) printf("0");
            R(i,0,dua[1]) printf("1");
            R(i,0,dua[8]) printf("8");
            R(i,0,dua[9]) printf("6");
            printf("\n");
        } else printf("-1\n");
    }

    return 0;
}
