@echo off
mkdir %~dp0\appbundle
mkdir %~dp0\appbundle\images

copy %~dp0\AppxManifest.xml %~dp0\appbundle\
copy %~dp0\application.exe %~dp0\appbundle\
copy %~dp0\icon.png %~dp0\appbundle\images\

makeappx pack /v /h SHA256 /d %~dp0\appbundle /p appbundle.appx /overwrite
