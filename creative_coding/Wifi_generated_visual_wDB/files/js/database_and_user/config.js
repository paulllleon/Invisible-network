var firebaseConfig = {
  apiKey: "AIzaSyBdHZbJ7E-FIrhZ5vjsju_rVuDl2K0E4FY",
  authDomain: "invisible-network.firebaseapp.com",
  databaseURL:
    "https://invisible-network-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "invisible-network",
  storageBucket: "invisible-network.appspot.com",
  messagingSenderId: "784298354999",
  appId: "1:784298354999:web:84f669b0bb02e86a0f92b2",
  measurementId: "G-6C3SRVYK81",
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);
// firebase.analytics();

const database = firebase.database();
