// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIOUYAANDROID_H
#define	MOAIOUYAANDROID_H

#ifndef DISABLE_OUYA

#include <moaicore/moaicore.h>

//================================================================//
// MOAIOuyaAndroid
//================================================================//
/**	@name	MOAIOuyaAndroid
	@text	Wrapper for OUYA integration on Android devices.
			
	@const 	AXIS_L2				Code for the left trigger axis
	@const 	AXIS_LS_X			Code for the left joystick x axis.
	@const 	AXIS_LS_Y			Code for the left joystick y axis.
	@const 	AXIS_R2				Code for the right trigger axis
	@const 	AXIS_RS_X			Code for the right joystick x axis.
	@const 	AXIS_RS_Y			Code for the right joystick y axis.
	@const 	BUTTON_A 			Code for the A button.
	@const 	BUTTON_DPAD_DOWN	Code for the D-pad down button.
	@const 	BUTTON_DPAD_LEFT	Code for the D-pad left button.
	@const 	BUTTON_DPAD_RIGHT	Code for the D-pad right button.
	@const 	BUTTON_DPAD_UP		Code for the D-pad up button.
	@const 	BUTTON_L1			Code for the left bumper button.
	@const 	BUTTON_L2			Code for the left trigger button. Considered pressed when AXIS_L2 > 0.5
	@const 	BUTTON_L3 			Code for left joystick button.
	@const 	BUTTON_O 			Code for the O button.
	@const 	BUTTON_R1			Code for the right bumper button. Considered pressed when AXIS_R2 > 0.5
	@const 	BUTTON_R2			Code for the right trigger button.
	@const 	BUTTON_R3 			Code for right joystick button.
	@const 	BUTTON_SYSTEM		Code for the system menu button.
	@const 	BUTTON_U 			Code for the U button.
	@const 	BUTTON_Y 			Code for the Y button.
	@const 	MAX_CONTROLLERS		Max Number of Controllers Supported

	@const	TOTAL				No Idea
*/
class MOAIOuyaAndroid :
	public MOAIGlobalClass < MOAIOuyaAndroid, MOAILuaObject > {
		
private:

	//----------------------------------------------------------------//
	static int	_setListener	( lua_State* L );
	
public:

	DECL_LUA_SINGLETON ( MOAIOuyaAndroid );

	enum {
		OUYA_BUTTON_DOWN,
		OUYA_BUTTON_UP,
		OUYA_MOTION_EVENT,
		TOTAL
	};
	
	MOAILuaRef		mListeners [ TOTAL ];

	//----------------------------------------------------------------//
	// Controller Constants 

	/**static const int AXIS_L2 = 17;
	static const int AXIS_LS_X = 0;
	static const int AXIS_LS_Y	= 1;
	static const int AXIS_R2 = 18;
	static const int AXIS_RS_X	= 11;
	static const int AXIS_RS_Y = 14;
	static const int BUTTON_A = 97;
	static const int BUTTON_DPAD_DOWN = 20;
	static const int BUTTON_DPAD_LEFT = 21;
	static const int BUTTON_DPAD_RIGHT = 22;
	static const int BUTTON_DPAD_UP = 19;
	static const int BUTTON_L1	= 102;
	static const int BUTTON_L2	= 104;
	static const int BUTTON_L3	= 106;
	static const int BUTTON_O	= 96;
	static const int BUTTON_R1	= 103;
	static const int BUTTON_R2	= 105;
	static const int BUTTON_R3	= 107;
	static const int BUTTON_SYSTEM	= 3;
	static const int BUTTON_U = 99;
	static const int BUTTON_Y = 100;
	static const int MAX_CONTROLLERS = 4;*/	
	
	//----------------------------------------------------------------//
	void    Finish                  ();
			MOAIOuyaAndroid			();
			~MOAIOuyaAndroid		();
	void	NotifyOuyaButtonDown	( int keyCode, int deviceId );
	void	NotifyOuyaButtonUp		( int keyCode, int deviceId );
	void  	NotifyOuyaMotionEvent  ( float leftAxisX, float leftAxisY, float rightAxisX, float rightAxisY, int deviceId ); 
	void	RegisterLuaClass		( MOAILuaState& state );
};

#endif  //DISABLE_OUYA

#endif  //MOAIOUYAANDROID_H
