#include <windows.h> 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine,
int iCmdShow) 
{ char szWitz[] = "Der erste sagt: \"Weihnachten ist schoener!\"\nund der zweite: \"Wieso??\"\n\nWeiter?";
  
  if (MessageBox(NULL,"Zwei alte Männer unterhalten sich.\nSagt der erste: \"Weihnachten ist schoen!\"\nSagt der zweite: \"Poppen ist auch schoen!\"\n\nWillst Du wissen wie es weiter geht?",
  "Witz komm raus", MB_YESNO | MB_DEFBUTTON1 | MB_ICONEXCLAMATION) == IDNO) return
  0;
  if (MessageBox(NULL, szWitz, "Witz komm raus, du bist", MB_OKCANCEL | MB_DEFBUTTON1
  | MB_ICONEXCLAMATION) == IDCANCEL) return 0;
  MessageBox(NULL, "Kommt ein Haeschen gehoppelt und meint:\n\"Weihnachten ist oefter!!\"\n\nHihihi", "Witz komm raus, du bist umzingelt!", MB_OK | MB_DEFBUTTON1
  | MB_ICONASTERISK);
  return 0;
}
