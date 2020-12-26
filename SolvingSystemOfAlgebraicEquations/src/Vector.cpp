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

void CVector::Print() const
{
  std::cout << "m_pdVector = " << std::endl;
  std::cout << "[" << m_pdVec[0] << std::endl;
  for (int iRow = 1; iRow < m_iRows-1; iRow++)
  {
    std::cout << " " << m_pdVec[iRow] << std::endl;;
  }
  std::cout << " " << m_pdVec[m_iRows-1] << "]" << std::endl;
}
