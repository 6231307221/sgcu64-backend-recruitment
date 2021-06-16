#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

vector<string> r1 = {" __ "," "," __ "," __ ","    "," __ "," __ "," __ "," __ "," __ "," ","  "};
vector<string> r2 = {"|  |","|"," __|"," __|","|__|","|__ ","|__ ","   |","|__|","|__|",".","  "};
vector<string> r3 = {"|__|","|","|__ "," __|","   |"," __|","|__|","   |","|__|"," __|",".","__"};
string R1;
string R2;
string R3;

void printErr(){
        R1 = r1[11] + " " + r1[10] + " " + r1[11] + " " + r1[10] + " " + r1[11];
        R2 = r2[11] + " " + r2[10] + " " + r2[11] + " " + r2[10] + " " + r2[11];
        R3 = r3[11] + " " + r3[10] + " " + r3[11] + " " + r3[10] + " " + r3[11];
}

void print(string x){
    int i =0;
    while(x[i] != ':'){
        int k = (int)(x[i])-48;
        R1 += r1[k];
        R2 += r2[k];
        R3 += r3[k];
        i+=1;
        R1 += " ";
        R2 += " ";
        R3 += " ";
    }
    i+=1;
    R1 += r1[10];
    R2 += r2[10];
    R3 += r3[10];
    R1 += " ";
    R2 += " ";
    R3 += " ";
    while(x[i] != ':'){
        int k = (int)(x[i])-48;
        R1 += r1[k];
        R2 += r2[k];
        R3 += r3[k];
        i+=1;
        R1 += " ";
        R2 += " ";
        R3 += " ";
    }
    i+=1;
    R1 += r1[10];
    R2 += r2[10];
    R3 += r3[10];
    R1 += " ";
    R2 += " ";
    R3 += " ";
    while (i != x.size()){
        int k = (int)(x[i])-48;
        R1 += r1[k];
        R2 += r2[k];
        R3 += r3[k];
        i+=1;
        R1 += " ";
        R2 += " ";
        R3 += " ";
    }
}

int main()
{
    string x;
    string hourI;
    string minuteI;
    string secI;
    int i = 0;
    cin >> x ;
    while(x[i] != ':'){
        hourI += x[i];
        i+=1;
    }
    i+=1;
    while(x[i] != ':'){
        minuteI += x[i];
        i+=1;
    }
    i+=1;
    while (i != x.size()){
        secI += x[i];
        i+=1;
    }

    int hour = stoi(hourI);
    int minute = stoi(minuteI);
    int sec = stoi(secI);

    if(minute > 59 || minute < 0){
        printErr();
    }else if(sec > 59 || sec < 0){
        printErr();
    }
    else{
        print(x);

    }
    cout << R1 <<endl;
    cout << R2 <<endl;
    cout << R3 <<endl;
    getch();
    return 0;




}

