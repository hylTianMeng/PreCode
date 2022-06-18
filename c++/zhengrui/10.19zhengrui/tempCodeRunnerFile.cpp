head[k];x;x=li[x].next){
        int to=li[x].to;
        if(li[x].Color!=-1) continue;
        li[x].Color=c;li[x^1].Color=c;
        dfs(to,c^1);break;