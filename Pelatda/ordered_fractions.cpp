/*
    ID: irfan1
    LANG: C++
    TASK: frac1
*/

#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> PII;
typedef map<PII,bool> MPB;
typedef pair<double,PII> DII;

DII ans[30000];

MPB m;
int n, ans_size=0;
int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    scanf("%d", &n);
    m[PII(0,1)]=1;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            int atas = i/(__gcd(i,j));
            int bawah = j/(__gcd(i,j));
            if(!m[PII(atas,bawah)]) m[PII(atas,bawah)]=1;
        }
    }
    for(MPB::iterator it=m.begin(); it!=m.end(); it++) {
        int atas = it->first.first, bawah = it->first.second;
        ans[ans_size].first = (double)atas/bawah;
        ans[ans_size].second = PII(atas,bawah);
        ans_size++;
        //printf("%d %d\n", it->first.first, it->first.second);
    }
    sort(ans,ans+ans_size);
    for(int i=0; i<ans_size; i++) {
        printf("%d/%d\n", ans[i].second.first, ans[i].second.second);
    }
    return 0;
}
