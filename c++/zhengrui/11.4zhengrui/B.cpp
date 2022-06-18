#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 26
#define M 100010
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

vector<int> v[N];
int n,m,k,f[M];
char s[M],t[M];

inline void Init(){
    read(n);read(m);read(k);
    scanf("%s %s",s+1,t+1);
}

inline int Calc(int s1,int s2,int t1,int t2){
    int lens=s2-s1+1,lent=t2-t1+1;
    fill(f+1,f+lent+1,0);f[0]=1;
    for(int j=0;j<=25;j++) vector<int>().swap(v[j]);
    for(int i=t2;i>=t1;i--) v[t[i]-'a'].push_back(i-t1+1);
    for(int i=s1;i<=s2;i++){
        for(int j:v[s[i]-'a']){
            f[j]=(f[j]+f[j-1])%mod;
        }
    }
    return f[lent];
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    int ans=Calc(1,n,1,m)%mod;
    // printf("%d\n",ans);
    if(m>k){return printf("%d\n",ans),0;}
    ans=(ans-Calc(n-k+2,n,1,m)+mod)%mod;
    for(int i=1;i<=n-k+1;i++){
        if(s[i]==t[1]) ans=(ans-Calc(i+1,i+k-1,2,m)+mod)%mod;
    }
    printf("%d\n",(ans+mod)%mod);
    return 0;
}