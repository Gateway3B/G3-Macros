; #Requires AutoHotkey v2.0

global TopMon
global LeftMon

Loop, 5 {
    SysGet, Mon, Monitor, %A_Index%
    if (MonLeft < 0) {
        LeftMon := {Left: MonLeft, Right: MonRight, Top: MonTop, Bottom: MonBottom}
    }
    
    if (MonTop < 0 && MonLeft == 0) {
        TopMon := {Left: MonLeft, Right: MonRight, Top: MonTop, Bottom: MonBottom}
    }
}

SnapToLeftChrome() {
    WinGet, id, List, ahk_exe chrome.exe

    Loop, %id%
    {
        win_ahk_id := id%A_Index%

        WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id
        cx:=x+w/2
        cy:=y+h/2

        if (cx >= LeftMon.Left && cx < LeftMon.Right && cy >= LeftMon.Top && cy < LeftMon.Bottom) {
            MoveMouse(cx, cy)
            WinActivate, ahk_id %win_ahk_id%
            break
        }
    }
}

SnapToTopChrome() {
    WinGet, id, List, ahk_exe chrome.exe

    Loop, %id%
    {
        win_ahk_id := id%A_Index%

        WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id
        cx:=x+w/2
        cy:=y+h/2

        if (cx >= TopMon.Left && cx < TopMon.Right && cy >= TopMon.Top && cy < TopMon.Bottom) {
            WinActivate, ahk_id %win_ahk_id%
            MoveMouse(cx, cy)
            break
        }
    }
}

SnapToDiscord() {
    WinGet, win_ahk_id, List, ahk_exe Discord.exe

    WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id1
    cx:=x+w/2
    cy:=y+h/2
    MoveMouse(cx, cy)
    WinActivate, ahk_id %win_ahk_id1%
}

SnapToVSCode() {
    WinGet, win_ahk_id, List, ahk_exe Code.exe

    WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id1
    cx:=x+w/2
    cy:=y+h/2
    MoveMouse(cx, cy)
    WinActivate, ahk_id %win_ahk_id1%
}

SnapToSpotify() {
    WinGet, win_ahk_id, List, ahk_exe Spotify.exe

    WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id1
    cx:=x+w/2
    cy:=y+h/2
    MoveMouse(cx, cy)
    WinActivate, ahk_id %win_ahk_id1%
}

SnapToObsidian() {
    WinGet, win_ahk_id, List, ahk_exe Obsidian.exe

    WinGetPos,x,y,w,h,% "ahk_id " win_ahk_id1
    cx:=x+w/2
    cy:=y+h/2
    MoveMouse(cx, cy)
    WinActivate, ahk_id %win_ahk_id1%
}

MoveMouse(cx, cy) {
    DllCall("SetCursorPos", "int", 960, "int", 540)  ; The first number is the X-coordinate and the second is the Y (relative to the screen).
    DllCall("SetCursorPos", "int", cx, "int", cy)  ; The first number is the X-coordinate and the second is the Y (relative to the screen).
    ; MouseMove, cx, cy
}