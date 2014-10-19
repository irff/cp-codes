#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,g;
vector<int> f;
int main(){
    scanf("%d%d", &a,&b);
    g=__gcd(a,b);
    for(int i=1; i*i<=g; i++){
        if(g%i==0){
            f.push_back(i);
            if(g/i != i) f.push_back(g/i);
        }
    }
    sort(f.begin(),f.end());
    int siz=f.size();
    for(int i=0; i<siz; i++){
        printf("%d %d %d\n", f[i],a/f[i],b/f[i]);
    }
    scanf("\n");
    return 0;
}
