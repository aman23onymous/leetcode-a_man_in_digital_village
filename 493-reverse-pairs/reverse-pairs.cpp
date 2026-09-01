class Solution {
public:
    int cnv(vector<int>& nums, int l, int r) {
        int rs = 0;

        if (l < r) {
            int m = l + (r - l) / 2;

            rs += cnv(nums, l, m);
            rs += cnv(nums, m + 1, r);

            vector<int> lt(m - l + 1), rt(r - m);

            for (int i = 0; i < lt.size(); i++) {
                lt[i] = nums[l + i];
            }

            for (int i = 0; i < rt.size(); i++) {
                rt[i] = nums[m + 1 + i];
            }

            int i = 0, j = 0;

            while (i < lt.size()) {
                while (j < rt.size() &&
                       1LL * lt[i] > 2LL * rt[j]) {
                    j++;
                }

                rs += j;
                i++;
            }

            i = 0;
            j = 0;
            int k = l;

            while (i < lt.size() && j < rt.size()) {
                if (lt[i] <= rt[j]) {
                    nums[k++] = lt[i++];
                } else {
                    nums[k++] = rt[j++];
                }
            }

            while (i < lt.size()) {
                nums[k++] = lt[i++];
            }

            while (j < rt.size()) {
                nums[k++] = rt[j++];
            }
        }

        return rs;
    }

    int reversePairs(vector<int>& nums) {
        return cnv(nums, 0, nums.size() - 1);
    }
};