#include <string>
#include <vector>
#include <iostream>

namespace dp
{
  void longest_common_subsequence(const std::string& s1,
                                  const std::string& s2,
                                  std::vector<std::vector<int>>& dp,
                                  std::vector<std::vector<int>>& locations)
  {
    int m = s1.size();
    int n = s2.size();

    dp.resize(m+1);
    for (int i=0; i<=m; ++i)
      dp[i].resize(n+1, 0);

    locations.resize(m+1);
    for (int i=0; i<=m; ++i)
      locations[i].resize(n+1, 2);

    for (int i=1; i<=m; ++i)
    {
      for (int j=1; j<=n; ++j)
      {
        if (s1[i-1] == s2[j-1])
        {
          dp[i][j] = dp[i-1][j-1] + 1;
          locations[i][j] = 0;
        }
        else if (dp[i-1][j] >= dp[i][j-1])
        {
          dp[i][j] = dp[i-1][j];
          locations[i][j] = -1;
        }
        else
        {
          dp[i][j] = dp[i][j-1];
          locations[i][j] = 1;
        }
      }
    }
  }

  void print_longest_common_subsequence(const std::vector<std::vector<int>>& locations,
                                        const std::string& s,
                                        int m,
                                        int n)
  {
    if (m == 0 || n == 0)
      return;

    if (locations[m][n] == 0)
    {
      print_longest_common_subsequence(locations, s, m-1, n-1);
      std::cout << s[m-1];
    }
    else if (locations[m][n] == -1)
    {
      print_longest_common_subsequence(locations, s, m-1, n);
    }
    else if (locations[m][n] == 1)
    {
      print_longest_common_subsequence(locations, s, m, n-1);
    }
  }
}