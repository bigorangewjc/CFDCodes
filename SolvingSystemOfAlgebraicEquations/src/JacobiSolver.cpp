#include "JacobiSolver.h"
#include <cmath>
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CJacobiSolver::CJacobiSolver(
    CMatrix& objMatA, CVector& objVecB,
    CVector& objVecInit, const double& dThreshold)
  : m_pdMatA(objMatA.GetMat()) 
  , m_pdVecB(objVecB.GetVector())
  , m_pdVecXPrev(objVecInit.GetVector())
  , m_iRows(objVecB.GetRows())
  , m_iColumns(objMatA.GetColumns())
  , m_dThreshold(dThreshold)
{
  if (m_iRows != m_iColumns)
  {
    std::cout << "A's column number " << m_iColumns
      << " is not equal to B's row number " << m_iRows << std::endl;
    abort();
  }
  if (nullptr == m_pdMatA)
  {
    std::cout << "Matrix A is NULL" << std::endl;
    abort();
  }
  if (nullptr == m_pdVecB)
  {
    std::cout << "Vector B is NULL" << std::endl;
    abort();
  }
  if (nullptr == m_pdVecXPrev)
  {
    std::cout << "Initial vector is NULL" << std::endl;
    abort();
  }
  pobjVecX = new CVector(m_iRows);
  m_pdVecX = pobjVecX->GetVector();
}
CJacobiSolver::~CJacobiSolver()
{

}
CVector* CJacobiSolver::Solve()
{
  int iIter = 1;
  double dError = 0.0;
  while (1 == iIter || dError > m_dThreshold)
  {
    std::cout << "iIter = " << iIter << std::endl;
    // Calculate new estimates
    for (int iI = 0; iI < m_iRows; iI++)
    {
        m_pdVecX[iI] = m_pdVecB[iI];
        for (int iJ = 0; iJ < m_iColumns; iJ++)
        {
            if (iI != iJ)
            {
                m_pdVecX[iI] -= m_pdMatA[iI][iJ] * m_pdVecXPrev[iJ]; 
            }
        }
        m_pdVecX[iI] /= m_pdMatA[iI][iI];
    }
    // Calculate maximum normalized difference between
    //   two consecutive iteration estimates
    double dTmp = 0.0;
    dError = fabs(m_pdVecX[0] - m_pdVecXPrev[0]);
    m_pdVecXPrev[0] = m_pdVecX[0];
    for (int iI = 1; iI < m_iRows; iI++)
    {
        dTmp = fabs(m_pdVecX[iI] - m_pdVecXPrev[iI]);
        if (dError < dTmp)
        {
            dError = dTmp;
        }
        std::cout << m_pdVecXPrev[iI] << std::endl;
        m_pdVecXPrev[iI] = m_pdVecX[iI];
    }
    std::cout << "dError = " << dError << std::endl;
    iIter++;
  }
  return pobjVecX;
}
void CJacobiSolver::SetNewThreshold(const double& dThreshold)
{
    m_dThreshold = dThreshold;
}
void CJacobiSolver::SetNewMatA(CMatrix& objMatA)
{
  if (objMatA.GetRows() != objMatA.GetColumns())
  {
    std::cout << "New matrix A is not a square matrix" << std::endl;
    abort();
  }
  m_pdMatA = objMatA.GetMat();
  m_iRows = objMatA.GetRows();
  m_iColumns = objMatA.GetColumns();
}
void CJacobiSolver::SetNewVecB(CVector& objVecB)
{
  if (m_iColumns != objVecB.GetRows())
  {
    std::cout << "A's column number " << m_iColumns
      << " is not equal to new B's row number " << m_iRows << std::endl;
    abort();
  }
  m_pdVecB = objVecB.GetVector();
}