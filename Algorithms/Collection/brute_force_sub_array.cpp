#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b)? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h)
{

    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h)
{

   if (l == h)
     return arr[l];


   int m = (l + h)/2;


   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}

int main()
{
   int arr[] = {2, 3, -1, -3, 3};
   int max_sum = maxSubArraySum(arr, 0, 4);
   printf("Maximum subarray sum is %d\n", max_sum);
   return 0;
}
