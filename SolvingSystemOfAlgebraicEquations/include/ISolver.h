#ifndef ISOLVER_H
#define ISOLVER_H

#include <string>

class CVector;
class CMatrix;
class ISolver
{
public:
    ISolver(){};
    virtual ~ISolver(){};
    virtual void SetDecomposeMethod(std::string sMethod){};
    virtual void SetInitVec(const CVector &objVecInit){};
    virtual void SetTol(const double &dTol){};
    virtual void Solve(CVector& objVecX) = 0;
    virtual void SolveNewB(CVector &objVecX, const CVector &objVecB){};
};

#endif//ISOLVER_H
