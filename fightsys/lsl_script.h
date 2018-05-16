#pragma once

#include <vector>
#include <map>
#include <deque>
#include <string>
#include <intsafe.h>
#include <memory>

class Lsl_FN;
class Lsl_Param;
class Lsl_Func;
class Lsl_Config;
class Lsl_App;

typedef std::shared_ptr<Lsl_FN>			Lsl_FNPtr;
typedef std::shared_ptr<Lsl_Param>		Lsl_ParamPtr;
typedef std::shared_ptr<Lsl_Func>		Lsl_FuncPtr;
typedef std::shared_ptr<Lsl_Config>		Lsl_ConfigPtr;
typedef std::shared_ptr<Lsl_App>		Lsl_AppPtr;
