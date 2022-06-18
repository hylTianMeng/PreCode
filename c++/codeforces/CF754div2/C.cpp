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

int t,n;
char s[N];
bool op;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        op=1;
        read(n);scanf("%s",s+1);
        for(int i=1;i<=n-1&&op;i++){
            if(s[i]=='a'&&s[i+1]=='a'){puts("2");op=0;break;}
        }
        if(!op) continue;
        for(int i=1;i<=n-2&&op;i++){
            if(s[i]=='a'&&s[i+2]=='a'){puts("3");op=0;break;}
        }
        if(!op) continue;
        for(int i=1;i<=n-3&&op;i++){
            if(s[i]=='a'&&s[i+3]=='a'&&s[i+1]!=s[i+2]){puts("4");op=0;break;}
        }
        if(!op) continue;
        for(int i=1;i<=n-6&&op;i++){
            if(s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a'&&s[i+1]!=s[i+4]){puts("7");op=0;break;}
        }
        if(!op) continue;
        puts("-1");
    }
    return 0;
}