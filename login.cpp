#include <iostream>
#include <set>  
#include <fstream>



using namespace std;


class person{
    public : 
    int id;
    string role;
    string password;
    string batch;
    string enroll;

    person (int id,string r, string pswrd,string batc,string enro) : id(id),role(r),password(pswrd),batch(batc),enroll(enro){}

    bool operator<(const person &other) const {
    return this->id < other.id;
  }
};


void deserialize(multiset<person> &m, ifstream &in) {
  while (true) {

    //reading id
    int id;
    in.read((char *)(&id), sizeof(int));


    //reading role  1
    int nameLength1;
    if (!in.read((char *)(&nameLength1), sizeof(int))) {
      break;
    }
    char *role = new char[nameLength1 + 1];
    in.read(role, nameLength1);
    role[nameLength1] = '\0';

    

    //reading password  2
    int nameLength2;
    if (!in.read((char *)(&nameLength2), sizeof(int))) {
      break;
    }
    char *password = new char[nameLength2 + 1];
    in.read(password, nameLength2);
    password[nameLength2] = '\0';

  


//reading batch
    int nameLength3;
    if (!in.read((char *)(&nameLength3), sizeof(int))) {
      break;
    }
    char *batch = new char[nameLength3 + 1];
    in.read(batch, nameLength3);
    batch[nameLength3] = '\0';


    //reading enroll
    int nameLength4;
    if (!in.read((char *)(&nameLength4), sizeof(int))) {
      break;
      }
      char *enroll = new char[nameLength4 + 1];
      in.read(enroll, nameLength4);
      enroll[nameLength4] = '\0';
  
      


    //inserting object (slot) into multi
    m.insert(person(id, string(role), string(password),string(batch), string(enroll)));

    delete[] role;
    delete[] password;
    delete[] batch;
    delete[] enroll;
  }
}



person takeInput1(){
    int i; string r;string p;string batch,enroll;
    cout<<"Enter id : ";
    cin>>i;
    cout<<"Enter password : ";
    cin>>p;
    cout<<"Enter batch : ";
    cin>>batch;
    cout<<"Enter enroll : ";
    cin>>enroll;
    hash<string> hasher;
    auto hashCode = hasher(p);

    string hashedPass = to_string(hashCode);

    person slot1(i,r,hashedPass,batch,enroll);
    return slot1;


}

// int pre_exist_check_ID() {
//   multiset<person> loadedData;

//   ifstream in("Log testing 8.bin", ios::binary );
//   if (!in) {
//     cerr << "Error opening file." << endl;
//     return 0;
//   }

//   deserialize(loadedData, in);
//   in.close();
// int id ;
//   for(const person attempt: loadedData){
//     id=attempt.id;

//   }

//   return id+1;
// }

int pre_exist_check_ID() {
  multiset<person> loadedData;

  ifstream in("Log testing 9.bin", ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return 0;
  }

  deserialize(loadedData, in);
  in.close();

  if (loadedData.empty()) {
    return 1; // Return 1 if the file is empty
  } else {
    // If not empty, determine the next available ID by finding the maximum ID and adding 1
    int maxId = 0;
    for (const person &attempt : loadedData) {
      if (attempt.id > maxId) {
        maxId = attempt.id;
      }
    }
    return maxId + 1; // Return the next available ID
  }
}


// main.cpp wala login hai ye yaad rakhlia kr
int log_in() {
  multiset<person> loadedData;

  ifstream in("Log testing 9.bin", ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return 9;
  }

  deserialize(loadedData, in);
  in.close();

  person attemp1 = takeInput1();
  bool success_huh = false;
  // Print the loaded data
  for (const auto &slot : loadedData) {
    if (attemp1.id==slot.id){
      if (attemp1.password==slot.password){
        cout<<"Login Successful";
        success_huh = true;
        if(slot.role=="student"){
          return 3;
        } else if(slot.role=="teacher"){
          return 2;
        } else if(slot.role=="admin"){
          return 1;
        }
      }
      
    }
    if (success_huh){
      break;
    }
  }
  if (!success_huh){
    cout<<"Wrong ID and Password";
  }

  return 0;
}


string login_fx(string id,string pass) {
  multiset<person> loadedData;

  ifstream in("Log testing 9.bin", ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return "file error";
  }

  deserialize(loadedData, in);
  in.close();


  hash<string> hasher;
  auto hashCode = hasher(pass);

  string hashedPass = to_string(hashCode);

  bool success_huh = false;
  // Print the loaded data
  for (const auto &slot : loadedData) {
    if (caseInsensitiveStringCompare(id,slot.enroll)){
      if (hashedPass==slot.password){
        // cout<<"Login Successful";
        success_huh = true;
        if(slot.role=="student"){
          return "student";
        } else if(slot.role=="teacher"){
          return "teacher";
        } else if(slot.role=="admin"){
          return "admin";
        }
      }
      
    }
      
  }
  if (!success_huh){
    cout<<"Wrong ID and Password";
    return "no";
  }

  return 0;
}

string login_batch(string id,string pass){
  multiset<person> loadedData;

  ifstream in("Log testing 9.bin", ios::binary);
  if (!in) {
    cerr << "Error opening file." << endl;
    return "file error";
  }

  deserialize(loadedData, in);
  in.close();

  for (const auto &slot : loadedData) {
    if (caseInsensitiveStringCompare(id,slot.enroll)){
      return slot.batch;
    
    
    }
  }

  return "no entry";

}