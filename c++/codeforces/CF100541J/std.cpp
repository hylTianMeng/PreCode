#include<cstdio>
const int inf=~0U>>2,N=250010;
int T,n,i,j,k,t,S,f[N][40],ans;
int w[3][4][2];
inline void up(int&a,int b){if(a<b)a=b;}
inline int idx(char x){
  if(x=='B')return 0;
  if(x=='G')return 1;
  if(x=='R')return 2;
  return 3;
}
inline void input(int o){
  static char s[20];
  scanf("%s",s);
  S=0;
  //puts(s);
  for(int i=0;i<4;i++){
    w[o][i][0]=idx(s[i*2]);
    w[o][i][1]=s[i*2+1]-'0';
    S+=s[i*2+1]-'0';
    //printf("%d=%c %c\n",i,s[i*2],s[i*2+1]);
  }
}
inline int cal(int S,int x,int o){
  if(o==0)return S-x;
  if(o==1)return S+x;
  if(o==2)return S*x;
  if(!x)return 0;
  return S/x;
}
int id[9][9][9][9];
int tot,g[40][4][4];
struct E{
  int a,b,c,d;
  E(){}
  E(int _a,int _b,int _c,int _d){a=_a,b=_b,c=_c,d=_d;}
}e[40];
inline int getid(int a,int b,int c,int d){
  if(a<0)return 0;
  if(b<0)return 0;
  if(c<0)return 0;
  if(d<0)return 0;
  return id[a][b][c][d];
}
void pre(){
  int A,B,C,D,i,j,k;
  for(A=0;A<=4;A++)for(B=0;B<=4;B++)for(C=0;C<=4;C++)for(D=0;D<=4;D++){
    if(A+B+C+D!=4)continue;
    e[++tot]=E(A,B,C,D);
    id[A][B][C][D]=tot;
    printf("ID[%d][%d][%d][%d]=%d\n",A,B,C,D,id[A][B][C][D]);
  }
  int q[5];
  for(i=1;i<=tot;i++){
    q[0]=e[i].a;
    q[1]=e[i].b;
    q[2]=e[i].c;
    q[3]=e[i].d;
    for(j=0;j<4;j++)if(q[j])for(k=0;k<4;k++){
      q[j]--;
      q[k]++;
      g[i][j][k]=getid(q[0],q[1],q[2],q[3]);
      q[j]++;
      q[k]--;
    }
  }
}
void init(){
  int q[5],i,j,k;
  for(i=0;i<4;i++)q[i]=0;
  for(i=0;i<4;i++)q[w[1][i][0]]++;
  up(f[1][id[q[0]][q[1]][q[2]][q[3]]],0);
}
int main(){
    // freopen("my.in","r",stdin);
    // freopen("std.out","w",stdout);
  pre();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    input(1);
    for(i=1;i<=n;i++)for(j=0;j<=tot;j++)f[i][j]=-inf;
    init();
    for(i=2;i<=n;i++){
      input(2);
      //printf("%d\n",S);
      //for(k=0;k<4;k++)printf("%d %d %d\n",i,k,cal(S,w[2][k][1],w[2][k][0]));
      for(j=1;j<=tot;j++){
        for(k=0;k<4;k++){
          for(t=0;t<4;t++){
            if(k!=w[2][t][0])continue;
            up(f[i][g[j][k][w[2][(t+2)%4][0]]],f[i-1][j]+cal(S,w[2][t][1],w[2][t][0]));
          }
        }
        up(f[i][j],f[i-1][j]-S);
      }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tot;j++){
            printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
    ans=-inf;
    for(i=1;i<=tot;i++)up(ans,f[n][i]);
    printf("%d\n",ans);
  }
  return 0;
}