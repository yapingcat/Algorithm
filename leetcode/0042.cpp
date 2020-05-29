/////leetcode 42. 接雨水

class Solution {
public:
    int trap(vector<int>& height) {
        
        int result = 0;
        for(int i = 0;i < height.size();)
        {
            int max2 = 0;
            int loc = i + 1;
            int j = i + 1;
            if(j == height.size()) break;
            for(;j < height.size();j++)
            {
                if(height[j] >= max2)
                {
                    loc = j;
                    max2 = height[j];
                }
                if(height[j] >= height[i])
                {   
                    break;
                }
            }
            if(j < height.size())
            {
                int area = (j - i - 1) * height[i];
                int sum = 0;
                for(int k = i + 1; k < j; k++)
                {
                    sum += height[k];
                }
                result += area - sum;
                i = j;
            }
            else
            {
                int area = (loc - i - 1) * height[loc];
                int sum = 0;
                for(int k = i + 1; k < loc; k++)
                {
                    sum += height[k];
                }
                result += area - sum;
                i = loc;
            }
        }
        return result;
    }
};