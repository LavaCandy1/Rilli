#include <iostream>
#include <regex>
#include <string>


using namespace std;

tuple<string, string, string, string, string> parse_string(const string& input_string) {
    // Define regex pattern to match the components
    regex pattern(R"((\w+):\s+(\w+);\s+\((\w+)\):\s+(.+?)\s+\{(.+?)\})");

    // Use regex to find matches in the input string
    smatch match;
    if (regex_search(input_string, match, pattern)) {
        string course_code = match[1].str();
        string section = match[2].str();
        string designation = match[3].str();
        string instructor = match[4].str();
        string room = match[5].str();
        
        return make_tuple(course_code, section, designation, instructor, room);
    } else {
        
        return make_tuple(" ", " ", " ", " ", " ");
    }
}



//for tesitng and manual running for understanding

// int main() {
//     // string input_string = "CSET206: B40, (P): Dr. Rashmi Kumari {207 B-LA}";
//     string input_string = "CSET488: ALL-L, (L): Dr. Rohit Sachan {Online-2}CSET292: ALL-L, (L): Dr. Shahnawaz Ahmad {302-B-TR}";
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
