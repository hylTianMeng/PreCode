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

char s[N];
int l=1,r=0,n,ans,cnt,k;

int main(){
    scanf("%s",s+1);n=strlen(s+1);read(k);
    while(cnt<=k&&r+1<=n){
        if(s[r+1]=='.'){
            if(cnt==k) break;
            cnt++;
        }
        r++;
    }
    ans=max(ans,r-l+1);
    for(l=2;l<=n;l++){
        if(s[l-1]=='X') continue;
        cnt--;
        while(cnt<=k&&r+1<=n){
            if(s[r+1]=='.'){
                if(cnt==k) break;
                cnt++;
            }
            r++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}