li=1;ri=n;
    for(int i=1;i<=tail;i++){
        if(ans[i]==1) b[i]=a[ri--];
        else b[i]=a[li++];
    }
    for(int i=tail;i>=1;i--){
        if(a[li]==b[i]){li++;ans[2*tail-i+1]=-1;}
        else{ri--;ans[2*tail-i+1]=1;} 
    }