@echo off
setlocal
set "test=sample"
if %1.==. goto start
set "test=%1"
:start
%test% -?
%test% -b 101
%test% -B 1100101
%test% -h 101
%test% -H 0x65
%test% -o 101
%test% -O 0145
endlocal
