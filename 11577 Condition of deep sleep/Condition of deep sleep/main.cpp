#include <stdio.h>
int mark[100000];
int N, K, S, res, cnt;
int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &S);
        mark[i] += mark[i-1];
        if(i <= N - K && S ^ (mark[i]%2)){
            mark[i]++;
            mark[i+K]--;
            cnt++;
        }
        if(S ^ (mark[i]%2)){
            res =1;
            break;
        }
    }
    if(res) printf("Insomnia\n");
    else printf("%d\n", cnt);
    return 0;
}
a
