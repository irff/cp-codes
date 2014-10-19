#include <cstdio>
#include <algorithm>
using namespace std;

const int turun=-1,naik=1;

int N,a[1005];
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    int pre=a[0],state=turun,MAX=0;
    for(int i=1; i<=N; i++){
        if(a[i]>a[i-1]){
            state=naik;
        }
        else if(state==turun and a[i]<=a[i-1]){
            pre=a[i];
        }
        else if(state==naik and a[i]<=a[i-1]){
            MAX=max(a[i-1]-pre,MAX);
            pre=a[i];
            state=turun;
        }
    }
    printf("%d\n", MAX);
    return 0;
}
