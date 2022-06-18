#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20100
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

bitset<20100> bit[N],b0,b1,b2,b3;
char s[N];
int n,m;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        b0.reset();b1.reset();b2.reset();b3.reset();
        scanf("%s",s+1);
        for(int j=1;j<=n;j++){
            if(s[j]=='0') b0[j]=1;
            else if(s[j]=='1') b1[j]=1;
            else if(s[j]=='2') b2[j]=1;
            else if(s[j]=='3') b3[j]=1;
        }
        for(int j=1;j<=n;j++){
            if(s[j]=='0') continue;
            else if(s[j]=='1') bit[j]=bit[j]^(b2|b3);
            else if(s[j]=='2') bit[j]=bit[j]^(b1|b3);
            else if(s[j]=='3') bit[j]=bit[j]^(b1|b2|b3);
            bit[j][j]=0;
        }
    }
    int Ans=0;
    for(int j=1;j<=n;j++){
        Ans+=bit[j].count();
    }
    assert(Ans%2==0);
    Ans/=2;
    printf("%d\n",Ans);
    return 0;
}