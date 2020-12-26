#ifndef JACOBI_SOLVER_H
#define JACOBI_SOLVER_H

#include "ISolver.h"

class CVector;
class CMatrix;
class CJacobiSolver : public ISolver
{
public:
    CJacobiSolver(const CMatrix &objMat, const CVector &objVecB);
    virtual ~CJacobiSolver();
    virtual void SetInitVec(const CVector &objVecInit);
    virtual void SetTol(const double &dTol);
    virtual void Solve(CVector &objVecX);

private:
    double m_dTol;
    int m_iRows;
    int m_iCols;
    const CMatrix &m_objMat;
    const CVector &m_objVecB;
    CVector &m_objVecXPrev;
};

#endif //JACOBI_SOLVER_H