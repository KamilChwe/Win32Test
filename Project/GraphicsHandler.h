// Following the "Direct2D QuickStart" to learn Direct2D for C++
// https://learn.microsoft.com/en-us/windows/win32/direct2d/getting-started-with-direct2d#drawing-a-simple-rectangle

#pragma once
#ifndef GRAPHICSHANDLER
#define GRAPHICSHANDLER

// Include the Win32 API
#include <Windows.h>
// Include the Direct2D API
#include <d2d1.h>


// Create a ID2D1Factory
// ID2D1Factory enables us to create Direct2D resources
ID2D1Factory* pD2DFactory = NULL;
HRESULT hr = D2D1CreateFactory(
	D2D1_FACTORY_TYPE_SINGLE_THREADED,
	&pD2DFactory
);



#endif

