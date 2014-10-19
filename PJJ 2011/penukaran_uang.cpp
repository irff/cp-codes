#include <cstdio>

int n, a[10] = {1,2,5,10,20,50,100,200,500,1000};
int main() {
    scanf("%d", &n);
    for(int i=9; i>=0; i--) {
        int count = n/a[i];
        if(count >=1 ) n%=a[i],printf("%d %d\n", a[i], count);
    }
    return 0;
}
