#include<bits/stdc++.h>
#define LL long long
#define dv double
#define rg 
#define il inline
#define us unsigned
#define eps 1e-6
#define INF 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
#define tmid ((tr[k].l+tr[k].r)>>1)
#define nmid ((l+r)>>1)
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
#define x first
#define y second
#define KafuuChino return
#define HotoKokoa 0;
using namespace std;
il void Read(int &x){
  int f=1;x=0;char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+c-'0',c=getchar();
  }
  x*=f;
}
const int N=810,p=1e9+7;
int n,g[N][N],d[N],vis[N*N];
struct Edge {
  int to,nxt,w;
}e[N*N];
int hd[N],cn;
il void ade(int u,int v,int w){
  e[++cn].to=v,e[cn].w=w,e[cn].nxt=hd[u],hd[u]=cn;
}
int dep[N],f[10][N],mx[10][N];
void DFS(int u,int ff,int w){
  f[0][u]=ff,dep[u]=dep[ff]+1,mx[0][u]=w;
  for(rg int i=1;i<=9;i++){
    f[i][u]=f[i-1][f[i-1][u]];
    mx[i][u]=max(mx[i-1][u],mx[i-1][f[i-1][u]]);
  }
  for(rg int i=hd[u];i;i=e[i].nxt){
    int v=e[i].to;
    if(v!=ff)DFS(v,u,e[i].w);
  }
}
il int LCA(int u,int v){
  int res=0;
  if(dep[u]<dep[v])swap(u,v);
  for(rg int i=9;i>=0;i--){
    if(dep[f[i][u]]>=dep[v]){
      res=max(res,mx[i][u]),u=f[i][u];
    }
  }
  if(u==v)return res;
  for(rg int i=9;i>=0;i--){
    if(f[i][u]!=f[i][v]){
      res=max(res,max(mx[i][u],mx[i][v]));
      u=f[i][u],v=f[i][v];
    }
  }
  return max(res,max(mx[0][u],mx[0][v]));
}
int main(){
  freopen("my.in","r",stdin);
  freopen("std.out","w",stdout);
  Read(n);int m=n*(n-1)/2;
  for(rg int i=1,u,v,w;i<n;i++){
    Read(u),Read(v),Read(w),ade(u,v,w),ade(v,u,w);
    g[u][v]=g[v][u]=w,vis[w]=1;
  }
  for(rg int i=m;i;i--)vis[i]+=vis[i+1];
  DFS(1,0,0);
  vector<pair<int,pii > > b;
  for(rg int u=1;u<=n;u++){
    for(rg int v=1;v<u;v++){
      if(g[u][v])continue;
      b.pub(mkp(LCA(u,v),mkp(u,v)));
    }
  }
  sort(b.begin(),b.end(),greater<pair<int,pii > >());
  vector<int> fuck;int ans=1,cnt=0,pos=m;
  for(rg auto i:b){
    ans=1ll*ans*max(0,(m-i.x-vis[i.x+1])-cnt)%p;
    if(!ans)return puts("0"),0;
    cnt++;
    while(pos&&vis[pos]>vis[pos+1])pos--;
    fuck.pub(pos),pos--;
  }
  for(rg int i=0;i<b.size();i++){
    int u=b[i].y.x,v=b[i].y.y;
    g[u][v]=g[v][u]=fuck[i];
  }
  printf("%d\n",ans);
  for(rg int i=1;i<=n;i++){
    for(rg int j=1;j<=n;j++){
      printf("%d ",g[i][j]);
    }
    puts("");
  }
  return 0;
}
