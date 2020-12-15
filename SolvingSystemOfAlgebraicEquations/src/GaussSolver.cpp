#include "GaussSolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CGaussSolver::CGaussSolver(CMatrix& objMatA, CVector& objVecB)
  : m_pdMatA(objMatA.GetMat()) 
  , m_pdVecB(objVecB.GetVector())
  , m_iRows(objVecB.GetRows())
  , m_iColumns(objMatA.GetColumns())
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
}

CGaussSolver::~CGaussSolver()
{

}

double* CGaussSolver::Solve()
{
  // Forward elimination 
  // Complexity: (N-1)*(N-i)*(N-i+1), i = 1,...,N-1
  // Elimilate the iColElim-th variable of X for rows below row iColElim of matrix A
  for (int iColElim = 0; iColElim < m_iColumns-1; iColElim++)
  {
    for (int iRow = iColElim+1; iRow < m_iRows; iRow++)
    {
      // The element located in lower triangle of matrix will be eliminated
      //   to be zero, so the ratio of the element in lower triangle of matrix
      //    and the diagonal element is zero after eliminating. As a result, 
      //    we need to store the quotient in a new variable dRatio.
      double dRatio = m_pdMatA[iRow][iColElim] / m_pdMatA[iColElim][iColElim];
      // In fact, there's no need to calculate elements aligned in column iColElim
      for (int iCol = iColElim; iCol < m_iColumns; iCol++)
        {
          m_pdMatA[iRow][iCol] -= dRatio * m_pdMatA[iColElim][iCol]; 
        }
      m_pdVecB[iRow] -= dRatio * m_pdVecB[iColElim];
    }
  }
  // Backward substitution
  m_pdVecB[m_iRows-1] /= m_pdMatA[m_iRows-1][m_iColumns-1];
  for (int iRow = m_iRows-2; iRow >= 0; iRow--)
  {
    for (int iCol = iRow+1; iCol < m_iColumns; iCol++)
    {
      m_pdVecB[iRow] -= m_pdMatA[iRow][iCol] * m_pdVecB[iCol];
    }
    m_pdVecB[iRow] /= m_pdMatA[iRow][iRow]; 
  }
  return m_pdVecB;
}


void CGaussSolver::SetNewMatA(CMatrix& objMatA)
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
void CGaussSolver::SetNewVecB(CVector& objVecB)
{
  if (m_iColumns != objVecB.GetRows())
  {
    std::cout << "A's column number " << m_iColumns
      << " is not equal to new B's row number " << m_iRows << std::endl;
    abort();
  }
  m_pdVecB = objVecB.GetVector();
}