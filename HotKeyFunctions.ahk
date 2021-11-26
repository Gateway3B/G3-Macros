
; Google bang
GoogleBang()
{
	SetTitleMatchMode 2
	if WinActive("DuckDuckGo") and WinActive("ahk_exe Chrome.exe")
	{
		Loop, 20
		{
			Send {Click WheelUp}
			Sleep 10
		}
		Send {Click 656, 113, 0}
		Send {Click 3}
		Send ^c
		Send ^l
		Send {!}g{Space}
		Send ^v
		Send {Enter}
		return
	}
	return
}

; Toggle sleep
global sleep := "On"
ToggleSleep()
{
	Sleep 200
	SendInput ^{Esc}
	Sleep 200
	SendInput Sleep
	Sleep 200
	SendInput {Enter}
	Sleep 200
	SendInput {Click 450, 200, 0}
	Sleep 1000

	If(sleep = "On")
	{
		; Screensaver Off
		DllCall("SystemParametersInfo", Int,17, Int,0, UInt,NULL, Int,2)

		Loop, 30
		{
			SendInput {Click WheelDown}
			Sleep 30
		}
		sleep := "Off"
	}
	Else
	{
		; Screensaver On
		DllCall("SystemParametersInfo", Int,17, Int,1, UInt,NULL, Int,2)

		Loop, 10
		{
			SendInput {Click WheelUp}
			Sleep 30
		}
		sleep := "On"
	}
	Sleep 100
	WinClose, Settings
}

TogglePin()
{
    global pinList
    temp := WinExist("A")
    temp := temp + 0
    If (temp)
    {
        Loop, % pinList.Length()
        {
            if (pinList[A_Index] = temp)
            {
                pinList.RemoveAt(A_Index)
                return
            }
        }
        pinList.Push(temp)
    }
}