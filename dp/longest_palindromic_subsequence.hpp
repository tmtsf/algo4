#include <string>
#include <vector>
#include <iostream>

namespace dp
{
  void longest_palindromic_subsequence(const std::string& s,
                                       std::vector<std::vector<int>>& dp,
                                       std::vector<std::vector<int>>& locations)
  {
    int n = s.size();
    dp.resize(n+1);
    for (int i=0; i<=n; ++i)
      dp[i].resize(n+1, 0);

    locations.resize(n+1);
    for (int i=0; i<=n; ++i)
      locations[i].resize(n+1, 2);

    for (int i=1; i<=n; ++i)
      dp[i][i] = 1;

    for (int l=1; l<n; ++l)
    {
      for (int i=1; i<=n-l; ++i)
      {
        int j = i+l;
        if (j == i+1 && s[j-1] == s[i-1])
        {
          continue;
        }

        if (s[i-1] == s[j-1])
        {
          if (j == i+1)
            dp[i][j] = 2;
          else
            dp[i][j] = dp[i+1][j-1] + 2;

          locations[i][j] = 0;
        }
        else if (dp[i+1][j] >= dp[i][j-1])
        {
          dp[i][j] = dp[i+1][j];
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

  void print_longest_palindromic_subsequence(const std::vector<std::vector<int>>& locations,
                                             const std::string& s,
                                             int start,
                                             int end)
  {
    if (start == end)
    {
      std::cout << s[start-1];
      return;
    }

    if (locations[start][end] == 0)
    {
      if (end == start + 1)
      {
        std::cout << s[start-1] << s[end-1];
        return;
      }
      else
      {
        std::cout << s[start-1];
        print_longest_palindromic_subsequence(locations, s, start+1, end-1);
        std::cout << s[end-1];
      }
    }
    else if (locations[start][end] == -1)
    {
      print_longest_palindromic_subsequence(locations, s, start+1, end);
    }
    else if (locations[start][end] == 1)
    {
      print_longest_palindromic_subsequence(locations, s, start, end-1);
    }
  }
}