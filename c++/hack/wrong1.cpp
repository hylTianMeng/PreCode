#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define N 100005
int n,m1,m2;
struct gns
{
  int a,b;
}gn[N];
struct gws
{
  int a,b;
}gw[N];
bool cmp_gn(gns a,gns b)
{
  return a.a<b.a;
}
bool cmp_gw(gws a,gws b)
{
  return a.a<b.a;
}
priority_queue<int> qu;
int check(int x)
{
  int ret=0;
  while(qu.size())
    qu.pop();
  int sy=x;
  for(int i=1;i<=m1;i++)
  {
    while(qu.size()&&gn[i].a>(-qu.top()))
      qu.pop(),sy++;
    if(sy)
    {
      sy--;
      qu.push(-gn[i].b);
      ret++;
    }
  }
  while(qu.size())
    qu.pop();
  sy=n-x;
  for(int i=1;i<=m2;i++)
  {
    while(qu.size()&&gw[i].a>(-qu.top()))
      qu.pop(),sy++;
    if(sy)
    {
      sy--;
      qu.push(-gw[i].b);
      ret++;
    }
  }
  return ret;
}
int main()
{
  freopen("airport.in","r",stdin);
  freopen("airport.out","w",stdout);  
  scanf("%d%d%d",&n,&m1,&m2);
  for(int i=1;i<=m1;i++)
    scanf("%d%d",&gn[i].a,&gn[i].b);
  for(int i=1;i<=m2;i++)
    scanf("%d%d",&gw[i].a,&gw[i].b);
  sort(gn+1,gn+1+m1,cmp_gn);
  sort(gw+1,gw+1+m2,cmp_gw);
  int l=0,r=n;
  while(l<r)
  {
    int midl=l+((r-l)/3);
    int midr=r-((r-l)/3);
    if(check(midl)<check(midr))
      l=midl+1;
    else
      r=midr-1;
  }
  printf("%d",check(r));
  return 0;
}

