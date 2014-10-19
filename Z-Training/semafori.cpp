#include <cstdio>
int time,n,dist,total,pos[200],red[200],grn[200];
int main(){
    scanf("%d%d", &n, &total);
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &pos[i],&red[i],&grn[i]);
    }
    int dist=0;
    for(int i=0; i<n; i++){
        if(i!=0) dist+=(pos[i]-pos[i-1]);
        else dist+=pos[i];
        if(dist%(red[i]+grn[i])<red[i]) dist+=red[i]-(dist%(red[i]+grn[i]));
        if(i==n-1) dist+=(total-pos[i]);
    }
    printf("%d\n", dist);
    scanf("\n");
    return 0; 
}
