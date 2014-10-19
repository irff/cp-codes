#include <cstdio>
#include <algorithm>
using namespace std;
bool ada[1000000];
int ngajah,gajah[5200];
long long hasil=0LL;
int main() {
    scanf("%d", &ngajah);
    for(int i=0; i<ngajah; i++) scanf("%d", &gajah[i]),ada[gajah[i]]=1;
    sort(gajah, gajah+ngajah);
    for(int i=0; i<ngajah; i++)
        for(int j=i+1; j<ngajah; j++)
            if(ada[ gajah[i]+gajah[j] ]) hasil++;
    printf("%lld\n", hasil);
    return 0;
}
