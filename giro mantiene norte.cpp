#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (14,15,16,17,30,22);

HMC5883L_Simple Compass;
int guardar = 0;

int reset=34;
int i =0;
const float pi = 3.14159265;
float L=1.0;
float r=1.0;
float g;
float lam =0.0;

float sin_A0 = -sin(0.0);
float cos_A0 = cos(0.0);
float sin_A1 = -sin(pi/2);
float cos_A1 = cos(pi/2);
float sin_A2 = -sin(pi);
float cos_A2 = cos(pi);
float sin_A3 = -sin((3*pi)/2);
float cos_A3 = cos((3*pi)/2);
float motor[4] = {0.0,0.0,0.0,0.0};


int M1_H=10;//7;
int M1_A=11;//6
int M3_A=6;//8
int M3_H=7;//9
int M0_H=13;
int M0_A=12;
int M2_A=8;//10
int M2_H=9;//11

float motor_pins_h[4]={13,7,9,10};
float motor_pins_a[4]={12,6,8,11};

int motores (float x,float y, float lam)
{
  motor[0]=((sin_A0 * x) + (cos_A0 * y) +(L * lam));
  motor[1]=((sin_A1 * x) + (cos_A1 * y) +(L * lam));
  motor[2]=((sin_A2 * x) + (cos_A2 * y) +(L * lam));
  motor[3]=((sin_A3 * x) + (cos_A3 * y) +(L * lam));
}



void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Compass.SetDeclination(23, 35, 'E');  
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
  pinMode(reset,OUTPUT);
  digitalWrite(reset,LOW);
  pinMode(42,OUTPUT);
  for (int i = 6; i < 14; i = i + 1)
    {
     pinMode(i,OUTPUT); //MOTORES
    }
}

void loop()
{ 
  
  for(int p =0;p<360;p=p+5){
  float heading = Compass.GetHeadingDegrees();  
  float h= heading;  
  lam =((h/1800)-0.1); 
  g= p * pi/180.0;
  float x=cos(g);
  float y=sin(g);
  motores(x,y,lam);
  for (int i=0;i<4;i++)
      {
      float value=motor[i];
      if(value>=0)
           {
           analogWrite(motor_pins_h[i], (value*255.0));
           }
      else
           {
           analogWrite(motor_pins_a[i], (value*-255.0));
           }
       }
    
 i=i+1;
    }
}
