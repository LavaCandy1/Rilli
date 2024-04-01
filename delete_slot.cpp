#include "Class.cpp"
#include "input.cpp"
#include "loader.cpp"
#include <iostream>

using namespace std;

void delete_slot(string batch,int slot_no){
    
    multiset<Class> loaded_data = load_data(batch);

    // Print the loaded data
  for (const auto &slot : loaded_data) {
    // cout << "Room no : " << slot.room_No << endl;
    // cout << "Course Code : " << slot.course_Code << endl;
    // cout << "Professor : " << slot.professor << endl;
    // cout << "Group: " << slot.group << endl;
    // cout << "Year: " << slot.year << endl;
    // cout << "Time Slot: " << slot.time_Slot << endl;
    // cout << "Day : " << slot.day << endl;
    // cout << "Type of class : " << slot.type<<endl;
    cout << "Slot_number : " << slot.slot_Num<<endl;

      cout << "Type : " << slot.type << endl;
    cout<<"\n\n\n\n\n";
  }

}


int main(){
    delete_slot("B27",1);
}