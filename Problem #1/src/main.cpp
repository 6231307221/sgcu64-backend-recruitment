#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

vector<string> r1 = {" __ "," "," __ "," __ ","    "," __ "," __ "," __ "," __ "," __ "," ","  "};
vector<string> r2 = {"|  |","|"," __|"," __|","|__|","|__ ","|__ ","   |","|__|","|__|",".","  "};
vector<string> r3 = {"|__|","|","|__ "," __|","   |"," __|","|__|","   |","|__|"," __|",".","__"};


void printErr(){
        string R1;
        string R2;
        string R3;
        R1 = r1[11] + " " + r1[10] + " " + r1[11] + " " + r1[10] + " " + r1[11];
        R2 = r2[11] + " " + r2[10] + " " + r2[11] + " " + r2[10] + " " + r2[11];
        R3 = r3[11] + " " + r3[10] + " " + r3[11] + " " + r3[10] + " " + r3[11];
        cout << R1 << "\n";
        cout << R2 <<"\n";
        cout << R3 <<"\n";
        cout << "--------------------------------------------------------------------------"<< "\n";
}

void print(string x){
    string R1;
    string R2;
    string R3;
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
    cout << R1 << "\n";
    cout << R2 <<"\n";
    cout << R3 <<"\n";
    cout << "--------------------------------------------------------------------------"<< "\n";
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
    if(hour > 99){
        printErr();
    }
    else if(minute > 59 || minute < 0){
        printErr();
    }else if(sec > 59 || sec < 0){
        printErr();
    }
    else{
        while(1){
            string newHour;
            string newMinute;
            string newSec;
            string tmp;
            if(hour < 10){
                newHour = "0";
                tmp = to_string(hour);
                newHour += tmp;
            }else{
                newHour = to_string(hour);
            }
            if(minute < 10){
                newMinute = "0";
                tmp = to_string(minute);
                newMinute += tmp;
            }else{
                 newMinute = to_string(minute);
            }
            if(sec < 10){
                newSec = "0";
                tmp = to_string(sec);
                newSec += tmp;
            }else{
                newSec = to_string(sec);
            }
            string k = newHour + ":" + newMinute + ":" + newSec;
            //cout << hour<< minute<< sec <<endl;
            cout << k << endl;
            print(k);

            if(hour == 0 && minute == 0 && sec == 0){
                //print("00:00:00");
                break;
            }
            if(minute == 0 && sec == 0){
                if(hour != 0){
                    hour -= 1;
                    minute = 60;
                }
            }
            if(sec == 0){
                if(minute != 0){
                    minute -= 1;
                     sec = 59;
                }
            }else{
                sec -=1;
            }


            for(int delay = 0; delay< 100000000; delay++);
        }
    }
    getch();
    return 0;




}

