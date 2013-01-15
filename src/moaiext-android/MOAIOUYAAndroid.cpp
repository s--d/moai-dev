// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef DISABLE_OUYA

#include "pch.h"

#include <jni.h>
#include <moaicore/moaicore.h>
#include <moaiext-android/moaiext-jni.h>
#include <moaiext-android/MOAIOuyaAndroid.h>

extern JavaVM* jvm;

//================================================================//
// OUYA JNI methods
//================================================================//

//----------------------------------------------------------------//
extern "C" void Java_com_ziplinegames_moai_MoaiOuya_AKUNotifyOuyaButtonDown ( JNIEnv* env, jclass obj, jint code, jint deviceId ) {
	MOAIOuyaAndroid::Get ().NotifyOuyaButtonDown ( code , deviceId );
}

extern "C" void Java_com_ziplinegames_moai_MoaiOuya_AKUNotifyOuyaButtonUp ( JNIEnv* env, jclass obj, jint code, jint deviceId ) {
	MOAIOuyaAndroid::Get ().NotifyOuyaButtonUp ( code , deviceId );
}

extern "C" void Java_com_ziplinegames_moai_MoaiOuya_AKUNotifyOuyaMotionEvent ( JNIEnv* env, jclass obj, jfloat axisX, jfloat axisY, jint deviceId ) {
	MOAIOuyaAndroid::Get ().NotifyOuyaMotionEvent ( axisX , axisY, deviceId );
}

//----------------------------------------------------------------//
void MOAIOuyaAndroid::NotifyOuyaButtonDown ( int keyCode, int deviceId ) {

	MOAILuaRef& callback = this->mListeners [ OUYA_BUTTON_DOWN ];

	if ( callback ) {

		MOAILuaStateHandle state = callback.GetSelf ();

		state.Push ( keyCode );
		state.Push ( deviceId );
		
		state.DebugCall ( 2, 0 );

	}
	
}

void MOAIOuyaAndroid::NotifyOuyaButtonUp ( int keyCode, int deviceId ) {

	MOAILuaRef& callback = this->mListeners [ OUYA_BUTTON_UP ];

	if ( callback ) {

		MOAILuaStateHandle state = callback.GetSelf ();

		state.Push ( keyCode );
		state.Push ( deviceId );
		
		state.DebugCall ( 2, 0 );

	}
	
}

void MOAIOuyaAndroid::NotifyOuyaMotionEvent ( float axisX, float axisY, int deviceId ) {

	MOAILuaRef& callback = this->mListeners [ OUYA_MOTION_EVENT ];

	if ( callback ) {

		MOAILuaStateHandle state = callback.GetSelf ();

		state.Push ( axisX );
		state.Push ( axisY );
		state.Push ( deviceId );
		
		state.DebugCall ( 3, 0 );

	}
	
}


//================================================================//
// MOAIOuyaAndroid
//================================================================//

//----------------------------------------------------------------//
void MOAIOuyaAndroid::Finish () {
  USLog::Print ( "MOAIOuyaAndroid: Finish ");
}

//----------------------------------------------------------------//
MOAIOuyaAndroid::MOAIOuyaAndroid () {

	RTTI_SINGLE ( MOAILuaObject )	
}

//----------------------------------------------------------------//
MOAIOuyaAndroid::~MOAIOuyaAndroid () {
	this->Finish();

}


//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
int MOAIOuyaAndroid::_setListener ( lua_State* L ) {
	
	MOAILuaState state ( L );
	
	u32 idx = state.GetValue < u32 >( 1, TOTAL );
	
	if ( idx < TOTAL ) {
		
		MOAIOuyaAndroid::Get ().mListeners [ idx ].SetStrongRef ( state, 2 );
	}
	
	return 0;
}


//----------------------------------------------------------------//
void MOAIOuyaAndroid::RegisterLuaClass ( MOAILuaState& state ) {

	state.SetField ( -1, "OUYA_BUTTON_DOWN",    ( u32 )OUYA_BUTTON_DOWN );
	state.SetField ( -1, "OUYA_BUTTON_UP",    ( u32 )OUYA_BUTTON_DOWN );
	state.SetField ( -1, "OUYA_MOTION_EVENT",    ( u32 )OUYA_BUTTON_DOWN );

	/*state.SetField ( -1, "AXIS_L2",    			( u32 )AXIS_L2 );
	state.SetField ( -1, "AXIS_LS_X",    		( u32 )AXIS_LS_X );
	state.SetField ( -1, "AXIS_LS_Y",    		( u32 )AXIS_LS_Y );
	state.SetField ( -1, "AXIS_R2",    			( u32 )AXIS_R2 );
	state.SetField ( -1, "AXIS_RS_X",    		( u32 )AXIS_RS_X );
	state.SetField ( -1, "AXIS_RS_Y",    		( u32 )AXIS_RS_Y );
	state.SetField ( -1, "BUTTON_A",    		( u32 )BUTTON_A );
	state.SetField ( -1, "BUTTON_DPAD_DOWN",    ( u32 )BUTTON_DPAD_DOWN );
	state.SetField ( -1, "BUTTON_DPAD_LEFT",    ( u32 )BUTTON_DPAD_LEFT );
	state.SetField ( -1, "BUTTON_DPAD_RIGHT",   ( u32 )BUTTON_DPAD_RIGHT );
	state.SetField ( -1, "BUTTON_DPAD_UP",    	( u32 )BUTTON_DPAD_UP );
	state.SetField ( -1, "BUTTON_L1",    		( u32 )BUTTON_L1 );
	state.SetField ( -1, "BUTTON_L2",    		( u32 )BUTTON_L2 );
	state.SetField ( -1, "BUTTON_L3",   		( u32 )BUTTON_L3 );
	state.SetField ( -1, "BUTTON_O",    		( u32 )BUTTON_O );
	state.SetField ( -1, "BUTTON_R1",    		( u32 )BUTTON_R1 );
	state.SetField ( -1, "BUTTON_R2",    		( u32 )BUTTON_R2 );
	state.SetField ( -1, "BUTTON_R3",    		( u32 )BUTTON_R3 );
	state.SetField ( -1, "BUTTON_SYSTEM",    	( u32 )BUTTON_SYSTEM );
	state.SetField ( -1, "BUTTON_U",    		( u32 )BUTTON_U );
	state.SetField ( -1, "BUTTON_Y",    		( u32 )BUTTON_Y );
	state.SetField ( -1, "MAX_CONTROLLERS",		( u32 )MAX_CONTROLLERS );*/

	luaL_Reg regTable [] = {
		{ "setListener",	_setListener },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}


#endif