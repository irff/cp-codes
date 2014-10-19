#include <cstdio>

int n;
bool ketemu=0;

int rek(int n) {
    int result=n;
    while(n>=3) {
        result+=(n/3);
        n=n/3 + n%3;
    }
    return result;
}

int main() {
    scanf("%d", &n);
    int ki=0,ka=1000000000,mid=0;
    while(!ketemu) {
        mid=(ki+ka)/2;
        int tmp=rek(mid);
        if(tmp >= n and rek(mid-1) < n) {
            printf("%d\n", mid);
            ketemu=1;
        } else if(tmp < n) ki=mid+1;
        else ka=mid-1;
    }
    return 0;
}
