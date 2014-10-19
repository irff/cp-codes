#include <cstdio>

int main(){
    int a,b,c,next;
    scanf("%d%d%d", &a,&b,&c);
    while(a!=0 or b!=0 or c!=0){
        if(c-b==b-a) printf("AP %d\n", c+(c-b));
        else if(c/b==b/a) printf("GP %d\n", c*(c/b));
        scanf("%d%d%d", &a,&b,&c);
    }
}
