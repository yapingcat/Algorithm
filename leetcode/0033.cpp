////leetcode 33题 搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
        {
            if(nums[0] == target) 
                return 0;
            else
                return -1;
        }
        auto j = nums.size() - 1;
        decltype(j) i = 0;
        int mid = 0;
        while(i < j)
        {
            mid = (i + j) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[j] ==  target)
                return j;
            if(nums[j] < target)
            {
                if(nums[mid] < target)
                {
                    if(nums[mid] < nums[j])
                      j  = mid;
                    else
                      i = mid + 1;
                }
                else
                {
                    j = mid;
                }
            }
            else
            {
                if(nums[mid] < target)
                {
                    i = mid + 1;
                }
                else 
                {
                    if(nums[mid] < nums[j])
                        j = mid;
                    else
                        i = mid + 1;
                }
            }
        }
        return -1;
    }
};