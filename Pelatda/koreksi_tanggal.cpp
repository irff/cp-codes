#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <string>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

const int INF = 2000111222;
typedef long long LLD;

int teskes, len = 0, mincost = INF;
char s[100];
int moonlength[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int moonchar[12], tanggal = 1, winning = 0;
char bulan[100][100], now[100];
int m[40][40];
void generate() {
strcpy(bulan[0],"JANUARY");
strcpy(bulan[1],"FEBRUARY");
strcpy(bulan[2],"MARCH");
strcpy(bulan[3],"APRIL");
strcpy(bulan[4],"MAY");
strcpy(bulan[5],"JUNE");
strcpy(bulan[6],"JULY");
strcpy(bulan[7],"AUGUST");
strcpy(bulan[8],"SEPTEMBER");
strcpy(bulan[9],"OCTOBER");
strcpy(bulan[10],"NOVEMBER");
strcpy(bulan[11],"DECEMBER");
R(i,0,12) moonchar[i] = strlen(bulan[i]);
//R(i,0,12) printf("%s %d\n", bulan[i], moonchar[i]);
}

void graph() {
R(i,0,40) R(j,0,40) if(i==j) m[i][j] = 0; else m[i][j] = 200;
m[1][2]=1;
m[2][1]=1;
m[2][3]=1;
m[3][2]=1;
m[3][4]=1;
m[4][3]=1;
m[4][5]=1;
m[5][4]=1;
m[5][6]=1;
m[6][5]=1;
m[6][7]=1;
m[7][6]=1;
m[7][8]=1;
m[8][7]=1;
m[8][9]=1;
m[9][8]=1;
m[9][0]=1;
m[0][9]=1;
m[26][1]=1;
m[1][26]=1;
m[26][2]=1;
m[2][26]=1;
m[32][2]=1;
m[2][32]=1;
m[32][3]=1;
m[3][32]=1;
m[14][3]=1;
m[3][14]=1;
m[14][4]=1;
m[4][14]=1;
m[27][4]=1;
m[4][27]=1;
m[27][5]=1;
m[5][27]=1;
m[29][5]=1;
m[5][29]=1;
m[29][6]=1;
m[6][29]=1;
m[34][6]=1;
m[6][34]=1;
m[34][7]=1;
m[7][34]=1;
m[30][7]=1;
m[7][30]=1;
m[30][8]=1;
m[8][30]=1;
m[18][8]=1;
m[8][18]=1;
m[18][9]=1;
m[9][18]=1;
m[24][9]=1;
m[9][24]=1;
m[24][0]=1;
m[0][24]=1;
m[25][0]=1;
m[0][25]=1;
m[26][32]=1;
m[32][26]=1;
m[32][14]=1;
m[14][32]=1;
m[14][27]=1;
m[27][14]=1;
m[27][29]=1;
m[29][27]=1;
m[29][34]=1;
m[34][29]=1;
m[34][30]=1;
m[30][34]=1;
m[30][18]=1;
m[18][30]=1;
m[18][24]=1;
m[24][18]=1;
m[24][25]=1;
m[25][24]=1;
m[10][26]=1;
m[26][10]=1;
m[10][32]=1;
m[32][10]=1;
m[28][32]=1;
m[32][28]=1;
m[28][14]=1;
m[14][28]=1;
m[13][14]=1;
m[14][13]=1;
m[13][27]=1;
m[27][13]=1;
m[15][27]=1;
m[27][15]=1;
m[15][29]=1;
m[29][15]=1;
m[16][29]=1;
m[29][16]=1;
m[16][34]=1;
m[34][16]=1;
m[17][34]=1;
m[34][17]=1;
m[17][30]=1;
m[30][17]=1;
m[19][30]=1;
m[30][19]=1;
m[19][18]=1;
m[18][19]=1;
m[20][18]=1;
m[18][20]=1;
m[20][24]=1;
m[24][20]=1;
m[21][24]=1;
m[24][21]=1;
m[21][25]=1;
m[25][21]=1;
m[10][28]=1;
m[28][10]=1;
m[28][13]=1;
m[13][28]=1;
m[13][15]=1;
m[15][13]=1;
m[15][16]=1;
m[16][15]=1;
m[16][17]=1;
m[17][16]=1;
m[17][19]=1;
m[19][17]=1;
m[19][20]=1;
m[20][19]=1;
m[20][21]=1;
m[21][20]=1;
m[35][10]=1;
m[10][35]=1;
m[35][28]=1;
m[28][35]=1;
m[33][28]=1;
m[28][33]=1;
m[33][13]=1;
m[13][33]=1;
m[12][13]=1;
m[13][12]=1;
m[12][15]=1;
m[15][12]=1;
m[31][15]=1;
m[15][31]=1;
m[31][16]=1;
m[16][31]=1;
m[11][16]=1;
m[16][11]=1;
m[11][17]=1;
m[17][11]=1;
m[23][17]=1;
m[17][23]=1;
m[23][19]=1;
m[19][23]=1;
m[22][19]=1;
m[19][22]=1;
m[22][20]=1;
m[20][22]=1;
m[35][33]=1;
m[33][35]=1;
m[33][12]=1;
m[12][33]=1;
m[12][31]=1;
m[31][12]=1;
m[31][11]=1;
m[11][31]=1;
m[11][23]=1;
m[23][11]=1;
m[23][22]=1;
m[22][23]=1;

m[33][36]=3;
m[36][33]=3;

m[12][36]=3;
m[36][12]=3;

m[31][36]=3;
m[36][31]=3;

m[11][36]=3;
m[36][11]=3;

m[23][36]=3;
m[36][23]=3;

m[22][36]=3;
m[36][22]=3;
}

void floyd() {
R(k,0,37)
R(i,0,37)
R(j,0,37)
m[i][j] = min(m[i][j], m[i][k]+m[k][j]);
}
int getdist(char a, char b) {
if(a==' ') a = 36;
else if(a>='A' and a<='Z') a=a-'A'+10;
else a-='0';

if(b==' ') b = 36;
else if(b>='A' and b<='Z') b=b-'A'+10;
else b-='0';
return m[a][b];
}
int main() {
generate();
graph();
/*
R(i,0,10) R(j,0,10) printf("%d%c", m[i][j],j==9?'\n':' ');
printf("\n\n");
*/
floyd();

printf(" ");
R(i,0,10) printf("%d ", i);
R(i,0,26) printf("%c ", i+'a');
printf("\n");
R(i,0,37) {
if(i<10) printf("%d ", i);
if(i>=10)printf("%c ", i-10+'a');
R(j,0,37) printf("%d%c", m[i][j],j==36?'\n':' ');
}


scanf("%d", &teskes);
gets(s);
R(t,0,teskes) {
memset(s, 0, sizeof s);
gets(s);
len = strlen(s);
R(i,0,len) if(s[i] >= 'a' and s[i] <='z') s[i]=s[i]-'a'+'A';
mincost = INF;
tanggal = 1;
winning = 0;
R(i,0,12) {
int leni = moonchar[i];
if(len==leni+2) {

memset(now, 0, sizeof now);
strcpy(now,bulan[i]);
now[leni]=' ';

int cost = 0, tgl=1, mintgl = INF;

R(j,0,leni+1) cost+=getdist(s[j],now[j]);

R(j,1,10) {
int distnow = getdist(j+'0',s[len-1]);
if(mintgl > distnow) tgl=j, mintgl = distnow;
}

if(mincost > cost+mintgl) {

mincost = cost+mintgl;
//printf("down %s%d\n%d\n", now,tgl, mincost);
tanggal = tgl;
winning = i;
}
} else
if(len==leni+3) {
memset(now, 0, sizeof now);
strcpy(now, bulan[i]);
now[leni]=' ';
int cost = 0, tgl = 1, mintgl = INF;

R(j,0,leni+1) cost+=getdist(s[j],now[j]);

R(j,10,moonlength[i]+1) {
int distnow = getdist( (j/10)+'0', s[len-2] );
distnow+= getdist( (j%10)+'0', s[len-1]);
if(mintgl > distnow) tgl = j, mintgl = distnow;
}
if(mincost > cost+mintgl) {
mincost = cost+mintgl;

//printf("down %s%d\n%d\n", now,tgl, mincost);
tanggal = tgl;
winning = i;
}
}
}
printf("%c", bulan[winning][0]);
R(i,1,moonchar[winning]) printf("%c", bulan[winning][i]-'A'+'a');
printf(" %d\n", tanggal);
//if(t!=teskes-1) printf("\n");
//printf("mincost = %d\n", mincost);
}
return 0;
}
