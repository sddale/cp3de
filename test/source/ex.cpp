#include <doctest/doctest.h>

#include <format>
#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xfixed.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xtensor.hpp>
#include <xtensor/xview.hpp>

#define CHECK_DBL_EQ(lhs, rhs) \
  CHECK_EQ(                    \
      lhs,                     \
      doctest::Approx(rhs).epsilon(std::numeric_limits<double>::epsilon()));

namespace cp3de::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Ex") {
  TEST_CASE("Ex1") {
    CHECK_DBL_EQ(2. / 2, 1.0);
    const auto arr1 = xt::xtensor_fixed<double, xt::xshape<3, 3>>{
        {1.0, 2.0, 3.0},
        {3.0, 5., 7.0},
        {3.0, 5.0, 7.0},
    };
    const auto arr2 = xt::xtensor<double, 1>{5.0, 6.0, 7.0};
    const auto res = xt::view(arr1, 1) + arr2;
    std::cout << arr1.shape()[0] << '\n';
    std::cout << arr1.shape()[1] << '\n';
    CHECK_DBL_EQ(res[0], 8.);

    // const auto res2 = xt::view(arr1, 1)[2] + arr2[0];
    CHECK_DBL_EQ(arr1(1, 1), 5.);
    CHECK_EQ(arr2.shape(0), 3);
    CHECK_EQ(arr2.shape(1), 1);
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace cp3de::test