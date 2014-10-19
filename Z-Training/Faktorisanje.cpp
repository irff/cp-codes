#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAX=201000;

vector<int> prim;
bitset<201000> bs;
int teskes,num,n;
int main(){
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=MAX; i++){
        for(int j=i*i; j<=MAX; j+=i){
            bs[j]=0;
        }
    }
    for(int i=2; i<=MAX; i++) if(bs[i]) prim.push_back(i);
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &num);
        int id=0,PF=prim[id];
        while(num!=1 and PF*PF<=num){
            bool ada=0;
            int p=0,ex=0;
            while(num%PF==0){  ada=1; num/=PF; p++;}
            if(ada) printf("%d^%d", PF,p);
            if(ada and num!=1) printf("*");
            PF=prim[++id];
        }
        if(num!=1) printf("%d^1", num);
        puts("");
    
    }
    scanf("\n");
    return 0;
}
