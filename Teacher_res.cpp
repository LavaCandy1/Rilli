#include <iostream>
#include <fstream>
using namespace std;

//string roomno[],string course[],string teacher[],string type[]

string generateHTMLWithCSS_teach(string roomno[],string course_Code[],string teacher[],string type[]) {
    string h = "hallo";
    string htmlContent = R"(
       <html>
  <head>
    <link rel="stylesheet" href="pret.css" />
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />

    <link
      href="https://fonts.googleapis.com/css2?family=Montserrat:wght@900&family=Rubik:wght@300;400&display=swap"
      rel="stylesheet"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200"
    />
    <link
      href="https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css"
      rel="stylesheet"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@24,400,0,0"
    />

    <style>
      .material-symbols-outlined {
        font-size: 35px;
        font-variation-settings: "FILL" 1, "wght" 600, "GRAD" 200, "opsz" 98;
      }
    </style>
  </head>
  <div id="mydiv">
    <div class="tt">
      <button class="divClose" id="changeZIndexButton2">
        <i class="material-symbols-outlined">
          close
          </i>
      </button>
      <!-- <button class="item-5" id="changeZIndexButton2"></button> -->
    </div>
    <form action="/rilli_teach_dev" method="post">
      <div class="tName fle">
        <div class="input-box">
          <input
            type="text"
            class="input"
            id="username"
            placeholder=""
            required
            name = "Teacher_Name"
          />
          <label for="username">Batch Name</label>
        </div>
      </div>
      <div class="sSubject fle">
        <div class="input-box">
          <input
            type="text"
            class="input"
            id="password"
            placeholder="Subject"
            required
            name = "course_code"
          />
          <label for="p">Subject</label>
        </div>
      </div>
      <div class="roomC fle">
        <div class="input-box">
          <input
            type="text"
            class="input"
            id="password"
            placeholder="Subject"
            required
            name = "room_no"
          />
          <label for="p">Room Code</label>
        </div>
      </div>
      <div class="dayI fle">
        <div class="wrapper-dropdown" id="dropdown">
          <input class="selected-display" id="destination" name="day" readonly></input>
          <svg
            class="arrow"
            id="drp-arrow"
            width="24"
            height="24"
            viewBox="0 0 24 24"
            fill="none"
            xmlns="http://www.w3.org/2000/svg"
            class="transition-all ml-auto rotate-180"
          >
            <path
              d="M7 14.5l5-5 5 5"
              stroke="currentColor"
              stroke-width="1.5"
              stroke-linecap="round"
              stroke-linejoin="round"
            ></path>
          </svg>
          <ul class="dropdown">
            <li class="item">Monday</li>
            <li class="item">Tuesday</li>
            <li class="item">Wednesday</li>
            <li class="item">Thursday</li>
            <li class="item">Friday</li>
          </ul>
        </div>
      </div>
      <div class="rangeT fle">
        <input type="time" id="time1" name="time1" />
        <span>------</span>
        <input type="time" id="time2" name="time2" />
      </div>

      <div class="sub fle">
        <div class="input-box">
          <input type="submit" class="btn-submit" value="Submit" required />
          <div class="notifi"></div>
        </div>
      </div>
    </form>
  
</div>
  <body onload="pageLoad() ">
    <style type="text/css"></style>
    <div class="parent">
      <div class="navy">
        <div class="logo" id="sid">
          <img
            class="GolGol"
            src="images/logo.png"
            onclick="toggleFunction() "
          />
        </div>
        <div class="log1"><img class="DP" src="images/New_Me.png" /></div>
        <div class="log2">
          <label class="DAY" id="current-day"></label
          ><label class="NO" id="current-date"></label>
        </div>
        <div class="log3" id="Theme">
          <i class="bx bx-sun bx-md" style="color: #282729"></i>
        </div>
        <div class="log4" onclick="window.close() ">
          <i class="bx bx-log-out bx-md"></i>
        </div>
        <div class="bor1"></div>
        <div class="bor2"></div>
        <div class="bor3"></div>
        <div class="ril">
          <label class="rills">RILLI</label>
        </div>
      </div>
      <div class="Todo" id="TD">
        <h1 id="sid" class="opa">Todo List</h1>
        <div
          class="button_minus opa"
          onclick="removeLastExpandableDiv() "
          id=""
        ></div>
        <div class="button_plus opa" onclick="createExpandableDiv() "></div>
        <div id="expandable-container" class="opa">
          <!-- Existing expandable divs or new ones will be added here -->
        </div>
      </div>


      <div class="Main" id="main">
        <div class="calendar">
          <div class="top">
            <h3 id="currentMonthYear"></h3>
            <div class="buttonContainer">
              <button class="topButtons" id="changeZIndexButton">
                +
              </button>
              <button class="topButtons" id="subRequest">
                <span class="material-symbols-outlined"> person_search </span>
              </button>
            </div>

            <!-- <button class="style-3" id="nextWeek">Prev</button>
            <button class="style-4" id="prevWeek">Next</button> -->
          </div>
          <div class="NONE days-1">SUN</div>
          <div class="NONE days-2">MON</div>
          <div class="NONE days-3">TUE</div>
          <div class="NONE days-4">WED</div>
          <div class="NONE days-5">THU</div>
          <div class="NONE days-6">FRI</div>
          <div class="NONE days-7">SAT</div>
          <!-- Numbers -->
          <label class="NONE sun dayN"></label>
          <label class="NONE mon dayN"></label>
          <label class="NONE tue dayN"></label>
          <label class="NONE wed dayN"></label>
          <label class="NONE thu dayN"></label>
          <label class="NONE fri dayN"></label>
          <label class="NONE sat dayN"></label>
          <div class="bars">
            <div class="bars2">
              <!--Borders-->
              <div class="bord bord1"></div>
              <div class="bord bord2"></div>
              <div class="bord bord3"></div>
              <div class="bord bord4"></div>
              <div class="bord bord5"></div>
              <div class="bord bord6"></div>
              <div class="bord bord7"></div>
              <div class="bord bord8"></div>
              <div class="bord bord9"></div>
              <div class="bord bord10"></div>
              <div class="bord bord11"></div>

              <!--Timings-->
              <div class="time All">All day</div>
              <div class="time AM12">08:30</div>
              <div class="time AM1">09:30</div>
              <div class="time AM2">10:40</div>
              <div class="time AM3">11:40</div>
              <div class="time AM4">BREAK</div>
              <div class="time AM5">13:30</div>
              <div class="time AM6">14:30</div>
              <div class="time AM7">15:40</div>
              <div class="time AM8">16:40</div>
              <div class="time AM9">17:35</div>

              <!-- BOXES -->
                       <div class="SLOT slot1 )"+type[0]+R"(">
                <form action="" class="slotF">
                  
                  <span>)"+course_Code[0]+R"(</span>
                  <span>)"+teacher[0]+R"(</span>
                  <span>)"+roomno[0]+R"(</span>
                  
                  </form>
              </div>
      <div class="SLOT slot2 )"+type[1]+R"(">
        <form action="" class="slotF">
          
          <span>)"+course_Code[1]+R"(</span>
          <span>)"+teacher[1]+R"(</span>
          <span>)"+roomno[1]+R"(</span>
          
        </form>
      </div>
      <div class="SLOT slot3 )"+type[2]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[2]+R"(</span>
            <span>)"+teacher[2]+R"(</span>
            <span>)"+roomno[2]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot4 )"+type[3]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[3]+R"(</span>
            <span>)"+teacher[3]+R"(</span>
            <span>)"+roomno[3]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot5 )"+type[4]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[4]+R"(</span>
            <span>)"+teacher[4]+R"(</span>
            <span>)"+roomno[4]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot6 )"+type[5]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[5]+R"(</span>
            <span>)"+teacher[5]+R"(</span>
            <span>)"+roomno[5]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot7 )"+type[6]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[6]+R"(</span>
            <span>)"+teacher[6]+R"(</span>
            <span>)"+roomno[6]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot8 )"+type[7]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[7]+R"(</span>
            <span>)"+teacher[7]+R"(</span>
            <span>)"+roomno[7]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot9 )"+type[8]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[8]+R"(</span>
            <span>)"+teacher[8]+R"(</span>
            <span>)"+roomno[8]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot10 )"+type[9]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[9]+R"(</span>
            <span>)"+teacher[9]+R"(</span>
            <span>)"+roomno[9]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot11 )"+type[10]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[10]+R"(</span>
            <span>)"+teacher[10]+R"(</span>
            <span>)"+roomno[10]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot12 )"+type[11]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[11]+R"(</span>
            <span>)"+teacher[11]+R"(</span>
            <span>)"+roomno[11]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot13 )"+type[12]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[12]+R"(</span>
            <span>)"+teacher[12]+R"(</span>
            <span>)"+roomno[12]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot14 )"+type[13]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[13]+R"(</span>
            <span>)"+teacher[13]+R"(</span>
            <span>)"+roomno[13]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot15 )"+type[14]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[14]+R"(</span>
            <span>)"+teacher[14]+R"(</span>
            <span>)"+roomno[14]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot16 )"+type[15]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[15]+R"(</span>
            <span>)"+teacher[15]+R"(</span>
            <span>)"+roomno[15]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot17 )"+type[16]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[16]+R"(</span>
            <span>)"+teacher[16]+R"(</span>
            <span>)"+roomno[16]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot18 )"+type[17]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[17]+R"(</span>
            <span>)"+teacher[17]+R"(</span>
            <span>)"+roomno[17]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot19 )"+type[18]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[18]+R"(</span>
            <span>)"+teacher[18]+R"(</span>
            <span>)"+roomno[18]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot20 )"+type[19]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[19]+R"(</span>
            <span>)"+teacher[19]+R"(</span>
            <span>)"+roomno[19]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot21 )"+type[20]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[20]+R"(</span>
            <span>)"+teacher[20]+R"(</span>
            <span>)"+roomno[20]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot22 )"+type[21]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[21]+R"(</span>
            <span>)"+teacher[21]+R"(</span>
            <span>)"+roomno[21]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot23 )"+type[22]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[22]+R"(</span>
            <span>)"+teacher[22]+R"(</span>
            <span>)"+roomno[22]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot24 )"+type[23]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[23]+R"(</span>
            <span>)"+teacher[23]+R"(</span>
            <span>)"+roomno[23]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot25 )"+type[24]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[24]+R"(</span>
            <span>)"+teacher[24]+R"(</span>
            <span>)"+roomno[24]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot26 )"+type[25]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[25]+R"(</span>
            <span>)"+teacher[25]+R"(</span>
            <span>)"+roomno[25]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot27 )"+type[26]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[26]+R"(</span>
            <span>)"+teacher[26]+R"(</span>
            <span>)"+roomno[26]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot28 )"+type[27]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[27]+R"(</span>
            <span>)"+teacher[27]+R"(</span>
            <span>)"+roomno[27]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot29 )"+type[28]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[28]+R"(</span>
            <span>)"+teacher[28]+R"(</span>
            <span>)"+roomno[28]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot30 )"+type[29]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[29]+R"(</span>
            <span>)"+teacher[29]+R"(</span>
            <span>)"+roomno[29]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot31 )"+type[30]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[30]+R"(</span>
            <span>)"+teacher[30]+R"(</span>
            <span>)"+roomno[30]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot32 )"+type[31]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[31]+R"(</span>
            <span>)"+teacher[31]+R"(</span>
            <span>)"+roomno[31]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot33 )"+type[32]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[32]+R"(</span>
            <span>)"+teacher[32]+R"(</span>
            <span>)"+roomno[32]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot34 )"+type[33]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[33]+R"(</span>
            <span>)"+teacher[33]+R"(</span>
            <span>)"+roomno[33]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot35 )"+type[34]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[34]+R"(</span>
            <span>)"+teacher[34]+R"(</span>
            <span>)"+roomno[34]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot36 )"+type[35]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[35]+R"(</span>
            <span>)"+teacher[35]+R"(</span>
            <span>)"+roomno[35]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot37 )"+type[36]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[36]+R"(</span>
            <span>)"+teacher[36]+R"(</span>
            <span>)"+roomno[36]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot38 )"+type[37]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[37]+R"(</span>
            <span>)"+teacher[37]+R"(</span>
            <span>)"+roomno[37]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot39 )"+type[38]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[38]+R"(</span>
            <span>)"+teacher[38]+R"(</span>
            <span>)"+roomno[38]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot40 )"+type[39]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[39]+R"(</span>
            <span>)"+teacher[39]+R"(</span>
            <span>)"+roomno[39]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot41 )"+type[40]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[40]+R"(</span>
            <span>)"+teacher[40]+R"(</span>
            <span>)"+roomno[40]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot42 )"+type[41]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[41]+R"(</span>
            <span>)"+teacher[41]+R"(</span>
            <span>)"+roomno[41]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot43 )"+type[42]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[42]+R"(</span>
            <span>)"+teacher[42]+R"(</span>
            <span>)"+roomno[42]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot44 )"+type[43]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[43]+R"(</span>
            <span>)"+teacher[43]+R"(</span>
            <span>)"+roomno[43]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot45 )"+type[44]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[44]+R"(</span>
            <span>)"+teacher[44]+R"(</span>
            <span>)"+roomno[44]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot46 )"+type[45]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[45]+R"(</span>
            <span>)"+teacher[45]+R"(</span>
            <span>)"+roomno[45]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot47 )"+type[46]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[46]+R"(</span>
            <span>)"+teacher[46]+R"(</span>
            <span>)"+roomno[46]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot48 )"+type[47]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[47]+R"(</span>
            <span>)"+teacher[47]+R"(</span>
            <span>)"+roomno[47]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot49 )"+type[48]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[48]+R"(</span>
            <span>)"+teacher[48]+R"(</span>
            <span>)"+roomno[48]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot50 )"+type[49]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[49]+R"(</span>
            <span>)"+teacher[49]+R"(</span>
            <span>)"+roomno[49]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot51 )"+type[50]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[50]+R"(</span>
            <span>)"+teacher[50]+R"(</span>
            <span>)"+roomno[50]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot52 )"+type[51]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[51]+R"(</span>
            <span>)"+teacher[51]+R"(</span>
            <span>)"+roomno[51]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot53 )"+type[52]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[52]+R"(</span>
            <span>)"+teacher[52]+R"(</span>
            <span>)"+roomno[52]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot54 )"+type[53]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[53]+R"(</span>
            <span>)"+teacher[53]+R"(</span>
            <span>)"+roomno[53]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot55 )"+type[54]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[54]+R"(</span>
            <span>)"+teacher[54]+R"(</span>
            <span>)"+roomno[54]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot56 )"+type[55]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[55]+R"(</span>
            <span>)"+teacher[55]+R"(</span>
            <span>)"+roomno[55]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot57 )"+type[56]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[56]+R"(</span>
            <span>)"+teacher[56]+R"(</span>
            <span>)"+roomno[56]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot58 )"+type[57]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[57]+R"(</span>
            <span>)"+teacher[57]+R"(</span>
            <span>)"+roomno[57]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot59 )"+type[58]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[58]+R"(</span>
            <span>)"+teacher[58]+R"(</span>
            <span>)"+roomno[58]+R"(</span>
            
            </form>
          </div>
      <div class="SLOT slot60 )"+type[59]+R"(">
          <form action="" class="slotF">
          
            <span>)"+course_Code[59]+R"(</span>
            <span>)"+teacher[59]+R"(</span>
            <span>)"+roomno[59]+R"(</span>
            
            </form>
          </div>
            </div>
          </div>
        </div>
      </div>

      <!-- <div class="curr"></div>
      <div class="even"></div> -->
    </div>
    <script>
      function pageLoad() {
        displayDay();
        displayDate();
        updateWeekNumbers();
      }
      function themeF() {}
      const Theme = document.getElementById("Theme");
      Theme.onclick = function () {
        document.body.classList.toggle("dark-theme");
      };

      var draggableDiv = document.getElementById("mydiv");
      var isDragging = false;
      var offsetX, offsetY;

      draggableDiv.addEventListener("mousedown", function (e) {
        isDragging = true;
        offsetX = e.clientX - draggableDiv.getBoundingClientRect().left;
        offsetY = e.clientY - draggableDiv.getBoundingClientRect().top;
      });

      document.addEventListener("mousemove", function (e) {
        if (isDragging) {
          var x = e.clientX - offsetX;
          var y = e.clientY - offsetY;
          draggableDiv.style.left = x + "px";
          draggableDiv.style.top = y + "px";
        }
      });

      document.addEventListener("mouseup", function () {
        isDragging = false;
      });

      // Get the current date
      const currentDate = new Date();

      // Get the month and year
      const month = currentDate.toLocaleString("default", { month: "long" });
      const year = currentDate.getFullYear();

      // Display the month and year in the h3 element
      const currentMonthYearElement =
        document.getElementById("currentMonthYear");
      currentMonthYearElement.textContent = `${month} ${year}`;

      function updateWeekNumbers() {
        const currentDate = new Date();
        const labels = document.querySelectorAll(
          ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
        );

        // Calculate the start of the current week (Sunday)
        const startDate = new Date(currentDate);
        startDate.setDate(currentDate.getDate() - currentDate.getDay());

        // Loop through the labels and update their text content with day numbers
        labels.forEach((label, index) => {
          const date = new Date(startDate);
          date.setDate(startDate.getDate() + index);
          const dayNumber = date.getDate();

          // Wrap around for days below 1 (previous month) or above 31 (next month)
          label.textContent =
            dayNumber <= 0
              ? 31 + dayNumber
              : dayNumber > 31
              ? dayNumber - 31
              : dayNumber;
        });
      }

      // Function to show the next week's day numbers
      function showNextWeek() {
        const labels = document.querySelectorAll(
          ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
        );

        labels.forEach((label) => {
          const currentNumber = parseInt(label.textContent);
          label.textContent =
            currentNumber + 7 > 31 ? currentNumber + 7 - 31 : currentNumber + 7;
        });
      }

      // Function to show the previous week's day numbers
      function showPreviousWeek() {
        const labels = document.querySelectorAll(
          ".sun, .mon, .tue, .wed, .thu, .fri, .sat"
        );

        labels.forEach((label) => {
          const currentNumber = parseInt(label.textContent);
          label.textContent =
            currentNumber - 7 < 1 ? currentNumber - 7 + 31 : currentNumber - 7;
        });
      }
      function toggleFunction() {
        let isToggled = false;
        const opaElements = document.querySelectorAll(".opa");
        const sid = document.getElementById("sid");
        const TD = document.getElementById("TD");
        const main = document.getElementById("main");
        return function () {
          isToggled = !isToggled;
          if (isToggled) {
            TD.style.width = "450px";
            main.style.marginLeft = "450px";
            opaElements.forEach((element) => {
              element.style.transitionDuration = "0.3s";
            });
            setTimeout(function () {
              opaElements.forEach((element) => {
                element.style.opacity = 1;
              });
            }, 600);
          } else {
            TD.style.width = "0";
            main.style.marginLeft = "0";
            opaElements.forEach((element) => {
              element.style.opacity = "0";
              element.style.transitionDuration = "0.3s";
            });
          }
        };
      }
      const toggleButton = document.getElementById("sid");
      toggleButton.addEventListener("click", toggleFunction());

      // Add event listeners to the Next and Previous Week buttons
      
    </script>
    <script>
      const changeZIndexButton = document.getElementById("changeZIndexButton");
      const ccDiv = document.getElementById("mydiv");
      changeZIndexButton.addEventListener("click", function () {
        ccDiv.style.zIndex = "2";
      });
      
      const changeZIndexButton2 = document.getElementById("changeZIndexButton2");
      changeZIndexButton2.addEventListener("click", function () {
        ccDiv.style.zIndex = "0";
      });

      const selectedAll = document.querySelectorAll(".wrapper-dropdown");

selectedAll.forEach((selected) => {
  const optionsContainer = selected.children[2];
  const optionsList = selected.querySelectorAll("div.wrapper-dropdown li");

  selected.addEventListener("click", () => {
    let arrow = selected.children[1];

    if (selected.classList.contains("active")) {
      handleDropdown(selected, arrow, false);
    } else {
      let currentActive = document.querySelector(".wrapper-dropdown.active");

      if (currentActive) {
        let anotherArrow = currentActive.children[1];
        handleDropdown(currentActive, anotherArrow, false);
      }

      handleDropdown(selected, arrow, true);
    }
  });

  // Update the display of the dropdown and set the value of "selected-display" input
  for (let o of optionsList) {
    o.addEventListener("click", () => {
      const inputValue = o.textContent; // Get the text content of the selected option
      const parentDropdown = o.closest(".wrapper-dropdown");
      const selectedDisplay = parentDropdown.querySelector(".selected-display");

      selectedDisplay.value = inputValue; // Set the value of "selected-display" input
    });
  }
});

// close all the dropdowns
function closeAllDropdowns() {
  const selectedAll = document.querySelectorAll(".wrapper-dropdown");
  selectedAll.forEach((selected) => {
    const optionsContainer = selected.children[2];
    let arrow = selected.children[1];

    handleDropdown(selected, arrow, false);
  });
}

// open all the dropdowns
function handleDropdown(dropdown, arrow, open) {
  if (open) {
    arrow.classList.add("rotated");
    dropdown.classList.add("active");
  } else {
    arrow.classList.remove("rotated");
    dropdown.classList.remove("active");
  }
}
      </script>
      <script src="ghatiya.js"></script>
    <script src="faltu.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  </body>
</html>


    )";

    return htmlContent;
}

