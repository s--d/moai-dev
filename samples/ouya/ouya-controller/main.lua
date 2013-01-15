print ( "hello, OUYA!" )

function onOuyaButtonDown (keyCode, deviceId)
	print ( "moai: Ouya Button Down " .. keyCode .. " " .. deviceId)
end

MOAIOuyaAndroid.setListener ( MOAIOuyaAndroid.OUYA_BUTTON_DOWN, onOuyaButtonDown )