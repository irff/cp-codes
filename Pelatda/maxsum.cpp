#include <cstdio>

int n, a[12000];
int main() {
    scanf("%d", &n);
    while(n!=0) {
        int ctr=0;
        for(int i=0; i<n; i++) {
            int num; scanf("%d", &num);
            if(num!=0) a[ctr++]=num;
        }
        if(ctr==0) printf("0\n");
        for(int i=0; i<ctr; i++) printf("%d%c", a[i], (i==ctr-1)?'\n':' ');
        scanf("%d", &n);
    }
    return 0;
}
