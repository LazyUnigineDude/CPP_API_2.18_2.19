#ifdef UNIGINE_PS5
	#include <UnigineInit.h>
#include <UniginePS5Init.h>
#endif
#include <UnigineEngine.h>

#include "AppEditorLogic.h"
#include "AppSystemLogic.h"
#include "AppWorldLogic.h"

#ifdef _WIN32
int wmain(int argc, wchar_t *argv[])
#else
int main(int argc, char *argv[])
#endif
{
	// UnigineLogic
	AppSystemLogic system_logic;
	AppWorldLogic world_logic;
	AppEditorLogic editor_logic;

	// init engine
	Unigine::EnginePtr engine(argc, argv);

	// enter main loop
	engine->main(&system_logic, &world_logic, &editor_logic);

	return 0;
}

#ifdef _WIN32
#include <Windows.h>
extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
extern "C" __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
#endif
