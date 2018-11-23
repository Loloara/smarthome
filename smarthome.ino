//60초마다 조도센서와 온도 센서의 값을 LoRa 모듈로 전송하는 예제입니다.
//LED와 모터를 제어하는 예제입니다.
 
#include <LoRaShield.h>
#include <Servo.h>
LoRaShield LoRa(10, 11);
 
int angle = 0; // servo position in degrees 
int JoyStick_X = A4; //x 
int JoyStick_Y = A5; //y 
int JoyStick_Z = 9; //key 
 
void setup()
{
 
  Serial.begin(115200);
  LoRa.begin(38400);
  NSBegin(8, 8);
  pinMode(JoyStick_X, INPUT);  
  pinMode(JoyStick_Y, INPUT);  
  pinMode(JoyStick_Z, INPUT);
  ServoWrite(2, 0);
  DigitalWrite(5, LOW);
  
 
  NSClear();
  NSShow();
}
 
 
int cnt = 0;
int bCnt = 0;
int zcnt = 0;
 
int ledA[3];
int decColour = 0;
int incColour = 1;
int start = 0;
 
int bright=0;
 
void loop()
{
 
   if(bCnt == 100){   //light 
      bright = analogRead(A0);
      if(bright < 700){
        NSSetAllColor(255, 255, 255);
        NSShow();
      }
      bCnt=0;
    }
 
/*
  x=analogRead(JoyStick_X); 
    y=analogRead(JoyStick_Y); 
    z=digitalRead(JoyStick_Z);
  
  diff = (x-500)/100;
  angle = angle+diff;
   
  if(angle > 75) 
    {
      angle = 75;
    }
    else if(angle < 0)
    {
      angle = 0;
    }
 
  ServoWrite(2,angle);
 
  if(start == 0){   //light initialize
    start = 1;
    ledA[0] = 255;
    ledA[1] = 0;
    ledA[2] = 0;
    NSSetAllColor(ledA[0], ledA[1], ledA[2]);
    NSShow();
  }
 
  if(abs(y-512) > 200)  //rainbow light
  {
      // cross-fade the two colours.
    if(y-512>0){
      if(ledA[decColour] == 0 && ledA[incColour] == 255){
        decColour = decColour == 2 ? 0 : decColour + 1;
      }
      incColour = decColour == 2 ? 0 : decColour + 1;
      ledA[decColour] -= 2;
      ledA[incColour] += 2;
      if(ledA[decColour] < 0)
        ledA[decColour] = 0;
      if(ledA[incColour] > 255)
        ledA[incColour] = 255;
    }else{
      if(ledA[decColour] == 0 && ledA[incColour] == 255){
        decColour = decColour == 0 ? 2 : decColour - 1;
      }
      incColour = decColour == 0 ? 2 : decColour - 1;
      ledA[decColour] -= 2;
      ledA[incColour] += 2;
      if(ledA[decColour] < 0)
        ledA[decColour] = 0;
      if(ledA[incColour] > 255)
        ledA[incColour] = 255;
    }
    NSSetAllColor(ledA[0], ledA[1], ledA[2]);
    NSShow();
  }
 
     if(z==0)
  {
    zcnt++;
    Delay(400);
  }
  
 
  if(zcnt == 1)
  {
    DigitalWrite(5, HIGH);
    zcnt = 50;
  }
 
  if(zcnt == 51)
  {
    DigitalWrite(5, LOW);
    zcnt = 0
  }
  */
  
  while (LoRa.available())
  {
    String s = LoRa.ReadLine();
    PrintLine(s);
 
    String m = LoRa.GetMessage();
 
    if (m == "260100")
    {
      PrintLine("[[ DC Motor Off ]]");
      DigitalWrite(5, LOW);
    }
    else if (m == "260101")
    {
      PrintLine("[[ DC Motor On ]]");
      DigitalWrite(5, HIGH);
    }
    else if (m == "270100")
    {
      PrintLine("[[ Door Close ]]");
      ServoWrite(2, 0);
    }
    else if (m == "270101")
    {
      PrintLine("[[ Door Open ]]");
      ServoWrite(2, 60);
    }
    else if (m == "280100")
    {
      PrintLine("[[ LED Off ]]");
      NSClear();
      NSShow();
    }
    else if (m == "280101")
    {
      PrintLine("[[ LED On ]]");
      NSSetAllColor(255, 0, 120);
      NSShow();
    }
  }
 
 
  if (Serial.available())
  {
    int k = Serial.read();
 
    if (k == 1)
    {
      PrintLine("[[ LED On ]]");
      NSSetAllColor(0, 0,255);
      NSShow();
    }
    else if (k == 2)
    {
      PrintLine("[[ LED Off ]]");
      NSClear();
      NSShow();
    }
    else if (k == 3)
    {
      PrintLine("[[ FAN On ]]");
      DigitalWrite(5, HIGH);
    }
    else if (k == 4)
    {
      PrintLine("[[ FAN Off ]]");
      DigitalWrite(5, LOW);
    }
    else if (k == 5)
    {
      PrintLine("[[ Door Open ]]");
      ServoWrite(2, 60);
    }
    else if (k == 6)
    {
      PrintLine("[[ Door Close ]]");
      ServoWrite(2, 0);
    }
  }
  
 
  if (cnt == 0)
  {
    //unsigned short 형식으로 데이터 전송
    unsigned int a = AnalogRead(2);
 
    int b = AnalogRead(0);
    float f = (float)b * 0.5;
 
    //습도
    unsigned int h = 75;
 
 
    //온도 센서
    //LoRa.PrintTTV("11", f);
  
    //조도센서
    //LoRa.PrintTTV("12", a);
 
    //습도센서
    //LoRa.PrintTTV("13", h);
 
    //LoRa.SendTTV();
  }
  
  cnt++;
  bCnt++;
 
  if (cnt > 6000)
    cnt = 0;
 
  delay(10);
}
