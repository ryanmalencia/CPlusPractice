#include "stdafx.h"
#include <Windows.h>
#include <Xinput.h>
#include "XboxController.h"
#pragma comment(lib, "XInput.lib")

XboxController::~XboxController()
{
	if (is_connected()) vibrate(0.0f, 0.0f);
}

XboxController::XboxController(GamePadIndex player)
{
	_playerIndex = player;
	State.reset();
}

void XboxController::vibrate(float left, float right)
{
	XINPUT_VIBRATION vibration;

	memset(&vibration, 0, sizeof(XINPUT_VIBRATION));

	vibration.wLeftMotorSpeed = (WORD)left;
	vibration.wRightMotorSpeed = (WORD)right;

	XInputSetState((int)_playerIndex, &vibration);
}

bool XboxController::is_connected()
{
	memset(&_controllerState, 0, sizeof(XINPUT_STATE));

	DWORD result = XInputGetState(_playerIndex, &_controllerState);

	if (result == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

XINPUT_STATE XboxController::GetState()
{
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	XInputGetState(_playerIndex, &_controllerState);

	return _controllerState;
}
