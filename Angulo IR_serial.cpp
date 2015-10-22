
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

int jj = 0;
LiquidCrystal lcd (14,15,16,17,30,22);

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
void print_val()
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
void print_pivo()
{
// para vr el PIVO  
  Serial.print("PIVO: ");
  for(int a=0;a<14;a++){Serial.print(myPIVO[a]);Serial.print(" ");}
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

float check_360(float n)
{
  if(n<0)
  {n=n+360;
  return n; }
  if(n>360)
  {n=n-360;
  return n; }
   return n; 
}

void setup() 
{
  pinMode(reset,OUTPUT);
  digitalWrite(reset,LOW);
  pinMode(42,OUTPUT);
  Serial.begin(115200);
  for(int a=0;a<14;a++)
    { 
    pinMode(myIR[a],INPUT);
    }
  for (int i = 6; i < 14; i = i + 1)
    {
     pinMode(i,OUTPUT);
    }
  lcd.begin(16, 2);//lcd
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
    //print_tag();
    
    int e,b=0;
    
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
      //print_pivo();
      int c=-100;
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
      //print_pos_pivo();
    
      for(int a=0;a<14;a++)
        {
          myVAL[a]=0;}
          if(check_1())
          {
            int f=pos_pivo;
            int fs=pos_ant(f);
            while( (myTAG[f]==1 || myTAG[fs]==1))
            {
              myVAL[f]=1;
              f++;
              fs=pos_ant(f);
            }
          }
          //print_val();
          int ch=0;
          ch=pos_pivo;
          while(myVAL[pos_ant(ch)]==1)
            {
              suma=suma+myDIF[ch];
              ch=pos_ant(ch);
            }
          x=suma/2;
          final=check_360(myIRValue[pos_pivo]-x);
          //print_result();
          Serial.print (jj++);
          Serial.print(" ");
          Serial.println(final);
          //////////////////////
                  
      }//check_0
      
   }//else
}//loop
