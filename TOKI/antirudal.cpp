#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define PII pair<int,int>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

vector<PII> v,a;
int teskes,n,maks,num;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        v.clear(); a.clear();
        scanf("%d", &n);
        R(i,0,n) {
            scanf("%d", &num); a.push_back(PII(num,0));
        }
        R(i,0,n) {
            scanf("%d", &num); a[i].y=num;
        }
        sort(a.begin(),a.end());
        v.push_back(PII(a[0].x+2,a[0].y));
        R(i,1,n){
            bool ketemu=0;
            R(j,0,v.size()){
                if(v[j].x <= a[i].x and v[j].y <= a[i].y){
                    v[j].x+=2; ketemu=1;
                }
            }
            if(!ketemu) v.push_back(PII(a[i].x+2,a[i].y));
        }
        maks=v.size();
        printf("%d\n", maks);
    }
    return 0;
}
