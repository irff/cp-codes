#include <cstdio>

int a[20000];
int main(){
    for(int i=1; i<=10000; i++){
        int next=i,n=i;
        while(n>0){
            next+=n%10;
            n/=10;
        }
        if(next<=10000) a[next]=1;
    }
    for(int i=1; i<=10000; i++){
        if(a[i]==0) printf("%d\n", i);
    }

}
