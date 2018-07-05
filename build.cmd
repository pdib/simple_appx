@echo off


set COMMON_COMPILER_FLAGS=/EHsc /std:c++17 /Zi /Od /DWINRT_NATVIS
set COMMON_LINKER_FLAGS=/SUBSYSTEM:WINDOWS

set COMPILER_ARGUMENTS=application.cpp
set LINKER_ARGUMENTS=runtimeobject.lib WindowsApp.lib user32.lib shcore.lib

cl.exe %COMMON_COMPILER_FLAGS% %COMPILER_ARGUMENTS% /link %COMMON_LINKER_FLAGS% %LINKER_ARGUMENTS%

if errorlevel 1 (
   echo [FAILURE]: %errorlevel%
   exit /b %errorlevel%
)

%~dp0pack.cmd
