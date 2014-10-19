#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

pair<double,int> ratio[1000];
int n, v[1000], w[1000], karung, hasil=0;
int main() {
    scanf("%d%d", &n, &karung);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &v[i], &w[i]);     
        ratio[i].first  = (double)v[i]/w[i];
        ratio[i].second = i;
    }
    sort(ratio, ratio+n, greater< pair<double, int> >());
    
    for(int i=0; i<n; i++) {
        if(w[ ratio[i].second ] <= karung) {
            hasil+=v[ ratio[i].second ];
            karung-=w[ ratio[i].second ];
        }
    }
    
    printf("%d\n", hasil);
    return 0;
}
