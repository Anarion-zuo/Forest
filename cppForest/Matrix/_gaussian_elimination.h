//
// Created by anarion on 2019/7/31.
//

#ifndef CPPFOREST__GAUSSIAN_ELIMINATION_H
#define CPPFOREST__GAUSSIAN_ELIMINATION_H
// Gaussian

// find the row with the largest entry on the pivot column
// inputs the matrix, the position of the pivot
// returns the row index;
size_t _largest_row(const double *amat, size_t coli, const char *flags, size_t width, size_t height);

// prototype of elimination on a single pivot
//    static void _eliminate(_cnst_mat* in, size_t rowi, size_t coli, char *flags);

// permutation along with the rhs vector(s)
void _eliminate_with(double *amat, double **bmat, size_t bnum, size_t rowi, size_t coli, const char *flags, size_t width, size_t height);

// permutation core step, the step matrix PA generated
// returns the step matrix, the step rhs vectors, the order of rows,
void _forward_substi(double *amat, double **bmat, size_t bnum, size_t** order, size_t width, size_t height);

// permutation core step, solve for the solution
void _backward_substi(const double *amat, double **bmat, size_t bnum, const size_t *order, double ***ans, size_t width);

// integrated
// returns the vector
// for solvable matrices only
void _perfect_cond_int(double *amat, double **bmat, size_t bnum, double ***ans, size_t width, size_t height);
#endif //CPPFOREST__GAUSSIAN_ELIMINATION_H
