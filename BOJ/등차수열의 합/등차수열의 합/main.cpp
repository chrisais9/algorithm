#include <cstdio>

int left, right, k;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d", &left, &right, &k);
    
    if(k%2==1)
    {
        int st=k*(k+1)/2, ed=right/k*k;
        if(st<left)
        {
            if(left%k==0) st=left;
            else st=(left/k+1)*k;
        }
        
        st/=k, ed/=k;
        if(st>ed) printf("0");
        else printf("%d", ed-st+1);
    }
    else
    {
        if(k==2)
        {
            int st=k*(k+1)/2;
            if(st<left) st=left;
            
            if(st>right) printf("0");
            else printf("%d", right-st+1);
        }
        else
        {
            int st=14, ed=right, v=0;
            if(left<=10 && 10<=right) v++;
            if(st<left) st=left;
            if(st%2==1) st++;
            if(ed%2==1) ed--;
            
            st/=2, ed/=2;
            if(st>ed) printf("%d", v);
            else printf("%d", ed-st+1+v);
        }
    }
    
    return 0;
}
