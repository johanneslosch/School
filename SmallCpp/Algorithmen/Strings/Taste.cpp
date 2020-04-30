#include <iostream.h>
#include <conio.h>
int main()
{ do
  { short x=getch();
    if(!x)
    { x=getch();
      if((x>=59&&x<=161))
      { if(x>=59&&x<=69) cout <<"\n    F" <<x-58 <<"\t- ";
        if(x>=84&&x<=93) cout <<"\nSft/F" <<x-83 <<"\t- ";
        if(x>=94&&x<=103) cout <<"\nStg/F" <<x-93 <<"\t- ";
        if(x>=104&&x<=113) cout <<"\nAlt/F" <<x-103 <<"\t- ";
        switch(x)
        { case 71: cout<<"\nPos1\t- ";break;
          case 72: cout<<"\n    " <<char(24) << "\t- ";break;
          case 73: cout<<"\nBild" <<char(24) << "\t- ";break;
          case 75: cout<<"\n    " <<char(27) << "\t- ";break;
          case 77: cout<<"\n    " <<char(26) << "\t- ";break;
          case 79: cout<<"\nEnde\t- ";break;
          case 80: cout<<"\n    " <<char(25) << "\t- ";break;
          case 81: cout<<"\nBild" <<char(25) << "\t- ";break;
          case 82: cout<<"\nEinfg\t- ";break;
          case 83: cout<<"\nEntf\t- ";break;
          case 115: cout<<"\nStg/" <<char(27) << "\t- ";break;
          case 116: cout<<"\nStg/" <<char(26) << "\t- ";break;
          case 117: cout<<"\nStg/Ende" << "- ";break;
          case 118: cout<<"\nStg/Bld" <<char(25) << "- ";break;
          case 119: cout<<"\nStg/Pos1" << "- ";break;
          case 132: cout<<"\nStg/Bld" <<char(24) << "- ";break;
          case 133: cout<<"\n    F11\t- ";break;
          case 134: cout<<"\n    F12\t- ";break;
          case 135: cout<<"\nSft/F11\t- ";break;
          case 136: cout<<"\nSft/F12\t- ";break;
          case 137: cout<<"\nStg/F11\t- ";break;
          case 138: cout<<"\nStg/F12\t- ";break;
          case 139: cout<<"\nAlt/F11\t- ";break;
          case 140: cout<<"\nAlt/F12\t- ";break;
          case 141: cout<<"\nStg/" <<char(24) << "\t- ";break;
          case 145: cout<<"\nStg/" <<char(25) << "\t- ";break;
          case 148: cout<<"\nStg/Tab" << "\t- ";break;
          case 151: cout<<"\nAlt/Pos1- ";break;
          case 152: cout<<"\nAlt/" <<char(24) << "\t- ";break;
          case 153: cout<<"\nAlt/Bld" <<char(25) << "- ";break;
          case 155: cout<<"\nAlt/" <<char(27) << "\t- ";break;
          case 157: cout<<"\nAlt/" <<char(26) << "\t- ";break;
          case 159: cout<<"\nAlt/Ende- ";break;
          case 160: cout<<"\nAlt/" <<char(25) << "\t- ";break;
          case 161: cout<<"\nAlt/Bld" <<char(24) << "- ";break;
        }
        cout<<"Funktionstaste Nr."<<x;
      }
      else cout<<"\n\t- Funktionstaste Nr."<<x;  
    }
    else
    { switch(x)
      { 
        case 7:  cout<<"\nBeep\t- ASCII-Code "<<x; break;
        case 9:  cout<<"\nTab\t- ASCII-Code "<<x; break;
        case 13:  cout<<"\nCR\t- ASCII-Code "<<x; break;
        case 27:  cout<<"\nESC\t- ASCII-Code "<<x; break;
        default: cout<<"\n'"<<(char)x<<"'\t- ASCII-Code "<<x;
      }
    }
  } while(true);
  getch();
  return 0;
}
