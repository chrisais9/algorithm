#include <cstdio>

char input1[60][60], input2[60][60];
bool map1[60][60], map2[60][60];
int tn1, tm1, tn2, tm2, res;

inline void swap(bool &a, bool &b)
{
    bool x=a;
    a=b, b=x;
}

inline int maxrect(bool input[][110], int n, int m)
{
    int i, j, res=0, S[110]={0,}, Ssize=0, p[110]={0,}, psize=0, up[110][110]={0,}, left[110]={0,}, right[110]={0,};
    
    for(i=1; i<=m; i++) for(j=1; j<=n; j++)
    {
        if(input[j][i]==false) up[j][i]=0;
        else up[j][i]=up[j-1][i]+1;
    }
    
    for(j=1; j<=n; j++)
    {
        up[j][0]=up[j][m+1]=-1;
        for(i=1; i<=m+1; i++)
        {
            if(Ssize==0) {S[++Ssize]=up[j][i]; p[++psize]=i; }
            else if(S[Ssize]<=up[j][i]) {S[++Ssize]=up[j][i]; p[++psize]=i; }
            else
            {
                int k;
                while(!(Ssize==0 || S[Ssize]<=up[j][i]))
                {
                    k=p[psize]; S[Ssize--]=0; p[psize--]=0;
                    left[k]=i-k;
                }
                
                S[++Ssize]=up[j][i]; p[++psize]=i;
            }
        }
        
        for(i=m; i>=0; i--)
        {
            if(Ssize==0) {S[++Ssize]=up[j][i]; p[++psize]=i; }
            else if(S[Ssize]<=up[j][i]) {S[++Ssize]=up[j][i]; p[++psize]=i; }
            else
            {
                int k;
                while(!(Ssize==0 || S[Ssize]<=up[j][i]))
                {
                    k=p[psize]; S[Ssize--]=0; p[psize--]=0;
                    right[k]=k-i;
                }
                
                S[++Ssize]=up[j][i]; p[++psize]=i;
            }
        }
        
        for(i=1; i<=m; i++)
        {
            if(res<(left[i]+right[i]-1)*up[j][i]) res=(left[i]+right[i]-1)*up[j][i];
            left[i]=right[i]=0;
        }
        
        Ssize=psize=0;
    }
    
    return res;
}

void overlap(bool map1[][60], bool map2[][60], int pn, int pm, int qn, int qm, int rot1, int lr1, int ud1, int rot2, int lr2, int ud2)
{
    bool arr[110][110]={0,};
    int i, j, k, l;
    
    for(i=1; i<=rot1; i++)
    {
        bool t[60][60]={0,};
        for(j=1; j<=pn; j++) for(k=1; k<=pm; k++) t[k][pn-j+1]=map1[j][k], map1[j][k]=false;
        for(j=1; j<=pm; j++) for(k=1; k<=pn; k++) map1[j][k]=t[j][k];
        
        j=pn, pn=pm, pm=j;
    }
    for(i=1; i<=rot2; i++)
    {
        bool t[60][60]={0,};
        for(j=1; j<=qn; j++) for(k=1; k<=qm; k++) t[k][qn-j+1]=map2[j][k], map2[j][k]=false;
        for(j=1; j<=qm; j++) for(k=1; k<=qn; k++) map2[j][k]=t[j][k];
        
        j=qn, qn=qm, qm=j;
    }
    for(i=1; i<=lr1; i++) for(j=1; j<=pn; j++) for(k=1; k<=pm/2; k++) swap(map1[j][k], map1[j][(pm+1)-k]);
    for(i=1; i<=lr2; i++) for(j=1; j<=qn; j++) for(k=1; k<=qm/2; k++) swap(map2[j][k], map2[j][(qm+1)-k]);
    for(i=1; i<=ud1; i++) for(j=1; j<=pm; j++) for(k=1; k<=pn/2; k++) swap(map1[k][j], map1[(pn+1)-k][j]);
    for(i=1; i<=ud2; i++) for(j=1; j<=qm; j++) for(k=1; k<=qn/2; k++) swap(map2[k][j], map2[(qn+1)-k][j]);
    
    for(i=1; i<=pn+1; i++) for(j=1; j<=pm+1; j++)
    {
        for(k=1; k<=pn+qn; k++) for(l=1; l<=pm+qm; l++) arr[k][l]=false;
        for(k=1; k<=pn; k++) for(l=1; l<=pm; l++) arr[k][l]=map1[k][l];
        for(k=1; k<=qn; k++) for(l=1; l<=qm; l++)
            arr[i+k-1][j+l-1]|=map2[k][l];
        
        int val=maxrect(arr, pn+qn, pm+qm);
        if(res<val) res=val;
        
        for(k=1; k<=pn+qn; k++) for(l=1; l<=(pm+qm)/2; l++) swap(arr[k][l], arr[k][(pm+qm+1)-l]);
        
        val=maxrect(arr, pn+qn, pm+qm);
        if(res<val) res=val;
    }
}

int main()
{
    int i, j, k, p, q, r;
    
    scanf("%d %d", &tn1, &tm1);
    for(i=1; i<=tn1; i++)
    {
        scanf("%s", &input1[i][1]);
        for(j=1; j<=tm1; j++) map1[i][j]=input1[i][j]=='X';
    }
    
    scanf("%d %d", &tn2, &tm2);
    for(i=1; i<=tn2; i++)
    {
        scanf("%s", &input2[i][1]);
        for(j=1; j<=tm2; j++) map2[i][j]=input2[i][j]=='X';
    }
    
    for(i=0; i<4; i++) for(j=0; j<2; j++) for(k=0; k<2; k++) for(p=0; p<4; p++) for(q=0; q<2; q++) for(r=0; r<2; r++)
    {overlap(map1, map2, tn1, tm1, tn2, tm2, i, j, k, p, q, r); }
    
    for(i=0; i<4; i++) for(j=0; j<2; j++) for(k=0; k<2; k++) for(p=0; p<4; p++) for(q=0; q<2; q++) for(r=0; r<2; r++)
    {overlap(map2, map1, tn2, tm2, tn1, tm1, i, j, k, p, q, r); }
    
    printf("%d", res);
    
    return 0;
}

