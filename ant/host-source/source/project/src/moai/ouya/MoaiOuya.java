//----------------------------------------------------------------//
// Copyright (c) 2010-2011 Zipline Games, Inc. 
// All Rights Reserved. 
// http://getmoai.com
//----------------------------------------------------------------//

package com.ziplinegames.moai;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.MotionEvent;

//Moai
import com.ziplinegames.moai.*;

//Ouya
import tv.ouya.console.api.*;

//================================================================//
// MoaiOuya
//================================================================//
public class MoaiOuya extends Activity{

  private static Activity sActivity = null;

  protected static native void AKUNotifyOuyaButtonDown  ( int keyCode, int deviceId );
  protected static native void AKUNotifyOuyaButtonUp  ( int keyCode, int deviceId );
  protected static native void AKUNotifyOuyaMotionEvent  ( float axisX, float axisY, int deviceId );

  //----------------------------------------------------------------//
  public static void onCreate ( Activity activity ) {
    MoaiLog.i ( "MoaiOuya onCreate: Initializing Ouya" );
    sActivity = activity;
  }

  //================================================================//
  // Ouya JNI callback methods
  //================================================================//

  //----------------------------------------------------------------//
  public static void NotifyOuyaButtonDown ( int keyCode, int deviceId ) {
    synchronized (Moai.sAkuLock) {
      AKUNotifyOuyaButtonDown (keyCode, deviceId);
    }
  }

  public static void NotifyOuyaButtonUp ( int keyCode, int deviceId ) {
    synchronized (Moai.sAkuLock) {
      AKUNotifyOuyaButtonUp (keyCode, deviceId);
    }
  }

  public static void NotifyOuyaMotionEvent ( float axisX, float axisY, int deviceId ) {
    synchronized (Moai.sAkuLock) {
      AKUNotifyOuyaMotionEvent (axisX, axisY, deviceId);
    }
  }
}