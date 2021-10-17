
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

class record{

     public:
    string name;
   vector<string> no; 
// string contact;
    string address;
    record *front;
    record *rear;

    record(string Name1,vector<string>&No,string Address1,int N1){
       name=Name1;
       for(int i=0;i<N1;i++){
           no.push_back(No[i]);
       }
    // contact=Contact;
       address=Address1;
       front=NULL;rear=NULL;
    }
};

void insert(record*&head){
    char ch;
string Name,Address;
vector<string>No;
 cin.ignore();
     cout<<"                                       Enter name -->";
      
     getline(cin,Name);

        cout<<endl;
        int N;
        cout<<"                                       How many contact nos. do you have? ->";
        cin>>N;
        cout<<endl;
        for(int i=0;i<N;i++){
            string x;
            cout<<"                                       ";
            cin>>x;
            No.push_back(x);
// string S;
//             stringstream s1;
//             s1<<no[i];
//             s1>>S;
            cout<<endl;
        }
        cin.ignore();
        cout<<"\n"<<"                                       Enter department, position and address separated by a space --> ";
        getline(cin,Address);

    if(head==NULL){
        
        record*temp=new record(Name,No,Address,N);
        head=temp;
        cout<<"                                       Do you want to add more? (y/n/Y/N) ";
        cin>>ch;
        if(ch=='Y' || ch=='y'){
            insert(head);
        }
    }
    else{
        
        record*temp=new record(Name,No,Address,N);
record*curr=head;
        while(curr->rear!=NULL)
        curr=curr->rear;

        curr->rear=temp;
        temp->front=curr;

        cout<<"Do you want to add more? (y,Y/n,N)? ";
        cin>>ch;
        if(ch=='Y' || ch=='y'){
            insert(head);
        }
        
    }
    return;
}

void display(record*&head){
    record*curr=head;

    while(curr!=NULL)
    {
        cout<<"Name: "<<curr->name<<endl<<" contact nos. ";
        
        for(auto i: curr->no){
            cout<<":"<<i<<endl;
        }
        cout<<"address -> "<<curr->address<<endl;
        curr=curr->rear;
        cout<<endl;
    }
    cout<<"............................................................."<<endl;
    return;
}

bool contact_check(string s,record*&curr){
    for(auto i: curr->no){
        if(i==s)
        return 1;
    }
    return 0;
}

void show_record_of(record*head){
    string s;
    cout<<"Enter name or number whose record is to be searched=>";
    cin>>s;
    record*curr=head;
while(curr->name!=s || contact_check(s,curr)){
    curr=curr->rear;
}
 cout<<"Name: "<<curr->name<<endl<<" contact nos. ";
        
        for(auto i: curr->no){
            cout<<":"<<i<<endl;
        }
        cout<<"address -> "<<curr->address<<endl;
        curr=curr->rear;
        cout<<endl;
        return;
}

void delete_record(record*head){
    record*curr=head;
    record*temp=head;
    string s;
    cout<<"Enter name whose record is to be deleted=>";
    cin>>s;
    while(curr->name!=s)
    curr=curr->rear;

    while(temp->rear->name!=s)
    temp=temp->rear;

    temp->rear=curr->rear;
    curr->rear->front=curr->front;
    free(curr);

    return;
}

void group(record*head){
    string s;
    record*curr=head;
cout<<"Enter department or position by which you want to group people => ";
cin>>s;
while(curr->rear!=NULL){
    while(!(curr->address.find(s))){
        curr=curr->rear;
    }
    cout<<"Name: "<<curr->name<<endl<<" contact nos. ";
        
        for(auto i: curr->no){
            cout<<":"<<i<<endl;
        }
        cout<<"address -> "<<curr->address<<endl;
        curr=curr->rear;
        cout<<endl;
}
return;
}

void update(record*head){
    string s;
    cout<<"Enter name whose number is to be updated=>";
    cin>>s;
    record*curr=head;
while(curr->name!=s){
    curr=curr->rear;
}
 cout<<"Name: "<<curr->name<<endl<<" contact nos. ";
        
        for(auto i: curr->no){
            cout<<":"<<i<<endl;
        }
        cout<<"address -> "<<curr->address<<endl;
        // curr=curr->rear;
        cout<<endl;
        // return;
        cout<<"Enter new contact nos.->"<<endl;
for(int i=0;i<curr->no.size();i++)
    curr->no.pop_back();
int newn;
cout<<"How many contact nos. do you have? ->";
cin>>newn;

    for(int i=0;i<newn;i++){
        string x;
        cin>>x;
    curr->no.push_back(x);
    cout<<endl;
    }
return;
}