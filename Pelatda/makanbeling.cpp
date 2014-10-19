#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>

using namespace std;

bool vis[200],udah[200],yep[200][200];
int n,m,a,b,ans;

void flood (int cur){
	vis[cur] =1;
	for (int i = 1; i <=n; i++) 
	  if (yep[cur][i] && !vis[i]) flood(i);
}

int cycle(int cur, int td,int byk){
	
	if (udah[cur]) return (byk);
	udah[cur] = 1;
	for (int i = 1; i <=n; i++)
	  if (yep[cur][i] && i!=td) return cycle(i,cur,byk+1);
	return 0;
}

int main(){
	memset(yep,0,sizeof(yep));
 scanf ("%d %d",&n,&m);
 for (int i = 0 ; i < m ; i++){
  scanf("%d %d",&a,&b);
  yep[a][b] = 1;
  yep[b][a] = 1;
 }
 ans = 0;
 memset(vis,0,sizeof(vis));
 for (int i = 1; i <=n; i++){
  if (!vis[i]){
    memset(udah,0,sizeof(udah));
    int tmp = cycle(i,0,1);
    if (tmp!= 0 && tmp%2 == 0) ans++;
    flood(i);
  }
 }
 if ((n-ans)%2 != 0) ans++;
 cout << ans << endl;
}