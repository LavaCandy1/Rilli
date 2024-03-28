void auto_save(multiset<Class> ms, ofstream &out) {
  for (const auto &clas : ms) {


    //writing slot_no in bin file
    out.write((char *)(&clas.slot_Num), sizeof(int));

    //writing room_No   1
    int nameLength1 = clas.room_No.length();
    out.write((char *)(&nameLength1), sizeof(int));
    out.write(clas.room_No.c_str(), nameLength1);

    //writing Course code   2
    int nameLength2 = clas.course_Code.length();
    out.write((char *)(&nameLength2), sizeof(int));
    out.write(clas.course_Code.c_str(), nameLength2);

    //writing professor   3
    int nameLength3 = clas.professor.length();
    out.write((char *)(&nameLength3), sizeof(int));
    out.write(clas.professor.c_str(), nameLength3);



    //writing year   5
    int nameLength5 = clas.year.length();
    out.write((char *)(&nameLength5), sizeof(int));
    out.write(clas.year.c_str(), nameLength5);


    //writing group   6
    int nameLength6 = clas.group.length();
    out.write((char *)(&nameLength6), sizeof(int));
    out.write(clas.group.c_str(), nameLength6);

    //writing time slot   7
    int nameLength7 = clas.time_Slot.length();
    out.write((char *)(&nameLength7), sizeof(int));
    out.write(clas.time_Slot.c_str(), nameLength7);

    //writing day   8
    int nameLength8 = clas.day.length();
    out.write((char *)(&nameLength8), sizeof(int));
    out.write(clas.day.c_str(), nameLength8);

    //writing Batch  9
    int nameLength9 = clas.type.length();
    out.write((char *)(&nameLength9), sizeof(int));
    out.write(clas.type.c_str(), nameLength9);
  }
}