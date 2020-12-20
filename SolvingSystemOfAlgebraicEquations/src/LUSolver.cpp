#ifdef JCWANG
#include "LUSolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CLUSolver::CLUSolver(CMatrix& objMatA, CVector& objVecB)
  : m_pdMatA(objMatA.GetMat()) 
  , m_pdVecB(objVecB.GetVector())
  , m_iRows(objVecB.GetNumRows())
  , m_iColumns(objMatA.GetNumCols())
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

CLUSolver::~CLUSolver()
{

}

double* CLUSolver::Solve(std::string sMethod)
{
  if ("Crout" == sMethod)
  {
    LUFactorization();
  }
  else if ("Gauss")
  {
    LUFactorizationByGaussElimination();
  }
  else
  {
    std::cout << "Unrecognized sMethod: " << sMethod << std::endl;
    abort();
  }
  ForwardSubstitution();
  BackwardSubstitution();
  return m_pdVecB;
}

double* CLUSolver::SolveNewB(CVector& objVecB)
{
  if (m_iColumns != objVecB.GetNumRows())
  {
    std::cout << "A's column number " << m_iColumns
      << " is not equal to new B's row number "
       << objVecB.GetNumRows() << std::endl;
    abort();
  }
  m_pdVecB = objVecB.GetVector();
  ForwardSubstitution();
  BackwardSubstitution();
  return m_pdVecB;
}

void CLUSolver::LUFactorization()
{
  // The first row of U equals to that of A
  // Calculate the first column of L
  for (int iM = 1; iM < m_iRows; iM++)
  {
    m_pdMatA[iM][0] /= m_pdMatA[0][0];
  }
  // Calculate the rest of U and L
  for (int iI = 1; iI < m_iRows; iI++)
  {
    // Calcute iI-th row of U
    for (int iJ = iI; iJ < m_iColumns; iJ++)
    {
      // iI is the real index minus one, so iK < iI
      for (int iK = 0; iK < iI; iK++)
      {
        m_pdMatA[iI][iJ] -= m_pdMatA[iI][iK] * m_pdMatA[iK][iJ];
      }
    }
    // Calculate iI-th column of L
    // The for loop will just return when iI = m_iRows-1, because of
    //   the loop condition is iM = iI+1 < m_iRows
    for (int iM = iI+1; iM < m_iRows; iM++)
    {
      // iI is the real index minus one, so iK < iI
      for (int iK = 0; iK < iI; iK++)
      {
        m_pdMatA[iM][iI] -= m_pdMatA[iM][iK] * m_pdMatA[iK][iI];
      }
      m_pdMatA[iM][iI] /= m_pdMatA[iI][iI];
    }
  }
}

void CLUSolver::LUFactorizationByGaussElimination()
{
  for (int iElim = 0; iElim < m_iRows-1; iElim++)
  {
    for (int iI = iElim+1; iI < m_iRows; iI++)
    {
      // The elements in column iElim of U is zero, so we replace the zero
      //    in U by element of L at the same position
      m_pdMatA[iI][iElim] /= m_pdMatA[iElim][iElim];
      for (int iJ =iElim+1; iJ < m_iColumns; iJ++)
      {
        m_pdMatA[iI][iJ] -= m_pdMatA[iI][iElim] * m_pdMatA[iElim][iJ];
      }
    }
  }
}

void CLUSolver::ForwardSubstitution()
{
  // Calculate solution vector y in system of L y = b
  // The first element in vector y is equals to that in vector b
  // Calculate the rest elements in vector y
  for (int iI = 1; iI < m_iRows; iI++)
  {
      // iI is the real index minus one, so iJ < iI
    for (int iJ = 0; iJ < iI; iJ++)
    {
      // m_pdMatA is lower triangular matrix
      m_pdVecB[iI] -= m_pdMatA[iI][iJ] * m_pdVecB[iJ];
    }
  }
}

void CLUSolver::BackwardSubstitution()
{
  // Calculate solution vector x in system of U x = y
  // Calculate the last element in vector x
  m_pdVecB[m_iRows-1] /= m_pdMatA[m_iRows-1][m_iRows-1];
  // Calculate the rest elements in vector x
  for (int iI = m_iRows-2; iI >= 0; iI--)
  {
    for (int iJ = iI+1; iJ < m_iColumns; iJ++)
    {
      // m_pdMatA is upper triangular matrix
      m_pdVecB[iI] -= m_pdMatA[iI][iJ] * m_pdVecB[iJ];
    }
    m_pdVecB[iI] /= m_pdMatA[iI][iI];
  }
}
#endif