#include "Mesh.h"
#include <iostream>
#include <math.h>
#include "LoadConfig.h"

CMesh::CMesh(const CLoadConfig &objConfig)
    : m_dLength(0.0)
    , m_iNumPoints(0)
    , m_pdMesh(nullptr)
{
    bool bRet = objConfig.GetParam(std::string("Length"), m_dLength);
    if (!bRet)
    {
        abort();
    }
    bRet = objConfig.GetParam(std::string("NumPoints"), m_iNumPoints);
    if (!bRet)
    {
        abort();
    }
    if (0 == m_iNumPoints)
    {
        std::cout << "ERROR: m_iNumPoints = 0" << std::endl;
        abort();
    }
    if (0.0 == m_dLength)
    {
        std::cout << "ERROR: m_dLength = 0.0" << std::endl;
        abort();
    }
    CreateInitialMesh();
}

CMesh::~CMesh()
{
    delete[] m_pdMesh;
}

void CMesh::CreateInitialMesh()
{
    m_pdMesh = new double[m_iNumPoints];
    double dDeltaLength = m_dLength / m_iNumPoints;
    double dIndependentVariable = 0.0;
    for (int i = 0; i < m_iNumPoints; i++)
    {
        m_pdMesh[i] = dIndependentVariable;
        dIndependentVariable += dDeltaLength;
    }
}

void CMesh::PrintMesh()
{
    if (nullptr == m_pdMesh)
    {
        std::cout << "m_pdMesh is nullptr!" << std::endl;
    }
    std::cout << "Mesh:" << std::endl;
    for (int i = 0; i < m_iNumPoints; i++)
    {
        std::cout << m_pdMesh[i] << std::endl;
    }
}
