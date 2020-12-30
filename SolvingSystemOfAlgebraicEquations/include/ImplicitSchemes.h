#ifndef IMPLICIT_SCHEMES_H
#define IMPLICIT_SCHEMES_H

class CFdMatrix;
class CField;

namespace fdm
{
    CFdMatrix &ddt(const CField &objField);
    CFdMatrix &ddx(const CField &objField);
    CFdMatrix &d2dx2(const CField &objField);
} // namespace fdm

#endif //IMPLICIT_SCHEMES_H