#ifndef VMFUNCTIONS_TYPE_MANIPULATIONS
#define VMFUNCTIONS_TYPE_MANIPULATIONS

#include <cstdint>

namespace vmfunctions::common {

template<typename F>
struct coupled_type;

template<>
struct coupled_type<float> {
    typedef std::int32_t type;
    static_assert(sizeof(type) == sizeof(float));
};

template<>
struct coupled_type<double> {
    typedef std::int64_t type;
    static_assert(sizeof(type) == sizeof(double));
};

template<typename F>
using coupled_type_t = typename coupled_type<F>::type;

template<typename F, typename I = coupled_type_t<F> >
union reinterpret {
    static_assert(sizeof(F) == sizeof(I));
    using this_t = reinterpret<F, I>;
public:
    reinterpret(F fval) : fpt_val{fval} {}
    reinterpret(I ival) : int_val{ival} {}
    operator F () const { return fpt_val; }
    F& as_fpt() { return fpt_val; }
    operator I () const { return int_val; }
    I& as_int() { return int_val; }
    auto operator^ (this_t r) const {
        return this_t{int_val ^ r.int_val};
    }
private:
    F fpt_val;
    I int_val;
};

template<typename F, typename I>
F XOR(F farg, I iarg) {
    using R = reinterpret<F, I>;
    return R{farg} ^ R{iarg};
}

} // vmfunctions::common

#endif // VMFUNCTIONS_TYPE_MANIPULATIONS
