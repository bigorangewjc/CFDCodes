#include <iostream>

inline double* CVector::GetVec() const
{
    return m_pdVec;
}

inline int CVector::GetNumRows() const
{
  return m_iRows;
}

inline double& CVector::operator()(const int iRow)
{
    if (nullptr == m_pdVec)
    {
        std::cout << "m_pdVec has not been initialized" << std::endl;
        abort();
    }
    return m_pdVec[iRow];
}

inline const double& CVector::operator()(const int iRow) const
{
    if (nullptr == m_pdVec)
    {
        std::cout << "m_pdVec has not been initialized" << std::endl;
        abort();
    }
    return m_pdVec[iRow];
}