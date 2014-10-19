#include <cstdio>

int a[30000];
int main(){
    int j=0;
    while(scanf("%d", &a[j])>0){
        j++;
    }
    for(int i=j-1; i>=0; i--) printf("%d\n", a[i]);

    return 0;
}
