#include <iostream>
#include <regex>
#include <string>


using namespace std;

tuple<string, string, string, string, string> parse_string(const string& input_string) {
    // Define regex pattern to match the components
    regex pattern1(R"((\w+):\s+(\w+);\s+\((\w+)\):\s+(.+?)\s+\{(.+?)\})");
    regex pattern2(R"((\w+):\s+(\w+);\s+(\w+);\s+\((\w+)\):\s+(.+?)\s+\{(.+?)\})");
    regex pattern3(R"((BTECH|First)_([A-Z]\d+))");
    // Use regex to find matches in the input string
    smatch match;
    if (regex_search(input_string, match, pattern1)) {
        string course_code = match[1].str();
        string section = match[2].str();
        string designation = match[3].str();
        string instructor = match[4].str();
        string room = match[5].str();
        
        return make_tuple(course_code, section, designation, instructor, room);
    } else if (regex_search(input_string, match, pattern2)) {
        string course_code = match[1].str();
        string section = match[2].str();
        string designation = match[4].str();
        string instructor = match[5].str();
        string room = match[6].str();
        
        return make_tuple(course_code, section, designation, instructor, room);
    } else if (regex_search(input_string, match, pattern3)) {
        // Extract matched groups
        string program = match[1].str();
        string year = match[2].str();
        string group = match[3].str();

    }else {
        
        return make_tuple(" ", " ", " ", " ", " ");
    }
    return make_tuple(" ", " ", " ", " ", " ");
}
//for tesitng and manual running for understanding

// int main() {
//     // string input_string = "CSET206: B40, (P): Dr. Rashmi Kumari {207 B-LA}";
//     string input_string = "EPHY111L: B1; B2; (T): Mr. Akshat Rana {127-N-CA}";
//     auto result = parse_string(input_string);
//     if (get<0>(result) != "") {
//         cout << "Course Code: " << get<0>(result) << endl;
//         cout << "Section: " << get<1>(result) << endl;
//         cout << "Designation: " << get<2>(result) << endl;
//         cout << "Instructor: " << get<3>(result) << endl;
//         cout << "Room: " << get<4>(result) << endl;
//     } else {
//         cout << "String does not match the expected format." << endl;
//     }

//     return 0;
// }
