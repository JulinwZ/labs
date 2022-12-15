@echo off

echo %time%
timeout 1 > NUL
echo %time%

start "" main.exe

echo %time%
timeout 3 > NUL
echo %time%

start "" main.exe

echo %time%
timeout 3 > NUL
echo %time%

start "" main.exe