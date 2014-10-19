#include <cstdio>
#include <map>
using namespace std;

int n,g,gajah,num;
map<int,bool> lulus;
int main() {
    scanf("%d%d", &n, &g);
    for(int i=0; i<n; i++) scanf("%d", &num),lulus[num]=1;
    for(int i=0; i<g; i++) {
        scanf("%d", &gajah);
        if(lulus[gajah]) printf("%d\n", gajah);
    }
    return 0;
}
