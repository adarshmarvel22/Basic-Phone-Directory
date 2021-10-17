
#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<climits>
#include<cmath>


#include<conio.h>//for getc();
#include"update.h"

int main(){
record*head=NULL;
    // record obj;
    int choice;
label:
cout<<"                    0->Exit"<<endl;
    cout<<"                    1->Insert record"<<endl;
    cout<<"                    2->Display record"<<endl;
    cout<<"                    3->Search record of by_name or number"<<endl;
        cout<<"                    4->Delete record"<<endl;
        cout<<"                    5->Add position and department"<<endl;
        cout<<"                    6->Group people by department or position"<<endl;
        cout<<"                    7->Update Contact Nos."<<endl;

cout<<"                      ";                    
cin>>choice;

switch(choice){
    case 1: insert(head);goto label;
    // break;

    case 2: display(head);goto label;
    // break;

    case 3: show_record_of(head);goto label;
    // break;

    case 4: delete_record(head);goto label;
    // break;

case 5: break;

case 6: group(head);goto label;

case 7: update(head);goto label;

case 0: break;

    default: cout<<"Please select a valid choice "<<endl;
    // break;
    goto label;
}

cout<<endl;
cout<<"****************THANKS FOR USING OUR SERVICE*****************";
getch();
return 0;
}