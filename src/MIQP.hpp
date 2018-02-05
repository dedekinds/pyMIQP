#ifndef MIQP_HPP
#define MIQP_HPP
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <Eigen/Eigen>

#include "ProblemQP.hpp"
#include "MyTMINLP.hpp"

typedef Eigen::VectorXd RowArray;
typedef Eigen::SparseMatrix<double> SpMat;

class MIQP
{
    // QP Problem
    ProblemQP problemqp;

    RowArray sol_x;
    double sol_obj;
    int sol_status;

public:
    // QP Problem API
    void set_c(RowArray& c);
    void set_Q(SpMat& Q);
    void set_A(SpMat& A);
    void set_glb(RowArray& glb);
    void set_gub(RowArray& gub);
    void set_xlb(RowArray& xlb);
    void set_xub(RowArray& xub);
    void set_var_types(std::vector<int>& var_types);
    void set_initial_point(std::vector<double>& initial_point);

    // SOLVER API
    void solve_bb();
    RowArray get_sol_x();
    double get_sol_obj();
    int get_sol_status();
};

#endif
