#include<bits/stdc++.h>
#define fp(i,a,b) for( int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for( int i=a,I=b-1;i>I;--i)
#define go(u) for( int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sd(T&x){
    char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45)y=-1;x=c-48;
    while(c=gc(),47<c&&c<58)x=x*10+c-48;x*=y;
}
char sr[1<<21],z[20];int C=-1,Z;
inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
template<class T>inline void we(T x){
    if(C>1<<20)Ot();if(x<0)sr[++C]=45,x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
}
const int N=1e5+5,M=1e5;
typedef int arr[N];
typedef long long ll;
struct Juice{
    int d,p,l;
    inline void init(){sd(d),sd(p),sd(l);}
    inline bool operator<(const Juice b)const{return d<b.d;}
}a[N];
struct Pt{int l,r;ll s,w;}tr[N*20];
int n,m,pt;arr T;
void ins(int&p,int L,int R,int x,int s,ll w){
    tr[++pt]=tr[p],p=pt;tr[p].s+=s,tr[p].w+=w;
    if(L==R)return;int mid=(L+R)>>1;
    if(x<=mid)ins(tr[p].l,L,mid,x,s,w);
    else ins(tr[p].r,mid+1,R,x,s,w);
}
ll qry(int p,int L,int R,ll s){
    if(L==R)return s*L;int mid=(L+R)>>1;
    if(s<=tr[tr[p].l].s)return qry(tr[p].l,L,mid,s);
    return tr[tr[p].l].w+qry(tr[p].r,mid+1,R,s-tr[tr[p].l].s);
}
inline int sol(){
    ll G,Lim;sd(G),sd(Lim);
    if(Lim>G)return -1;
    int L=0,R=M,mid,tp=0;
    while(L<=R){
        mid=(L+R)>>1;
        if(Lim<=tr[T[mid]].s&&qry(T[mid],0,M,Lim)<=G)tp=mid,L=mid+1;
        else R=mid-1;
    }return a[tp].d;
}
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    sd(n),sd(m);a[0].d=-1;
    fp(i,1,n)a[i].init();
    sort(a+1,a+n+1);
    fd(i,n,1)ins(T[i]=T[i+1],0,M,a[i].p,a[i].l,(ll)a[i].p*a[i].l);
    T[0]=T[1];while(m--)we(sol());
return Ot(),0;
}