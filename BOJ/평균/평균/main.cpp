#include <stdio.h>
#include <algorithm>
#define MAX 10010

int n;
__int64 dap = 0;
int data[MAX+1];
int* ptr[MAX+1][2];

void input()
{
    int i;
    FILE *fin = fopen("input.txt", "r");
    fscanf(fin, "%d", &n);
    for(i=1; i<=n; i++)
        fscanf(fin, "%d", &data[i]);
    fclose(fin);
    std::sort(data+1, data+n+1);
}

int search(int left, int right, int key)
{
    int mid;
    
    while(left <= right) {
        mid = (left + right) / 2;
        
        if(data[mid] == key)
            return mid;
        else if(data[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void proc()
{
    int i, j, p;
    
    for(i=1; i<=n; i++) {
        if(i > 1 && data[i] == data[i-1]) {
            ptr[i][0] = ptr[i-1][0];
            ptr[i][1] = ptr[i-1][1];
            continue;
        }
        
        ptr[i][0] = std::lower_bound(data+1, data+n+1, data[i]);
        ptr[i][1] = std::upper_bound(data+1, data+n+1, data[i]);
    }
    
    for(i=1; i<n; i++) {
        p = i+1;
        for(j=i+1; j<=n; j++) {
            if(((data[i]+data[j]) & 1) == 1)
                continue;
            
            while(data[p] < (data[i]+data[j])/2)
                p++;
            
            if(data[p] != (data[i]+data[j])/2)
                continue;
            
            //p = search(i, j, (data[i]+data[j])/2);
            //if(p == -1)
            //    continue;
            
            //p1 = std::lower_bound(data+1, data+n+1, data[p]);
            //p2 = std::upper_bound(data+1, data+n+1, data[p]);
            
            dap += (ptr[p][1] - ptr[p][0]);
        }
    }
}

void output()
{
    FILE *fout = fopen("output.txt", "w");
    fprintf(fout, "%I64d\n", dap);
    fclose(fout);
}

int main()
{
    input();
    proc();
    output();
    return 0;
}
