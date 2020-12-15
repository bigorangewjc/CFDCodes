#ifndef LU_SOLVER_H
#define LU_SOLVER_H

#include <string>

class CVector;
class CMatrix;
class CLUSolver
{
public:
    CLUSolver(CMatrix& objMatA, CVector& objVecB);
    virtual ~CLUSolver();
    double* Solve(std::string sMethod = "Crout");
    double* SolveNewB(CVector& objVecB);

private:
    void LUFactorization();
    void LUFactorizationByGaussElimination();
    void ForwardSubstitution();
    void BackwardSubstitution();
    double** m_pdMatA;
    double* m_pdVecB;
    int m_iColumns;
    int m_iRows;
};
#endif//LU_SOLVER_H
