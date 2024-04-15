// #include <iostream>
// #include <fstream>
// #include <set>
// #include "Class.cpp"
// #include "TT_extract\\betterYear.cpp"
// #include "file_manipulation\auto_save.cpp"
// #include "file_manipulation\deserialization.cpp"

//requires BATCH and SLOT_NO only to delete a perticular class

using namespace std;

void delete_slot(string batch,int slot_no,string year,string course){
  
  multiset<Class> loaded_data;

  deserialize(loaded_data,batch,year,course);

    // Print the loaded data
  for (const auto &slot : loaded_data) {
    
    if(slot.slot_Num==slot_no){
      // cout << "Slot_number : " << slot.slot_Num<<endl;
      // cout << "Type : " << slot.professor << endl;
      // cout<<"\n\n\n\n\n";
      loaded_data.erase(slot);
      loaded_data.insert(Class(slot_no,"","","","","","","","",""));
      break;
    }
  }

auto_save(loaded_data,batch,year,course);

}


// int main(){
//     delete_slot("B55",1,"1st Year","BTECH");
// }