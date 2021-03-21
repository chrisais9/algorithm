#include <iostream>
using namespace std;

char S[11111];
int L;
char Roman[10] = "mdclxvi";
int Roman_num[10] = {1000, 500, 100, 50, 10, 5, 1};

int search(int start, char key)
{
    int i;
    for(i=start;i<=L;i++)if(S[i] == key)return i;
    return 0;
}

int process(void)
{
    int ans = 0,end = 0,t1,t2,i,j;
    
    for(i=1;i<=L;i++)
    {
        if('m' == S[i])
        {
            end = i;
            ans += 1000;
        }
    }
    end++;
    for(i=1;i<=5;i+=2)
    {
        t1 = search( end, Roman[ i+1 ] );
        if( t1 )
        {
            t2 = search( t1 + 1, Roman[ i-1 ] );
            if( t2 )
            {
                ans += Roman_num[i-1] - Roman_num[i+1];
                end = t2 + 1;
                continue;
            }
        }
        t1 = search ( end, Roman[ i ] );
        if( t1 )
        {
            end = t1 + 1;
            ans += Roman_num[i];
            for(j=1;j<=3;j++)
            {
                t1 = search( end, Roman[i+1] );
                if( t1 )
                {
                    ans += Roman_num[i+1];
                    end = t1 + 1;
                }
                else break;
            }
            continue;
        }
        for(j=1;j<=3;j++)
        {
            t1 = search( end, Roman[i+1] );
            if( t1 )
            {
                ans += Roman_num[i+1];
                end = t1 + 1;
            }
            else break;
        }
    }
    return ans;
}

int main(void){
    int test_case;
    int i, j;
    char temp[11111];
    cin>>test_case;
    cin.ignore();
    while(test_case--)
    {
        cin.getline(temp+1,10010);
        L = 0;
        for(i=1;temp[i];i++)
        {
            for(j=0;j<=6;j++)
            {
                if(temp[i] == Roman[j])
                {
                    L++;
                    S[L] = Roman[j];
                    break;
                }
            }
        }
        cout<<process()<<endl;
    }
}
