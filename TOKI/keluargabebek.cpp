#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
deque<long>bebek;
long teskes,toler,num,keluarga;
int main(){
    keluarga=1;
    scanf("%ld%ld", &teskes, &toler);
    while(teskes--){
        scanf("%ld", &num);
        bebek.push_back(num);
    }
    for(int i=1; i<bebek.size(); i++){
        if(bebek[i]-bebek[i-1]>=toler)keluarga++;
    }
    printf("%ld\n", keluarga);
    return 0;
}
