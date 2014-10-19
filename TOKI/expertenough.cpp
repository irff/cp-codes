#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#define PLL pair<long,long>
#define k1 first
#define k2 second
using namespace std;

vector<long> ada;
pair<string,PLL> mobil[10002];
int teskes, nmobil, npembeli;
long pembeli[10002];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        memset(pembeli,0,10002);
        scanf("%d", &nmobil);
        for(int i=0; i<nmobil; i++){
            cin >> mobil[i].k1 >> mobil[i].k2.k1 >> mobil[i].k2.k2;
            //cout << mobil[i].k1 << " " << mobil[i].k2.k1 << " " << mobil[i].k2.k2 << endl;
        }
        scanf("%d", &npembeli);
        for(int i=0; i<npembeli; i++){
            scanf("%d", &pembeli[i]);
        }
        for(int i=0; i<npembeli; i++){
            ada.clear();
            for(int j=0; j<nmobil; j++){
                if( (mobil[j].k2.k1 <= pembeli[i]) and (mobil[j].k2.k2 >= pembeli[i]) ){
                    ada.push_back(j);
                }
            }
            if( (ada.size() > 1) or (ada.size()==0) ) printf("UNDETERMINED\n");
            else printf("%s\n", mobil[ada[0]].k1.c_str());
        }
        if(teskes!=0)printf("\n");
    }
    
    return 0;
}
