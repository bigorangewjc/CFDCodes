#ifndef GAUSS_SOLVER_H
#define GAUSS_SOLVER_H

class CVector;
class CMatrix;
class CGaussSolver
{
public:
  CGaussSolver(CMatrix& objMatA, CVector& objVecB);
  virtual ~CGaussSolver();
  void SetNewMatA(CMatrix& objMatA);
  void SetNewVecB(CVector& objVecB);
  // 指针作为形参，被调函数内部对指针的地址可作改变，
  // 但是实参指针指向的地址不会改变; 引用作为形参，
  // 函数的形参/实参的引用的地址不能被改变；引用必须初始化；
  double* Solve();
private:
  double** m_pdMatA;
  double* m_pdVecB;
  int m_iColumns;
  int m_iRows;
};
#endif//GAUSS_SOLVER_H