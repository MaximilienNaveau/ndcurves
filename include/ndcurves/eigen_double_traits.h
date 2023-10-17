#ifndef NDCURVES_EIGEN_DOUBLE_TRAITS_H
#define NDCURVES_EIGEN_DOUBLE_TRAITS_H

#include "ndcurves/fwd.h"
#include "ndcurves/linear_variable.h"

namespace ndcurves {

template <typename Point>
struct EigenDoubleTraits {
  static std::size_t getDim(const Point& in) {
    return static_cast<std::size_t>(in.size());
  }

  static Point getZero(const int& dim) { return Point::Zero(dim); }

  static bool isApprox(const Point& a, const Point& b,
                       const double eps = 1e-6) {
    return (a - b).isMuchSmallerThan(1.0, eps);
  }
};

template <>
inline std::size_t EigenDoubleTraits<double>::getDim(const double& /*in*/) {
  return static_cast<std::size_t>(1);
}

template <>
inline double EigenDoubleTraits<double>::getZero(const int& /*dim*/) {
  return 0.0;
}

template <>
inline bool EigenDoubleTraits<double>::isApprox(const double& a,
                                                const double& b,
                                                const double eps) {
  return fabs(a - b) < eps;
}

}  //  namespace ndcurves

#endif  //  NDCURVES_EIGEN_DOUBLE_TRAITS_H
