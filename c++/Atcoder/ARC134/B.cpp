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

int n;
char s[N];
int c[26][N],t[26],minl;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        int k=s[i]-'a';
        c[k][++t[k]]=i;
    }
    int p=1;minl=n+1;
    for(int i=0;i<=25;i++){
        while(p<c[i][t[i]]){
            while(s[p]-'a'<=i&&p<=n) p++;
            while(c[i][t[i]]>=minl) t[i]--;
            if(p>c[i][t[i]]) break;
            swap(s[p],s[c[i][t[i]]]);minl=min(minl,c[i][t[i]]);
            t[i]--;p++;
        }
    }
    printf("%s",s+1);
    return 0;
}