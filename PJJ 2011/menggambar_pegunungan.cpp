#include <cstdio>
#include <cstring>

int n;
char a[2000][20];
int main() {
    scanf("%d", &n);
    int len = (1<<n)-1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=len; j++) {
            if(j % (1<<(i)) == 0) {
                a[j][strlen(a[j])]='*';
            }
        }
    }
    for(int i=1; i<=len; i++) printf("%s\n", a[i]);
    return 0;
}
