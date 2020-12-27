#ifndef FIELD_H
#define FIELD_H

#include <string>

class CLoadConfig;
class CMesh;
class CField
{
public:
    CField(const CLoadConfig &objConfig, const CMesh& objMesh);
    virtual ~CField();
    void PrintField();

private:
    bool CreateInitialField(const CMesh& objMesh);

private:
    double *m_pdField;
    int m_iNumPoints;
    std::string m_sInitStrategy;
};

#endif //FIELD_H