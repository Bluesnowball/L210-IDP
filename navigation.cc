#include "header.h"

int StarttoC1[2][4]={{FORWARD,RIGHT,RIGHT,PAUSE},{START,8,8,INGLIS}}; //Placeholders, also showing how initialization should work for these.
int StarttoC2[2][3]={{FORWARD,FORWARD,RIGHT},{0,0,0}};
int C1D1[2][5]={{SPINBACK,RIGHT, RIGHT, LEFT, PAUSE},{INGLIS,8,8,8,CEBON}}; //Notation: j takes it to junction before destination,
//int C2D1j[2][1]={{RIGHT},{0}};
int C1D2[2][3]={{LEFT,FORWARD,LEFT},{0,0,0}}; //Dont have competition map, so cant be specific
//int C2D2[2][1]={{FORWARD},{0}};
int C1D3[2][1]={{FORWARD},{0}}; 
//int C2D3[2][1]={{LEFT},{0}};
int D1C1[2][5]={{SPINBACK,RIGHT,LEFT, LEFT,PAUSE},{CEBON,8,8,8,INGLIS}};
int D2C1[2][7]={{SPINBACK,LEFT,RIGHT,RIGHT,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0}};
int D3C1[2][8]={{SPINBACK,RIGHT,FORWARD,RIGHT,RIGHT,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0,0}};
int D1Start[2][7]={{SPINBACK,LEFT,LEFT,FORWARD,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0}};
int D2Start[2][7]={{SPINBACK,LEFT,LEFT,FORWARD,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0}};
int D3Start[2][9]={{SPINBACK,RIGHT,FORWARD,RIGHT,RIGHT,FORWARD,FORWARD,LEFT,FORWARD},{0,0,0,0,0,0,0,0,0}};
int testinstr[2][9]={{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
//plan b is to have single arreays per journey, not concatenating them, overall probs fewer lines.

NavInstructions MarcoPolo(int Stype,bool justpick,int loc){
    NavInstructions Result;
    cout<<"Marco Called"<<endl;
    vector<int> tempvector1,tempvector2;
    //temp testing rig
    //Result.name="Testrig";
     // tempvector1.assign(testinstr[0], testinstr[0]+(sizeof(testinstr[0])/sizeof(testinstr[0][0])));
     //Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
   // bool justpick=false; //made true if just picked up, will need to actually be made working, currently just to show idea
    if (justpick){
		cout<<"JustPicked"<<endl;
    switch (Stype){
    case 0: cout<<"No shirt, unknown location"<<endl;
      break;
    case 1: cout<<"Shirt type D1"<<endl;
      Result.name="D1";
      tempvector1.assign(C1D1[0], C1D1[0]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D1[1], C1D1[1]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
     
   
      Result.Indicator=0;
      break;
    case 2: cout<<"Shirt type D2"<<endl;
      Result.name="D2";
     tempvector1.assign(C1D2[0], C1D2[0]+(sizeof(C1D2[0])/sizeof(C1D2[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D2[1], C1D2[1]+(sizeof(C1D2[0])/sizeof(C1D2[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
    
     
     /* Result.Instruct+=C1D1j[1]+D1D2j[1]+D2jD3[1]+D2C1[1];
Result.Loc+= C1D1j[2]+D1D2j[2]+D2[2]+D2C1[2];*/
      Result.Indicator=0;
      break;
    case 3:
     Result.name="D3";
      tempvector1.assign(C1D3[0], C1D3[0]+(sizeof(C1D3[0])/sizeof(C1D3[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D3[1], C1D3[1]+(sizeof(C1D3[0])/sizeof(C1D3[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
     
   
      Result.Indicator=0;
      break;
    case 4: cout<<"Unknown shirt type, going to D1"<<endl;
Result.name="D1"; //copy of D1
     Result.name="D1";
      tempvector1.assign(C1D1[0], C1D1[0]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D1[1], C1D1[1]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
      Result.Indicator=0;
      break;
    }
    }
    else if (loc==0){
		cout<<"STARTS"<<endl;
	tempvector1.assign(StarttoC1[0], StarttoC1[0]+(sizeof(StarttoC1[0])/sizeof(StarttoC1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(StarttoC1[1], StarttoC1[1]+(sizeof(StarttoC1[0])/sizeof(StarttoC1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());	
          Result.Indicator=0;
	}
	for(unsigned int i=0;i<Result.Instruct.size();i++){
cout<<Result.Instruct[i]<<endl;
 }
    return Result;
    }


int Lost(int prev){
int errorterm = -4;
if (prev == 1) errorterm = 4;
return errorterm;
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

