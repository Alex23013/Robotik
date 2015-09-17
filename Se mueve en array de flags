int M1_H_04=7;
int M1_A_05=6;
int M3_A_06=8;
int M3_H_07=9;
int M0_H_08=13;
int M0_A_09=12;
int M2_A_10=10;
int M2_H_11=11;


int flag_3=0;
int flag_1=0;
int flag_2=0;
int flag_4=0;
int flag_5=0;
int flag_6=0;
int flag_0=0;

void OFF() {
  digitalWrite(M1_H_04,LOW);
  digitalWrite(M1_A_05,LOW);
  digitalWrite(M3_A_06,LOW);
  digitalWrite(M3_H_07,LOW);
  digitalWrite(M0_H_08,LOW);
  digitalWrite(M0_A_09,LOW);
  digitalWrite(M2_A_10,LOW);
  digitalWrite(M2_H_11,LOW);} 
  
  
void right_up(){ //flag 1
  digitalWrite(M1_H_04,HIGH);
  digitalWrite(M1_A_05,LOW);
  digitalWrite(M3_A_06,HIGH);
  digitalWrite(M3_H_07,LOW);}
  
void left_up(){//flag 6
  digitalWrite(M0_H_08,HIGH);
  digitalWrite(M0_A_09,LOW);
  digitalWrite(M2_A_10,HIGH);
  digitalWrite(M2_H_11,LOW);}
void up(){ //flag 0 
  digitalWrite(M1_H_04,HIGH);
  digitalWrite(M3_A_06,HIGH);
  digitalWrite(M0_H_08,HIGH);
  digitalWrite(M2_A_10,HIGH);
  }
void right(){//flag 2
  digitalWrite(M1_H_04,HIGH);
  digitalWrite(M3_A_06,HIGH);
  digitalWrite(M0_A_09,HIGH);
  digitalWrite(M2_H_11,HIGH);
  }
void left(){//flag 5
  digitalWrite(M1_A_05,HIGH);
  digitalWrite(M3_H_07,HIGH);
  digitalWrite(M0_H_08,HIGH);
  digitalWrite(M2_A_10,HIGH);
} 
void left_down(){//flag 4
  digitalWrite(M1_H_04,LOW);
  digitalWrite(M1_A_05,HIGH);
  digitalWrite(M3_A_06,LOW);
  digitalWrite(M3_H_07,HIGH);
}
void right_down(){//flag 3
  digitalWrite(M0_H_08,LOW);
  digitalWrite(M0_A_09,HIGH);
  digitalWrite(M2_A_10,LOW);
  digitalWrite(M2_H_11,HIGH);
}


  
int reset=34;
int GND=40;
int it = 20;
int i =0;
int myLED[]={52,53,51,23,32,48,50};
int myIR[14]={54,55,56,57,58,59,60,61,62,63,64,65,66,67};
int myTAG[14];
int myflag[7];
//int myTEST[7]={1,1,0,0,0,0,1};

int check(int a, int b){
 int v1 =0;
 for(int i =0;i<a;i++){
   if (myflag[i]==1)
     {v1 =1;}}
int v2 =0;
 for(int i =a+1;i<b;i++){
   if (myflag[i]==1)
     {v2 =1;}}
if(v1 == 0 && v2==0 && myflag[a]==1)
  {return 1;}
else
{return 0;} } 

int more( int a[]){
  for(int i =0;i<7;i++){
   if (myflag[i]!=a[i]){return 0;}}
  {return 1;}}

#include <LiquidCrystal.h>
LiquidCrystal lcd (14,15,16,17,30,22);

void setup() {
   for (i = 0; i < 7; i = i + 1){
   pinMode(myLED[i],OUTPUT);}


pinMode(GND,OUTPUT);
pinMode(reset,OUTPUT);

lcd.begin(16, 2);

pinMode(42,OUTPUT);
Serial.begin(9600);
for(int a=54;a<69;a++){ 
  pinMode(a,INPUT);
}

digitalWrite(GND,LOW);
digitalWrite(reset,LOW);
}

void loop() {
 lcd.clear();
 lcd.setCursor(0, 0);
lcd.print("Estado: ");
OFF();

if (i==it){
  digitalWrite(42,LOW);
  i=0;

}else{
  i=i+1;
  digitalWrite(42,HIGH);

  for(int a=0;a<14;a++){
    int b=analogRead(myIR[a]);
    if (b>400) {myTAG[a]=0;}
    else  {myTAG[a]=1;}}
    
  for(int a=0;a<14;a++){
  Serial.print(myTAG[a]);}
  Serial.println();
  
  if ( myTAG[6] == 1 && myTAG[7] == 1 && myTAG[8] == 1 && myTAG[5] == 1 )//flag 0
    {digitalWrite(myLED[0],HIGH);myflag[0] =1;}//;flag_0 = 1;}
  else
    {digitalWrite(myLED[0],LOW);myflag[0] =0;}//flag_0= 0;}
   
  
  
  if ( myTAG[9] == 1 && myTAG[10] == 1 )//flag 1
    {digitalWrite(myLED[1],HIGH);myflag[1] =1;}//flag_1 = 1;}
  else
    {digitalWrite(myLED[1],LOW);myflag[1] =0;}//flag_1= 0;}
   
  
  
 
  if ( myTAG[11] == 1 && myTAG[12] == 1 )//flag 2
    {digitalWrite(myLED[2],HIGH);myflag[2] =1;}//flag_2 = 1;}
  else
    {digitalWrite(myLED[2],LOW);myflag[2] =0;}//flag_2= 0;}
   

  
   if ( myTAG[13] == 1 )//flag 3
    {digitalWrite(myLED[3],HIGH);myflag[3] =1;}//flag_3 = 1;}
  else
    {digitalWrite(myLED[3],LOW);myflag[3] =0;}//flag_3= 0;}

 
  if ( myTAG[0] == 1 )//flag 4
    {digitalWrite(myLED[4],HIGH);myflag[4] =1;}//flag_4 = 1;}
  else
    {digitalWrite(myLED[4],LOW);myflag[4] =0;}//flag_4= 0;}
 
  
  if ( myTAG[1] == 1 && myTAG[2] == 1 )//flag 5
    {digitalWrite(myLED[5],HIGH);myflag[5] =1;}//flag_5 = 1;}
  else
    {digitalWrite(myLED[5],LOW);myflag[5] =0;}//flag_5= 0;}
  
 
if ( myTAG[3] == 1 && myTAG[4] == 1 )//flag 6
    {digitalWrite(myLED[6],HIGH);myflag[6] =1;}//flag_6 = 1;}
  else
    {digitalWrite(myLED[6],LOW);myflag[6] =0;}//flag_6= 0;}
    }
if (myflag[0] == 1){up();}
if (myflag[1] == 1){right_up(); }
if (myflag[2] == 1){right();}
if (myflag[3] == 1){right_down();}
if (myflag[4] == 1){left_down();}
if (myflag[5] == 1){left(); }
if (myflag[6] == 1){left_up(); }
//if ( more(myTEST[7])==1){up();}
//for(int q=0;q<7;q++){
  //if(myflag[q]!= myTEST[q]){OFF();}else{up();}}

  lcd.setCursor(0, 1);     
for(int o=0;o<7;o++){
    lcd.print(myflag[o]);}    

    
}
