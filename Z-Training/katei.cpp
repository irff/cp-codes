#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int main(){
    int mins=2000111222;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if((n/i)*i==n) {
          mins=min(2*((n/i)+i),mins);
        }
    }
    printf("%d\n", mins);
    scanf("\n");
    return 0;
}
