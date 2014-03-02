#include "header.h"

int StarttoC1[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; //Placeholders, also showing how initialization should work for these.
int StarttoC2[2,5]={{0,0,0,0,0},{0,0,0,0,0}};
int C1D1j[2,5]={{0,0,0,0,0},{0,0,0,0,0}};   //Notation: j takes it to junction before destination,
int C2D1j[2,5]={{0,0,0,0,0},{0,0,0,0,0}};
int jD1[2,5]={{0,0,0,0,0},{0,0,0,0,0}};       //j is instructions for fine tuning and pickup
int jD2[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int jD3[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D1jD2j[2,5]={{0,0,0,0,0},{0,0,0,0,0}};   //Dont have competition map, so cant be specific
int D2jD3j[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D1C1[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D2C1[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D3C1[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D1Start[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int D3Start[2,5]={{0,0,0,0,0},{0,0,0,0,0}}; 

NavInstructions MarcoPolo(int Stype){
    Navinstructions Result;
    Switch (Stype){
    case 0: cout<<"No shirt, unknown location"<<endl;
      break;
    case 1: cout<<"Shirt type D1"<<endl;
      Result.name="D1";
      Result.Instruct=C1D1j[1]+jD1[1]+D1C1[1];
      Result.Loc=     C1D1j[2]+jD1[2]+D1C1[2];
      Result.Indicator=0;
      break;
    case 2: cout<<"Shirt type D2"endl;
      Result.name="D2";
      Result.Instruct=C1D1j[1]+D1D2j[1]+D2jD3[1]+D2C1[1];
      Result.Loc=     C1D1j[2]+D1D2j[2]+D2[2]+D2C1[2];
      Result.Indicator=0;
      break;
    case 3:
     Result.name="D3";
      Result.Instruct=C1D1j[1]+D1jD2j[1]+D2jD3j[1]+jD3[1]+D3C1;
      Result.Loc=     C1D1j[2]+D1jD2j[2]+D2jD3j[2]+jD3[2]+D3C1;
      Result.Indicator=0;
      break;
    case 4: cout<<"Unknown shirt type, going to D1"<<endl;
      Result.name="D1";
      Result.Instruct=C1D1j[1]+D1j[1]+D1C1[1];
      Result.Loc=     C1D1j[2]+D1j[2]+D1C1[2];
      Result.Indicator=0;
      break;
    }
    return NavInstructions;
    }

void Lost(){
// Ohh God wtf
//Current version reverse a little bit checking for line
//swivel looking for line
//find line then return where it was
//else cry
}

void ProfligateNavigate(NavInstructions Instr){
//Not sure about this, needs discussion, and to be put in appropriate loop
if (Instr.Instruct(Instr.Indicator)<=2 Advance();
else{
// Again not sure, elseif and switches for end of the line and picking up stuff
}
Instr.Indicator++;
}

