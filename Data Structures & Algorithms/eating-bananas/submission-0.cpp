class Solution {
public:
    bool is_possible(vector<int>& piles, int h, int speed) {
        int num_hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            num_hrs += piles[i] / speed + (piles[i] % speed == 0 ? 0 : 1);
        }
        return num_hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (is_possible(piles, h, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
