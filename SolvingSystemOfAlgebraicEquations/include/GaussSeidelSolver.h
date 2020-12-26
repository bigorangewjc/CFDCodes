#ifndef GAUSS_SEIDEL_SOLVER_H
#define GAUSS_SEIDEL_SOLVER_H

#include "ISolver.h"

class CVector;
class CMatrix;
class CGaussSeidelSolver : ISolver
{
public:
    CGaussSeidelSolver(const CMatrix &objMat, const CVector &objVecB);
    virtual ~CGaussSeidelSolver();
    void SetInitVec(const CVector &objVecInit);
    void SetTol(const double &dTol);
    virtual void Solve(CVector &objVecX);

private:
    double m_dTol;
    int m_iRows;
    int m_iCols;
    const CMatrix &m_objMat;
    const CVector &m_objVecB;
    CVector &m_objVecXPrev;
};

#endif //GAUSS_SEIDEL_SOLVER_H