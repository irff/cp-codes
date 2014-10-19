#include <cstdio>

int a[1001],n,num,maks=-1,modus;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        a[num]++;
    }
    for(int i=1; i<=1000; i++){
        if(a[i]>=maks){
            maks=a[i];
            modus=i;
        }
    }
    printf("%d\n", modus);
    scanf("\n");
    return 0;
}
