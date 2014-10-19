#include <cstdio>
int n, sum=0;

void rek(int a, int b) {
    int mid = (a+b)/2;
    if(b == a) return ;
    
    if(b-a == 1) {
        sum += (a*b);
        return ;
    }
    
    rek(a,mid);
    rek(mid+1,b);
}

int main() {
    scanf("%d", &n);
    rek(1,n);
    printf("%d\n", sum);
    return 0;
}
