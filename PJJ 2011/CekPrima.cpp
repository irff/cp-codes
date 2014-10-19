#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n)>0){
        bool prima=0;
        if(n>1){
            prima=1;
            for(int i=2; i*i<=n; i++){
                if(n%i==0) { prima=0; break;}
            }
        }
        printf("%s\n", prima?"YA":"TIDAK");
    }
    return 0;
}
