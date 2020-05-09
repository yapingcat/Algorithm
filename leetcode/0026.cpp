////leetcode 26题，删除排序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int pre = 0;
        int newloc = 1;
        int num = 1;
        for(int i = 1; i < nums.size(); i ++)
        {   
            if(nums[pre] != nums[i])
            {
                nums[newloc] =  nums[i];
                newloc ++;
                pre++;
                num++;
            }
        }
        return num;
    }
};