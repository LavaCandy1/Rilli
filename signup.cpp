#include <iostream>
#include <set>
#include <fstream>
#include "String_compi.cpp"
#include "login.cpp"

using namespace std;

// class person {
// public:
//     int id;
//     string role;
//     string password;
//
//     person(int id, string r, string pswrd) : id(id), role(r), password(pswrd) {}
//
//     bool operator<(const person &other) const {
//         return this->id < other.id;
//     }
// };

person take_Input() {
    int i=pre_exist_check_ID();
    string r;
    string p;
    string batch;
    string enroll;
    cout << "Enter id : ";
    cin >> enroll;
    cout << "Enter role : ";
    cin >> r;
    cout << "Enter password : ";
    cin >> p;
    cout << "Enter batch : ";
    cin >> batch;


    hash<string> hasher;
    auto hashCode = hasher(p);

    string hashedPass = to_string(hashCode);

    person slot1(i, r, hashedPass,batch,enroll);
    return slot1;
}

class signUp {
public:
    multiset<person> ms;

    void insert_Slot(person slot1) {
        ms.insert(slot1);
    }
};




bool pre_exist_check(string enroll) {
  multiset<person> loadedData;

  ifstream in("Log testing 9.bin", ios::binary );
  if (!in) {
    cerr << "Error opening file." << endl;
    return 0;
  }

  deserialize(loadedData, in);
  in.close();
  for(const person attempt: loadedData){
    if(caseInsensitiveStringCompare(attempt.enroll,enroll)){
        return 1;
    }
  } 

  return 0;
}

void serialize(signUp &m, ofstream &out) {
    for (const auto &clas : m.ms) {
        // writing slot_no in bin file
        out.write((char *)(&clas.id), sizeof(int));

        // writing role   1
        int nameLength1 = clas.role.length();
        out.write((char *)(&nameLength1), sizeof(int));
        out.write(clas.role.c_str(), nameLength1);

        // writing Course code   2
        int nameLength2 = clas.password.length();
        out.write((char *)(&nameLength2), sizeof(int));
        out.write(clas.password.c_str(), nameLength2);

        
        // writing Course code   3
        int nameLength3 = clas.batch.length();
        out.write((char *)(&nameLength3), sizeof(int));
        out.write(clas.batch.c_str(), nameLength3);

        
        // writing Course code   4
        int nameLength4 = clas.enroll.length();
        out.write((char *)(&nameLength4), sizeof(int));
        out.write(clas.enroll.c_str(), nameLength4);

    }
}


string student_signup(string enro,string pass,string batch){
    
    string role = "student";
    signUp user1;
    int id1 = pre_exist_check_ID();

    // Open the file in append mode to avoid overwriting
    ofstream out("Log testing 9.bin", ios::binary | ios::app);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    hash<string> hasher;
    auto hashCode = hasher(pass);

    string hashedPass = to_string(hashCode);

    person slot(id1, role, hashedPass,batch,enro);

    if(pre_exist_check(slot.enroll)){
        cout<<"This ID already exsists.";
        return "shut";
    }
        cout<<"saving";
        user1.insert_Slot(slot);
        serialize(user1, out);
        
    
    

    cout<<"hullluu";
    out.close();
    return "bich";


    
}



string mod_signup(string enro,string pass){

    string batch_all = "All";
    string role_mod = "admin";
    signUp user12;
    int id1 = pre_exist_check_ID();

    // Open the file in append mode to avoid overwriting
    ofstream out("Log testing 9.bin", ios::binary | ios::app);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    hash<string> hasher;
    auto hashCode = hasher(pass);

    string hashedPass = to_string(hashCode);

    person slot(id1, role_mod, hashedPass,batch_all,enro);

    if(pre_exist_check(slot.enroll)){
        cout<<"This ID already exsists.";
        return "shut";
    }
        // cout<<"saving";
        user12.insert_Slot(slot);
        serialize(user12, out);
        
    
    

    // cout<<"hullluu";
    out.close();
    return "bich";


    
}






int sign_up() {
    signUp user1;

    // Open the file in append mode to avoid overwriting
    ofstream out("Log testing 9.bin", ios::binary | ios::app);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    auto slot = take_Input();
    if(pre_exist_check(slot.enroll)){
        cout<<"This ID already exsists.";
    }else{
        cout<<"saving";
        user1.insert_Slot(slot);
        serialize(user1, out);
    }


    out.close();

    return 0;
}


//admin not permitted wala code