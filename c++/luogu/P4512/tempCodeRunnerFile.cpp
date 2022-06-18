]=a[i];for(int i=0;i<lenb;i++) B[i]=b[i];
        m=1;while(m<(lenb+lena)) m<<=1;Gettr(m);
        NTT(A,lena,1);NTT(B,lenb,1);for(int i=0;i<len;i++) c[i]=f[i];for(int i=len;i<m;i++) c[i]=0;
        NTT(c,len,1);for(int i=0;i<m;i++) h[i]=((A[i]-1ll*B[i]*c[i]%mod)%mod+mod)%mod;
        for(int i=lenb;i<m;i++) h[