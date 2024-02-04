#include <string>
#include <iostream>
using namespace std;
bool caseInsensitiveStringCompare(const std::string& str1, const std::string& str2) {
    return str1.size() == str2.size() &&
           std::equal(str1.begin(), str1.end(), str2.begin(), [](char a, char b) {
               return tolower(a) == tolower(b);
           });
}

// int main(){
//     string c = "E22";
//     string b = "e22";
//     cout<<caseInsensitiveStringCompare(c,b);
// }