#include <cstdio>
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(i==93){
            printf("ERROR"); break;
        }
        else if(i%10!=0) printf("%d\n", i);
    }
}
