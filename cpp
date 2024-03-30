class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int count = 0;
        std::unordered_map<int, int> frequency;

        for (int right = 0; right < n; ++right) {
            if (frequency[nums[right]] == 0) {
                k--;
            }
            frequency[nums[right]]++;

            while (k < 0) {
                frequency[nums[left]]--;
                if (frequency[nums[left]] == 0) {
                    k++;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};
