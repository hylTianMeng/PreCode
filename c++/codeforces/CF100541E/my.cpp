#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 50100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int Prime[N],tail,t,n,m;
bool NotPrime[N];

inline void GetPrimeTable(int n){
    NotPrime[1]=1;
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i;
        for(int j=1;j<=tail&&Prime[j]*i<=n;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
}

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

struct PrimeTable{
    int a[40];
    inline void Clear(){memset(a,0,sizeof(a));}
    inline PrimeTable operator + (const PrimeTable &b)const{
        PrimeTable c;c.Clear();
        for(int i=1;i<=tail;i++) c.a[i]=a[i]+b.a[i];
        return c;
    }
    inline int GetAns(int mod){
        int res=1;
        for(int i=1;i<=tail;i++){
            // if(a[i]<0) return -1;
            res=1ll*res*ksm(Prime[i],a[i],mod)%mod;
        }
        return res;
    }
    inline void Print(){
        // printf("*this=:\n");
        for(int i=1;i<=tail;i++){
            if(a[i]) printf("%d ^ %d\n",Prime[i],a[i]);
        }puts("");
    }
    inline PrimeTable operator * (const int &b)const{
        PrimeTable c;c.Clear();
        for(int i=1;i<=tail;i++) c.a[i]=a[i]*b;
        return c;
    }
};

struct Node{
    PrimeTable sum,lazy;
    int len;
    inline void Clear(){sum.Clear(),lazy.Clear();}
}p[N<<2];

#define ls k<<1
#define rs k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        p[k].sum=p[ls].sum+p[rs].sum;
        p[k].len=p[ls].len+p[rs].len;
    }
    inline void build(int l,int r,int k){
        if(l==r){p[k].Clear();p[k].len=1;return;}
        p[k].Clear();int mid=(l+r)>>1;
        build(l,mid,ls);build(mid+1,r,rs);
        PushUp(k);
    }
    inline void Build(){build(1,n,1);}
    inline void A(int k,PrimeTable x){
        p[k].sum=p[k].sum+(x*p[k].len);p[k].lazy=p[k].lazy+x;
    }
    inline void PushDown(int k){
        A(ls,p[k].lazy);A(rs,p[k].lazy);p[k].lazy.Clear();
    }
    inline void Ad(int k,int l,int r,int z,int y,PrimeTable x){
        if(l==z&&r==y){A(k,x);return;}
        int mid=(l+r)>>1;
        PushDown(k);
        if(y<=mid) Ad(ls,l,mid,z,y,x);
        else if(z>mid) Ad(rs,mid+1,r,z,y,x);
        else{Ad(ls,l,mid,z,mid,x);Ad(rs,mid+1,r,mid+1,y,x);}
        PushUp(k);
    }
    inline void Add(int l,int r,PrimeTable a){Ad(1,1,n,l,r,a);}
    inline PrimeTable As(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k].sum;
        int mid=(l+r)>>1;
        PushDown(k);
        if(y<=mid) return As(ls,l,mid,z,y);
        else if(z>mid) return As(rs,mid+1,r,z,y);
        else return As(ls,l,mid,z,mid)+As(rs,mid+1,r,mid+1,y);
    }
    inline int AskSum(int l,int r,int mod){
        PrimeTable ans=As(1,1,n,l,r);
        // printf("ans:\n");ans.Print();
        return ans.GetAns(mod);
    }
}st;

inline PrimeTable GetFactor(int x,int op){
    PrimeTable now;now.Clear();
    for(int i=1;i<=tail&&x>1;i++){
        while(x%Prime[i]==0){x/=Prime[i];now.a[i]++;} 
    }
    if(op==2) for(int i=1;i<=tail;i++) now.a[i]*=-1;
    // printf("Factor Get!\n");
    return now;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    GetPrimeTable(150);
    read(t);
    while(t--){
        // printf("t=%d\n",t);
        // memset(p,0,sizeof(p));
        read(n);read(m);st.Build();
        for(int i=1;i<=m;i++){
            // printf("i=%d\n",i);
            int op,l,r,val;read(op);read(l);read(r);read(val);
            // printf("op=%d l=%d r=%d val=%d\n",op,l,r,val);
            // printf("Began to enter\n");
            if(op==0){
                if(l<=r) printf("%lld\n",st.AskSum(l,r,val));
                else printf("%lld\n",(1ll*st.AskSum(l,n,val)*st.AskSum(1,r,val))%val);
            }
            else{
                // printf("Began Add\n");
                PrimeTable now=GetFactor(val,op);
                // now.Print();
                if(l<=r) st.Add(l,r,now);
                else{st.Add(l,n,now);st.Add(1,r,now);}
                // printf("End Adding\n");
            }
        }
    }
    return 0;
}