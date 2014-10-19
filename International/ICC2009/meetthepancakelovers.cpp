#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;
typedef vector<PII> VII;

VII q;
int n, ke, now=-1;
PII person[10200],target;
bool muncul=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &person[i].x, &person[i].y);
    }
    scanf("%d", &ke);
    for(int i=0; i<n; i++) {
        
        if(!muncul) q.push_back(person[i]);
 
        if(person[i].y==ke) {
            target=person[i];
            sort(q.begin(),q.end(),greater<PII>());
            int ukuran=q.size();
            for(int j=0; j<ukuran; j++)
                if(q[j] == person[i]) {
                    now=j+1;
                    break;
                }
            muncul=1;
        } else if(muncul) {
            if(target < person[i]) now++;
        }
        
        printf("%d\n", now);
    }
    
    return 0;
}
