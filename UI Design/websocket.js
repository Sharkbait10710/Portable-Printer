const ws = new WebSocket("ws://localhost:8082");
        ws.id = 0;
        ws.addEventListener("open", () => {
            console.log("We are connected!");
            ws.send("My id is: 0");
        });

        ws.addEventListener("message", event => {
            console.log(event.data);
        });


//HStepperCC
document.getElementById("HStepperCC").addEventListener("mousedown", function() {
    ws.send("Send data to 1. Turn stepper 1 CC");
    console.log("Just sent a message to the server from GUI");
    });

document.getElementById("HStepperCC").addEventListener("mouseup", function() {
    ws.send("Send data to 1. Turn stepper 1 OFF");
    console.log("Just sent a message to the server from GUI");
    });

//HStepperC
document.getElementById("HStepperC").addEventListener("mousedown", function() {
    ws.send("Send data to 1. Turn stepper 1 C");
    console.log("Just sent a message to the server from GUI");
    });

document.getElementById("HStepperC").addEventListener("mouseup", function() {
    ws.send("Send data to 1. Turn stepper 1 OFF");
    console.log("Just sent a message to the server from GUI");
    });

//VStepperCC
document.getElementById("VStepperCC").addEventListener("mousedown", function() {
    ws.send("Send data to 1. Turn stepper 2 CC");
    console.log("Just sent a message to the server from GUI");
    });

document.getElementById("VStepperCC").addEventListener("mouseup", function() {
    ws.send("Send data to 1. Turn stepper 2 OFF");
    console.log("Just sent a message to the server from GUI");
    });

//VStepperC
document.getElementById("VStepperC").addEventListener("mousedown", function() {
    ws.send("Send data to 1. Turn stepper 2 C");
    console.log("Just sent a message to the server from GUI");
    });

document.getElementById("VStepperC").addEventListener("mouseup", function() {
    ws.send("Send data to 1. Turn stepper 2 OFF");
    console.log("Just sent a message to the server from GUI");
    });

