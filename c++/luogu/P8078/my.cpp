

#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
// #define int long long
#define N 500010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}
void print(ll x)
{
	char P[105];int w=0;
    if(!x){putchar('0');return;}
	if(x<0) putchar('-'),x=-x;//特判负数 
	while(x) P[++w]=x%10+'0',x/=10;//分离各位 
	for(int i=w; i>=1; i--) putchar(P[i]);//逆序输出 
}

int n,m,a[N],Len,Posi[N],b[N];

struct Ques{
    int l,r,id;
}ques[N];
vector<int> q2[N];
ll ans[N];

inline ll Abs(int x){return (x<0)?-x:x;}

struct LinkList{
    int L[N],R[N];
    ll Ans;
    int Stack[N],top;
    bool vis[N];
    inline void Init(int l,int r){
        for(int i(1);i<=n;i++) L[i]=R[i]=vis[i]=0;Ans=0;top=0;
        for(int i(l);i<=r;i++){
            vis[a[i]]=1;
            // assert(i<=500000);
        }
        int last=0;
        for(int i(1);i<=n;i++){
            if(!vis[i]) continue;
            if(last) L[i]=last,R[last]=i,Ans+=Abs(b[last]-b[i]);
            last=i;
        }
    }
    inline void Del(int val){
        vis[val]=0,Stack[++top]=val;
        if(L[val]) Ans-=Abs(b[L[val]]-b[val]);
        if(R[val]) Ans-=Abs(b[R[val]]-b[val]);
        if(L[val]&&R[val]) Ans+=Abs(b[L[val]]-b[R[val]]);
        R[L[val]]=R[val],L[R[val]]=L[val];
    }
    inline void Rollonce(){
        int val=Stack[top--];vis[val]=1;
        R[L[val]]=L[R[val]]=val;
        if(L[val]&&R[val]) Ans-=Abs(b[R[val]]-b[L[val]]);
        if(R[val]) Ans+=Abs(b[R[val]]-b[val]);
        if(L[val]) Ans+=Abs(b[L[val]]-b[val]);
    }
    inline void RollBack(){
        for(;top;) Rollonce();
    }
}li;

inline bool cmp(int a,int b){
    // if(ques[a].r!=ques[b].r) return ques[a].r>ques[b].r;
    // return ques[a].l<ques[b].l;
    return (ques[a].r>ques[b].r)||(ques[a].r==ques[b].r&&ques[a].l<ques[b].l);
//	return (ques[a].l < ques[b].l)||(ques[a].l==ques[b].l&&ques[a].r>ques[b].r);
}

inline void Work2(){
    for(int i(1);i<=Posi[n];i++){
        int nowl=(i-1)*Len+1,nowr=n;
        li.Init(nowl,nowr);
        for(int j:q2[i]){
            int nl=nowl;
            while(ques[j].r<nowr&&nowr>=1) li.Del(a[nowr--]);
            li.top=0;
            while(nl<ques[j].l&&nl<=n) li.Del(a[nl++]);
            ans[ques[j].id]=li.Ans;
            li.RollBack();
        }
    }
}

signed main(){
    int maxx=-INF;
    n=read();m=read();for(int i=1;i<=n;i++) a[i]=read(),b[a[i]]=i,maxx=max(maxx,a[i]);
    Len=min((int)sqrt(maxx)+301,n);
//	Len = pow(maxx, 1.0 / 3);
//	Len = pow(maxx, 1.0/3); Len *= Len;
//	if(!Len) Len++;
//	Len = 1950;
    for(int i(1);i<=n;i++) Posi[i]=(i-1)/Len+1;
    for(int i(1);i<=m;i++){
        int l,r;l=read();r=read();ques[i].id=i;
        ques[i].l=l;ques[i].r=r;q2[Posi[l]].push_back(i);
    }
    for(int i(1);i<=n;i++) if(q2[i].size()) sort(q2[i].begin(),q2[i].end(),cmp);
    Work2();
    for(int i(1);i<=m;i++) print(ans[i]),puts("");
    return 0;
}