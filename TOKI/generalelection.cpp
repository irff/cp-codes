#include <cstdio>
using namespace std;

int teskes;
long vote[200][10];
long total[10];
long tmp;
long maks,winner;
int row,col;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        maks=-9999;
        scanf("%d%d", &col, &row);
        for(int i=0; i<row; i++){
            tmp=0;
            for(int j=0; j<col; j++) scanf("%d", &vote[i][j]);
        }
        for(int i=0; i<col; i++){
            tmp=0;
            for(int j=0; j<row; j++) tmp+=vote[j][i];
            total[i]=tmp;
            if(tmp>maks) { maks=tmp; winner=i+1; }
        }
        printf("%d\n", winner);
    }
    return 0;
}
