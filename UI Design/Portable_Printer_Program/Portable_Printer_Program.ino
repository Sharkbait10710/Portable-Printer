#include "Websocket.h"
#include "Stepper.h"
#include "Servo.h"
//Access the WSMsg variable to evalute what message is being returned from WS server

//Variables
unsigned motor_1_retuns = 0;
unsigned motor_2_retuns = 0;

//Task for multithreading
TaskHandle_t motorTask;

void setup() {
  WSSetup("BadWifi", "Sanmina02", "192.168.0.28", 8082);
  stepperSetup();

  xTaskCreatePinnedToCore(
                    motorTaskcode,   // Function to implement the task
                    "motorTask", // Name of the task 
                    10000,      // Stack size in words 
                    NULL,       // Task input parameter 
                    0,          // Priority of the task 
                    NULL,       // Task handle. 
                    0);  // Core where the task should run 
}

void evaluateWSMsg(String& str) {
  if (str.indexOf("Turn stepper 1 OFF") > -1) {
    USE_SERIAL.println("Turn stepper 1 OFF Continuously");
    motor_1_retuns = 0;
  }
  else if (str.indexOf("Turn stepper 1 CC") > -1) {
    USE_SERIAL.println("Turn stepper 1 CC Continuously");
    motor_1_retuns = 1;
  }
  else if (str.indexOf("Turn stepper 1 C") > -1) {
    USE_SERIAL.println("Turn stepper 1 C Continuously");
    motor_1_retuns = 2;
  }
  if (str.indexOf("Turn stepper 2 OFF") > -1) {
    USE_SERIAL.println("Turn stepper 2 OFF Continuously");
    motor_2_retuns = 0;
  }
  else if (str.indexOf("Turn stepper 2 CC") > -1) {
    USE_SERIAL.println("Turn stepper 2 CC Continuously");
    motor_2_retuns = 1;
  }
  else if (str.indexOf("Turn stepper 2 C") > -1) {
    USE_SERIAL.println("Turn stepper 2 C Continuously");
    motor_2_retuns = 2;
  }

  str = "";
}

void MotorAction() {
  switch (motor_1_retuns) {
    case 0: 
      break;
    case 1: {USE_SERIAL.println("Step1CC"); stepper_1.move(MOTOR_STEPS*MICROSTEPS);}
      break;
    case 2: {USE_SERIAL.println("Step1C"); stepper_1.move(-MOTOR_STEPS*MICROSTEPS);}
      break;
  }

  switch (motor_2_retuns) {
    case 0:
      break;
    case 1: {USE_SERIAL.println("Step2CC"); stepper_2.move(MOTOR_STEPS*MICROSTEPS);}
      break;
    case 2: {USE_SERIAL.println("Step2C"); stepper_2.move(-MOTOR_STEPS*MICROSTEPS);}
      break;
  }
}

void motorTaskcode( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){MotorAction(); delay(10);}
}

void loop() {
  //Constantly evaluate WS connection for messages 
  webSocket.loop();
  evaluateWSMsg(WSMsg);
  //MotorAction();
}
