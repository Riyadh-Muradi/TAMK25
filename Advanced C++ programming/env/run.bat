@echo off
setlocal enabledelayedexpansion

set "IMAGE_NAME=cpp-course-pohjolainen"

rem Build context should be this script's directory to avoid running from elsewhere.
set "SCRIPT_DIR=%~dp0."

rem Check if Docker is installed.
where docker >nul 2>&1
if errorlevel 1 (
  echo Docker not installed or not in PATH.
  exit /b 1
)

rem Check if Docker daemon is running.
docker info >nul 2>&1
if errorlevel 1 (
  echo Docker not running, please start Docker.
  exit /b 1
)

echo 🔧 Building C++ environment (Docker image: %IMAGE_NAME%)
docker build -t "%IMAGE_NAME%" "%SCRIPT_DIR%"

echo.
echo Starting C++ development environment
echo Workspace:
echo      %cd%
echo Compile:
echo      clang++ -std=c++20 -Wall -Wextra mycode.cpp -o mycode
echo Run:
echo      ./mycode
echo Edit files (inside the container):
echo      nano mycode.cpp
echo Exit:
echo      exit

docker run --rm -it ^
  -e TERM=xterm-256color ^
  -v "%cd%":/workspace ^
  "%IMAGE_NAME%"
