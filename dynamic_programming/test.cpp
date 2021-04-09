#include <iostream>
#include "cutting_rod.hpp"
#include "matrix_multiplication.hpp"
#include "longest_common_subsequence.hpp"
#include "longest_palindromic_subsequence.hpp"

int main(void)
{
  {
    std::cout << "***********************************************\n";

    std::cout << "Testing cutting rod problem:\n";
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    std::vector<int> dp;
    std::vector<int> locations;
    dp::cutting_rod(prices, dp, locations);

    for (int i=1; i<=prices.size(); ++i)
    {
      std::cout << i << ": " << dp[i] << " [ ";
      int j = i;
      while (j > 0)
      {
        int temp = locations[j];
        std::cout << temp << " ";
        j -= temp;
      }
      std::cout << "]\n";
    }

    std::cout << "***********************************************\n\n";
  }

  {
    std::cout << "***********************************************\n";

    std::cout << "Testing matrix chain multiplication problem:\n";
    std::vector<int> dimensions = {30, 35, 15, 5,  10, 20, 25};
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> locations;
    dp::matrix_chain_parenthesization(dimensions, dp, locations);
    std::cout << "The minimum number of multiplication performed is " << dp[1][dimensions.size()-1] << " ";
    dp::print_optimal_parentheses(locations, 1, dimensions.size()-1);
    std::cout << "\n";

    std::cout << "***********************************************\n\n";
  }

  {
    std::cout << "***********************************************\n";

    std::cout << "Testing longest common subsequence problem:\n";
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCABA";
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> locations;
    dp::longest_common_subsequence(s1, s2, dp, locations);

    int m = s1.size();
    int n = s2.size();
    std::cout << "The longest common subsequence is ";
    dp::print_longest_common_subsequence(locations, s1, m, n);
    std::cout << ", whose size is " << dp[m][n] << ".\n";

    std::cout << "***********************************************\n\n";
  }

  {
    std::cout << "***********************************************\n";

    std::cout << "Testing longest palindromic subsequence problem:\n";
    std::string s = "aacabdkacaa";
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> locations;
    dp::longest_palindromic_subsequence(s, dp, locations);

    int n = s.size();
    // for (int i=0; i<=n; ++i)
    // {
    //   for (int j=0; j<=n; ++j)
    //     std::cout << dp[i][j] << "\t";
    //   std::cout << "\n";
    // }

    std::cout << "The longest palindromic subsequence is ";
    dp::print_longest_palindromic_subsequence(locations, s, 1, n);
    std::cout << ", whose size is " << dp[1][n] << ".\n";

    std::cout << "***********************************************\n\n";
  }

  return 0;
}