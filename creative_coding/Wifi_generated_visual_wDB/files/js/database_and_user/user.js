const displayUserName = false;

let USER;

class User {
  constructor() {
    this.name = "";
    this.selecter = document.getElementById("participants");

    this.selecter.onchange = () => {
      if (this.selecter.value != "-nothing-") {
        console.log("redirecting");
        const url = this.urlWithoutParam();
        window.location.href = `${url}?user=${this.selecter.value}`;
      }
    };

    this.userName = document.getElementById("userName");

    if (!displayUserName) {
      this.userName.style.display = "none";
    }

    this.userName.onclick = () => {
      this.addUser();
    };
  }

  serachParam() {
    const queryString = window.location.search;
    let urlParams = new URLSearchParams(queryString);
    USER = urlParams.get("user");
    //console.log(USER);

    if (USER == null) {
      this.addUser();
    } else {
      document.getElementById("userName").innerHTML = USER;
      readDB();
    }
  }

  urlWithoutParam() {
    const rawUrl = window.location.href;
    let url = "";
    for (let i = 0; i < rawUrl.length; i++) {
      const char = rawUrl[i];
      if (char != "?") {
        url += char;
      } else {
        break;
      }
    }
    return url;
  }

  addUser() {
    document.getElementById("userbox").style.display = "block";
    database.ref(`/`).once("value", (snapshot) => {
      // console.log("im in");
      const userList = Object.keys(snapshot.val());
      //   console.log(userList);

      this.selecter.innerHTML = "";

      userList.unshift("-nothing-");

      userList.forEach((name) => {
        const option = document.createElement("option");
        option.value = name;
        option.innerHTML = name;
        this.selecter.appendChild(option);
      });
    });
  }
}

window.onload = defineUser();

function defineUser() {
  const newUser = new User();
  newUser.serachParam();
}
