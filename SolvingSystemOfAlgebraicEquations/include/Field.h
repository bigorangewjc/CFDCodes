#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "Vector.h"

class CLoadConfig;
class CMesh;
class CField
{
public:
    CField(const CLoadConfig &objConfig, const CMesh &objMesh);
    virtual ~CField();
    inline CVector& GetVec();
    inline const CVector& GetVec() const;
    void PrintField();

private:
    bool CreateInitialField(const CMesh &objMesh);

private:
    CVector &m_objVec;
    double *m_pdField;
    int m_iNumPoints;
    std::string m_sInitStrategy;
};

#include "Field.h"

#endif //FIELD_H