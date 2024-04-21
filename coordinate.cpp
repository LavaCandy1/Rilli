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


pair<string, string> getDayAndTimeSlot(int coordinateNumber) {
    map<int, string> reverseDayMap = {
        {1, "Monday"}, {2, "Tuesday"}, {3, "Wednesday"}, {4, "Thursday"},
        {5, "Friday"}, {6, "Saturday"}
    };

    map<int, string> reverseTimeSlotMap = {
        {1, "08:30"}, {2, "09:30"}, {3, "10:30"}, {4, "11:30"}, {5, "12:30"},
        {6, "13:30"}, {7, "14:30"}, {8, "15:30"}, {9, "16:30"}, {10, "17:30"}
    };

    if (coordinateNumber > 0 && coordinateNumber <= 60) {
        int dayNumber = (coordinateNumber - 1) / reverseTimeSlotMap.size() + 1;
        int timeSlotNumber = (coordinateNumber - 1) % reverseTimeSlotMap.size() + 1;
        return {reverseDayMap[dayNumber], reverseTimeSlotMap[timeSlotNumber]};
    } else {
        return {"Invalid", "Invalid"};
    }
}


// #include <map>
// #include <string>

// int getCoordinateNumber(const std::string& day, const std::string& timeSlot) {
//     std::map<std::string, int> dayMap = {
//         {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4},
//         {"Friday", 5}, {"Saturday", 6}
//     };

//     std::map<std::string, int> timeSlotMap = {
//         {"08:30", 1}, {"09:30", 2}, {"10:30", 3}, {"11:30", 4}, {"12:30", 5},
//         {"13:30", 6}, {"14:30", 7}, {"15:30", 8}, {"16:30", 9}, {"17:30", 10}
//     };

//     // Check if the given day and time slot exist in the maps
//     if (dayMap.find(day) != dayMap.end() && timeSlotMap.find(timeSlot) != timeSlotMap.end()) {
//         int dayNumber = dayMap[day];
//         int timeSlotNumber = timeSlotMap[timeSlot];
//         return (dayNumber - 1) * timeSlotMap.size() + timeSlotNumber;
//     } else {
//         // Return -1 for invalid input
//         return -1;
//     }
// }




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


// testing opposite thingi
// int main() {
//     int inputCoordinate;

//     cout << "Enter the coordinate number: ";
//     cin >> inputCoordinate;

//     pair<string, string> result = getDayAndTimeSlot(inputCoordinate);
//     cout << "The corresponding day and time slot for coordinate number " << inputCoordinate << " is: " << result.first << " " << result.second << endl;

//     return 0;
// }