#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <filesystem>
#include "TT_extract\attri_division.cpp"
#include "Class.cpp"
#include "TT_extract\betterYear.cpp"
#include "coordinate.cpp"
#include "file_manipulation\auto_save.cpp"


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

string year = "1st Year";
string group = "G1"; //make a code to find group from batch or vise versa
string batch = "Batch";


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



// int main() {


//     multiset<Class> TimeTable;
//     string filename = "TT_extract\\"+batch+".csv";
    
//     ifstream file(filename);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << filename << endl;
//         return 1;
//     }

//     vector<vector<string>> data;
//     string line, cell;
//     while (getline(file, line)) {
//         stringstream lineStream(line);
//         vector<string> row;

//         while (getline(lineStream, cell, ',')) {
//             row.push_back(cell);
//         }
//         data.push_back(row);
//     }
//     file.close();

//     int slots[60];
//     int count = 0;
//     for(int i=1;i<=10;i++){
//         for(int j=0;j<6;j++){
//             int slot_num = j*10+i;
//             slots[count] = slot_num;
//             // cout<<slot_num<<"\t-\t"<<count<<"\n";
//             count++;
//         }
//     }

//     int iter = 1;
//     cout << "Data extraciton in progress...\n";
//     for (const auto& row : data) {
//         for (const auto& cell : row) {

//             // insert_TimeTable(TimeTable,cell);
//             auto result = parse_string(cell);
//             int slot_num = slots[iter-1];
//             // cout<<slot_num<<"\t-\t"<<iter<<"\n";
//             string room_No = get<4>(result);
//             string course_Code = get<0>(result);
//             // cout<<course_Code;
//             string professor = get<3>(result);
//             // cout<<"-"<<cell<<"-"<<endl;
//             string full_type = get_full(get<2>(result));
//             string type = full_type;
//             pair<string,string> result1 = getDayAndTimeSlot(slot_num);
//             string day = result1.first;
//             string time_Slot = result1.second;
//             Class slot(slot_num,room_No,course_Code,professor,batch,year,group,time_Slot,day,type);
//             TimeTable.insert(slot); 
//             iter++;
            
//         }
        
//     }
//     cout << "Extraction Done o7\n";


//     // cout<<"Outputting Data...\n\n";
//     // for(const auto& slot : TimeTable){
//     //     cout<<slot.slot_Num<<"-"<<slot.professor<<"-"+slot.day<<"-"+slot.time_Slot<<"\n";
//     // }


//     // string TimeTableName = batch+".bin";
//     // //making a bin file and writing in it
//     // ofstream out(TimeTableName, ios::binary);
//     // if (!out) {
//     //     cerr << "Error opening file." << endl;
//     //     return 1;
//     // }

//     auto_save(TimeTable, batch);
//     // out.close();

//     return 0;
// }


int main() {
    // Directory paths
    string csv_folder = "CsvTables1/";
    string bin_folder = "Bin/";

    // Iterate through each CSV file in the CsvTables1 folder
    for (const auto& entry : filesystem::directory_iterator(csv_folder)) {
        string csv_filename = entry.path().string();

        // Extract batch name from the CSV filename (assuming filename format: "BATCH_NAME.csv")
        string batch = csv_filename.substr(csv_filename.find_last_of('/') + 1);
        batch = batch.substr(0, batch.find_last_of('.'));

        multiset<Class> TimeTable;

        // Read data from the CSV file
        ifstream file(csv_filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << csv_filename << endl;
            continue; // Move to the next CSV file if current one couldn't be opened
        }

        
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

        // Process CSV file line by line
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

        // Iterate through each cell in the CSV file
        int iter = 1;
        for (const auto& row : data) {
            for (const auto& cell : row) {
                auto result = parse_string(cell);
                int slot_num = slots[iter - 1];
                string room_No = get<4>(result);
                string course_Code = get<0>(result);
                string professor = get<3>(result);
                string full_type = get_full(get<2>(result));
                string type = full_type;
                pair<string, string> result1 = getDayAndTimeSlot(slot_num);
                string day = result1.first;
                string time_Slot = result1.second;
                Class slot(slot_num, room_No, course_Code, professor, batch, year, group, time_Slot, day, type);
                TimeTable.insert(slot);
                iter++;
            }
        }

        // Save TimeTable to .bin file
        string course = "BTECH";
        string year_m = "First";
        auto_save_2multi(TimeTable,batch);
    }

    cout << "Conversion and saving to .bin files completed successfully." << endl;

    return 0;
}
