#ifndef GAUSS_SOLVER_H
#define GAUSS_SOLVER_H

#include "ISolver.h"

class CMatrix;
class CVector;
class CGaussSolver : public ISolver
{
public:
    CGaussSolver(const CMatrix &objMat, const CVector &objVecB);
    virtual ~CGaussSolver();
    virtual void Solve(CVector &objX);

private:
    int m_iRows;
    int m_iCols;
    CMatrix &m_objMat;
    CVector &m_objVecB;
};

#endif //GAUSS_SOLVER_H
