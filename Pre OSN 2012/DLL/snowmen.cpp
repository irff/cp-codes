#include <cstdio>
#include <algorithm>
using namespace std;
#define fs first
#define ls last
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int n, uk[102000];
pair<int,int> x[102000];
int out[102000][5];
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
    sort(x, x+ctr);
    int a = ctr-3, b=ctr-2,c=ctr-1;
    int total = 0;
    ctr = 0;

    while( a>=0 and b>=0 and c>=0) {
        int mins = min(min(x[a].fs, x[b].fs), x[c].fs);
        
        int tmp[3]; tmp[0]=x[a].second; tmp[1]=x[b].second; tmp[2]=x[c].second;
        sort(tmp, tmp+3);
        out[ctr][0] = mins; out[ctr][1]=tmp[2]; out[ctr][2]=tmp[1]; out[ctr][3]=tmp[0];
        ctr++;
        
        total+=mins;
        
        x[a].fs -= mins; x[b].fs -= mins; x[c].fs -= mins;
        if(x[a].fs == 0 and x[b].fs == 0 and x[c].fs == 0) {
            c = a-1; b = a-2; a = a-3;
        } else
        if(x[a].fs == 0 and x[b].fs == 0 and x[c].fs > 0) {
            b = a-1; a = a-2;
        } else
        if(x[a].fs == 0 and x[b].fs > 0 and x[c].fs == 0) {
            c = b; b = a-1; a = a-2;
        } else 
        if(x[a].fs > 0 and x[b].fs == 0 and x[c].fs == 0) {
            c = a; b = a-1; a = a-2;
        } else
        if(x[a].fs == 0) {
            a = a-1;
        } else
        if(x[b].fs == 0) {
            b = a; a = a-1;
        } else
        if(x[c].fs == 0) {
            c = b; b = a; a = a-1;
        }
    }
    printf("%d\n", total);
    if(total!=0) {
        R(i,0,ctr) {
            R(j,0,out[i][0]) printf("%d %d %d\n", out[i][1], out[i][2], out[i][3]);
        }
    }
    return 0;
}
