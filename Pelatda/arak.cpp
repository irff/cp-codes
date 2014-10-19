#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> II;
queue<II> q;

int n, num, a[120000];
int main() {
    scanf("%d", &n);
    while(n!=0) {
        int dist = 0;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) {
            if(a[i]!=0)
            for(int j=i+1; j<n; j++) {
                if(a[i] > 0 and a[j] < 0) {
                    int mins = min(a[i],abs(a[j]));
                    if(a[i]==mins) {
                        a[j]+=a[i];
                        a[i]=0;
                        dist+=(abs(i-j)*mins);
                        break;
                    } else {
                        a[i]-=abs(a[j]); a[j]=0;
                        dist+=(abs(i-j)*mins);
                    }
                } else 
                if(a[i] < 0 and a[j] > 0) {
                    int mins = min(a[j], abs(a[i]));
                    if(abs(a[i])==mins) {
                        a[j]+=a[i];
                        a[i]=0;
                        dist+=(abs(i-j)*mins);
                        break;
                    } else {
                        a[i]+=abs(a[j]); a[j]=0;
                        dist+=(abs(i-j)*mins);
                    }
                }
            }
        }
        //for(int i=0; i<n; i++) printf("%d ", a[i]);
        printf("%d\n", dist);
        scanf("%d", &n);
    }
    return 0;
}
