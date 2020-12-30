#ifndef EXPLICIT_SCHEMES_H
#define EXPLICIT_SCHEMES_H

class CField;

namespace fdc
{
    CField &ddt(const CField &objField);
    CField &ddx(const CField &objField);
    CField &d2dx2(const CField &objField);
} // namespace fdc

#endif // EXPLICIT_SCHEMES_H