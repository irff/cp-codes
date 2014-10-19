#include <cstdio>
int duit,pecahan[10]={1000,500,200,100,50,20,10,5,2,1};
int main(){
    scanf("%d", &duit);
    for(int i=0; i<10 and duit!=0; i++){
        if(duit/pecahan[i]) printf("%d %d\n", pecahan[i],duit/pecahan[i]);
        duit%=pecahan[i];
    } 
    return 0;
}
