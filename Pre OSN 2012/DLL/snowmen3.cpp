#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define fs first
#define ls second
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

typedef pair<int,int> PII;
priority_queue<greater<int>(),vector<PII> > q;
int n, uk[102000];
pair<int,int> x[102000];
int out[102000][5];
map<vector<int>, int> m;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &uk[i]);
    }
    sort(uk, uk+n);
    int ctr=0;
    x[ctr].first = 1;
    x[ctr].second = uk[0];
    R(i,1,n) {
        if(uk[i]==uk[i-1]) {
            x[ctr].first++;
        } else {
            ctr++;
            x[ctr].first=1;
            x[ctr].second=uk[i];
        }
    }
    ctr++;
    R(i,0,ctr) q.push(x[i]);
    int total = 0;
    ctr = 0;

    while(q.size() >= 3) {
        PII a=q.top(); q.pop(); PII b=q.top(); q.pop(); PII c=q.top(); q.pop();
        a.fs--; b.fs--; c.fs--;
        int tmp[3]; tmp[0]=a.ls; tmp[1]=b.ls; tmp[2]=c.ls;
        sort(tmp, tmp+3);
        vector<int> v; v.push_back(tmp[2]); v.push_back(tmp[1]); v.push_back(tmp[0]);
        m[v]++;
        if(a.fs) q.push(a);
        if(b.fs) q.push(b);
        if(c.fs) q.push(c);
        total++;
    }
    printf("%d\n", total);
    if(total!=0) {
        for(map< vector<int>,int>::iterator it=m.begin(); it!=m.end(); it++) {
            vector<int> v = it->first;
            
            R(j,0,it->second) printf("%d %d %d\n", v[0], v[1], v[2]);
        }
    }
    return 0;
}
