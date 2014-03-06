#include "header.h"

int StarttoC1[2][2]={{FORWARD,RIGHT},{0,0}}; //Placeholders, also showing how initialization should work for these.
int StarttoC2[2][3]={{FORWARD,FORWARD,RIGHT},{0,0,0}};
int C1D1j[2][2]={{RIGHT,FORWARD},{0,0}};   //Notation: j takes it to junction before destination,
int C2D1j[2][1]={{RIGHT},{0}};
int jD1[2][1]={{FORWARD},{0}};       //j is instructions for fine tuning and pickup
int jD2[2][1]={{LEFT},{0}}; 
int jD3[2][1]={{RIGHT},{0}}; 
int D1jD2j[2][3]={{LEFT,FORWARD,LEFT},{0,0,0}};   //Dont have competition map, so cant be specific
int D2jD3j[2][1]={{FORWARD},{0}}; 
int D1C1[2][6]={{SPINBACK,LEFT,LEFT,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0}}; 
int D2C1[2][7]={{SPINBACK,LEFT,RIGHT,RIGHT,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0}}; 
int D3C1[2][8]={{SPINBACK,RIGHT,FORWARD,RIGHT,RIGHT,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0,0}}; 
int D1Start[2][7]={{SPINBACK,LEFT,LEFT,FORWARD,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0}}; 
int D3Start[2][9]={{SPINBACK,RIGHT,FORWARD,RIGHT,RIGHT,FORWARD,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0,0,0}}; 


NavInstructions MarcoPolo(int Stype){ 
    NavInstructions Result;
    vector<int> tempvector1,tempvector2,tempvector3;
    bool justpick=false //made true if just picked up, will need to actually be made working, currently just to show idea
    if (justpick){
    if switch (Stype){
    case 0: cout<<"No shirt, unknown location"<<endl;
      break;
    case 1: cout<<"Shirt type D1"<<endl;
      Result.name="D1";
      tempvector1.assign(C1D1j[0], C1D1j[0]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(C1D1j[1], C1D1j[1]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(jD1[0], jD1[0]+(sizeof(jD1[0])/sizeof(jD1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(jD1[1], jD1[1]+(sizeof(jD1[0])/sizeof(jD1[0][0])));
             Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(D1C1[0], D1C1[0]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(D1C1[1], D1C1[1]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     /* Result.Instruct+=C1D1j[1]+jD1[1]+D1C1[1];
      Result.Loc+=     C1D1j[2]+jD1[2]+D1C1[2]; */
      Result.Indicator=0;
      break;
    case 2: cout<<"Shirt type D2"<<endl;
      Result.name="D2";
     tempvector1.assign(C1D1j[0], C1D1j[0]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(C1D1j[1], C1D1j[1]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
           tempvector1.assign(D1jD2j[0], D1jD2j[0]+(sizeof(D1jD2j[0])/sizeof(D1jD2j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(D1jD2j[1], D1jD2j[1]+(sizeof(D1jD2j[0])/sizeof(D1jD2j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(jD2[0], jD2[0]+(sizeof(jD2[0])/sizeof(jD2[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(jD2[1], jD2[1]+(sizeof(jD2[0])/sizeof(jD2[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
          tempvector1.assign(D2C1[0], D2C1[0]+(sizeof(D2C1[0])/sizeof(D2C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
      tempvector2.assign(D2C1[1], D2C1[1]+(sizeof(D2C1[0])/sizeof(D2C1[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     /* Result.Instruct+=C1D1j[1]+D1D2j[1]+D2jD3[1]+D2C1[1];
      Result.Loc+=     C1D1j[2]+D1D2j[2]+D2[2]+D2C1[2];*/
      Result.Indicator=0;
      break;
    case 3:
     Result.name="D3";
      tempvector1.assign(C1D1j[0], C1D1j[0]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(C1D1j[1], C1D1j[1]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
           tempvector1.assign(D1jD2j[0], D1jD2j[0]+(sizeof(D1jD2j[0])/sizeof(D1jD2j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
      tempvector2.assign(D1jD2j[1], D1jD2j[1]+(sizeof(D1jD2j[0])/sizeof(D1jD2j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(D2jD3j[0], D2jD3j[0]+(sizeof(D2jD3j[0])/sizeof(D2jD3j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(D2jD3j[1], D2jD3j[1]+(sizeof(D2jD3j[0])/sizeof(D2jD3j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     
          tempvector1.assign(jD3[0], jD3[0]+(sizeof(jD3[0])/sizeof(jD3[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
    tempvector2.assign(D2jD3j[1], D2jD3j[1]+(sizeof(D2jD3j[0])/sizeof(D2jD3j[0][0]))); 
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     
     tempvector1.assign(D3C1[0], D3C1[0]+(sizeof(D3C1[0])/sizeof(D3C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(D2jD3j[1], D2jD3j[0]+(sizeof(D2jD3j[0])/sizeof(D2jD3j[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     
     /*
      Result.Instruct+=C1D1j[1]+D1jD2j[1]+D2jD3j[1]+jD3[1]+D3C1;
      Result.Loc+=     C1D1j[2]+D1jD2j[2]+D2jD3j[2]+jD3[2]+D3C1;*/
      Result.Indicator=0;
      break;
    case 4: cout<<"Unknown shirt type, going to D1"<<endl;
      Result.name="D1"//copy of D1
      tempvector1.assign(C1D1j[0], C1D1j[0]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(C1D1j[1], C1D1j[1]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(jD1[0], jD1[0]+(sizeof(jD1[0])/sizeof(jD1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(jD1[1], jD1[1]+(sizeof(jD1[0])/sizeof(jD1[0][0])));
             Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     
     tempvector1.assign(D1C1[0], D1C1[0]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
     tempvector2.assign(D1C1[1], D1C1[1]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempVector2.begin(), tempVector2.end());
     /* Result.Instruct+=C1D1j[1]+D1j[1]+D1C1[1];
      Result.Loc+=     C1D1j[2]+D1j[2]+D1C1[2];*/
      Result.Indicator=0;
      break;
    } 
    }
    return Result; 
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
if (Instr.Instruct[Instr.Indicator]<=2) Advance();
else{
// Again not sure, elseif and switches for end of the line and picking up stuff
}
Instr.Indicator++;
}

