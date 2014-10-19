#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define ALL(v) v.begin(),v.end()
#define PII pair<int,int>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define x first
#define y second
int teskes,n,num;
vector<PII> co,ce;

void coerase(int loc){ co.erase(co.begin()+loc); }
void ceerase(int loc){ ce.erase(ce.begin()+loc); }

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        co.clear(); ce.clear();
        scanf("%d", &n);
        R(i,0,n) { scanf("%d", &num); co.push_back(PII(num,i)); }
        R(i,0,n) { scanf("%d", &num); ce.push_back(PII(num,i)); }
        sort(ALL(co)); sort(ALL(ce));
        //R(i,0,n) printf("%d %d\n", co[i].x, co[i].y);
        R(i,0,n){
            int coma,cema; coma=cema=co.size()-1;
            while(coma && co[coma-1].x==co[coma].x) coma--;
            while(cema && ce[cema-1].x==ce[cema].x) cema--;
            //printf("%d %d\n", coma,cema);
            int kika=abs(co[0].x-ce[cema].x); kika*=kika;
            int kaki=abs(ce[0].x-co[coma].x); kaki*=kaki;
            
            if(kika > kaki or (kika==kaki and co[0].y < co[coma].y) or(kika==kaki and co[0].y==co[coma].y and ce[cema].y <= ce[0].y) ){ // comin x cemax
                printf("%d %d %d\n", co[0].y, ce[cema].y, kika);
                coerase(0); ceerase(cema);
            }
            else {
                 //if(kika < kaki or(kika==kaki and co[0].y > co[coma].y) or (kika==kaki and co[0].y==co[coma].y and ce[cema].y > ce[0].y) ){ // cemax comin
                printf("%d %d %d\n", co[coma].y, ce[0].y, kaki);
                coerase(coma); ceerase(0);
            }
        }
        printf("\n");
    }
    return 0;
}
