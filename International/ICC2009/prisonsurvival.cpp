#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n,teskes;
double hasil;
int p[11000],np[11000];

int main() {
    R(i,2,10001) p[i]=1;
    
    for(int i=2; i*i<=10000; i++)
        for(int j=i*i; j<=10000; j+=i)
            p[j]=0;
    R(i,2,10001) {
        np[i]=np[i-1];
        if(p[i]==0) np[i]++;
        p[i]=p[i-1]+p[i];
    }
    R(i,0,15) printf("%d->%d %d\n", i, p[i], np[i]);
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        n++;
        if(p[n]==p[n-1]) {
            printf("YES %.1lf\n", np[n]+(double)(p[n]-1)/2);
            
        } else {
            printf("NO %.1lf\n", np[n]+(double)(p[n]-1)/2);
        }
    }
    return 0;
}
