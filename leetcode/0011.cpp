/////leetcode 第11题 盛最多水的容器


class Solution {
public:
    enum Direction
    {
        LEFT = 0,
        RIGHT,
    };
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        int pre = 0;
        int direction = -1;
        while( i < j)
        {
            if(direction == LEFT && pre >= height[i])
            {
                i++;
                continue;
            }
            if(direction == RIGHT && pre >= height[j])
            {
                j--;
                continue;
            }
            if(height[i] < height[j])
            {
                auto nowArea = height[i] * (j-i);
                if(nowArea > max)
                    max = nowArea;
                pre = height[i];
                i++;
                direction = LEFT;
            }
            else
            {
                auto nowArea =  height[j] * (j-i);
                if(nowArea > max)
                    max = nowArea;
                pre = height[j];
                j--;
                direction = RIGHT;
            }
        }
        return max;
    }
};