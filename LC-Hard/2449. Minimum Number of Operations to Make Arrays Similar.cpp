// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> nums1,nums2;
        vector<int> target1,target2;
        for(auto x:nums){
            if(x%2) nums2.push_back(x);
            else    nums1.push_back(x);
        }
        for(auto x:target){
            if(x%2) target2.push_back(x);
            else    target1.push_back(x);
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(target1.begin(),target1.end());
        sort(target2.begin(),target2.end());
        long long ans=0;
        int l=nums1.size();
        for(int i=0;i<l;i++){
            ans+=abs(nums1[i]-target1[i]);
        }
        int m=nums2.size();
        for(int i=0;i<m;i++){
            ans+=abs(nums2[i]-target2[i]);
        }
        return ans/4;
    }
};