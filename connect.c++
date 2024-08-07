#include <iostream>
#include <set>
#include <fstream>  
#include "cpp-httplib\\httplib.h"
#include "String_compi.cpp"
#include "TT_extract\\betterYear.cpp"
#include "Class.cpp"
#include "file_manipulation\auto_save.cpp"
#include "file_manipulation\deserialization.cpp"
#include "coordinate.cpp"
#include "signup.cpp"
#include "input.cpp"
#include "loader.cpp"
#include "student_res.cpp"
#include "moderator_res.cpp"
#include "Teacher_res.cpp"
#include "delete_slot.cpp"
using namespace std;


string teach_name;

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });


//---------------------------------------RILLI STUDENT--------------------------------------------------------------

    svr.Get("/rilli", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilli.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/rilli_up", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilli_update.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    svr.Get("/pret.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("Front End\\pret.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/faltu.js", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream js_file("Front End\\faltu.js");
        if (js_file.is_open()) {
            std::string js_content((std::istreambuf_iterator<char>(js_file)), std::istreambuf_iterator<char>());
            res.set_content(js_content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    // images************************   

    svr.Get("/images/logo.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\logo.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/images/New_Me.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\New_Me.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });



//---------------------------------------RILLI TEACHER--------------------------------------------------------------

    svr.Get("/rilli_Teacher", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilliTeacher.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/rilli_Teach_up", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilliTeacher_update.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    svr.Get("/pret.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("Front End\\pret.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/faltu.js", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream js_file("Front End\\faltu.js");
        if (js_file.is_open()) {
            std::string js_content((std::istreambuf_iterator<char>(js_file)), std::istreambuf_iterator<char>());
            res.set_content(js_content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    // images

    svr.Get("/images/logo.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\logo.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/images/New_Me.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\New_Me.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });



//---------------------------------------------Rilli Moderator---------------------------------------

    svr.Get("/rilli_mod", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilliM.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/rilliM_up", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\rilliM_updtate.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    // svr.Get("/rilliM_del", [](const httplib::Request& req, httplib::Response& res) {
    //     std::ifstream html_file("Front End\\test.html");
    //     if (html_file.is_open()) {
    //         std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
    //         res.set_content(html_content, "text/html");
    //     } else {
    //         res.status = 404;
    //         res.set_content("File not found", "text/plain");
    //     }
    // });

    svr.Get("/pret2.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("Front End\\pret2.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/faltu.js", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream js_file("Front End\\faltu.js");
        if (js_file.is_open()) {
            std::string js_content((std::istreambuf_iterator<char>(js_file)), std::istreambuf_iterator<char>());
            res.set_content(js_content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/ghatiya.js", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream js_file("Front End\\ghatiya.js");
        if (js_file.is_open()) {
            std::string js_content((std::istreambuf_iterator<char>(js_file)), std::istreambuf_iterator<char>());
            res.set_content(js_content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    // images

    svr.Get("/images/logo.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\logo.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/images/New_Me.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\images\\New_Me.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


//---------------------------------------RILLI HOMEPAGE--------------------------------------------------------------

    svr.Get("/homepage", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("Front End\\Homepage.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    svr.Get("/style.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("Front End\\style.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    svr.Get("/Formatting.js", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream js_file("Front End\\Formatting.js");
        if (js_file.is_open()) {
            std::string js_content((std::istreambuf_iterator<char>(js_file)), std::istreambuf_iterator<char>());
            res.set_content(js_content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    // fonts

   svr.Get("/Assets/Fonts/Mori/PPMori-SemiBold.otf", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream font_file("Front End\\Assets\\Fonts\\Mori\\PPMori-SemiBold.otf", std::ios::binary);
    if (font_file.is_open()) {
        std::string font_content((std::istreambuf_iterator<char>(font_file)), std::istreambuf_iterator<char>());
        res.set_content(font_content, "font/otf"); // Correct content type for font file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
    });

    svr.Get("/Assets/Fonts/CanopeeRegular.otf", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream font_file("Front End\\Assets\\Fonts\\CanopeeRegular.otf", std::ios::binary);
    if (font_file.is_open()) {
        std::string font_content((std::istreambuf_iterator<char>(font_file)), std::istreambuf_iterator<char>());
        res.set_content(font_content, "font/otf"); // Correct content type for font file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Fonts/TombstoneBlues.otf", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream font_file("Front End\\Assets\\Fonts\\TombstoneBlues.otf", std::ios::binary);
    if (font_file.is_open()) {
        std::string font_content((std::istreambuf_iterator<char>(font_file)), std::istreambuf_iterator<char>());
        res.set_content(font_content, "font/otf"); // Correct content type for font file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

// videos

svr.Get("/Assets/Clips/Feat1.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Feat1.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Clips/Feat2.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Feat2.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Clips/Feat3.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Feat3.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Clips/Feat6.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Feat6.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Clips/Test3.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Test3.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/R.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\R.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

svr.Get("/Assets/Clips/Main.mp4", [](const httplib::Request& req, httplib::Response& res) {
    std::ifstream video_file("Front End\\Assets\\Clips\\Main.mp4", std::ios::binary);
    if (video_file.is_open()) {
        std::string video_content((std::istreambuf_iterator<char>(video_file)), std::istreambuf_iterator<char>());
        res.set_content(video_content, "video/mp4"); // Correct content type for video file
    } else {
        res.status = 404;
        res.set_content("File not found", "text/plain");
    }
});

 svr.Get("/Assets/logo.png", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream img_file("Front End\\Assets\\logo.png", std::ios::binary);
        if (img_file.is_open()) {
            std::string img_content((std::istreambuf_iterator<char>(img_file)), std::istreambuf_iterator<char>());
            res.set_content(img_content, "image/jpeg");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    
//------------------------------------SignUp------------------------------------------------------------

    svr.Get("/rilli_signUp", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\index.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/rilli_Mod_signUp", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\mSign.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/sign.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("HTML\\sign.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/fail", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\fail.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/success", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\success.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });


    // svr.Post("/Mod_signUp", [](const httplib::Request& req, httplib::Response& res) {
    //     // std::string enrollmentID = req.get_param_value("enrollment_id");
    //     // std::string password = req.get_param_value("password");

    //     // std::string result = mod_signup(enrollmentID, password);

    //     res.set_redirect("/rilli_Login");

    //     // if(result=="bich"){
    //     //     res.set_redirect("/success");
    //     // }else{
    //     //     res.set_redirect("/fail");
    //     // }
    // });
    
//-------------------------------------------SignUp (post)-------------------------------------------
    

    svr.Post("/rilli_signUp", [](const httplib::Request& req, httplib::Response& res) {
        std::string enrollmentID = req.get_param_value("enrollment_id");
        std::string password = req.get_param_value("password");
        std::string batch = req.get_param_value("batch");

        std::string result = student_signup(enrollmentID, password, batch);

        if(result=="bich"){
            res.set_redirect("/success");
        }else{
            res.set_redirect("/fail");
        }
        });


    


//-------------------------------rilliMod (post)---------------------------------------
std::string year_m,group_m,batch_m,course_m,class_type_m;

svr.Post("/rilli_mod", [&](const httplib::Request& req, httplib::Response& res) {
    year_m = req.get_param_value("year");
    group_m = req.get_param_value("group");
    batch_m = req.get_param_value("batch");
    course_m = req.get_param_value("course");
    class_type_m = req.get_param_value("type");

    
    mod_res_str(batch_m,year_m,course_m);

    res.set_redirect("/rilliM_up");
    });

    svr.Post("/rilli_mod_dev", [&](const httplib::Request& req, httplib::Response& res) {
    
    int slot_No;
    string room_No = req.get_param_value("room_no");
    string professor = req.get_param_value("Teacher_Name");
    string time = req.get_param_value("time1");
    string course_Code = req.get_param_value("course_code");
    string day = req.get_param_value("day");
    // cout<<"--"<<room_No<<"--"<<professor<<"--"<<class_type_m<<"--"<<time<<"--"<<day<<"--"<<course_Code;

    cout<<"\niinputing into mod_res";
    mod_input(room_No,course_Code,professor,batch_m,year_m,group_m,time,day,class_type_m);
    cout<<"\nrestarting mod_res page";

    mod_res_str(batch_m,year_m,course_m);
    res.set_redirect("/rilliM_up");

    });

    


    //-----delete(post)-----------
    //updates into rilliM_up   (moderator res)
    svr.Post("/rilliM_del", [&](const httplib::Request& req, httplib::Response& res) {
       string slot_no = req.get_param_value("del_slot");
       cout<<"- "<<slot_no<<" -";
    delete_slot(batch_m,stoi(slot_no),year_m,course_m);
    mod_res_str(batch_m,year_m,course_m);

    res.set_redirect("/rilliM_up");
    });



    //------------------------------------LoginPage------------------------------------------------------------
    svr.Get("/rilli_Login", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\login.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/rilli_Login_err", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream html_file("HTML\\errlogin.html");
        if (html_file.is_open()) {
            std::string html_content((std::istreambuf_iterator<char>(html_file)), std::istreambuf_iterator<char>());
            res.set_content(html_content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/login.css", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream css_file("HTML\\login.css");
        if (css_file.is_open()) {
            std::string css_content((std::istreambuf_iterator<char>(css_file)), std::istreambuf_iterator<char>());
            res.set_content(css_content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    

    //--------------------------------login (post)-----------------------------------------------------
    svr.Post("/rilli_Login", [](const httplib::Request& req, httplib::Response& res) {
    std::string enrollmentID = req.get_param_value("enroll");
    std::string password = req.get_param_value("password");

    cout << enrollmentID<<" "<< password;

    string role = login_fx(enrollmentID,password);
    string batch = login_batch(enrollmentID,password);
    cout<<"\n"<<role;

    if(role=="student"){
        // res.set_redirect("/rilli");
        
    //     string weekdays[] = {"monday", "tuesday", "wednesday", "thursday", "friday"};
    //     string timeslots[] = {"08:30", "09:30", "10:30", "11:30", "13:30", "14:30","15:30","16:30"};
        
    //     // important change 40 to 60 for updated csv extraction thingi 
    //     int size = 60;
    //     string roomno_stud[size];
    //     string course_stud[size];
    //     string teacher_stud[size];
    //     string type_stud[size];
    //     for (int i = 0; i < size; ++i) {
    //     roomno_stud[i] = "DefaultRoom";
    //     course_stud[i] = "DefaultCourse";
    //     teacher_stud[i] = "DefaultTeacher";
    //     type_stud[i] = "invis";
    // }

        

    //     // 2 list day aur time ki jisse for loop chlega
    //     for(const string& day : weekdays){
    //         for(const string& time : timeslots){
    //             Class slot = search(day,time,batch);
    //             int slot_no = getCoordinateNumber(day,time);
    //             // cout<<day<<" "<<time<<" "<<slot_no<<endl;
    //             roomno_stud[slot_no-1] = slot.room_No;
    //             course_stud[slot_no-1] = slot.course_Code;
    //             teacher_stud[slot_no-1] = slot.professor;
    //             type_stud[slot_no-1] = slot.type;
    //         }
    //     }

        student_resp(batch,enrollmentID);

        res.set_redirect("/rilli_up");



        
    } else if(role=="admin"){
        res.set_redirect("/rilli_mod");
    
    } else if(role=="teacher"){
        teach_name = enrollmentID;
        Teacher_resp(teach_name);
    //     string weekdays[] = {"monday", "tuesday", "wednesday", "thursday", "friday"};
    //     string timeslots[] = {"08:30", "09:30", "10:30", "11:30", "13:30", "14:30","15:30","16:30"};
        

    //     int size = 60;
    //     string roomno_teach[size];
    //     string course_teach[size];
    //     string teacher_teach[size];
    //     string type_teach[size];
    //     for (int i = 0; i < size; ++i) {
    //     roomno_teach[i] = "DefaultRoom";
    //     course_teach[i] = "DefaultCourse";
    //     teacher_teach[i] = "DefaultTeacher";
    //     type_teach[i] = "invis";
    // }

        

    //     // 2 list day aur time ki jisse for loop chlega
    //     for(const string& day : weekdays){
    //         for(const string& time : timeslots){
    //             Class slot = search(day,time,batch);
    //             int slot_no = getCoordinateNumber(day,time);
    //             // cout<<day<<" "<<time<<" "<<slot_no<<endl;
    //             roomno_teach[slot_no-1] = slot.room_No;
    //             course_teach[slot_no-1] = slot.course_Code;
    //             teacher_teach[slot_no-1] = slot.professor;
    //             type_teach[slot_no-1] = slot.type;
    //         }
    //     }

        // Teacher_resp(roomno_teach,course_teach,teacher_teach,type_teach);
        res.set_redirect("/rilli_Teach_up");

    } else {
        res.set_redirect("/rilli_Login_err");
    }
    });



//-----------Teacher add POST------------------
     svr.Post("/rilli_teach_dev", [&](const httplib::Request& req, httplib::Response& res) {
    
    int slot_No;
    string room_No = req.get_param_value("room_no");
    string professor = req.get_param_value("Teacher_Name");
    string time = req.get_param_value("time1");
    string course_Code = req.get_param_value("course_code");
    string day = req.get_param_value("day");
    // cout<<"--"<<room_No<<"--"<<professor<<"--"<<class_type_m<<"--"<<time<<"--"<<day<<"--"<<course_Code;
    class_type_m = "Teacher";
    batch_m = "B00";
    group_m = "G0";

    cout<<"\niinputing into teach_res";
    teacher_input(room_No,professor,batch_m,group_m,time,day,class_type_m,teach_name);
    cout<<"\nrestarting teach_res page";

    Teacher_resp(teach_name);
    res.set_redirect("/rilli_Teach_up");

    });
    

    


svr.set_default_headers({
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"},
    });

    svr.listen("localhost", 8080);

    std::cout << "Server started on http://localhost:8080" << std::endl;

    return 0;
}
