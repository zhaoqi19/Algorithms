class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] == target) {
                return true;
            }

            // right part is ordered
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            } 
            else if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            } 
            else {
                if (nums[left] == nums[mid]) {
                    left++;
                } 
                if (nums[right] == nums[mid]) {
                    right--;
                }
            }
        }

        return false;
    }
};