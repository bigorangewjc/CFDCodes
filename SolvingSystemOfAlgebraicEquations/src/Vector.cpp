#include "Vector.h"
#include <iostream>

CVector::CVector(int iRows)
  : m_iRows(iRows)
  , m_pdVec(nullptr)
{
  m_pdVec = new double [m_iRows]; 
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdVec[i] = 0.0;
  }
}

CVector::CVector(const CVector& objVector)
{
  m_iRows = objVector.GetNumRows();
  m_pdVec = new double [m_iRows];
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdVec[i] = objVector(i);
  }
}

CVector::~CVector()
{
  delete[] m_pdVec;
}

inline double* CVector::GetVec() const
{
    return m_pdVec;
}

inline int CVector::GetNumRows() const
{
  return m_iRows;
}

inline double& CVector::operator()(const int iRow) const
{
    if (nullptr == m_pdVec)
    {
        std::cout << "m_pdVec has not been initialized" << std::endl;
        abort();
    }
    return m_pdVec[iRow];
}

void CVector::Print()
{
  std::cout << "m_pdVector = " << std::endl;
  std::cout << "[" << m_pdVec[0] << std::endl;
  for (int iRow = 1; iRow < m_iRows-1; iRow++)
  {
    std::cout << " " << m_pdVec[iRow] << std::endl;;
  }
  std::cout << " " << m_pdVec[m_iRows-1] << "]" << std::endl;
}
