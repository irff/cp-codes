#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> m;
int teskes,a,b;
int main(){
    int maks=-1,now=0;
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &a,&b);
        m[a]++; m[b+1]--;
    }
    for(map<int,int>::iterator it=m.begin(); it!=m.end(); it++){
        now+=it->second;
        maks=max(maks,now);
    }
    printf("%d\n", maks);
    scanf("\n");
    return 0;
}
