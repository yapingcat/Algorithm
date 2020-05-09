////leetcode 27题 移除元素


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0] == val ? 0 : 1;
        
        int newloc = 0;
        int num = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != val)
            {
                nums[newloc] = nums[i];
                newloc++;
                num++;
            }
        }
        return num;
    }
};