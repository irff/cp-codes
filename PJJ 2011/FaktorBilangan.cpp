#include <cstdio>

int n,a[1000],ctr;
int main(){
    scanf("%d", &n);
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            a[ctr]=i;
            ctr++;
            if(i*i!=n){
                a[ctr]=(n/i);
                ctr++;
            }
        }
    }
    for(int i=0; i<ctr; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    for(int i=0; i<ctr; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
