#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;

const int INF = 2000111222;

int pom[120000];
int jarak, cost = 0;
int main() {
    scanf("%d", &jarak);
    R(i,0,100111) pom[i] = INF;
    int ntoko = 0, x = 0, y = 0;
    while(scanf("%d%d", &x, &y) > 0) {
        pom[x] = min(pom[x], y);
        ntoko++;
    }
    int pos = 0, cost = 0, perut = 100;
    int tadi = 0;
    for(int i=0; i<=jarak; i++) {
        printf("%d %d\n", i, perut);
        
        if(pom[i]!=INF) {
            int mins = pom[i], id = i;
            //200 meter kedepan, cari minimal
            for(int j=i+1; j<=i+200; j++) {
                if(pom[j]!=INF and pom[j] < mins) {
                    mins = pom[j], id = j;
                }
            }
            if(id==i) {
                //beli semua
                cost  += (200-perut)*pom[id];
                perut += (200-perut);
                tadi = pom[id];
            } else {
                //beli agar sampai di B
                int butuh = id-i;
                if(butuh > perut) {
                    cost+=(butuh-perut)*pom[id];
                    perut = butuh;
                    tadi = pom[id];
                }
            }

        }
        perut--;
    }
    perut++;
    if(perut>100) {
        cost-=(perut-100)*tadi;
        perut = 100;
    }
    printf("%d\n", perut);
    printf("%d\n", cost);
    return 0;
}
