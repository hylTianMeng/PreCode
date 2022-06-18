#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 10005
struct e
{
  int u,v,d;
};
vector<e> mp[N];
int n,m,C,I,T;
bool vis[N];
int dis[N];
void dij()
{
  priority_queue<pair<int,int> > qu;
  memset(vis,0,sizeof(vis));
  memset(dis,0x3f,sizeof(dis));
  dis[I]=0;
  qu.push(make_pair(0,I));
  while(qu.size())
  {
    int u=qu.top().second;
    qu.pop();
    if(vis[u])
      continue;
    vis[u]=1;
    for(auto i:mp[u])
      if(dis[i.v]>dis[u]+i.d)
      {
        dis[i.v]=dis[u]+i.d;
        qu.push(make_pair(-dis[i.v],i.v));
      }
  } 
}
double x[N];
int disfc[N];
void dij2()
{
  priority_queue<pair<double,int> > qu;
  memset(vis,0,sizeof(vis));
  memset(disfc,0x3f,sizeof(disfc));
  disfc[C]=0;
  qu.push(make_pair(0,C));
  while(qu.size())
  {
    int u=qu.top().second;
    qu.pop();
    if(vis[u])
      continue;
    vis[u]=1;
    for(auto i:mp[u])
    {
      if(dis[i.v]==0)
        continue;
      if(disfc[i.v]>disfc[u]+i.d)
      {
        disfc[i.v]=disfc[u]+i.d;
        x[i.v]=max(x[u],(1.0*disfc[i.v])/(1.0*dis[i.v]));
        qu.push(make_pair(-x[i.v],i.v));
      }
    }
  } 
}
int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1,u,v,w;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    mp[u].push_back((e){u,v,w});
    mp[v].push_back((e){v,u,w});
  }
  scanf("%d%d%d",&C,&I,&T);
  dij();
  dij2();
  if(!x[T])
  {
    printf("-1\n");
    return 0;
  }
  printf("%0.5lf",x[T]);
  return 0;
}