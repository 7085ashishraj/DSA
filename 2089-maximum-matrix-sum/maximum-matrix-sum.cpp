#include <vector>
#include <cmath>
#include <algorithm> // For std::min

class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        long long total_sum = 0;
        int neg_count = 0;
        int min_abs_val = 100001; // Constraints: -10^5 <= matrix[i][j] <= 10^5, so max abs value is 10^5. Initialize with something larger.

        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                int val = matrix[r][c];
                if (val < 0) {
                    neg_count++;
                }
                total_sum += std::abs(val);
                min_abs_val = std::min(min_abs_val, std::abs(val));
            }
        }
        
        // If there's an odd number of negative elements, we must end up with one.
        // To maximize the sum, we make the smallest absolute value element negative.
        if (neg_count % 2 == 1) {
            total_sum -= 2 * min_abs_val;
        }
        
        return total_sum;
    }
};  