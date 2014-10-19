#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[110000],stone,cost;
pair<int,int> x[110000];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]); x[i].first=a[i],x[i].second=i;
    }
    sort(x,x+n);
	// Destroying
    while(stone<n-1){
        int c=x[stone].second,ki=c-1,ka=c+1;
        while(ki>=0 and a[ki]==-1) ki--;
        while(ka<n and a[ka]==-1) ka++;
        if(ki>=0 and (ka>=n or a[ki]<=a[ka])) cost+=a[ki];
        else cost+=a[ka];
        a[c]=-1,stone++;
    }
    printf("%d\n", cost);
    return 0;
}
