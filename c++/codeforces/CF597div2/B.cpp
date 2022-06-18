#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 150
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

int t,n,a,b,c;
char s[N];
int cnt[4];
char ss[N];

int main(){
    read(t);
    while(t--){
        read(n);read(a);read(b);read(c);
        int ans=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) ss[i]=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='R'){
                if(b){b--;ss[i]='P';}else ans++;
            }
            else if(s[i]=='P'){
                if(c){c--;ss[i]='S';}else ans++;
            }
            else if(s[i]=='S'){
                if(a){a--;ss[i]='R';}else ans++;
            }
        }
        ans=n-ans;
        if(ans>=(n+1)/2){
            puts("YES");
            for(int i=1;i<=n;i++){
                if(ss[i]!='P'&&ss[i]!='S'&&ss[i]!='R'){
                    if(a){a--;ss[i]='R';}
                    else if(b){b--;ss[i]='P';}
                    else if(c){c--;ss[i]='S';}
                }
                putchar(ss[i]);
            }
            puts("");
        }
        else puts("NO");
    }
}