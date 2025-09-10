#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int crossSum(int nums[], int left, int mid, int right) {
    int leftSum = INT_MIN, sum = 0;

    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int helper(int nums[], int left, int right) {
    if (left == right)
        return nums[left];

    int mid = left + (right - left) / 2;

    int leftMax = helper(nums, left, mid);
    int rightMax = helper(nums, mid + 1, right);
    int crossMax = crossSum(nums, left, mid, right);

    return max3(leftMax, rightMax, crossMax);
}

int maxSubarraySum(int nums[], int n) {
    return helper(nums, 0, n - 1);
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int ans = maxSubarraySum(nums, n);
    printf("%d\n", ans);

    return 0;
}

