#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

int n, a[15];
int d[15];
int pa[10], pb[10];
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        int num;
        scanf("%d", &num);
        a[num]++;
    }
    if(a[0]==0) {
        printf("-1\n");
    } else {
        LLD x = 0;
        R(i,0,10) x += (i*a[i]);
        if(x%3==1) {
            bool bisa = 0;
            R(i,0,10) {
                if(a[i] and i%3==1) {
                    a[i]--; x-=i;
                    bisa = 1;
                    break;
                }
            }
            //printf("%d\n",x);
            if(!bisa) {
                R(i,1,10) {
                    if(a[i] >=2 and (2*i)%3==1) {
                        a[i]-=2; x-=(2*i);
                        bisa = 1;
                        break;
                    }
                }
                if(!bisa) {
                  R(i,1,10) {
                    R(j,1,10) {
                        if( i!=j and a[i] and a[j] and (i+j)%3==1) {
                            //printf("%d %d\n", i, j);
                            a[i]--; a[j]--; x-=i; x-=j;
                            bisa = 1;
                            break;
                        }
                    }
                    if(bisa) break;
                }
               }
            }
        } else if(x%3==2) {
            bool bisa = 0;
            R(i,0,10) {
                if(a[i] and i%3==2) {
                    a[i]--; x-=i;
                    bisa = 1;
                    break;
                }
            }
            
            if(!bisa) {
                R(i,1,10) {
                    if(a[i] >=2 and (2*i)%3==2) {
                        a[i]-=2; x-=(2*i);
                        bisa = 1;
                        break;
                    }
                }
                if(!bisa) {
                  R(i,1,10) {
                    R(j,1,10) {
                        if( i!=j and a[i] and a[j] and (i+j)%3==2) {
                            a[i]--; a[j]--; x-=i; x-=j;
                            bisa = 1;
                            break;
                        }
                    }
                    if(bisa) break;
                  }
                }
            }
        }
        if(x == 0) printf("0");
        else {
          RV(i,9,0) {
            R(j,0,a[i]) {
                printf("%d", i);
            }
          }
        }
        printf("\n");
    }
}
