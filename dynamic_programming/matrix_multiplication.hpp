#include <vector>
#include <climits>

namespace dp
{
  int matrix_multiplication(const std::vector<int>& dimensions)
  {
    int n = dimensions.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i=1; i<n; ++i)
      dp[i][i] = 0;

    int num_matrices = n - 1;
    for (int l=1; l<num_matrices; ++l)
    {
      for (int i=1; i<=num_matrices-l; ++i)
      {
        int j = i + l;
        int ans = INT_MAX;
        for (int k=i; k<j; ++k)
        {
          ans = std::min(ans, dp[i][k] + dp[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j]);
        }

        dp[i][j] = ans;
      }
    }

    return dp[1][num_matrices];
  }
}