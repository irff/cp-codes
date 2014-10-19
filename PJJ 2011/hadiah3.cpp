#include <cstdio>

int num;
int pangkattiga[20],hasil[20],n;
int main() {
    pangkattiga[0]=1;
    for(int i=1; i<20; i++) {
        pangkattiga[i]=pangkattiga[i-1]*3;
    }
    scanf("%d", &num);
    for(int i=19; i>=0; i--) {
        if(num>=pangkattiga[i]) {
            hasil[n++]=pangkattiga[i];
            num-=pangkattiga[i];
        }
    }
    printf("%d\n", n);
    for(int i=n-1; i>=0; i--) printf("%d ", hasil[i]);
    printf("\n");
    return 0;
}
