#ifndef LU_SOLVER_H
#define LU_SOLVER_H
#include "ISolver.h"
#include <string>

class CMatrix;
class CVector;
class CLUSolver : public ISolver
{
public:
    CLUSolver(const CMatrix &objMatA, const CVector &objVecB);
    virtual ~CLUSolver();
    void SetDecomposeMethod(std::string sMethod = "Crout");
    virtual void Solve(CVector &objVecX);
    void SolveNewB(CVector &objVecX, const CVector &objVecB);

private:
    void LUFactorization();
    void LUFactorizationByGaussElimination();
    void ForwardSubstitution();
    void BackwardSubstitution(CVector &objVecX);

private:
    std::string m_sMethod;
};
#endif //LU_SOLVER_H