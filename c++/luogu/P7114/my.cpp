#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2088576
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int base=131;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int F[N][27],n,nowF,Cnt[27],CF,t;
ll Ans;
ull Pow[N],Hash,NowHash,Ha[N];
vector<int> v[N];
char s[N];

inline int GetHash(int l,int r){
    return Ha[r]-Ha[l-1]*Pow[r-l+1];
}

inline void Init(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++) Ha[i]=Ha[i-1]*base+s[i];
    for(int i=1;i<=n;i++){
        if(Cnt[s[i]-'a']&1) nowF--;else nowF++;Cnt[s[i]-'a']++;
        for(int j=0;j<=26;j++){F[i][j]=F[i-1][j];}
        for(int j=nowF;j<=26;j++) F[i][j]++;
    }
    for(int i=2;i<=n-1;i++){
        Hash=GetHash(1,i);v[i].push_back(i);
        for(int j=i+1;j+i-1<=n;j+=i){
            NowHash=GetHash(j,j+i-1);
            if(NowHash!=Hash) break;
            v[j+i-1].push_back(i);
        }
    }
    // assert(GetHash(1,3)==GetHash(4,6));
}

inline void Solve(){
    for(int i=0;i<=26;i++) Cnt[i]=0;
    for(int i=n;i>=3;i--){
        //s[i,n]=C
        if(Cnt[s[i]-'a']&1) CF--;
        else CF++;
        Cnt[s[i]-'a']++;
        // printf("i=%d\n",i);
        for(int j=0;j<(int)v[i-1].size();j++){
            int x=v[i-1][j];
            Ans+=F[x-1][CF];
            // printf("x=%d\n",x);
            // printf("Ans=%d\n",Ans);
        }
    }
}

int a[N];

inline void Init(){
    for(int i=1;i<=n;i++) read(a[i]);
}

inline void Print(){printf("%lld\n",Ans);}

inline void Clear(){
    for(int i=0;i<=26;i++) Cnt[i]=0;
    for(int i=1;i<=n;i++) v[i].clear();
    Ans=0;CF=nowF=0;
}

inline void PreWork(){
    Pow[0]=1;for(int i=1;i<=(1<<20);i++) Pow[i]=1ll*Pow[i-1]*base;
}

inline void Cancel(){
    int a,b;cin>>a>>b;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    // dd c1=clock();
    read(t);PreWork();
    while(t--){
        Init();
        Solve();Print();Clear();
    }
    // dd c2=clock();
    // printf("%lf\n",(c2-c1)/CLOCKS_PER_SEC);
    return 0;
}