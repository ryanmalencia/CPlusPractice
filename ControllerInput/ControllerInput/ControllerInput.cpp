// ControllerInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <Xinput.h>
#include "XboxController.h"
#include <iostream>
#pragma comment(lib, "XInput.lib")

using namespace std;

int main()
{
	XboxController controller(GamePadIndex_One);
	int start = 0;
	int off = 0;
	while (true)
	{
		if (controller.is_connected())
		{
			if (start == 0)
			{
				cout << "Controller connected" << endl;
				start++;
			}

			if (controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
			{
				cout << "Pressed A";
				controller.vibrate(65535, 0);
			}

			if (controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
			{
				cout << "Pressed B";
				controller.vibrate(0, 65535);
			}

			if (controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
			{
				cout << "Pressed X";
				controller.vibrate(65535, 65535);
			}

			if (controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
			{
				cout << "Pressed Y";
				controller.vibrate();
			}

			if (controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
			{
				cout << "Exiting";
				break;
			}
			off = 0;
		}
		else
		{
			if (off == 0)
			{
				cout << "No controller found" << endl;
				off++;
			}
			start = 0;
		}
	}
    return 0;
}

