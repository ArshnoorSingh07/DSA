class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minOdd = INT_MAX;

        for(int num : nums1) {
            if(num % 2 != 0) {
                minOdd = min(minOdd, num);
            }
        }

        for(int num : nums1) {
            if(num % 2 == 0 && minOdd != INT_MAX && num < minOdd) {
                return false;
            }
        }

        return true;
    }
};