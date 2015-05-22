#ifndef LONGINTEGER_GLOBAL_H
#define LONGINTEGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LONGINTEGER_LIBRARY)
#  define LONGINTEGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LONGINTEGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LONGINTEGER_GLOBAL_H