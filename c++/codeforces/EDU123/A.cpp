#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3000
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

int t;

bool vis[N];

int main(){
    read(t);
    while(t--){
        string s;
        cin>>s;
        bool op=0;
        int len=s.length();
        for(int i=1;i<=300;i++) vis[i]=0;
        for(int i=0;i<len;i++){
            if('a'<=s[i]&&s[i]<='z'){
                vis[s[i]-'a'+'A']=1;
            }
            else{
                if(vis[s[i]]==1) continue;
                else{op=1;puts("NO");break;}
            }
        }
        if(!op){puts("YES");}
    }
    return 0;
}