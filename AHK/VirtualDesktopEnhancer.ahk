;https://github.com/Ciantic/VirtualDesktopAccessor/tree/master

DetectHiddenWindows, On
hwnd:=WinExist("ahk_pid " . DllCall("GetCurrentProcessId","Uint"))
hwnd+=0x1000<<32

hVirtualDesktopAccessor := DllCall("LoadLibrary", Str, "VirtualDesktopAccessor.dll", "Ptr")
MoveWindowToDesktopNumberProc := DllCall("GetProcAddress", Ptr, hVirtualDesktopAccessor, AStr, "MoveWindowToDesktopNumber", "Ptr")
RegisterPostMessageHookProc := DllCall("GetProcAddress", Ptr, hVirtualDesktopAccessor, AStr, "RegisterPostMessageHook", "Ptr")
UnregisterPostMessageHookProc := DllCall("GetProcAddress", Ptr, hVirtualDesktopAccessor, AStr, "UnregisterPostMessageHook", "Ptr")
RestartVirtualDesktopAccessorProc := DllCall("GetProcAddress", Ptr, hVirtualDesktopAccessor, AStr, "RestartVirtualDesktopAccessor", "Ptr")

; Restart the virtual desktop accessor when Explorer.exe crashes, or restarts (e.g. when coming from fullscreen game)
explorerRestartMsg := DllCall("user32\RegisterWindowMessage", "Str", "TaskbarCreated")
OnMessage(explorerRestartMsg, "OnExplorerRestart")
OnExplorerRestart(wParam, lParam, msg, hwnd)
{
    global RestartVirtualDesktopAccessorProc
    DllCall(RestartVirtualDesktopAccessorProc, UInt, result)
}

global Monitors:=[]

SysGet, Mon, Monitor, 3
Monitors.Push({Left: MonLeft, Right: MonRight, Top: MonTop, Bottom: MonBottom})
SysGet, Mon, Monitor, 4
Monitors.Push({Left: MonLeft, Right: MonRight, Top: MonTop, Bottom: MonBottom})
SysGet, Mon, Monitor, 5
Monitors.Push({Left: MonLeft, Right: MonRight, Top: MonTop, Bottom: MonBottom})

; Windows 10 desktop changes listener
DllCall(RegisterPostMessageHookProc, Int, hwnd, Int, 0x1400 + 30)
OnMessage(0x1400 + 30, "VWMess")
VWMess(wParam, lParam, msg, hwnd)
{
    ; global MoveWindowToDesktopNumberProc, discord, spotify, pinList

    ; DllCall(MoveWindowToDesktopNumberProc, UInt, discord, UInt, lParam)

    ; DllCall(MoveWindowToDesktopNumberProc, UInt, spotify, UInt, lParam)
    global MoveWindowToDesktopNumberProc

    WinGet List, List

    Loop % List
    {
        WinHwnd:=List%A_Index%

        WinGetPos,x,y,w,h,% "ahk_id " WinHwnd
        cx:=x+w/2
        cy:=y+h/2

        For index, Mon in Monitors
        {
            If (cx>=Mon.Left && cx<Mon.Right && cy>=Mon.Top && cy<Mon.Bottom)
            {
                ; MsgBox %WinHwnd%
                DllCall(MoveWindowToDesktopNumberProc, UInt, WinHwnd, UInt, lParam)
            }
        }
    }
}
