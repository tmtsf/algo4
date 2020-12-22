#include <iostream>
#include "cutting_rod.hpp"
#include "matrix_multiplication.hpp"
#include "longest_common_subsequence.hpp"

int main(void)
{
  {
    std::cout << "***********************************************\n";

    std::cout << "Testing cutting rod problem:\n";
    std::vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int i=1; i<=10; ++i)
      std::cout << i << ": " << dp::cutting_rod(prices, i) << "\n";

    std::cout << "***********************************************\n\n";
  }

  {
    std::cout << "***********************************************\n";

    std::cout << "Testing matrix chain multiplication problem:\n";
    std::vector<int> dimensions = {30, 35, 15, 5,  10, 20, 25};
    std::cout << dp::matrix_multiplication(dimensions) << "\n";

    std::cout << "***********************************************\n\n";
  }

  {
    std::cout << "***********************************************\n";

    std::cout << "Testing longest common subsequence problem:\n";
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCABA";
    std::cout << dp::longest_common_subsequence(s1, s2) << "\n";

    std::cout << "***********************************************\n\n";
  }

  return 0;
}