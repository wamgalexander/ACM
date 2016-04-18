#include <cstdio>

int main()
{
    int n, max = 0, num[1001], LIS[1001];;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &num[i]);
        LIS[i] = 1;
        for (int j = 0 ; j < i ; ++j)
            if (num[i] > num[j] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;

        if (LIS[i] > max)
			max = LIS[i];
    }
    printf("%d\n", max);

	return 0;
}
