#ifndef __GUIDUTIL__
#define __GUIDUTIL__

#ifdef _OBJBASE_H_

#ifdef USE_STD_STRING
#include <string>
#endif

//  Outputting GUID names.  If you want to include the name
//  associated with a GUID (eg CLSID_...) then
//
//      GuidNames[yourGUID]
//
//  Returns the name defined in uuids.h as a string

typedef struct {
    const CHAR* szName;
    GUID    guid;
} GUID_STRING_ENTRY;

class CGuidNameList {
public:
    const CHAR* operator [] (const GUID& guid);
#ifdef USE_STD_STRING
    std::string GetString(const GUID& guid, bool allowhex);
#endif
};

extern CGuidNameList GuidNames;

#ifdef USE_STD_STRING
#define GET_GUID_NAME(guid) GuidNames.GetString(guid, true).c_str()
#else
#define GET_GUID_NAME(guid) GuidNames[guid]
#endif

#endif // _OBJBASE_H_

#endif // __GUIDUTIL__
