#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,string> PIS;
PIS ans[200];
int teskes, now, target, n;
char dum[50], numa[50], numb[50];
string s;
int main() {
    scanf("%d", &teskes);
    for(int i=0; i<teskes; i++) {
        scanf("%d%d%d", &now, &target, &n);
        for(int j=0; j<n; j++) {
            s.clear();
            memset(dum, 0, sizeof dum);
            memset(numa, 0, sizeof numa);
            memset(numb, 0, sizeof numb);
            int a, b; scanf("%s", &dum);
            //printf("%s\n", dum);
            int len = strlen(dum);
            int state = 0, lena=0, lenb=0;
            for(int k=0; k<len; k++) {
                
                if(dum[k]==':') state=1;
                else if(dum[k]==',') state=2;
                else if(state==0) s.push_back(dum[k]);
                else if(state==1) numa[lena++]=dum[k];
                else if(state==2) numb[lenb++]=dum[k];
            }
            a = atoi(numa); b=atoi(numb);
            //printf("%s %s\n", numa, numb);
            //printf("%s %d %d\n", s[j], a, b);
            int x = now, cost = 0;
            while(x!=target) {
                if(x/2 >= target and b < (x-target)*a) {
                    cost+=b;
                    x/=2;
                } else {
                    cost+=(x-target)*a;
                    x=target;
                }
            }
            ans[j].first = cost; ans[j].second = s;
        }
        sort(ans,ans+n);
        printf("Case %d\n", i+1);
        for(int j=0; j<n; j++) printf("%s %d\n", ans[j].second.c_str(), ans[j].first);
    }
    return 0;
}
