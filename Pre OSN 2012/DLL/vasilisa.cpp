#include <algorithm>
#include <cstdio>
using namespace std;

int ra,rb,ca,cb,da,db;
int main() {
    scanf("%d%d%d%d%d%d", &ra, &rb, &ca, &cb, &da, &db);
    bool ketemu = 0;
    for(int i=1; i<=9 and !ketemu; i++) {
        for(int j=1; j<=9 and !ketemu; j++) {
            if(i!=j) {
                for(int k=1; k<=9 and !ketemu; k++) {
                    if(i!=k and j!=k) {
                        for(int l=1; l<=9 and !ketemu; l++) {
                            if(i!=l and j!=l and k!=l) {
                                if(i+j==ra and k+l==rb and i+k==ca and j+l==cb
                                   and i+l==da and j+k==db) {
                                    printf("%d %d\n%d %d\n", i, j, k, l);
                                    ketemu=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!ketemu) printf("-1\n");
    return 0;
}
