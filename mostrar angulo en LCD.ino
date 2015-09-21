
int reset=34;
int it = 10;
int i =0;
int myIR[14]={54,55,56,57,58,59,60,61,62,63,64,65,66,67};
int myTAG[14];
//int myIRValue[]={0,22,38,54,69,82,98,110,127,142,157,180,245,292};
int myIRValue[]={245,180,157,142,127,110,98,82,69,54,38,22,0,292};
int mySV[14];

int w=0;
int p=0;
 int q=0;
  
#include <LiquidCrystal.h>
LiquidCrystal lcd (14,15,16,17,30,22);

void setup() {   

pinMode(reset,OUTPUT);
lcd.begin(16, 2);
pinMode(42,OUTPUT);
Serial.begin(9600);
for(int a=54;a<69;a++){ 
  pinMode(a,INPUT);}

digitalWrite(reset,LOW);}

void loop() { 

if (i==it){
  digitalWrite(42,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(p);
  lcd.setCursor(0, 1);
  lcd.print(w);
  i=0;}
  else
  {i=i+1;
  digitalWrite(42,HIGH);
  int k =0;
  for(int a=0;a<14;a++){
    int b=analogRead(myIR[a]);
    if (b>400) {myTAG[a]=0;}
    else  
    {myTAG[a]=1;
     k=k+1;}
    
    if (myTAG[a]==1){
    mySV[a]=myIRValue[a];}
    else{mySV[a]=0;}}
  
    
    
  for(int a=0;a<14;a++){
    Serial.print(myTAG[a]);}
  Serial.println();
  for(int a=0;a<14;a++){
    Serial.print(mySV[a]);
    Serial.print(" ");}
    
  Serial.println();
  delay(50);
  p=0;
  for(int a=0;a<14;a++){
  
  
  
  if (mySV[12] ==1 ){
    
  if(mySV[13] ==1 || mySV[0] ==1 || mySV[1] ==1 || mySV[2] ==1 || mySV[3] ==1 ){
    mySV[7]= mySV[7]+360;
    mySV[8]= mySV[8]+360;
    mySV[9]= mySV[9]+360;
    mySV[10]= mySV[10]+360;
    mySV[11]= mySV[11]+360; 
    mySV[12]= mySV[12]+360;}
  }
  if (mySV[a]!=0){ 
 q=mySV[a];
  p=p+q;}}// p es la suma
 w=0;
  w=p/ k;//w es el promedio
  if (w > 360){
  w = w-360;}
  
}}
  
  
