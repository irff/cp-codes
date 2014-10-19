#include <cstdio>

int main(){
    int teskes;
    scanf("%d", &teskes);
    for(int i=1; i<=teskes; i++){
        int r;
        scanf("%d", &r);
        printf("Case %d: %.2lf\n", i,(double)(16*r*r+1)/4);
    }
    
    return 0;
}
