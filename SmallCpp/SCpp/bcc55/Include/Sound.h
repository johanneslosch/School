#include <time.h>
void SoundOn(void)
{ asm
  { mov al,182
    out 43h,al
  }
}
void SoundOff(void)
{ asm
  { in   al,61h             //Lautsprecher-Kontroll-Bit einlesen
    and  al,11111100b       //untersten beiden Bits löschen
    out  61h,al             //Lautsprecher ausschalten
  }
}
void SoundFrq(unsigned short Ton)
{ asm
  { mov  ax,Ton             //Ton-Wert holen
    out  42h,al             //LO-Byte an Timer-Counter-Register
    mov  al,ah              //HI-Byte an AL übertragen
    out  42h,al             //und auch an Timer-Counter-Register
    in   al,61h             //Lautsprecher-Kontroll-Bit einlesen
    or   al,11b             //untersten beiden Bits schalten Ls. an
    out  61h,al             //Lautsprecher anschalten
  }
}
void Delay(unsigned short Msec)
{ int zeit=clock();
  while(clock()<zeit+Msec);
}
void Sound(unsigned short Ton,unsigned short Msec)
{ SoundOn();
  SoundFrq(Ton);
  Delay(Msec);
  SoundOff();
}
/* toene  9121,8609,8126,7670  	//Ton-Werte für die Oktave 3
          7239,6833,6449,6087
          5746,5423,5119,4831
          4560,4304,4063,3834  	;Ton-Werte für die Oktave 4
          3619,3416,3224,3043
          2873,2711,2559,2415
          2280,2152,2031,1917  	;Ton-Werte für die Oktave 5
          1809,1715,1612,1521
          1436,1355,1292,1207
*/

