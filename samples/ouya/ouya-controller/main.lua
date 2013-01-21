        print ( "hello, OUYA!" )
        function onOuyaButtonDown (keyCode, deviceId)
                print ( "moai: Ouya Button Down " .. keyCode .. " " .. deviceId)
        end

        function onOuyaButtonUp (keyCode, deviceId)
                print ( "moai: Ouya Button Up " .. keyCode .. " " .. deviceId)
        end
	function onGenericMotionEvent(leftAxisX, leftAxisY, rightAxisX, rightAxisY, deviceId)
		print ("moai: Left Axis X: " .. leftAxisX .. " Left Axis Y: " .. leftAxisY .." deviceId: " ..deviceId)
		print ("moai: Right Axis X: " .. rightAxisX .. " Right Axis Y: " .. rightAxisY .." deviceId: " ..deviceId)
	end

       MOAIOuyaAndroid.setListener ( MOAIOuyaAndroid.OUYA_MOTION_EVENT, onGenericMotionEvent )
       MOAIOuyaAndroid.setListener ( MOAIOuyaAndroid.OUYA_BUTTON_DOWN, onOuyaButtonDown )
       MOAIOuyaAndroid.setListener ( MOAIOuyaAndroid.OUYA_BUTTON_UP, onOuyaButtonUp )
