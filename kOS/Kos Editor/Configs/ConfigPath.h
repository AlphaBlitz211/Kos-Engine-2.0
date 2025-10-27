#pragma once
#include <string>

namespace configpath {
	constexpr const char* configFilePath = "Kos Editor/Configs/Config.json";
    constexpr const char* assetFilePath = "Kos Editor/Assets";
    constexpr const char* resourceFilePath = "Resource";
    constexpr const char* logFilePath = "LogFile.txt";
    constexpr const char* editorTagPath = "Kos Editor/Configs/editorTag.txt";
    constexpr const char* imguiINIPath = "Kos Editor/Configs/imgui.ini";
#ifdef _DEBUG
    constexpr const char* scriptWatherFilePath = "bin/Debug/SCRIPTS/SCRIPTS.dll";
#else
    constexpr const char* scriptWatherFilePath = "bin/Release/SCRIPTS/SCRIPTS.dll";
#endif
#ifdef _DEBUG
    constexpr const char* scriptReloadFilePath = "Kos Editor/PeformHotReload-Debug.bat";
#else
    constexpr const char* scriptReloadFilePath = "Kos Editor/PeformHotReload-Release.bat";
#endif
}