
class Class{
    public : 
    int slot_Num;
    string room_No;
    string course_Code;
    string professor;
    string batch;
    string year;
    string group;
    string time_Slot;
    string day;
    string type;

    Class (int s,string r, string cc,string p,string b,string y,string g,string t,string d,string typ) : slot_Num(s),room_No(r),course_Code(cc),professor(p),batch(b),year(y),group(g),time_Slot(t),day(d),type(typ){}

    bool operator<(const Class &other) const {
    return this->slot_Num < other.slot_Num;
  }
};


Class take_Input(int s,string batch){
    string r; string cc;string p;string b;string y;string g;string t;string d;int slot;string type;
    slot = s;
    cout<<"Enter room_no : ";
    cin>>r;
    cout<<"Enter course_code : ";
    cin>>cc;
    cout<<"Enter professor : ";
    cin>>p;
    cout<<"Enter type of class : ";
    cin>>type;
    cout<<"Enter year : "; // remeber to write only number in accordance to which year this tt belongs to (eg - 1,2,3,4 or 1st,2nd,etc.)
    cin>>y;
    cout<<"Enter group : ";
    cin>>g;
    cout<<"Enter time_slot : ";
    cin>>t;
    cout<<"Enter day : ";
    cin>>d;

    Class slot1(s,r,cc,p,batch,y,g,t,d,type);
    return slot1;


}


Class give_Input(int s,string r,string cc,string p,string batch,string y,string g,string t,string d,string type){
    // string r; string cc;string p;string b;string y;string g;string t;string d;int slot;string type;
    

    Class slot1(s,r,cc,p,batch,y,g,t,d,type);
    return slot1;


}


class time_Table{
    public:
    multiset<Class> ms;

    void insert_Slot(Class slot1){
        ms.insert(slot1);
    }

};