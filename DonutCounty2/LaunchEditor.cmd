if not defined UNREAL_DIRECTORY (
	set UNREAL_DIRECTORY=C:\Program Files\Epic Games
)

call "%UNREAL_DIRECTORY%\UE_5.5\Engine\Build\BatchFiles\Build.bat" -Target="DonutCounty2Editor Win64 Development" -Project="%cd%\DonutCounty2.uproject"
start "" "%UNREAL_DIRECTORY%\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe" -Project="%cd%\DonutCounty2.uproject"