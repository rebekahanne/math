#ifndef STAN_MATH_REV_SCAL_FUN_DIGAMMA_HPP
#define STAN_MATH_REV_SCAL_FUN_DIGAMMA_HPP

#include <stan/math/prim/scal/fun/digamma.hpp>
#include <stan/math/prim/scal/fun/trigamma.hpp>
#include <stan/math/rev/core.hpp>

namespace stan {
namespace math {

namespace {
class digamma_vari : public op_v_vari {
 public:
  explicit digamma_vari(vari *avi) : op_v_vari(digamma(avi->val_), avi) {}
  void chain() { avi_->adj_ += adj_ * trigamma(avi_->val_); }
};
}  // namespace

inline var digamma(const var &a) { return var(new digamma_vari(a.vi_)); }

}  // namespace math
}  // namespace stan
#endif
