#include <iostream>

inline double *CVector::GetVec() const
{
    return m_pdVec;
}

inline int CVector::GetNumRows() const
{
    return m_iRows;
}

inline double &CVector::operator()(const int iRow)
{
    if (nullptr == m_pdVec)
    {
        std::cout << "m_pdVec has not been initialized" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows - 1
                  << std::endl;
        abort();
    }
    return m_pdVec[iRow];
}

inline const double &CVector::operator()(const int iRow) const
{
    if (nullptr == m_pdVec)
    {
        std::cout << "m_pdVec has not been initialized" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows - 1
                  << std::endl;
        abort();
    }
    return m_pdVec[iRow];
}

inline CVector &CVector::operator+(const CVector &objVec)
{
    if (m_iRows != objVec.GetNumRows())
    {
        std::cout << "ERROR: m_iRows = " << m_iRows << " is not equal to objVec.GetNumRows() = "
                  << objVec.GetNumRows() << std::endl;
        abort();
    }
    for (int iI = 0; iI < m_iRows; iI++)
    {
        m_pdVec[iI] += objVec(iI);
    }
    return *this;
}

inline CVector &CVector::operator+=(const CVector &objVec)
{
    if (m_iRows != objVec.GetNumRows())
    {
        std::cout << "ERROR: m_iRows = " << m_iRows << " is not equal to objVec.GetNumRows() = "
                  << objVec.GetNumRows() << std::endl;
        abort();
    }
    for (int iI = 0; iI < m_iRows; iI++)
    {
        m_pdVec[iI] += objVec(iI);
    }
    return *this;
}