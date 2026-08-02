class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        // ans=0;
        int left=0;
        int right=n-1;
        int sum=0;
        while(left<right) {
            int area=min(height[left],height[right])*(right-left);
            sum=max(sum,area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return sum;
    }
};