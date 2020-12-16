#ifndef JACOBI_SOLVER_H
#define JACOBI_SOLVER_H

class CVector;
class CMatrix;
class CJacobiSolver
{
public:
  CJacobiSolver(
      CMatrix& objMatA, CVector& objVecB,
       CVector& objVecInit, const double& dThreshold);
  virtual ~CJacobiSolver();
  void SetNewThreshold(const double& dThreshold);
  void SetNewMatA(CMatrix& objMatA);
  void SetNewVecB(CVector& objVecB);
  double* Solve();
private:
  double m_dThreshold;
  double** m_pdMatA;
  double* m_pdVecB;
  double* m_pdVecX;
  double* m_pdVecXPrev;
  int m_iColumns;
  int m_iRows;
};
#endif//JACOBI_SOLVER_H
