// fightsys.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TinyXml2/tinyxml2.h"
#include "lsl_script.h"
#include "lsl_config.h"
#include "lsl_app.h"

using namespace tinyxml2;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	GetLslConfig()->LoadConfigFromString("");

	Lsl_AppPtr app = Lsl_AppPtr(new Lsl_App);
	app->GetPtr();
	app->GetPtr()->RunScript("Eat", Lsl_ParamPtr());

	getchar();

	return 0;
}

