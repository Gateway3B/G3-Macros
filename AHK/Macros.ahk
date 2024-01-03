#include HotKeyFunctions.ahk
#include VirtualDesktopEnhancer.ahk
#include AppSnap.ahk
#SingleInstance force

RAlt::GoogleBang()
!1::SnapToLeftChrome()
!2::SnapToTopChrome()
!3::SnapToDiscord()
!4::SnapToVSCode()
!5::SnapToSpotify()
!6::SnapToObsidian()

!PgUp::Send {Blind}{Alt up}{PgUp up}{Ctrl down}{PgUp down}{Ctrl up}
!PgDn::Send {Blind}{Alt up}{PgDn up}{Ctrl down}{PgDn down}{Ctrl up}
!+PgUp::Send {Blind}{Alt up}{PgUp up}{Ctrl down}{PgUp down}{Ctrl up}
!+PgDn::Send {Blind}{Alt up}{PgDn up}{Ctrl down}{PgDn down}{Ctrl up}

; RCtrl::SendInput #n

; AppsKey::T
; RWin::
; Media_Stop:: 