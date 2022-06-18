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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n;
string s[N];


int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) cin>>s[i];
        bool op=0;
        for(int i=1;i<=n;i++){
            if(s[i].length()==1){op=1;break;}
            else if(s[i].length()==2&&s[i][0]==s[i][1]){op=1;break;}
            else if(s[i].length()==3&&s[i][0]==s[i][2]){op=1;break;}
        }
        // printf("op1=%d\n",op);
        if(op){puts("Yes");continue;}
        map<string,bool> Map;
        Map.clear();op=0;
        for(int i=1;i<=n;i++){
            string t;t.clear();
            if(s[i].length()==2){
                t+=s[i][1];t+=s[i][0];if(Map[t]){op=1;break;}
                for(char c='a';c<='z';c++){
                    string nowt=t+c;
                    if(Map[nowt]){op=1;break;}
                }
                if(op) break;
                t=s[i];Map[t]=1;
            }
            else{
                t+=s[i][2];t+=s[i][1];t+=s[i][0];if(Map[t]){op=1;break;}
                t.clear();t+=s[i][2];t+=s[i][1];if(Map[t]){op=1;break;}
                t=s[i];Map[t]=1;t.clear();
            }
        }
        // printf("op2=%d\n",op);
        if(op){
            puts("Yes");continue;
        }
        puts("No");
    }
}