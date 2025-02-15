#pragma once
#ifndef KEYHANDLER
#define KEYHANDLER

#include <stdio.h>
#include <string>
// Include the Win32 API
#include <Windows.h>
// Handles ANSI and Unicode strings
#include <tchar.h>

void keyLogic(WPARAM key);

#endif
