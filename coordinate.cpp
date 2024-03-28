#include <iostream>
#include <map>
#include <string>

using namespace std;

int getCoordinateNumber(const string& day, const string& timeSlot) {
    map<string, int> dayMap = {
        {"monday", 1}, {"tuesday", 2}, {"wednesday", 3}, {"thursday", 4},
        {"friday", 5}, {"saturday", 6}
    };

    map<string, int> timeSlotMap = {
        {"08:30", 1}, {"09:30", 2}, {"10:30", 3}, {"11:30", 4}, {"12:30",5},
        {"13:30", 6}, {"14:30", 7}, {"15:30", 8}, {"16:30", 9}, {"17:30",10}
    };

    if (dayMap.find(day) != dayMap.end() && timeSlotMap.find(timeSlot) != timeSlotMap.end()) {
        int dayNumber = dayMap[day];
        int timeSlotNumber = timeSlotMap[timeSlot];
        return ((dayNumber - 1) * timeSlotMap.size()) + timeSlotNumber;
    } else {
        return -1;
    }
}

// int main() {
//     string inputDay, inputTimeSlot;

//     cout << "Enter the day (e.g., Monday, Tuesday, etc.): ";
//     getline(cin, inputDay);

//     cout << "Enter the time slot (e.g., 8:30, 9:30, etc.): ";
//     getline(cin, inputTimeSlot);

//     int coordinateNumber = getCoordinateNumber(inputDay, inputTimeSlot);
//     if (coordinateNumber != -1) {
//         cout << "The coordinate/number for " << inputDay << " " << inputTimeSlot << " is: " << coordinateNumber << endl;
//     } else {
//         cout << "Invalid input! Please enter a valid day and time slot." << endl;
//     }

//     return 0;
// }