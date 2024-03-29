#include <vector>
#include <iostream>

int trap(std::vector<int>& height) {
    int ans {};
    // two pointer
    int left {}, right = height.size() - 1;
    int leftMax {} ,rightMax {};
    while (left < right) {
        leftMax = std::max(leftMax, height[left]);
        rightMax = std::max(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        }
        else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;

}

int main() {
    // output 6
    std::vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap(height) << '\n';
    // output 9
    height = {4,2,0,3,2,5};
    std::cout << trap(height) << '\n';

    return 0;
}