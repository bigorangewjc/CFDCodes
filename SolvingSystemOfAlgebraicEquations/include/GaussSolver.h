#ifndef GAUSS_SOLVER_H
#define GAUSS_SOLVER_H

#include "ISolver.h"

class CMatrix;
class CVector;
class CGaussSolver : public ISolver
{
public:
    CGaussSolver(const CMatrix &objMatA, const CVector &objVecB);
    virtual ~CGaussSolver();
    // 指针作为形参，被调函数内部对指针的地址可作改变，
    // 但是实参指针指向的地址不会改变; 引用作为形参，
    // 函数的形参/实参的引用的地址不能被改变；引用必须初始化；
    void Solve(CVector &objX);
};
#endif //GAUSS_SOLVER_H
