class Solution {
public:
    vector<int> get(vector<int>& divRequired) {
        int n = divRequired.size();
        vector<int> st;
        vector<int> sol(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && divRequired[st.back()] <= divRequired[i]) {
                st.pop_back();
            }
            if (st.empty()) {
                sol[i] = 0;
            } else {
                sol[i] = st.back() + 1;
            }
            st.push_back(i);
        }
        return sol;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> divRequired(n);
        auto getDivRequired = [&] (int value) -> int {
            int low = 1;
            int high = n;
            int sol = n + 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if ((double) threshold / mid < value) {
                    sol = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return sol;
        };
        for (int i = 0; i < n; i++) {
            divRequired[i] = getDivRequired(nums[i]);
        }
        int sol = -1;
        vector<int> left = get(divRequired);
        reverse(divRequired.begin(), divRequired.end());
        vector<int> right = get(divRequired);
        reverse(divRequired.begin(), divRequired.end());
        for (int i = 0; i < n; i++) {
            if (divRequired[i] == n + 1) continue;
            int l = left[i];
            int r = n - 1 - right[n - 1 - i];
            if (r - l + 1 >= divRequired[i]) {
                sol = r - l + 1;
                break;
            }
        }
        return sol;
    }
};