class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int X = 0;
        for (auto x:nums) {X^=x;}
        return (X == 0 || nums.size() % 2 == 0);
    }
};