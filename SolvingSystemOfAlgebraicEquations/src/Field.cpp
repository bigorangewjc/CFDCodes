#include "Field.h"
#include <iostream>
#include <math.h>
#include "LoadConfig.h"
#include "Mesh.h"

CField::CField(const CLoadConfig &objConfig, const CMesh &objMesh)
    : m_iNumPoints(objMesh.GetMeshSize())
    , m_pdField(nullptr)
    , m_sInitStrategy("")
    , m_objVec(*(new CVector(objMesh.GetMeshSize())))
{
    bool bRet = objConfig.GetParam(std::string("InitStrategy"), m_sInitStrategy);
    if (!bRet)
    {
        abort();
    }
    if ("" == m_sInitStrategy)
    {
        std::cout << "ERROR: m_sInitStrategy = \" \" " << std::endl;
        abort();
    }
    bRet = CreateInitialField(objMesh);
    if (!bRet)
    {
        abort();
    }
}

CField::~CField()
{
    delete &m_objVec;
}

bool CField::CreateInitialField(const CMesh &objMesh)
{
    m_pdField = new double[m_iNumPoints];
    if (m_sInitStrategy == "sin")
    {
        for (int iI = 0; iI < m_iNumPoints; iI++)
        {
            m_objVec(iI) = std::sin(objMesh(iI));
        }
    }
    else
    {
        std::cout << "Unrecognized InitStrategy: " << m_sInitStrategy
                  << std::endl;
        return false;
    }
    return true;
}

void CField::PrintField()
{
    std::cout << "Field:" << std::endl;
    for (int iI = 0; iI < m_iNumPoints; iI++)
    {
        std::cout << m_objVec(iI) << std::endl;
    }
}
