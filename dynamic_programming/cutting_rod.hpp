#include <vector>
#include <climits>

namespace dp
{
  void cutting_rod(const std::vector<int>& prices,
                   std::vector<int>& totals,
                   std::vector<int>& locations)
  {
    int n = prices.size();

    totals.resize(n+1, 0);
    locations.resize(n+1, 0);
    for (int i=1; i<=n; ++i)
    {
      totals[i] = INT_MIN;
      for (int j=1; j<=i; ++j)
      {
        if (totals[i] < prices[j-1] + totals[i-j])
        {
          totals[i] = prices[j-1] + totals[i-j];
          locations[i] = j;
        }
      }
    }
  }
}