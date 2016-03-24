class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) {
            return n;
        }
        int result = 0;
        vector<int> V(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                V[i] = V[i-1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && V[i] <= V[i+1]) {
                V[i] = V[i+1] + 1;
            } 
        }
        for (int i = 0; i < n; i++) {
            result += V[i];
        }

        return result;
    }
};
