#include <stdio.h>

int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) {
        int cur = (height[left] < height[right] ? height[left] : height[right]) * (right - left);
        max = cur > max ? cur : max;

        if (height[left] <= height[right])
            left++;
        else
            right--;
    }

    return max;
}

void main()
{
    int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9));
}
