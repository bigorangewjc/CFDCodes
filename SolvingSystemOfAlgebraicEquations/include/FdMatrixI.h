inline CMatrix& CFdMatrix::GetMat()
{
    return m_objMat;
}

inline const CMatrix& CFdMatrix::GetMat() const
{
    return m_objMat;
}

inline CVector& CFdMatrix::GetVec()
{
    return m_objSrc;
}

inline const CVector& CFdMatrix::GetVec() const
{
    return m_objSrc;
}

inline CFdMatrix &CFdMatrix::operator+(const CFdMatrix &objFdMat)
{
    m_objMat += objFdMat.GetMat();
    return *this;
}

inline CFdMatrix &CFdMatrix::operator==(const CField &objField)
{
    m_objSrc += objField.GetVec();
    return *this;
}
