#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

stack<int>a;
int basis,angka;
int main(){
    
    scanf("%d%d", &angka, &basis);
    
    while(angka!=0){
        a.push(angka%basis);
        angka/=basis;
    }
    
    while(!a.empty()){
        printf("%d",a.top());
        a.pop();
    }
    printf("\n");
    
}
