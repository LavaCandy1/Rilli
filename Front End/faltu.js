// Save the current state when a change happens
function displayDay() {
  var daysOfWeek = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  var currentTime = new Date();
  var currentDay = daysOfWeek[currentTime.getDay()];

  document.getElementById("current-day").textContent = currentDay;
}
function displayDate() {
  var currentDate = new Date();
  var year = currentDate.getFullYear();
  var month = currentDate.getMonth() + 1; // Adding 1 since months are zero-indexed
  var day = currentDate.getDate();

  // Add leading zeros if necessary
  if (month < 10) {
    month = "0" + month;
  }
  if (day < 10) {
    day = "0" + day;
  }

  var formattedDate = day;
  document.getElementById("current-date").textContent = formattedDate;

  // Update date every day
  setTimeout(displayDate, 86400000); // 24 hours in milliseconds
}
let currentExpandable = null;

function toggleExpand(element) {
  if (currentExpandable !== null) {
    currentExpandable.classList.remove("expanded");
  }
  element.classList.add("expanded");
  currentExpandable = element;
}

function createExpandableDiv() {
  const container = document.getElementById("expandable-container");
  const newDiv = document.createElement("div");
  newDiv.className = "expandable";
  newDiv.onclick = function () {
    toggleExpand(this);
  };
  newDiv.innerHTML = `
    <input
        type="text"
        class="editableInput"
        value="Task"
        oninput="updateInputValue(this)"
    />
    <input
        type="text"
        class="editableInput2"
        value="Things to do"
        oninput="updateInputValue()"
    />

`;
  container.appendChild(newDiv);
}

function removeLastExpandableDiv() {
  const container = document.getElementById("expandable-container");
  const expandableDivs = container.getElementsByClassName("expandable");
  if (expandableDivs.length > 0) {
    const lastDiv = expandableDivs[expandableDivs.length - 1];
    container.removeChild(lastDiv);
    if (lastDiv === currentExpandable) {
      currentExpandable = null;
    }
  }
}

function updateInputValue(inputElement) {
  // Get the parent expandable div
  const parentDiv = inputElement.closest(".expandable");
  if (parentDiv) {
    const value = inputElement.value;
    // Update the input value within the parent expandable div
    const editableInput = parentDiv.querySelector(".editableInput");
    if (editableInput) {
      editableInput.value = value;
    }
  }
}

function filterDivs(className) {
  var divs = document.querySelectorAll(".Tutorial, .Lecture, .Practical");
  for (var i = 0; i < divs.length; i++) {
    if (className === "" || divs[i].classList.contains(className)) {
      divs[i].style.display = "block";
    } else {
      divs[i].style.display = "none";
    }
  }
}
