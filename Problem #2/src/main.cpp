#include <iostream>
#include <vector>
#include <map>
#include <conio.h>

using namespace std;


map<string,string> allPeople;
pair<string,int> p1("Mahamakut Building",0);
pair<string,int> p2("CU Sport Complex",0);
pair<string,int> p3("Sanam Jub",0);
pair<string,int> p4("Prasart Dang",0);
pair<string,int> p5("Larngear",0);
vector<pair<string,int>> listPlace = {p1,p2,p3,p4,p5};

void checkIn(){
    string phone;
    int place;
    cout << "Please input phone number:" ;
    cin >> phone;
    cout << "list of places" << endl;
    for(int i = 0; i < listPlace.size();i++){
       cout << i+1<<" "<<listPlace[i].first << endl;
    }
    cout << "Please input place:" ;
    cin >> place;
    if(place > listPlace.size()){
        cout << "input wrong place" << endl;
    }else{
        if(allPeople.find(phone) != allPeople.end()){
        string oldPlace = allPeople[phone];
        for(int i = 0; i < listPlace.size();i++){
            if(listPlace[i].first == oldPlace){
                listPlace[i].second -= 1;
                break;
            }
        }
        allPeople[phone] = listPlace[place-1].first;

        }else{
            allPeople[phone] = listPlace[place-1].first;
        }
    }

    listPlace[place-1].second += 1;
    cout << "------------------------"<< endl;
}

void checkOut(){
    string phone;
    cout << "Please input phone number:" ;
    cin >> phone;
    if(allPeople.find(phone) != allPeople.end()){
        string oldPlace = allPeople[phone];
        for(int i = 0; i < listPlace.size();i++){
            if(listPlace[i].first == oldPlace){
                listPlace[i].second -= 1;
                break;
            }
        }
        allPeople.erase(allPeople.find(phone));

    }else{
        cout << "Yon didn't log in" << endl;
    }


    cout << "------------------------"<< endl;

}



int main()
{
    int x;
    while(1){
        cout << "Welcome to Chula chana!!" << endl;
        cout << "List of commands" << endl;
        cout << "1) Check in" << endl;
        cout << "2) Check out" << endl;
        cout << "3) Print people number" << endl;
        cout << "4) quit " << endl;
        cout << "Please input any number:" ;
        cin >> x;
        cout << "------------------------"<< endl;
        if(x == 1){
            checkIn();
        }else if(x == 2){
            checkOut();
        }else if(x == 3){
            for(int i = 0; i < listPlace.size();i++){
                cout << i+1<<" "<<listPlace[i].first << " "<< listPlace[i].second<< endl;
            }

        }else if(x == 4){
            break;
        }else{
             cout << "wrong input!!! " << endl;
        }
        cout << "------------------------"<< endl;
    }
    getch();
    return 0;
}
