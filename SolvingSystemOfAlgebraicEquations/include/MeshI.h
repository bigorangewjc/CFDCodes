#include <iostream>

inline const double &CMesh::operator()(const int iI) const
{
    if (nullptr == m_pdMesh)
    {
        std::cout << "m_pdMesh is nullptr!" << std::endl;
        abort();
    }
    if (iI < 0 || iI >= m_iNumPoints)
    {
        std::cout << "iI = " << iI << " is out of range 0..." << m_iNumPoints - 1
                  << std::endl;
        abort();
    }
    return m_pdMesh[iI];
}

inline const int &CMesh::GetMeshSize() const
{
    return m_iNumPoints;
}