#include <cstdio>
#include <algorithm>
using namespace std;

int t[100000];
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int ha,ma,sa,hb,mb,sb;
        scanf("%d:%d:%d %d:%d:%d", &ha,&ma,&sa,&hb,&mb,&sb);
        int start=ha*3600+ma*60+sa;
        int stop=hb*3600+mb*60+sb;
        for(int i=start; i<=stop; i++) t[i]++;
    }
    int maks=0;
    for(int i=0; i<86500; i++) maks=max(maks,t[i]);
    printf("%d\n", maks);
}
