#include <vector>
#include <climits>
#include <iostream>

namespace dp
{
  void matrix_chain_parenthesization(const std::vector<int>& dimensions,
                                     std::vector<std::vector<int>>& dp,
                                     std::vector<std::vector<int>>& locations)
  {
    int n = dimensions.size();
    dp.resize(n);
    for (int i=0; i<n; ++i)
      dp[i].resize(n, 0);

    locations.resize(n);
    for (int i=0; i<n; ++i)
      locations[i].resize(n, 0);

    int num_matrices = n - 1;
    for (int l=1; l<num_matrices; ++l)
    {
      for (int i=1; i<=num_matrices-l; ++i)
      {
        int j = i + l;
        dp[i][j] = INT_MAX;
        for (int k=i; k<j; ++k)
        {
          if (dp[i][j] > dp[i][k] + dp[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j])
          {
            dp[i][j] = dp[i][k] + dp[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
            locations[i][j] = k;
          }
        }
      }
    }
  }

  void print_optimal_parentheses(const std::vector<std::vector<int>>& locations,
                                 int start,
                                 int end)
  {
    if (start == end)
    {
      std::cout << "A_{" << start << "}";
    }
    else
    {
      std::cout << "(";
      print_optimal_parentheses(locations, start, locations[start][end]);
      print_optimal_parentheses(locations, locations[start][end]+1, end);
      std::cout << ")";
    }
  }
}