int Teacher_resp(string Tname) {

  int sizeee = 60;
  string roomno[sizeee];
  string course[sizeee];
  string teacher[sizeee];
  string type[sizeee];
  for (int i = 0; i < sizeee; ++i) {
    roomno[i] = "DefaultRoom";
    course[i] = "DefaultCourse";
    teacher[i] = "DefaultTeacher";
    type[i] = "invis";
  }

  string path = "Teach Bin\\Time_Table_2023-24-even_"+Tname;
  auto data = load_data(path);
  int slotno = 0;
  for(const auto& slot : data){
    roomno[slotno] = slot.room_No;
    course[slotno] = slot.course_Code;
    teacher[slotno] = slot.professor;
    type[slotno] = slot.type;
    slotno++;
    // cout<<slot.slot_Num<<"\t"<<slot.course_Code<<endl;
  }
    // Get CSS-related data from your backend logic
    double divOpacity = 0.7; // Replace with your actual logic to get the opacity

    std::string htmlContent = generateHTMLWithCSS_teach(roomno,course,teacher,type);

    std::ofstream outFile("Front End\\rilliTeacher_update.html");
    outFile << htmlContent;

    return 0;
}


// int main() {
//     // Replace with your actual logic to get the opacity
//     string roomno[60];
//     string course[60];
//     string teacher[60];
//     string type[60];
//     std::string htmlContent = generateHTMLWithCSS(roomno,course,teacher,type);

//     std::ofstream outFile("Front End\\rilliTeacher_updtae.html");
//     outFile << htmlContent;

//     return 0;
// }