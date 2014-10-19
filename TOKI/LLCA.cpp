#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,a,b) for(long i=long(a);i<long(b);i++)
#define VL vector<long>
VL v1;
VL v2;
long teskes,k,a,b;
long sama;
bool sudah;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        sama=1;
        sudah=0;
        v1.clear();
        v2.clear();
        scanf("%ld%ld%ld", &k,&a,&b);
        while(a!=1){
            v1.push_back(a);
            a=(a+k-2)/k;
        }
        v1.push_back(a);
        
        while(b!=1){
            v2.push_back(b);
            b=(b+k-2)/k;
        }
        v2.push_back(b);
        R(i,0,v1.size()){
            if(sudah) break; 
            else 
            R(j,0,v2.size()) 
                if(v1[i]==v2[j]) { sama=v1[i]; sudah=1; break; }
        }
        printf("%ld\n", sama);
        
    }
    return 0;
}
