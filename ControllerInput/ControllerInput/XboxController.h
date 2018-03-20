#pragma once

typedef enum
{
	GamePad_Button_DPAD_UP = 0,
	GamePad_Button_DPAD_DOWN = 1,
	GamePad_Button_DPAD_LEFT = 2,
	GamePad_Button_DPAD_RIGHT = 3,
	GamePad_Button_START = 4,
	GamePad_Button_BACK = 5,
	GamePad_Button_LEFT_THUMB = 6,
	GamePad_Button_RIGHT_THUMB = 7,
	GamePad_Button_LEFT_SHOULDER = 8,
	GamePad_Button_RIGHT_SHOULDER = 9,
	GamePad_Button_A = 10,
	GamePad_Button_B = 11,
	GamePad_Button_X = 12,
	GamePad_Button_Y = 13,
	GamePadButton_Max = 14
}GamePadButton;

typedef enum
{
	GamePadIndex_One = 0,
	GamePadIndex_Two = 1,
	GamePadIndex_Three = 2,
	GamePadIndex_Four = 3
}GamePadIndex;

struct Vector2
{
	float x;
	float y;
};

struct ControllerState
{
	bool _buttons[GamePadButton_Max];
	float _left_trigger;
	float _right_trigger;
	Vector2 _left_thumbstick;
	Vector2 _right_thumbstick;

	void reset()
	{
		for (int i = 0; i < (int)GamePadButton_Max; ++i) _buttons[i] = false;
		_left_trigger = _right_trigger = 0.0f;
	}

};

class XboxController
{
public:
	XINPUT_STATE _controllerState;
	GamePadIndex _playerIndex;
	ControllerState State;
	XboxController(GamePadIndex player);

	virtual ~XboxController(void);

	bool is_connected();
	void vibrate(float leftmotor = 0.0f, float rightmotor = 0.0f);
	XINPUT_STATE GetState();
	
};

