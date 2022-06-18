#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

int n,opr,x,y;

struct p {int x,y;double ang;}o,ori[4]; 
//ang 极角
 
set<p> S;
set<p>::iterator pre,suc;

inline bool operator < (p i,p j)
{return i.ang==j.ang?i.x<j.x:i.ang<j.ang;}

p operator - (p i,p j) {return (p){i.x-j.x,i.y-j.y};}

ll cross(p i,p j) {return (ll)i.x*j.y-(ll)i.y*j.x;}

set<p>::iterator PRE(set<p>::iterator x)
{return x==S.begin()?--S.end():--x;}
//注意边界 

set<p>::iterator SUC(set<p>::iterator x)
{return (++x)==S.end()?S.begin():x;}

inline void insert(p x) {
    if(cross(x-*pre,*suc-x)<=0) return ; //在凸包内 解释看询问处 
    S.insert(x);
    set<p>::iterator cur=S.find(x),i=PRE(cur),j=PRE(i);
    //相当于P=cur=p A=i=s[top] B=j=s[top-1] 
    while(cross(*cur-*j,*i-*j)>=0) S.erase(i),i=j,j=PRE(j);
    //往极角小的地方修改 向量BP在向量BA上或右边 就删掉A 
    //下面同理 画个图就很清晰了 
    i=SUC(cur);j=SUC(i);
    while(cross(*cur-*j,*i-*j)<=0) S.erase(i),i=j,j=SUC(j);
}

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d",&n);
    for(  int i=1;i<=3;++i) { //先读入三个点定原点 
        scanf("%d %d %d",&opr,&ori[i].x,&ori[i].y);
        o.x+=ori[i].x;o.y+=ori[i].y;
        ori[i].x*=3;ori[i].y*=3; //注意精度处理 
    } for(  int i=1;i<=3;++i) {
        ori[i].ang=atan2(ori[i].y-o.y,ori[i].x-o.x); //求波极角 
        S.insert(ori[i]);
    } for(  int i=4;i<=n;++i) { //读入剩下的 
        scanf("%d %d %d",&opr,&x,&y);x*=3;y*=3;
        p P=(p){x,y,atan2(y-o.y,x-o.x)};
        if((suc=S.lower_bound(P))==S.end()) suc=S.begin();
        //找插入点后面的位置 
		//就是找到大于等于插入点的点在凸包上的位置
		//想象成指南针那样的会很好理解？ 最小的极角在x正半轴
		//最大的极角是逆时针绕一圈后也在x正半轴 
		//如果没有 说明插入点将是最大的 它的后面就设为开头 
        pre=PRE(suc);
        //找插入点前面的位置 
        if(opr==1) insert(P);
        else if(cross(P-*pre,*suc-P)<=0) printf("YES\n");
        //相当于 极角较小的点A[*pre] 和极角较大的点B[*suc]
		//他们之间有个点P 如果向量AP在向量PB上或者左边
		//P点就在凸包内 可以画图想想 
        else printf("NO\n");
    } return 0;
}