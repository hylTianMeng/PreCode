#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int t,n,m,k,q;

typedef pair<int,int> P;

P a[N];
bool v1[N],v2[N];
int c1=0,c2=0;

inline void Clear(){
    for(int i=1;i<=q;i++) v1[a[i].first]=0;
    for(int i=1;i<=q;i++) v2[a[i].second]=0;
    c1=0;c2=0;
}

int cnt=0;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(m);read(k);read(q);
        cnt=0;
        for(int i=1;i<=q;i++){
            read(a[i].first);read(a[i].second);
        }
        for(int i=q;i>=1;i--){
            if((!v1[a[i].first]||!v2[a[i].second])&&c1!=n&&c2!=m) cnt++;
            if(v1[a[i].first]!=1){
                c1++;
            }
            if(v2[a[i].second]!=1){
                c2++;
            }
            v1[a[i].first]=v2[a[i].second]=1;
        }
        printf("%d\n",ksm(k,cnt,mod));
        Clear();
    }
    return 0;
}