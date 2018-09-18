@echo off
mkdir debug
pushd debug
cl ..\source\RePC.cpp ..\source\pc_lib.cpp
popd