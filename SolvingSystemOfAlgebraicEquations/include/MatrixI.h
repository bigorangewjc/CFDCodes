#include <iostream>

inline double** CMatrix::GetMat() const
{
    return m_pdMat;
}

inline int CMatrix::GetNumRows() const
{
    return m_iRows;
}

inline int CMatrix::GetNumCols() const
{
    return m_iCols;
}

inline double &CMatrix::operator()(const int iRow, const int iCol)
{
    if (nullptr == m_pdMat)
    {
        std::cout << "m_pdMat is nullptr!" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows-1
                  << std::endl;
        abort();
    }
    if (iCol < 0 || iCol >= m_iCols)
    {
        std::cout << "iCol = " << iCol << " is out of range 0..." << m_iCols-1
                  << std::endl;
        abort();
    }
    return m_pdMat[iRow][iCol];
}

inline const double &CMatrix::operator()(const int iRow, const int iCol) const
{
    if (nullptr == m_pdMat)
    {
        std::cout << "m_pdMat is nullptr!" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows-1
                  << std::endl;
        abort();
    }
    if (iCol < 0 || iCol >= m_iCols)
    {
        std::cout << "iCol = " << iCol << " is out of range 0..." << m_iCols-1
                  << std::endl;
        abort();
    }
    return m_pdMat[iRow][iCol];
}