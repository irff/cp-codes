#include <cstdio>

bool prime[150],biprime[150];
int teskes,a,b;
int main() {
    for(int i=2; i<=100; i++) prime[i]=1;
    for(int i=2; i*i<=100; i++) {
        for(int j=i*i; j<=100; j+=i) {
            prime[j]=0;
        } 
    }
    for(int i=1; i<=100; i++) {
        for(int j=i+1; j<=100; j++) {
            if(prime[i] and prime[j] and i*j<=100 and !biprime[i*j]) biprime[i*j]=1;
        }
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &a, &b);
        for(int i=a+1; i<b; i++) if(biprime[i]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
