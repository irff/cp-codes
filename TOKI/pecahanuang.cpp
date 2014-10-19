#include <cstdio>
int uang,pecahan[10]={1,2,5,10,20,50,100,200,500,1000};
int main(){
    scanf("%d", &uang);
    for(int i=9; i>=0; i--){
        if( (uang/pecahan[i])>0 ){
            printf("%d %d\n", pecahan[i], uang/pecahan[i]);
            uang%=pecahan[i];
        }
    }
    return 0;
}
