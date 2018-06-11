#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string name[100];
    string sex[100];
    double score[100];
    string nametep;string sextep;
    string scoretep;
    ifstream inscore("score.csv",ios::in);
    int counter=0;
    string line;
    getline(inscore,line);
    while (getline(inscore,line) ){
    stringstream ss(line);
    getline(ss,nametep,',' );
    getline(ss,sextep,',');
    getline(ss,scoretep);
    name[counter]=nametep;
    scoretep.erase(0,1);
    double douscore= atof(scoretep.c_str());
    sex[counter]=sextep;
    score[counter]= douscore;
    sex[counter].erase(0,1);
    counter++;
}
    double sum=0;
    double fesum=0;
    double masum=0;
    int fecounter=0;
    int macounter=0;
    for(int i=0;i<counter;i++){
    sum+=score[i];
    if(sex[i]=="Male"){
    masum+=score[i];
    macounter++;
    }
    else {
    fesum+=score[i];
    fecounter++;
    }
}
while(true){
    int dcounter=0;
    for(int i=0;i<counter-1;i++){
    if(score[i]<score[i+1]||((score[i]==score[i+1])&&(name[i+1]<name[i]))){
    double temp1=score[i];
    score[i]=score[i+1];
    score[i+1]=temp1;
    string temp2 = name[i];
    name[i]=name[i+1];
    name[i+1]=temp2;
    temp2 = sex[i];
    sex[i]=sex[i+1];
    sex[i+1]=temp2;
    dcounter++;
 }
}
    if(dcounter==0)
        break;
} 
    cout << sum/counter << endl;
    cout << masum/macounter << endl;
    cout << fesum/fecounter << endl;
    for(int i=0;i<counter;i++){
    cout << name[i]<<" "<< sex[i]<<" "<< score[i] <<endl;
}   
}
