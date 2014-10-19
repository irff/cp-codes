#include <cstdio>

int nstamp,num,stamp[60],used[60];

int main() {
    scanf("%d", &nstamp);
    for(int i=0; i<nstamp; i++) scanf("%d", &stamp[i]);
    scanf("%d", &num);
    for(int i=nstamp-1; i>=0; i--) {
        while(num >= stamp[i]) {
            num-=stamp[i];
            used[i]++;
        }
    }
    for(int i=0; i<nstamp; i++) {
        if(used[i]) {
            printf("%d %d\n", used[i], stamp[i]);
        }
    }
    return 0;
}
