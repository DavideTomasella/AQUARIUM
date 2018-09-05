#ifndef FILE_H
#define FILE_H

#include <QtGlobal>

QT_BEGIN_NAMESPACE
class QObject;

QT_END_NAMESPACE

class FILETYPE {
public:
   static const int Nothing = 0;
   static const int Open = 1;
   static const int Close = 2;
   static const int OpenNClose = 3;
};

extern void LOAD_GLOBALS();
extern void LOAD_PARAM(int _DATATYPE, int _FILETYPE);
extern void SAVE_GLOBALS();
extern void SAVE_PARAM(int _DATATYPE, int _FILETYPE);
extern void openFile();
extern void closeFile();

#endif // FILE_H
