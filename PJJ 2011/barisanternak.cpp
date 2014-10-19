#include <cstdio>

int nhewan,ntanya;
int hewan[100000];

int bsearch(int a, int b, int num) {
    int mid=(a+b)/2;
    if(num > hewan[mid-1] and num <=hewan[mid]) return mid;
    if(hewan[mid]<num) return bsearch(mid+1,b,num);
    return bsearch(a,mid-1,num);
}

int main() {
    scanf("%d", &nhewan);
    for(int i=1; i<=nhewan; i++) {
        scanf("%d", &hewan[i]);
        if(i>1) hewan[i]=hewan[i-1]+hewan[i];
    }
    scanf("%d", &ntanya);
    for(int i=0; i<ntanya; i++) {
        int num;
        scanf("%d", &num);
        int lokasi=bsearch(1,nhewan,num);
        printf("%d\n", lokasi);
    }
    return 0;
}
