#ifndef MESH_H
#define MESH_H

#include <string>

class CLoadConfig;
class CMesh
{
public:
    CMesh(const CLoadConfig &objConfig);
    virtual ~CMesh();
    inline const double& operator()(const int iI) const;
    inline const int& GetMeshSize() const;
    void PrintMesh();

private:
    void CreateInitialMesh();

private:
    double m_dLength;
    double *m_pdMesh;
    int m_iNumPoints;
};

#include "MeshI.h"

#endif //MESH_H
