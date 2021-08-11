//Setup WebSocket Server
const WebSocket = require("ws");
const wss = new WebSocket.Server({port: 8082});

//If DEBUG is true, DEBUG console logs will run
const DEBUG = false;

//array of clients
var lookup = {};

wss.on("connection", ws => {

    ws.on("message", data => {
        //get the data in string form
        dataStr = "" + data;

        if (DEBUG) console.log('Client has sent: ' + dataStr);
        
        //function to give client an id
        if (dataStr.search("My id is: ") != -1) {
            ws.id = dataStr.substring(10, dataStr.length);
            lookup[ws.id] = ws;
            if (DEBUG) console.log("This is id: ");
            if (DEBUG) console.log(lookup[ws.id].id); 
        }

        //function to send data to ESP32
        if (dataStr.search("Send data to ") != -1) {
            sendId = dataStr.substring(13, 14);
            lookup[sendId].send(dataStr.substring(16, dataStr.length));
            if (DEBUG) console.log("Attempted to send data from GUI to ESP32");
        }

        if (DEBUG) console.log("New client (what server sees)" + ws.id);
        if (DEBUG) console.log("New client (what client is)" + dataStr.substring(9, dataStr.length));
    });

    ws.on("close", () => {
        //remove id from client array
        delete lookup[ws.id];
        if (DEBUG) console.log("Client " + ws.id + " has been disconnected");
    });
});