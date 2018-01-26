/*
   >>>>This is SPYFU main function<<<<
   機械工程實務_氣動車專題_藍芽遙控系統
   SPYFU (S__ P__ Y__ Fuck You)
*/


#include <SoftwareSerial.h>
#include <Servo.h>


///////////////////////////////////////////////////////////////
////////// Pins /////////////////
///////////////////////////////////////////
#define bRX 9             // 定義連接藍牙模組的序列埠
#define bTX 8             // 定義連接藍牙模組的序列埠
#define BrushlessFPin 3   //forward BLDC motor ESC data pin
#define BrushlessBPin  4  //backward BLDC motor ESC data pin
#define myServoPin  5     //direction control servo motor data pin

///////////////////////////////////////////////////////////////
////////// variable/////////////////
///////////////////////////////////////////
//**********Motor********************
Servo BrushlessF;
Servo BrushlessB;
Servo myServo;
//**********BlueTooth********************
SoftwareSerial BTSerial(bTX, bRX);   //定義連接藍牙模組的序列埠//接收腳, 傳送腳
char Binput = '1';                   // 儲存接收資料的變數
//**********Speed********************
int n = 1;
int ControlSpeed = 0;
int ControlDegree = 0;
int middleDegree = 89;
int breakcounter = 0;


///////////////////////////////////////////////////////////////
////////// Set up/////////////////
///////////////////////////////////////////
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  BTSerial.begin(9600);
  //**********Motor********************
  BrushlessF.attach(BrushlessFPin);
  BrushlessB.attach(BrushlessBPin);
  BrushlessF.write(0);
  BrushlessB.write(0);
  myServo.attach(myServoPin);
  directionControl(0);
  //**********initialize********************
  delay(1000);
  systemInitialize();
  ControlSpeed=15;
}

void loop() {
  if (BTSerial.available()) {
    getBluetooth();
    action();
  } else {
    //speedControl(5, 5);
  }
}
