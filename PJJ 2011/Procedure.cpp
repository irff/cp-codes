#include <cstdio>

int n;
int main(){
    while(scanf("%d", &n)>0){
        if(n<10) printf("satuan");
        else if(n<100) printf("puluhan");
        else if(n<1000) printf("ratusan");
        else if(n<10000) printf("ribuan");
        else if(n<100000) printf("puluhribuan");
        puts("");
    }
}
