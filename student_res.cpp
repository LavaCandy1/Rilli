#include <iostream>
#include <fstream>
using namespace std;

//string roomno[],string course[],string teacher[],string type[]

string generateHTMLWithCSS(string roomno[],string course_Code[],string teacher[],string type[]) {
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
    <style>
      .material-symbols-outlined {
        font-size: 35px;
        font-variation-settings: "FILL" 1, "wght" 600, "GRAD" 200, "opsz" 98;
      }
    </style>
  </head>
  <body onload="pageLoad() ">
    <style type="text/css"></style>
    <div class="parent">
      <div class="navy">
        <div class="logo">
          <img class="GolGol" src="images/logo.png" />
        </div>
        <div class="log1"><img class="DP" src="images/New_Me.png" /></div>
        <div class="log2">
          <label class="DAY" id="current-day"></label
          ><label class="NO" id="current-date"></label>
        </div>
        <div class="log3">
          <i class="bx bx-sun bx-md" style="color: #c8a366"></i>
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
      <div class="Todo">
        <h1>Todo List</h1>
        <div class="button_minus" onclick="removeLastExpandableDiv() "></div>
        <div class="button_plus" onclick="createExpandableDiv() "></div>
        <div id="expandable-container">
          <!-- Existing expandable divs or new ones will be added here -->
        </div>
      </div>

      <div class="Main">
        <div class="calendar">
          <div class="top">
            <h3>November 2023 /</h3>
            <button class="style-3" id="nextWeek">Prev</button>
            <button class="style-4" id="prevWeek">Next</button>
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
                <span>)"+course_Code[0]+R"(</span>
                <span>)"+teacher[0]+R"(</span>
                <span>)"+roomno[0]+R"(</span>
              </div>

              <div class="SLOT slot2 )"+type[1]+R"(">
                <span>)"+course_Code[1]+R"(</span>
                <span>)"+teacher[1]+R"(</span>
                <span>)"+roomno[1]+R"(</span>
              </div>

              <div class="SLOT slot3 )"+type[2]+R"(">
                <span>)"+course_Code[2]+R"(</span>
                <span>)"+teacher[2]+R"(</span>
                <span>)"+roomno[2]+R"(</span>
              </div>

              <div class="SLOT slot4 )"+type[3]+R"(">
                <span>)"+course_Code[3]+R"(</span>
                <span>)"+teacher[3]+R"(</span>
                <span>)"+roomno[3]+R"(</span>
              </div>

              <div class="SLOT slot5 )"+type[4]+R"(">
                <span>)"+course_Code[4]+R"(</span>
                <span>)"+teacher[4]+R"(</span>
                <span>)"+roomno[4]+R"(</span>
              </div>

              <div class="SLOT slot6 )"+type[5]+R"(">
                <span>)"+course_Code[5]+R"(</span>
                <span>)"+teacher[5]+R"(</span>
                <span>)"+roomno[5]+R"(</span>
              </div>

              <div class="SLOT slot7 )"+type[6]+R"(">
                <span>)"+course_Code[6]+R"(</span>
                <span>)"+teacher[6]+R"(</span>
                <span>)"+roomno[6]+R"(</span>
              </div>

              <div class="SLOT slot8 )"+type[7]+R"(">
                <span>)"+course_Code[7]+R"(</span>
                <span>)"+teacher[7]+R"(</span>
                <span>)"+roomno[7]+R"(</span>
              </div>

              <div class="SLOT slot9 )"+type[8]+R"(">
                <span>)"+course_Code[8]+R"(</span>
                <span>)"+teacher[8]+R"(</span>
                <span>)"+roomno[8]+R"(</span>
              </div>

              <div class="SLOT slot10 )"+type[9]+R"(">
                <span>)"+course_Code[9]+R"(</span>
                <span>)"+teacher[9]+R"(</span>
                <span>)"+roomno[9]+R"(</span>
              </div>

              <div class="SLOT slot11 )"+type[10]+R"(">
                <span>)"+course_Code[10]+R"(</span>
                <span>)"+teacher[10]+R"(</span>
                <span>)"+roomno[10]+R"(</span>
              </div>

              <div class="SLOT slot12 )"+type[11]+R"(">
                <span>)"+course_Code[11]+R"(</span>
                <span>)"+teacher[11]+R"(</span>
                <span>)"+roomno[11]+R"(</span>
              </div>

              <div class="SLOT slot13 )"+type[12]+R"(">
                <span>)"+course_Code[12]+R"(</span>
                <span>)"+teacher[12]+R"(</span>
                <span>)"+roomno[12]+R"(</span>
              </div>

              <div class="SLOT slot14 )"+type[13]+R"(">
                <span>)"+course_Code[13]+R"(</span>
                <span>)"+teacher[13]+R"(</span>
                <span>)"+roomno[13]+R"(</span>
              </div>

              <div class="SLOT slot15 )"+type[14]+R"(">
                <span>)"+course_Code[14]+R"(</span>
                <span>)"+teacher[14]+R"(</span>
                <span>)"+roomno[14]+R"(</span>
              </div>

              <div class="SLOT slot16 )"+type[15]+R"(">
                <span>)"+course_Code[15]+R"(</span>
                <span>)"+teacher[15]+R"(</span>
                <span>)"+roomno[15]+R"(</span>
              </div>

              <div class="SLOT slot17 )"+type[16]+R"(">
                <span>)"+course_Code[16]+R"(</span>
                <span>)"+teacher[16]+R"(</span>
                <span>)"+roomno[16]+R"(</span>
              </div>

              <div class="SLOT slot18 )"+type[17]+R"(">
                <span>)"+course_Code[17]+R"(</span>
                <span>)"+teacher[17]+R"(</span>
                <span>)"+roomno[17]+R"(</span>
              </div>

              <div class="SLOT slot19 )"+type[18]+R"(">
                <span>)"+course_Code[18]+R"(</span>
                <span>)"+teacher[18]+R"(</span>
                <span>)"+roomno[18]+R"(</span>
              </div>

              <div class="SLOT slot20 )"+type[19]+R"(">
                <span>)"+course_Code[19]+R"(</span>
                <span>)"+teacher[19]+R"(</span>
                <span>)"+roomno[19]+R"(</span>
              </div>

              <div class="SLOT slot21 )"+type[20]+R"(">
                <span>)"+course_Code[20]+R"(</span>
                <span>)"+teacher[20]+R"(</span>
                <span>)"+roomno[20]+R"(</span>
              </div>

              <div class="SLOT slot22 )"+type[21]+R"(">
                <span>)"+course_Code[21]+R"(</span>
                <span>)"+teacher[21]+R"(</span>
                <span>)"+roomno[21]+R"(</span>
              </div>

              <div class="SLOT slot23 )"+type[22]+R"(">
                <span>)"+course_Code[22]+R"(</span>
                <span>)"+teacher[22]+R"(</span>
                <span>)"+roomno[22]+R"(</span>
              </div>

              <div class="SLOT slot24 )"+type[23]+R"(">
                <span>)"+course_Code[23]+R"(</span>
                <span>)"+teacher[23]+R"(</span>
                <span>)"+roomno[23]+R"(</span>
              </div>

              <div class="SLOT slot25 )"+type[24]+R"(">
                <span>)"+course_Code[24]+R"(</span>
                <span>)"+teacher[24]+R"(</span>
                <span>)"+roomno[24]+R"(</span>
              </div>

              <div class="SLOT slot26 )"+type[25]+R"(">
                <span>)"+course_Code[25]+R"(</span>
                <span>)"+teacher[25]+R"(</span>
                <span>)"+roomno[25]+R"(</span>
              </div>

              <div class="SLOT slot27 )"+type[26]+R"(">
                <span>)"+course_Code[26]+R"(</span>
                <span>)"+teacher[26]+R"(</span>
                <span>)"+roomno[26]+R"(</span>
              </div>

              <div class="SLOT slot28 )"+type[27]+R"(">
                <span>)"+course_Code[27]+R"(</span>
                <span>)"+teacher[27]+R"(</span>
                <span>)"+roomno[27]+R"(</span>
              </div>

              <div class="SLOT slot29 )"+type[28]+R"(">
                <span>)"+course_Code[28]+R"(</span>
                <span>)"+teacher[28]+R"(</span>
                <span>)"+roomno[28]+R"(</span>
              </div>

              <div class="SLOT slot30 )"+type[29]+R"(">
                <span>)"+course_Code[29]+R"(</span>
                <span>)"+teacher[29]+R"(</span>
                <span>)"+roomno[29]+R"(</span>
              </div>

              <div class="SLOT slot31 )"+type[30]+R"(">
                <span>)"+course_Code[30]+R"(</span>
                <span>)"+teacher[30]+R"(</span>
                <span>)"+roomno[30]+R"(</span>
              </div>

              <div class="SLOT slot32 )"+type[31]+R"(">
                <span>)"+course_Code[31]+R"(</span>
                <span>)"+teacher[31]+R"(</span>
                <span>)"+roomno[31]+R"(</span>
              </div>

              <div class="SLOT slot33 )"+type[32]+R"(">
                <span>)"+course_Code[32]+R"(</span>
                <span>)"+teacher[32]+R"(</span>
                <span>)"+roomno[32]+R"(</span>
              </div>

              <div class="SLOT slot34 )"+type[33]+R"(">
                <span>)"+course_Code[33]+R"(</span>
                <span>)"+teacher[33]+R"(</span>
                <span>)"+roomno[33]+R"(</span>
              </div>

              <div class="SLOT slot35 )"+type[34]+R"(">
                <span>)"+course_Code[34]+R"(</span>
                <span>)"+teacher[34]+R"(</span>
                <span>)"+roomno[34]+R"(</span>
              </div>

              <div class="SLOT slot36 )"+type[35]+R"(">
                <span>)"+course_Code[35]+R"(</span>
                <span>)"+teacher[35]+R"(</span>
                <span>)"+roomno[35]+R"(</span>
              </div>

              <div class="SLOT slot37 )"+type[36]+R"(">
                <span>)"+course_Code[36]+R"(</span>
                <span>)"+teacher[36]+R"(</span>
                <span>)"+roomno[36]+R"(</span>
              </div>

              <div class="SLOT slot38 )"+type[37]+R"(">
                <span>)"+course_Code[37]+R"(</span>
                <span>)"+teacher[37]+R"(</span>
                <span>)"+roomno[37]+R"(</span>
              </div>

              <div class="SLOT slot39 )"+type[38]+R"(">
                <span>)"+course_Code[38]+R"(</span>
                <span>)"+teacher[38]+R"(</span>
                <span>)"+roomno[38]+R"(</span>
              </div>

              <div class="SLOT slot40 )"+type[39]+R"(">
                <span>)"+course_Code[39]+R"(</span>
                <span>)"+teacher[39]+R"(</span>
                <span>)"+roomno[39]+R"(</span>
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

      // Add event listeners to the Next and Previous Week buttons
      document
        .getElementById("nextWeek")
        .addEventListener("click", showNextWeek);
      document
        .getElementById("prevWeek")
        .addEventListener("click", showPreviousWeek);

      // Initial call to display the current week's day numbers
      updateWeekNumbers();
    </script>
    <script src="faltu.js"></script>
  </body>
</html>

    )";

    return htmlContent;
}

int student_resp(string roomno[],string course[],string teacher[],string type[]) {
    // Get CSS-related data from your backend logic
    double divOpacity = 0.7; // Replace with your actual logic to get the opacity

    std::string htmlContent = generateHTMLWithCSS(roomno,course,teacher,type);

    std::ofstream outFile("Front End\\rilli_update.html");
    outFile << htmlContent;

    return 0;
}


// int main() {
//     // Get CSS-related data from your backend logic
//     double divOpacity = 0.7; // Replace with your actual logic to get the opacity

//     std::string htmlContent = generateHTMLWithCSS();

//     std::ofstream outFile("Front End\\rilli_updtae.html");
//     outFile << htmlContent;

//     return 0;
// }