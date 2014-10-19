#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    bool tes=0;
    for(int i=0; i<=20; i++){
        if(n==(1<<i)) tes=1;
    }
    printf("%s\n", tes?"TRUE":"FALSE");
    return 0;
}
