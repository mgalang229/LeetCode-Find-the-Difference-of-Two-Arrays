class Solution {
    bool found(int x, vector<int>& a) {
        int low = 0, high = a.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == x) {
                return true;
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> st;
        for (int i = 0; i < (int) nums1.size(); i++) {
            if (!found(nums1[i], nums2) && st.find(nums1[i]) == st.end()) {
                res[0].push_back(nums1[i]);
                st.insert(nums1[i]);
            }
        }
        st.clear();
        for (int i = 0; i < (int) nums2.size(); i++) {
            if (!found(nums2[i], nums1) && st.find(nums2[i]) == st.end()) {
                res[1].push_back(nums2[i]);
                st.insert(nums2[i]);
            }
        }
        return res;
    }
};
