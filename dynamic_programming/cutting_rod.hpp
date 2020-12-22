#include <vector>
#include <climits>

namespace dp
{
  int cutting_rod(const std::vector<int>& prices,
                  int n)
  {
    std::vector<int> dp(prices.size(), 0);
    for (int i=1; i<=n; ++i)
    {
      int ans = INT_MIN;
      for (int j=1; j<=i; ++j)
      {
        ans = std::max(ans, prices[j] + dp[i-j]);
      }

      dp[i] = ans;
    }

    return dp[n];
  }
}