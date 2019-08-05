//
// Created by anarion on 2019/7/31.
//

#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include "_gaussian_elimination.h"

//void _eliminate(_cnst_mat* in, size_t rowi, size_t coli, char *flags) {
//    size_t i = 0, j, rowp = rowi * in->_width;
//    double piv = in->_mat[coli + rowp];
//    for (; i < in->_height; ++i){
//        if (i == rowi || flags[i]){
//            continue;
//        }
//        j = coli;
//        size_t rowd = i * in->_width;
//        double q = in->_mat[coli + rowd] / piv;
//
//        for (; j < in->_width; ++j){
//            in->_mat[j + rowd] -= q * in->_mat[j + rowp];
//        }
//    }
//}

void _eliminate_with(double *amat, double **bmat, size_t bnum, size_t rowi, size_t coli, const char *flags, size_t width, size_t height) {
    size_t i = 0, j, rowp = rowi * width;
    double piv = amat[coli + rowp];
    for (; i < height; ++i){
        if (i == rowi || flags[i]){
            continue;
        }
        j = coli;
        size_t rowd = i * width;
        double q = amat[coli + rowd] / piv;

        for (; j < width; ++j){
            amat[j + rowd] -= q * amat[j + rowp];
//            if (perm){
//                res = q * perm->_mat[pos1];
//                perm->_mat[pos] -= res;
//            }
        }
        for (size_t k = 0; k < bnum; ++k){
            bmat[k][i] -= q * bmat[k][rowi];
        }
    }
}
void _forward_substi(double *amat, double **bmat, size_t bnum, size_t** order, size_t width, size_t height) {
    size_t *roworder = calloc(width, sizeof(size_t));
    char *flags = malloc(height);
    memset(flags, 0, height);
//    size_t len;
//    if (in->_width >= in->_height){
//        len = in->_height;
//    } else {
//        len = in->_width;
//    }
//    auto unit = new _unit_mat(height, width);
    for (size_t i = 0; i < width; ++i){
        size_t ri = _largest_row(amat, i, flags, width, height);
        flags[ri] = 1;
        roworder[i] = ri;
        _eliminate_with(amat, bmat, bnum, ri, i, flags, width, height);
    }
    free(flags);
    *order = roworder;
}

size_t _largest_row(const double *amat, size_t coli, const char *flags, size_t width, size_t height) {
    size_t res = 0;
    double piv = amat[coli];
    for (size_t i = 0; i < height; ++i){
        if (flags[i]){  // if the row has already been registered, skip it
            continue;
        }
        size_t loc = coli + width * i;
        double temp = amat[loc];
        if (temp > piv){
            piv = temp;
            res = i;
        }
    }
    return res;
}

void _backward_substi(const double *amat, double **bmat, size_t bnum, const size_t *order, double ***ans, size_t width) {
    double **an = calloc(bnum, sizeof(double*));
    for (size_t bn = 0; bn < bnum; ++bn){
        an[bn] = calloc(width, sizeof(double));
    }
    for (size_t i = width; i > 0; --i){
        size_t j = i - 1, o = order[j], rowi = o * width;
        for (size_t bn = 0; bn < bnum; ++bn){
            double rhs = bmat[bn][o];
            for (size_t k = width - 1; k > j; --k){
                rhs -= amat[rowi + k] * an[bn][k];
            }
            an[bn][j] = rhs / amat[rowi + j];
        }
    }
    *ans = an;
}

void _perfect_cond_int(double *amat, double **bmat, size_t bnum, double ***ans, size_t width, size_t height) {
    size_t *order;
    _forward_substi(amat, bmat, bnum, &order, width, height);
    _backward_substi(amat, bmat, bnum, order, ans, width);
}
