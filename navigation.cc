#include "header.h"

int StarttoC1[2][4]={{FORWARD,RIGHT,RIGHT,PAUSE},{START,ENDOFTERM,EIETL,INGLIS}}; 
int StarttoC2[2][5]={{FORWARD,RIGHT,FORWARD,RIGHT,PAUSE},{START,ENDOFTERM,EIETL,DPO,BAKER}};
int C1D1[2][3]={{LEFTSPINBACK, FORWARD, PAUSE},{INGLIS,BAKER,CEBON}}; 
//int C2D1j[2][1]={{RIGHT},{0}};
int C1D2[2][6]={{LEFTSPINBACK,FORWARD,LEFT,FORWARD,LEFT,LEFTPAUSE},{INGLIS,EIETL,DPO,WORKSHOP,K2,SUTCLIFFE}}; 
//int C2D2[2][1]={{FORWARD},{0}};
int C1D3[2][7]={{LEFTSPINBACK,FORWARD,LEFT,FORWARD,LEFT,FORWARD,RIGHTPAUSE},{INGLIS,EIETL,DPO,WORKSHOP,K2,MATLAB,VENKATARAMANAN}}; 
//int C2D3[2][1]={{LEFT},{0}};
int D1C1[2][5]={{SPINBACK,RIGHT,LEFT, LEFT,PAUSE},{CEBON,BAKER,DPO,EIETL,INGLIS}};
int D2C1[2][7]={{LEFTSPINBACK,RIGHT,RIGHT,RIGHT,FORWARD,LEFT,PAUSE},{SUTCLIFFE,0,0,0,0,EIETL,INGLIS}};
int D3C1[2][7]={{RIGHTSPINBACK,FORWARD,RIGHT,RIGHT,FORWARD,LEFT,PAUSE},{VENKATARAMANAN,0,0,0,0,EIETL,INGLIS}};
int D1Start[2][8]={{SPINBACK,RIGHT,LEFT,FORWARD,LEFT,FORWARD,FORWARD,STOP},{CEBON,BAKER,DPO,EIETL,ENDOFTERM,20,44,START}};
int D2Start[2][8]={{LEFTSPINBACK,LEFT,LEFT,FORWARD,FORWARD,LEFT,FORWARD,STOP},{SUTCLIFFE,0,0,0,0,0,0,START}};
int D3Start[2][10]={{SPINBACK,RIGHT,FORWARD,RIGHT,RIGHT,FORWARD,FORWARD,LEFT,FORWARD,STOP},{VENKATARAMANAN,0,0,0,0,0,0,0,0,START}};
int spinC1[2][4]={{SPINBACK,FORWARD,SPINBACK,PAUSE},{INGLIS,EIETL,EIETL,INGLIS}};
int C1start[2][5]={{SPINBACK,LEFT,LEFT,FORWARD,PAUSE},{INGLIS,EIETL,EIETL,INGLIS}};

NavInstructions MarcoPolo(int Stype,bool justpick,int loc){
    NavInstructions Result;
    cout<<"Marco Called"<<endl;
    vector<int> tempvector1,tempvector2;
    //temp testing rig
    //Result.name="Testrig";
     // tempvector1.assign(testinstr[0], testinstr[0]+(sizeof(testinstr[0])/sizeof(testinstr[0][0])));
     //Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
    if (justpick){
		cout<<"JustPicked"<<endl;
    switch (Stype){
    case Lingerie: cout<<"No shirt, unknown location"<<endl;
          tempvector1.assign(spinC1[0], spinC1[0]+(sizeof(spinC1[0])/sizeof(spinC1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(spinC1[1], spinC1[1]+(sizeof(spinC1[0])/sizeof(spinC1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
          
          
      Result.Indicator = 0;
      break;
    case Green: cout<<"Shirt type D1"<<endl;
      Result.name="D1";
      tempvector1.assign(C1D1[0], C1D1[0]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D1[1], C1D1[1]+(sizeof(C1D1[0])/sizeof(C1D1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
     
   
      Result.Indicator=0;
      break;
    case Yellow: cout<<"Shirt type D2"<<endl;
      Result.name="D2";
     tempvector1.assign(C1D2[0], C1D2[0]+(sizeof(C1D2[0])/sizeof(C1D2[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D2[1], C1D2[1]+(sizeof(C1D2[0])/sizeof(C1D2[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
    
     
     /* Result.Instruct+=C1D1j[1]+D1D2j[1]+D2jD3[1]+D2C1[1];
Result.Loc+= C1D1j[2]+D1D2j[2]+D2[2]+D2C1[2];*/
      Result.Indicator=0;
      break;
    case Invshroom:
     Result.name="D3";
      tempvector1.assign(C1D3[0], C1D3[0]+(sizeof(C1D3[0])/sizeof(C1D3[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(C1D3[1], C1D3[1]+(sizeof(C1D3[0])/sizeof(C1D3[0][0])));
     Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
     
   
      Result.Indicator=0;
      break;
    case Burkha: cout<<"Unknown shirt type, going to D1"<<endl;
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
	else if (loc==CEBON || loc == 25){
		//add time/shirt check here
		cout<<"Going back for more Mech"<<endl;
	tempvector1.assign(D1C1[0], D1C1[0]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(D1C1[1], D1C1[1]+(sizeof(D1C1[0])/sizeof(D1C1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());	
          Result.Indicator=0;	
		
	}
	else if (loc==SUTCLIFFE || loc == 1077627992){
			cout<<"Going back for more Mat"<<endl;
	tempvector1.assign(D2C1[0], D2C1[0]+(sizeof(D2C1[0])/sizeof(D2C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(D2C1[1], D2C1[1]+(sizeof(D2C1[0])/sizeof(D2C1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());	
          Result.Indicator=0;
	}
	else if (loc==VENKATARAMANAN){
		cout<<"Going back for more Comms"<<endl;
	tempvector1.assign(D3C1[0], D3C1[0]+(sizeof(D3C1[0])/sizeof(D3C1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(D3C1[1], D3C1[1]+(sizeof(D3C1[0])/sizeof(D3C1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());	
          Result.Indicator=0;
	}
	 else if (loc==INGLIS){
	 cout<<"Going home"<<endl;
     tempvector1.assign(spinC1[0], spinC1[0]+(sizeof(spinC1[0])/sizeof(spinC1[0][0])));
     Result.Instruct.insert(Result.Instruct.end(), tempvector1.begin(), tempvector1.end());
     tempvector2.assign(spinC1[1], spinC1[1]+(sizeof(spinC1[0])/sizeof(spinC1[0][0])));
          Result.Loc.insert(Result.Loc.end(), tempvector2.begin(), tempvector2.end());
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

