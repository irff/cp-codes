#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef map<string,VI> MVI;

MVI m;
int teskes;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        m.clear();
        string sa,sb;
        int ca,cb;
        for(int i=0; i<16; i++){
            cin >> sa >> sb >> ca >> cb;
            m[sa].push_back(ca-cb);
            m[sb].push_back(cb-ca);
        }
        string win;
        for(MVI::iterator it=m.begin(); it!=m.end(); it++){
            if(it->second.size()==4){
                bool jadi=1;
                for(int i=0; i<4; i++){
                    if(it->second[i]<=0) jadi=0;
                }
                if(jadi) win=it->first;
            }
        }
        cout << win << endl;
    }
    return 0;
}
