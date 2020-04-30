SetCapsLockState, AlwaysOff ; Disable Capslock
if(GetKeyState("Capslock", "P")){
!n::
  Run, Notepad
  return
;open Dev folder
#r::
  Run, P:\
  return
#c::
 Run, P:\SmallCpp\SmallCpp.exe
return
#v::
 Run, P:\strukted32\Strukted32.exe
return
}

