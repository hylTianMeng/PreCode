#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

int Ans0=0,Ans1=0,n,sum;
char s[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        sum+=len;
        int cnt=0;char c=s[1];
        for(int j=1;j<=len;j++){
            if(s[j]!=s[j-1]) cnt++;
        }
        if(c=='1'){
            Ans0=Max(cnt+1,Ans0);
            Ans1=Max(cnt,Ans1);
        }
        else{
            Ans0=Max(cnt,Ans0);
            Ans1=Max(cnt+1,Ans1);
        }
    }
    printf("%d\n",sum-Min(Ans0,Ans1));
    return 0;
}