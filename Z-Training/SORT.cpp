#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII; // frequency > index
typedef pair<PII,int> PIII; // freq, id, num
typedef map<int,PII> MIII;

MIII m;
vector<PIII> v;
int n,c,num;
int main(){
    scanf("%d%d", &n,&c);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(!m.count(num)){
            m[num].first=i;
            m[num].second++;
        } 
        else{
            m[num].second++;
        }
    }
    for(MIII::iterator it=m.begin(); it!=m.end(); it++){
        v.push_back(PIII(PII(-it->second.second,it->second.first),it->first));
    }
    sort(v.begin(),v.end());
    int vsiz=v.size();
    for(int i=0; i<vsiz; i++){
        for(int j=0; j<-v[i].first.first; j++) printf("%d ", v[i].second);
    }
    printf("\n");
    scanf("\n");
}
