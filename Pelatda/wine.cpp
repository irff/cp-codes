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
        while(!q.empty()) q.pop();
        int dist = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &num);
            if(i==1) q.push(II(num,i));
            else {
                int x = q.front().first, y = q.front().second;
                
                if(x * num < 0) {
                    int sel = abs(num);
                    while(sel!=0 and !q.empty()) {
                        int now=0;
                        x = q.front().first, y = q.front().second;
                        if(sel < abs(x)) {
                            if(x<0) q.front().first+=sel;
                            else q.front().first-=sel;
                            now=(abs(i-y)*sel);
                            sel=0;
                        } else {
                            q.pop();
                            now=(abs(i-y)*abs(x));
                            sel-=abs(x);
                        }
                        dist+=now;
                    }
                    if(sel!=0) {
                        if(num < 0) q.push(II(-sel,i));
                        else q.push(II(sel,i));
                    }
                } else
                if(num!=0) {
                    q.push(II(num,i));
                }
            }
        }
        printf("%d\n", dist);
        scanf("%d", &n);
    }
    return 0;
}
