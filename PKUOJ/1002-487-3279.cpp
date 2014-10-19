#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<char,int> m;
int n;
char s[1000];
vector<int> v;
map<vector<int>,int > me;
int main(){
    m['A']=m['B']=m['C']=2;
    m['D']=m['E']=m['F']=3;
    m['G']=m['H']=m['I']=4;
    m['J']=m['K']=m['L']=5;
    m['M']=m['N']=m['O']=6;
    m['P']=m['R']=m['S']=7;
    m['T']=m['U']=m['V']=8;
    m['W']=m['X']=m['Y']=9;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        v.clear();
        scanf("%s", &s);
        int len=strlen(s);
        for(int j=0; j<len; j++){
            if(s[j]>='A' and s[j]<='Z' and s[j]!='Q') v.push_back(m[ s[j] ]);
            else if( s[j]>='0' and s[j]<='9' ) v.push_back(s[j]-'0');
        }
        me[v]++;
    }
    for(map<vector<int>,int > ::iterator it=me.begin(); it!=me.end(); it++){
        vector<int> x=it->first;
        if(it->second!=1){
        for(int i=0; i<3; i++) printf("%d", x[i]);
        printf("-");
        for(int i=3; i<7; i++) printf("%d", x[i]);
        printf(" %d\n", it->second);
        }
        else printf("No duplicates\n");
    }

    return 0;
}
