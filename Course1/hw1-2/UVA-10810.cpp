#include <cstdio>  
#include <cstring>  
  
const int N = 500005;   
int n, input[N], output[N];  
  
long long merge_sort(int left, int right, int* a, int* b) {  
    if (right - left == 1) return 0;  
  
    int mid = (left + right) / 2;  
    long long ans = merge_sort(left, mid, a, b) + merge_sort(mid, right, a, b);  
    int p = left, q = mid, c = left;  
    while (p < mid || q < right) {  
        if (q >= right || (p < mid &&  a[p] <= a[q])) 
            b[c++] = a[p++];  
        else {  
            ans += (mid-p);  
            b[c++] = a[q++];  
        }  
    }  
    for (int i = left; i < right; i++) 
        a[i] = b[i];  
    return ans;  
}  
  
int main() {  
    while (scanf("%d", &n) == 1 && n) {  
        for (int i = 0; i < n; i++) 
            scanf("%d", &input[i]);  
        printf("%lld\n", merge_sort(0, n, input, output));  
    }  
    return 0;  
}  