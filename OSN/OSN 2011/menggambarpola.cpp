#include <cstdio>

int bar,kol;
int main() {
    scanf("%d%d", &bar, &kol);
    for(int i=1; i<=bar; i++) {
        for(int j=1; j<=kol; j++)
            if(i%2==0 and j%2==0) putchar('#');
            else if(i%2==1 and j%2==1) putchar('*');
            else putchar('$');
        printf("\n");
    }
    return 0;
}
