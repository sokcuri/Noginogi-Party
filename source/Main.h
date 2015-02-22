#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <process.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "wchar.h"
#include <tchar.h>
#include <basetsd.h>
#include <stdarg.h>
#include "Aclapi.h"
#include "AccCtrl.h"
#include <psapi.h>
#include <Tlhelp32.h>

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <stack>
#include <fstream>

#include <assert.h>

// Boost libraries
// Make sure these are installed!
// Make sure that C:\Program Files\boost\boost_1_39 (or whatever) is included in
//    Project Properties -> Configuration Properties -> C/C++
//    -> General -> Additional Include Directories

#include <boost/assign/std/vector.hpp>

#include "../Resource/resource.h"

using namespace std;
using namespace boost::assign;

#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)

typedef unsigned int uint;
typedef unsigned long ulong;
typedef __int64 int64;
typedef wchar_t wchar;

extern HHOOK hHook;
extern bool g_isRunning;
extern HINSTANCE g_hInstance;