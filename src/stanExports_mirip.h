// Generated by rstantools.  Do not edit by hand.

/*
    mirip is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    mirip is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with mirip.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_mirip_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_mirip");
    reader.add_event(103, 101, "end", "model_mirip");
    return reader;
}
#include <stan_meta_header.hpp>
class model_mirip : public prob_grad {
private:
        int N;
        int n;
        std::vector<std::vector<int> > y;
        std::vector<double> s_gmpr;
        std::vector<double> g;
        std::vector<int> ip;
        double beta_mu;
        double alpha_mu;
        double beta_delta;
        double alpha_delta;
        double beta_phi;
        double alpha_phi;
        std::vector<double> s;
        int m;
        int k;
        int l;
        std::vector<std::vector<int> > y_input;
        std::vector<std::vector<int> > y_ip;
public:
    model_mirip(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_mirip(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_mirip_namespace::model_mirip";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];
            check_greater_or_equal(function__, "n", n, 0);
            current_statement_begin__ = 4;
            validate_non_negative_index("y", "N", N);
            validate_non_negative_index("y", "n", n);
            context__.validate_dims("data initialization", "y", "int", context__.to_vec(N,n));
            y = std::vector<std::vector<int> >(N, std::vector<int>(n, int(0)));
            vals_i__ = context__.vals_i("y");
            pos__ = 0;
            size_t y_k_0_max__ = N;
            size_t y_k_1_max__ = n;
            for (size_t k_1__ = 0; k_1__ < y_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                    y[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t y_i_0_max__ = N;
            size_t y_i_1_max__ = n;
            for (size_t i_0__ = 0; i_0__ < y_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < y_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "y[i_0__][i_1__]", y[i_0__][i_1__], 0);
                }
            }
            current_statement_begin__ = 5;
            validate_non_negative_index("s_gmpr", "n", n);
            context__.validate_dims("data initialization", "s_gmpr", "double", context__.to_vec(n));
            s_gmpr = std::vector<double>(n, double(0));
            vals_r__ = context__.vals_r("s_gmpr");
            pos__ = 0;
            size_t s_gmpr_k_0_max__ = n;
            for (size_t k_0__ = 0; k_0__ < s_gmpr_k_0_max__; ++k_0__) {
                s_gmpr[k_0__] = vals_r__[pos__++];
            }
            size_t s_gmpr_i_0_max__ = n;
            for (size_t i_0__ = 0; i_0__ < s_gmpr_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "s_gmpr[i_0__]", s_gmpr[i_0__], 0);
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("g", "N", N);
            context__.validate_dims("data initialization", "g", "double", context__.to_vec(N));
            g = std::vector<double>(N, double(0));
            vals_r__ = context__.vals_r("g");
            pos__ = 0;
            size_t g_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < g_k_0_max__; ++k_0__) {
                g[k_0__] = vals_r__[pos__++];
            }
            size_t g_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < g_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "g[i_0__]", g[i_0__], 0);
            }
            current_statement_begin__ = 7;
            validate_non_negative_index("ip", "n", n);
            context__.validate_dims("data initialization", "ip", "int", context__.to_vec(n));
            ip = std::vector<int>(n, int(0));
            vals_i__ = context__.vals_i("ip");
            pos__ = 0;
            size_t ip_k_0_max__ = n;
            for (size_t k_0__ = 0; k_0__ < ip_k_0_max__; ++k_0__) {
                ip[k_0__] = vals_i__[pos__++];
            }
            size_t ip_i_0_max__ = n;
            for (size_t i_0__ = 0; i_0__ < ip_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "ip[i_0__]", ip[i_0__], 0);
                check_less_or_equal(function__, "ip[i_0__]", ip[i_0__], 1);
            }
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "beta_mu", "double", context__.to_vec());
            beta_mu = double(0);
            vals_r__ = context__.vals_r("beta_mu");
            pos__ = 0;
            beta_mu = vals_r__[pos__++];
            check_greater_or_equal(function__, "beta_mu", beta_mu, 0);
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "alpha_mu", "double", context__.to_vec());
            alpha_mu = double(0);
            vals_r__ = context__.vals_r("alpha_mu");
            pos__ = 0;
            alpha_mu = vals_r__[pos__++];
            check_greater_or_equal(function__, "alpha_mu", alpha_mu, 0);
            current_statement_begin__ = 10;
            context__.validate_dims("data initialization", "beta_delta", "double", context__.to_vec());
            beta_delta = double(0);
            vals_r__ = context__.vals_r("beta_delta");
            pos__ = 0;
            beta_delta = vals_r__[pos__++];
            check_greater_or_equal(function__, "beta_delta", beta_delta, 0);
            current_statement_begin__ = 11;
            context__.validate_dims("data initialization", "alpha_delta", "double", context__.to_vec());
            alpha_delta = double(0);
            vals_r__ = context__.vals_r("alpha_delta");
            pos__ = 0;
            alpha_delta = vals_r__[pos__++];
            check_greater_or_equal(function__, "alpha_delta", alpha_delta, 0);
            current_statement_begin__ = 12;
            context__.validate_dims("data initialization", "beta_phi", "double", context__.to_vec());
            beta_phi = double(0);
            vals_r__ = context__.vals_r("beta_phi");
            pos__ = 0;
            beta_phi = vals_r__[pos__++];
            check_greater_or_equal(function__, "beta_phi", beta_phi, 0);
            current_statement_begin__ = 13;
            context__.validate_dims("data initialization", "alpha_phi", "double", context__.to_vec());
            alpha_phi = double(0);
            vals_r__ = context__.vals_r("alpha_phi");
            pos__ = 0;
            alpha_phi = vals_r__[pos__++];
            check_greater_or_equal(function__, "alpha_phi", alpha_phi, 0);
            // initialize transformed data variables
            current_statement_begin__ = 21;
            validate_non_negative_index("s", "n", n);
            s = std::vector<double>(n, double(0));
            stan::math::fill(s, DUMMY_VAR__);
            stan::math::assign(s,s_gmpr);
            current_statement_begin__ = 22;
            m = int(0);
            stan::math::fill(m, std::numeric_limits<int>::min());
            stan::math::assign(m,divide(n, 2));
            current_statement_begin__ = 23;
            k = int(0);
            stan::math::fill(k, std::numeric_limits<int>::min());
            stan::math::assign(k,1);
            current_statement_begin__ = 23;
            l = int(0);
            stan::math::fill(l, std::numeric_limits<int>::min());
            stan::math::assign(l,1);
            current_statement_begin__ = 24;
            validate_non_negative_index("y_input", "N", N);
            validate_non_negative_index("y_input", "m", m);
            y_input = std::vector<std::vector<int> >(N, std::vector<int>(m, int(0)));
            stan::math::fill(y_input, std::numeric_limits<int>::min());
            current_statement_begin__ = 25;
            validate_non_negative_index("y_ip", "N", N);
            validate_non_negative_index("y_ip", "m", m);
            y_ip = std::vector<std::vector<int> >(N, std::vector<int>(m, int(0)));
            stan::math::fill(y_ip, std::numeric_limits<int>::min());
            // execute transformed data statements
            current_statement_begin__ = 26;
            for (int j = 1; j <= n; ++j) {
                current_statement_begin__ = 27;
                if (as_bool(logical_eq(get_base1(ip, j, "ip", 1), 0))) {
                    current_statement_begin__ = 28;
                    for (int i = 1; i <= N; ++i) {
                        current_statement_begin__ = 29;
                        stan::model::assign(y_input, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                                    get_base1(get_base1(y, i, "y", 1), j, "y", 2), 
                                    "assigning variable y_input");
                    }
                    current_statement_begin__ = 31;
                    stan::math::assign(k, (k + 1));
                } else {
                    current_statement_begin__ = 33;
                    for (int i = 1; i <= N; ++i) {
                        current_statement_begin__ = 34;
                        stan::model::assign(y_ip, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(l), stan::model::nil_index_list())), 
                                    get_base1(get_base1(y, i, "y", 1), j, "y", 2), 
                                    "assigning variable y_ip");
                    }
                    current_statement_begin__ = 36;
                    stan::math::assign(l, (l + 1));
                }
            }
            // validate transformed data
            current_statement_begin__ = 21;
            size_t s_i_0_max__ = n;
            for (size_t i_0__ = 0; i_0__ < s_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "s[i_0__]", s[i_0__], 0);
            }
            current_statement_begin__ = 24;
            size_t y_input_i_0_max__ = N;
            size_t y_input_i_1_max__ = m;
            for (size_t i_0__ = 0; i_0__ < y_input_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < y_input_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "y_input[i_0__][i_1__]", y_input[i_0__][i_1__], 0);
                }
            }
            current_statement_begin__ = 25;
            size_t y_ip_i_0_max__ = N;
            size_t y_ip_i_1_max__ = m;
            for (size_t i_0__ = 0; i_0__ < y_ip_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < y_ip_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "y_ip[i_0__][i_1__]", y_ip[i_0__][i_1__], 0);
                }
            }
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 43;
            num_params_r__ += 1;
            current_statement_begin__ = 44;
            validate_non_negative_index("mu", "N", N);
            num_params_r__ += (1 * N);
            current_statement_begin__ = 45;
            validate_non_negative_index("phi", "N", N);
            num_params_r__ += (1 * N);
            current_statement_begin__ = 46;
            validate_non_negative_index("delta", "N", N);
            num_params_r__ += (1 * N);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_mirip() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 43;
        if (!(context__.contains_r("pi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable pi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("pi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "pi", "double", context__.to_vec());
        double pi(0);
        pi = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(0, 1, pi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable pi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 44;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        validate_non_negative_index("mu", "N", N);
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec(N));
        std::vector<double> mu(N, double(0));
        size_t mu_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            mu[k_0__] = vals_r__[pos__++];
        }
        size_t mu_i_0_max__ = N;
        for (size_t i_0__ = 0; i_0__ < mu_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_lb_unconstrain(0, mu[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }
        current_statement_begin__ = 45;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        validate_non_negative_index("phi", "N", N);
        context__.validate_dims("parameter initialization", "phi", "double", context__.to_vec(N));
        std::vector<double> phi(N, double(0));
        size_t phi_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < phi_k_0_max__; ++k_0__) {
            phi[k_0__] = vals_r__[pos__++];
        }
        size_t phi_i_0_max__ = N;
        for (size_t i_0__ = 0; i_0__ < phi_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_lb_unconstrain(0, phi[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }
        current_statement_begin__ = 46;
        if (!(context__.contains_r("delta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable delta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("delta");
        pos__ = 0U;
        validate_non_negative_index("delta", "N", N);
        context__.validate_dims("parameter initialization", "delta", "double", context__.to_vec(N));
        std::vector<double> delta(N, double(0));
        size_t delta_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < delta_k_0_max__; ++k_0__) {
            delta[k_0__] = vals_r__[pos__++];
        }
        size_t delta_i_0_max__ = N;
        for (size_t i_0__ = 0; i_0__ < delta_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_lb_unconstrain(0, delta[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable delta: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 43;
            local_scalar_t__ pi;
            (void) pi;  // dummy to suppress unused var warning
            if (jacobian__)
                pi = in__.scalar_lub_constrain(0, 1, lp__);
            else
                pi = in__.scalar_lub_constrain(0, 1);
            current_statement_begin__ = 44;
            std::vector<local_scalar_t__> mu;
            size_t mu_d_0_max__ = N;
            mu.reserve(mu_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < mu_d_0_max__; ++d_0__) {
                if (jacobian__)
                    mu.push_back(in__.scalar_lb_constrain(0, lp__));
                else
                    mu.push_back(in__.scalar_lb_constrain(0));
            }
            current_statement_begin__ = 45;
            std::vector<local_scalar_t__> phi;
            size_t phi_d_0_max__ = N;
            phi.reserve(phi_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < phi_d_0_max__; ++d_0__) {
                if (jacobian__)
                    phi.push_back(in__.scalar_lb_constrain(0, lp__));
                else
                    phi.push_back(in__.scalar_lb_constrain(0));
            }
            current_statement_begin__ = 46;
            std::vector<local_scalar_t__> delta;
            size_t delta_d_0_max__ = N;
            delta.reserve(delta_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < delta_d_0_max__; ++d_0__) {
                if (jacobian__)
                    delta.push_back(in__.scalar_lb_constrain(0, lp__));
                else
                    delta.push_back(in__.scalar_lb_constrain(0));
            }
            // model body
            {
            current_statement_begin__ = 52;
            validate_non_negative_index("contributions", "2", 2);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> contributions(2);
            stan::math::initialize(contributions, DUMMY_VAR__);
            stan::math::fill(contributions, DUMMY_VAR__);
            current_statement_begin__ = 54;
            for (int j = 1; j <= m; ++j) {
                current_statement_begin__ = 55;
                for (int i = 1; i <= N; ++i) {
                    current_statement_begin__ = 57;
                    lp_accum__.add(neg_binomial_2_log(get_base1(get_base1(y_input, i, "y_input", 1), j, "y_input", 2), ((get_base1(s, j, "s", 1) * get_base1(g, i, "g", 1)) * get_base1(mu, i, "mu", 1)), get_base1(phi, i, "phi", 1)));
                    current_statement_begin__ = 60;
                    stan::model::assign(contributions, 
                                stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                                (stan::math::log(pi) + neg_binomial_2_log(get_base1(get_base1(y_ip, i, "y_ip", 1), j, "y_ip", 2), (((get_base1(s, (j + m), "s", 1) * get_base1(mu, i, "mu", 1)) * get_base1(g, i, "g", 1)) * get_base1(delta, i, "delta", 1)), get_base1(phi, i, "phi", 1))), 
                                "assigning variable contributions");
                    current_statement_begin__ = 61;
                    stan::model::assign(contributions, 
                                stan::model::cons_list(stan::model::index_uni(2), stan::model::nil_index_list()), 
                                (stan::math::log((1 - pi)) + normal_log(get_base1(get_base1(y_ip, i, "y_ip", 1), j, "y_ip", 2), 0, 0.00000000001)), 
                                "assigning variable contributions");
                    current_statement_begin__ = 62;
                    lp_accum__.add(log_sum_exp(contributions));
                }
            }
            current_statement_begin__ = 67;
            lp_accum__.add(normal_log<propto__>(phi, 0, 4));
            current_statement_begin__ = 70;
            lp_accum__.add(gamma_log<propto__>(mu, alpha_mu, beta_mu));
            current_statement_begin__ = 72;
            lp_accum__.add(gamma_log<propto__>(delta, 0.2, 0.5));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("pi");
        names__.push_back("mu");
        names__.push_back("phi");
        names__.push_back("delta");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_mirip_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double pi = in__.scalar_lub_constrain(0, 1);
        vars__.push_back(pi);
        std::vector<double> mu;
        size_t mu_d_0_max__ = N;
        mu.reserve(mu_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < mu_d_0_max__; ++d_0__) {
            mu.push_back(in__.scalar_lb_constrain(0));
        }
        size_t mu_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            vars__.push_back(mu[k_0__]);
        }
        std::vector<double> phi;
        size_t phi_d_0_max__ = N;
        phi.reserve(phi_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < phi_d_0_max__; ++d_0__) {
            phi.push_back(in__.scalar_lb_constrain(0));
        }
        size_t phi_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < phi_k_0_max__; ++k_0__) {
            vars__.push_back(phi[k_0__]);
        }
        std::vector<double> delta;
        size_t delta_d_0_max__ = N;
        delta.reserve(delta_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < delta_d_0_max__; ++d_0__) {
            delta.push_back(in__.scalar_lb_constrain(0));
        }
        size_t delta_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < delta_k_0_max__; ++k_0__) {
            vars__.push_back(delta[k_0__]);
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_mirip";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "pi";
        param_names__.push_back(param_name_stream__.str());
        size_t mu_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t phi_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < phi_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t delta_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < delta_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "pi";
        param_names__.push_back(param_name_stream__.str());
        size_t mu_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t phi_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < phi_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t delta_k_0_max__ = N;
        for (size_t k_0__ = 0; k_0__ < delta_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_mirip_namespace::model_mirip stan_model;
#endif