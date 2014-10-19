#include <cstdio>

int main(){
    int teskes,x,y;
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &x,&y);
        if(x==y){
            if(x%2==0) printf("%d\n", 2*x);
            else printf("%d\n", 2*x-1);
        } else if(x-y==2){
            if(x%2==0) printf("%d\n", 2*x-2);
            else printf("%d\n", 2*x-3);
        
        } else printf("No Number\n");
    }
    return 0;
}
