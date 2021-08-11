#include "Websocket.h"
//Access the WSMsg variable to evalute what message is being returned from WS server
 
void setup() {
  WSSetup("BadWifi", "Sanmina02", "192.168.0.28", 8082);

}

void loop() {
  //Constantly evaluate WS connection for messages 
  webSocket.loop();

}
