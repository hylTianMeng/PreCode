#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M number
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

char t[N],s[N];
int f[N][16],T,len,a[N];

inline int GetTrans(int p1,int p2,int p3){
    return t[p1+(p2<<1)+(p3<<2)]-'0';
}

inline int GetState(int p1,int p2){
    return 1<<((p1<<1)+p2);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(T);
    while(T--){
        scanf("%s%s",t,s+1);
        int n=strlen(s+1);
        memset(f,0,sizeof(f));
        f[0][9]=1;
        for(int i=2;i<n;i++)
            for(a[i-1]=0;a[i-1]<2;a[i-1]++)
                for(a[i]=0;a[i]<2;a[i]++){
                    if(s[i]!='?'&&a[i]!=s[i]-'0') continue;
                    if(s[i-1]!='?'&&a[i-1]!=s[i-1]-'0') continue;
                    for(int S=0;S<16;S++){
                        if(!f[i-2][S]) continue;
                        int SS=0;
                        for(int j=0;j<2;j++)
                            for(int k=0;k<2;k++){
                                bool pd=(S&GetState(GetTrans(a[i-1],a[i],j),k));
                                if(GetTrans(0,a[i],j)==k) pd|=(S&GetState(a[i-1],0));
                                if(GetTrans(1,a[i],j)==k) pd|=(S&GetState(a[i-1],1));
                                if(pd) SS|=GetState(j,k);
                            }
                        (f[i][SS]+=f[i-2][S])%=mod;
                    }
                }
        int ans=0;
        for(int S=0;S<16;S++){
            if(!f[n-1][S]) continue;
            for(int j=0;j<2;j++){
                if(s[n]!='?'&&s[n]!=j+'0') continue;
                if(S&GetState(j,1)) (ans+=f[n-1][S])%=mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}