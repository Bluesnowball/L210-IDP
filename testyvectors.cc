#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class NavInstructions{
 public:
  string name;
  int Indicator;
  vector<int> Instruct;
  vector<int> Loc; };
int StarttoC1[2][6]={{2,4,5,6,7,30},{0,0,0,0,0}}; //Placeholders, also showing how initialization should work for these.
int StarttoC2[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int C1D1j[2][5]={{1,2,3,4,5},{1,2,3,4,5}}; //Notation: j takes it to junction before destination,
int C2D1j[2][5]={{6,7,8,9,10},{6,7,8,9,10}};
int jD1[2][5]={{0,0,0,0,0},{0,0,0,0,0}}; //j is instructions for fine tuning and pickup
int jD2[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int jD3[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D1jD2j[2][5]={{0,0,0,0,0},{0,0,0,0,0}}; //Dont have competition map, so cant be specific
int D2jD3j[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D1C1[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D2C1[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D3C1[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D1Start[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int D3Start[2][5]={{0,0,0,0,0},{0,0,0,0,0}}; 
int testa[5]={0,1,2,3,4};

int main(){
 NavInstructions Result;
 vector<int> tempVector1,tempvector2,tempvector3;
tempVector1.assign(StarttoC1[0], StarttoC1[0]+(sizeof(StarttoC1[0])/sizeof(StarttoC1[0][0])));
tempvector2.assign(C1D1j[0], C1D1j[0]+(sizeof(C1D1j[0])/sizeof(C1D1j[0][0])));
Result.Instruct.insert(Result.Instruct.end(), tempVector1.begin(), tempVector1.end());
Result.Instruct.insert(Result.Instruct.end(), tempvector2.begin(), tempvector2.end());
 //cout<<sizeof(StarttoC1[0])/sizeof(StarttoC1[0][0]);
 for(int i=0;i<12;i++){
	 cout<<Result.Instruct[i]<<endl;
 }
 cout<<Result.Instruct.size();
 //Result.name="D1";
//Result.Instruct.insert(Result.Instruct.end(),C1D1j[0],sizeof(StarttoC1[0])/sizeof(StarttoC1[0][0]));
//Result.Instruct.insert(Result.Instruct.end(),jD1[0],jD1[0].size());
//Result.Instruct.insert(Result.Instruct.end(),D1C1[0],sizeof(D1C1[0]) / sizeof(int));
//Result.Loc+= C1D1j[2]+jD1[2]+D1C1[2];
//Result.Indicator=0;
//cout<<testa.size();
}

