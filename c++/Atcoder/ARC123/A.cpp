#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

char s[N],t[N];
int n;
int len,cnt;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='C'){
            for(int j=1;j<=cnt/2;j++) t[++len]='A';
            if(cnt&1) t[++len]='B';
            cnt=0;
            t[++len]=s[i];
        }
        else{
            if(s[i]=='B') cnt++;
            else if(s[i]=='A') cnt+=2;
        }
    }
    for(int j=1;j<=cnt/2;j++) t[++len]='A';
    if(cnt&1) t[++len]='B';
    printf("%s",t+1);
    return 0;
}