#include <cstdio>
#include <cmath>
#include <algorithm>

int a,b,k;
int main(){
    scanf("%d%d", &a, &b);
    int k=a+b;
    for(int i=(int)sqrt(k)+1; i>=3; i--){
        if(k/i*i==k and (k/i+k/i+i+i-4==a)){ 
            printf("%d %d\n", std::max(i,k/i), std::min(i,k/i));
            break;
        }
    }
    scanf("\n");
    return 0;
}
