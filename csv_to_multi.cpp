#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "TT_extract\attri_division.cpp"
#include "Class.cpp"
#include "coordinate.cpp"
#include "auto_save.cpp"


using namespace std;

string get_full(string str){
    if(str=="P"){
        return "Practical ";
    }else if(str=="L"){
        return "Lecture ";
    }else if(str=="T"){
        return "Tutorial";
    }else{
        return str;
    }
}

string year = "2nd Year";
string group = "G4"; //make a code to find group from batch or vise versa
string batch = "B27";

void insert_TimeTable(multiset<Class> TimeTable,string cell){
    auto result = parse_string(cell);
    for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            int slot_Num = j*10+i;
            string room_No = get<4>(result);
            string course_Code = get<0>(result);
            string professor = get<3>(result);
            string type = get<2>(result);
            pair<string,string> result1 = getDayAndTimeSlot(slot_Num);
            string day = result1.first;
            string time_Slot = result1.second;
            Class slot(slot_Num,room_No,course_Code,professor,batch,year,group,time_Slot,day,type);
            TimeTable.insert(slot);
        }
    }     
}



int main() {


    multiset<Class> TimeTable;
    string filename = "TT_extract\\"+batch+".csv";
    
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<vector<string>> data;
    string line, cell;
    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<string> row;

        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    file.close();

    int slots[60];
    int count = 0;
    for(int i=1;i<=10;i++){
        for(int j=0;j<6;j++){
            int slot_num = j*10+i;
            slots[count] = slot_num;
            // cout<<slot_num<<"\t-\t"<<count<<"\n";
            count++;
        }
    }

    int iter = 1;
    cout << "Data extraciton in progress...\n";
    for (const auto& row : data) {
        for (const auto& cell : row) {

            // insert_TimeTable(TimeTable,cell);
            auto result = parse_string(cell);
            int slot_num = slots[iter-1];
            // cout<<slot_num<<"\t-\t"<<iter<<"\n";
            string room_No = get<4>(result);
            string course_Code = get<0>(result);
            // cout<<course_Code;
            string professor = get<3>(result);
            string full_type = get_full(get<2>(result));
            string type = full_type;
            pair<string,string> result1 = getDayAndTimeSlot(slot_num);
            string day = result1.first;
            string time_Slot = result1.second;
            Class slot(slot_num,room_No,course_Code,professor,batch,year,group,time_Slot,day,type);
            TimeTable.insert(slot); 
            iter++;
            
        }
        
    }
    cout << "Extraction Done o7\n";


    // cout<<"Outputting Data...\n\n";
    // for(const auto& slot : TimeTable){
    //     cout<<slot.slot_Num<<"-"<<slot.course_Code<<"-"+slot.day<<"-"+slot.time_Slot<<"\n";
    // }


    string TimeTableName = batch+".bin";
    //making a bin file and writing in it
    ofstream out(TimeTableName, ios::binary);
    if (!out) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    auto_save(TimeTable, out);
    out.close();

    return 0;
}
