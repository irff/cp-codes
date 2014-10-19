#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(v,it) for(set<short>::iterator it=(v).begin();it!=(v).end();it++)
#define P2 pair<int,int>
#define PS pair<int,long long>
#define P4 pair<PS,P2>
set<short> s[200][200];
short mat[200][200],n,m,c;
P4 data[40000];
int main(){
    scanf("%d%d", &n,&m);
    R(i,0,n) R(j,0,n) scanf("%d", &mat[i][j]);
    R(i,0,n-m+1){
        R(j,0,n-m+1){
            int jum=0;
            R(k,i,i+m) R(l,j,j+m) s[i][j].insert(mat[k][l]);
            RV(s[i][j],it) jum+=*it;
            data[c++]=P4(PS(s[i][j].size(),0),P2(i,j));
            //printf("%d %d size: %d\n", i,j, s[i][j].size());
        }
    }
    sort(data,data+c);
    int x=0;
    while(x!=n-1 and data[x].first.first==data[x+1].first.first) x++;
    for(int i=0; i<=x; i++){
        long long num=0LL,ten=1LL;
        for(set<short>::iterator it=s[data[i].second.first][data[i].second.second].begin(); it!=s[data[i].second.first][data[i].second.second].end();it++){;
            num+= (*it * ten);
            ten*=10;
        }
        data[i].first.second=-num;
    }
    sort(data,data+x+1);
    printf("%d %d\n", data[0].second.first+1,data[0].second.second+1);

    return 0;
}
