#ifndef HELPER_CLASS_H
#define HELPER_CLASS_H

#include <QObject>
class HelperClass
{
  public:
    static quint16 BeToUint16(quint8* pData)
    {
        return ((pData[0] << 8) | pData[1]);
    }

    static quint16 LeToUint16(quint8* pData)
    {
        return ((pData[1] << 8) | pData[0]);
    }
};

#endif
