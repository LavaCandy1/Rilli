string betterYear(const string& year) {
    if (year == "1st Year")
        return "First";
    else if (year == "2nd Year")
        return "Second";
    else if (year == "3rd Year")
        return "Third";
    else if (year == "4th Year")
        return "Fourth";
    else
        return " "; // Invalid year
}