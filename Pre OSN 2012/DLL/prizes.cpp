#include <cstdio>
#include <algorithm>
using namespace std;

long long n, sisa, dapet[100], beli[10];
pair<int,long long> prizes[10];
int main() {
    scanf("%I64d", &n);
    for(int i=0; i<n; i++) {
        scanf("%I64d", &dapet[i]);
    }
    for(int i=0; i<5; i++) {
        scanf("%I64d", &prizes[i].first);
        prizes[i].second = i;
    }
    sort(prizes, prizes+5);
    for(int i=0; i<n; i++) {
        sisa+=dapet[i];
        for(int j=4; j>=0; j--) {
            while(sisa >= prizes[j].first) {
                beli[prizes[j].second]+= sisa/prizes[j].first;
                sisa %= prizes[j].first;
            }
        }
    }
    for(int i=0; i<5; i++) printf("%I64d ", beli[i]);
    printf("\n");
    printf("%I64d\n", sisa);
    return 0;
}
