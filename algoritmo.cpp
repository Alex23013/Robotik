#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>
#include <LiquidCrystal.h>

int reset=34;
int it= 20;
int i=0;
int t=0;
int pos_pivo;
int myTAG[14];
int *tag = myTAG;
float x=0.0;
float suma=0.0;
float final=0.0;
int myPIVO[14];
int myVAL[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int myIR[14]={54,55,56,57,58,59,60,61,62,63,64,65,66,67};
int myDIF[14]={65,20,10,22,18,10,10,10,10,20,22,18,70,45};
int myIRValue[]={25,90,110,120,142,160,170,190,200,210,230,252,270,340};

LiquidCrystal lcd (14,15,16,17,30,22);
HMC5883L_Simple Compass;
const float pi = 3.14159265;
float L=1.0;
float r=1.0;
float g;
float lam =0.1;

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

float motor_pins_h[4]={13,10,9,7};
float motor_pins_a[4]={12,11,8,6};

int motores (float x,float y, float lam)
{
  motor[0]=((sin_A0 * x) + (cos_A0 * y) +(L * lam));
  motor[1]=((sin_A1 * x) + (cos_A1 * y) +(L * lam));
  motor[2]=((sin_A2 * x) + (cos_A2 * y) +(L * lam));
  motor[3]=((sin_A3 * x) + (cos_A3 * y) +(L * lam));
}

int pos_ant(int n)
{
  if(n==0)
  {
    return 13;  
  }
  return n=n-1;
}

int pos_sig(int n)
{
  if(n==13)
  {
    return 0;  
  }
  return n=n+1;
}
void val()
{  
  // para vr el VAL
  Serial.print("VAL ");
  for(int a=0;a<14;a++){Serial.print(myVAL[a]);}
 }
void print_tag()
{
// para vr el TAG  
  Serial.print("TAG: ");
  for(int a=0;a<14;a++){Serial.print(myTAG[a]);}
  Serial.println();
}
void pivo()
{
// para vr el PIVO  
  Serial.print("PIVO: ");
  for(int a=0;a<14;a++){Serial.print(myPIVO[a]);}
  Serial.println();
}
void print_pos_pivo()
{
// para vr l pos_pivo
  Serial.print("pos_pivo: ");
  Serial.print(pos_pivo);
  Serial.println();
}
void print_result()
{
    Serial.println();
    Serial.print("s ");
    Serial.print(suma);
    Serial.println();
    Serial.print("x  ");
    Serial.println(x);
    Serial.println(myIRValue[pos_pivo]);
    Serial.println(pos_pivo);
    Serial.print("final ");
    Serial.print(final);
    Serial.println();
}
int check_1()
{
  for (int i=0;i<14;i++)
  {
    if(tag[i] == 0)
    {
      return true;
    }
  }
  return false;
}
int check_0()
{
  for (int i=0;i<14;i++)
  {
    if(tag[i] == 1)
    {
      return true;
    }
  }
  Serial.print(" NO MIRO ");
  return false;
}

void setup() 
{
  pinMode(reset,OUTPUT);
  digitalWrite(reset,LOW);
  pinMode(42,OUTPUT);
  Serial.begin(9600);
  for(int a=0;a<14;a++)
    { 
    pinMode(myIR[a],INPUT);
    }
  Serial.begin(9600);
  for (int i = 6; i < 14; i = i + 1)
    {
     pinMode(i,OUTPUT);
    }
  lcd.begin(16, 2);//lcd
  Wire.begin();
  Compass.SetDeclination(23, 35, 'E');  
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
}

void loop()
{ 
  
  if (i==it)
  {
    digitalWrite(42,LOW);
    i=0;
  
  }
  else
  { 
    suma=0.0;
    final=0.0;
    i=i+1;
    digitalWrite(42,HIGH);
    
    for(int a=0;a<14;a++)
    {
      int b=analogRead(myIR[a]);
      if (b>400) 
      {
        myTAG[a]=0;
      }
      else  
      {
        myTAG[a]=1;
      }
    }
    print_tag();
    
    int b,e=0;
    if (check_0())
    {
      for(int a=0;a<27 ;a++)
      {
        if(myTAG[e]==1)
        {
          b=b+1;
          myPIVO[e]=b;
        }
        if(myTAG[e]==0)
        {
          b=b-1;
          if(b<0)
            {b=0;}
          myPIVO[e]=b;
        }
        e=pos_sig(e);
      }
      pivo();
      int c=-10;
      int d=0;
      for(int a=0;a<27;a++)
      {
        if(myPIVO[d]>=c)
        {
          c=myPIVO[d];
          pos_pivo=d;
        }
        d=pos_sig(d);
      }
      print_pos_pivo();
    
      for(int a=0;a<14;a++)
        {
          myVAL[a]=0;}
          if(check_1())
          {
            int f=pos_pivo;
            while( (myTAG[f]==1 || myTAG[pos_ant(f)]==1))
                {
                  myVAL[f]=1;
                  f=pos_ant(f);
                }
          }
          val();
          int ch=0;
          ch=pos_pivo;
          while(myVAL[pos_ant(ch)]==1)
            {
              suma=suma+myDIF[ch];
              ch=pos_ant(ch);
              
            }
          x=suma/2;
          final=myIRValue[pos_pivo]-x;
    
          if(final<0)
            {final=final+360;}
           print_result();
          //////////////////////
          float p=final;
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
          if (t==it - 10)
          {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("el norte esta ");
            lcd.setCursor(0, 1);
            lcd.print(heading);
            lcd.print(" _ ");
            lcd.print(lam);
            t=0;
          }
          t=t+1;
      }//check_0
      
   }//else
}//loop

