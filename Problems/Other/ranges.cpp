#include <ranges>
#include <span>
#include <array>
#include <print>
#include <algorithm>
#include <numeric>

namespace other_ranges
{
    using namespace std::ranges;

    void ranges_test()
    {
        std::array test{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

        std::span test_span{test};

        auto sum = []<typename T>(const T &lhs, const T &rhs) -> decltype(lhs + rhs)
        {
            return lhs + rhs;
        };

        auto sub_span = test_span | views::drop(2) | views::take(4);

        std::println("fold_left: {}",
                   fold_left(sub_span, 0, std::plus{}));

        std::println("accumulate: {}",
                   std::accumulate(rbegin(sub_span), rend(sub_span), 0, sum));
    }
}