/*
    ID: irfan1
    LANG: C++
    TASK: sort3
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1200], lis[1200], swp=0;

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    for(int i=0; i<n; i++) {
        int mins = a[i], id=i+1;

        for(int j=i+1; j<n; j++) {
            if(mins >= a[j]) {
                mins = a[j]; id=j;
            }
        }

        if(a[i] > mins) {
            printf("--%d %d\n", a[i], a[id]);
            swap(a[i],a[id]),swp++;
            
            for(int j=0; j<n; j++) printf("%d ", a[j]);
            printf("\n");

        }
    }
    printf("%d\n", swp);
    return 0;
}
