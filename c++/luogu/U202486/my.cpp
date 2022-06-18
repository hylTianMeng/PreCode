#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

int Begin,len,now;
bitset<(1<<24)> bit;
bool ans[24];
int nowans=-1,anslen=-1;
char c;

bitset<10> A;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    while(scanf("%c",&c)!=EOF&&(c=='1'||c=='0')){
        if(len<24) Begin=(Begin<<1)+c-'0';
        else now&=((1<<23)-1);
        now=(now<<1)+c-'0';
        len++;
        if(len>=24){
            bit[now]=1;
            // printf("now=%d\n",now);
        }
    }
    // printf("len=%d\n",len);
    // A>>=10000;
    bit[Begin]=1;
    len=min(len,24);
    for(int i=len;i>=1;i--){
        // printf("i=%d\n",i);
        bool op=0;
        for(int j=0;j<(1<<i);j++){
            if(!bit[j]){
                op=1;nowans=j;anslen=i;
                break;
            }
        }
        if(!op) break;
        Begin>>=1;
        bit|=(bit>>(1<<(i-1)));
        bit[Begin]=1;
        // for(int j=0;j<(1<<(i-1));j++){
        //     if(bit[j]){
        //         printf("%d ",j);
        //     }
        // }puts("");
    }
    int w=0;
    while(nowans){
        ans[w]=nowans&1;
        w++;nowans>>=1;
    }
    for(int i=anslen-1;i>=0;i--) printf("%d",ans[i]);
    return 0;
}