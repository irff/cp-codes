#include <cstdio>
#include <cmath>
using namespace std;

int bar,kol;
double pro[1009];
bool sig[1009];
int main(){
    while(scanf("%d%d",&bar,&kol)>0){
        for(int i=0; i<1009; i++) pro[i]=0.000;
        for(int i=0; i<bar; i++){
            for(int j=0; j<kol; j++){
                int num;
                scanf("%d",&num);
                if(num==0) pro[j]=0.00;
                else if(num<0) pro[j]+=log10(-num),pro[j]*=-1;
                else pro[j]+=log10(num);
            }
        }
        
        int maks=0;
        double t=-99999999999.00;
        for(int i=0; i<kol; i++){
            if(pro[i]-t >= 0.000000000001) {
                maks=i;
                t=pro[i];
            }
        }
        printf("%d\n", maks);
    }
    return 0;
}
