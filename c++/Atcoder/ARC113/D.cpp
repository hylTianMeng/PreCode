#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int L,R,V,Ans;
const int num[]={0,0,1,3};

typedef pair<int,pair<int,int> > P;

inline int Solve(int a,int b,int val){
    if(a==0||b==0) return 0;
    if(val==0) return min(a,b);
    P now=make_pair(a,make_pair(b,val));
    static map<P,int> Map;
    if(Map.count(now)) return Map[now];
    for(int i=0;i<=1;i++){
        int j=(val%2)^i;
        (Map[now]+=Solve((a-i+1)/2,(b-j+1)/2,val/2))%=mod;
    }
    return Map[now];
}

inline int work(int a,int b,int val){
    int ans=0;
    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++){
            int c=(a+3-i)/4,d=(b+3-j)/4;
            int t=val^num[i]^num[j];
            if(i%2==0){
                if(j%2==0){if(t==0) ans=(ans+1ll*c*d%mod)%mod;}
                else if(t%4==0&&t/4<d) ans=(ans+c)%mod;
            }
            else{
                if(j%2==0){if(t%4==0&&t/4<c) ans=(ans+d)%mod;}
                else if(t%4==0) ans=(ans+Solve(c,d,t/4))%mod;
            }
        }
    return ans;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(L);read(R);read(V);R+=2;
    Ans=(work(L,L,V)-1ll*work(L,R,V)*2%mod+work(R,R,V))%mod;
    if(V==0) (Ans-=(R-L)%mod)%=mod;
    printf("%lld\n",(1ll*Ans*(mod+1)/2 %mod+mod)%mod);
    return 0;
}