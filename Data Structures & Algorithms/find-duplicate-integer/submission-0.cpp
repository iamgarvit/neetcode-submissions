class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        while (true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];

            if (tortoise == hare)   break;
        }

        int slow = nums[0];

        while (tortoise != slow) {
            tortoise = nums[tortoise];
            slow = nums[slow];
        }

        return slow;
    }
};
