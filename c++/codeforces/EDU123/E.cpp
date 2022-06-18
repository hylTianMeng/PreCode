#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int t,n,len;
char s[N];

inline int Solve(){
    int posi=0,cnt=1,cnt3=1;
    for(int i=1;i<=len;i++){
        if(s[i]=='D'){posi=i;cnt++;}
        if(s[i]=='R'&&posi==0) cnt3++;
        if(s[i]=='R'&&posi!=0){break;}
    }
    // printf("posi=%lld\n",posi);
    if(posi==0){
        return n*(n-1);
    }
    int S=0,Ans=0,cnt2=1;;
    for(int i=posi+1;i<=len;i++){
        if(s[i]=='R'){
            cnt2++;
            S+=n-cnt;
        }
        else{
            cnt++;
        }
    }
    S+=(n-cnt);
    int S2=S-cnt2*(n-cnt);
    S2+=(cnt3-1)*(n-1);
    return S2;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);
        scanf("%s",s+1);
        len=strlen(s+1);
        int Ans=0;
        Ans+=Solve();
        // printf("%lld\n",Ans);
        for(int i=1;i<=len;i++){
            if(s[i]=='D') s[i]='R';
            else if(s[i]=='R') s[i]='D';
        }
        Ans+=Solve();
        // printf("%lld\n",Ans);
        // printf("%lld\n",Ans);
        printf("%lld\n",n*n-Ans);
    }
    return 0;
}