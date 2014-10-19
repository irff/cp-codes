#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[52000], meledak=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        if(i==0 and a[i] >=a[i+1] or i==n-1 and a[i] >= a[i-1] or a[i] >= a[i-1] and a[i] >= a[i+1]) {
            meledak++; 
            printf("%d\n", i+1);
        }
    }
    
    return 0;
}
