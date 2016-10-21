#include <Windows.h>
#include <iostream>


int wmain()
{
	HWND hwnd = NULL;
	//Color of wood 
	COLORREF woodColor = RGB(161, 116, 56);

	//get hwnd of chrome browser
	for (;;)
	{
		hwnd = FindWindowEx(0, hwnd, "Chrome_WidgetWin_1", 0);
		if (!hwnd)
			break;

		if (!IsWindowVisible(hwnd))
			continue;
		//ShowWindow(hwnd, SW_MINIMIZE);
		//SetFocus(hwnd);

		break;
	}


	HDC hdcChrome = GetDC(hwnd);
	bool WoodOnLeft = true;
	COLORREF colorNEXT;

	for (;;) {

		Sleep(172);
		colorNEXT = GetPixel(hdcChrome, 400, 665);
		
		if (colorNEXT == woodColor) {
			WoodOnLeft = true;
		}
		else{
			WoodOnLeft = false;
		}

		if (WoodOnLeft){

			keybd_event(VK_RIGHT, NULL, NULL, NULL);
			Sleep(17);
			keybd_event(VK_RIGHT, NULL, NULL, NULL);
		}
		else {

			keybd_event(VK_LEFT, NULL, NULL, NULL);
			Sleep(17);
			keybd_event(VK_LEFT, NULL, NULL, NULL);
		}

	}
	
	return 0;
}