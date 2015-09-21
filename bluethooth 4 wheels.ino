///CONTROLES///
//s=ATRAS
// d=DERECHA
//a= IZQUIERDA
//w=ADELANTE
//r=giro A LA IZQUIERDA
//t=giro A LA DERECHA
//e=diagonal derecha arriba
//q=diagonal arriba izquierd 
//z=ATRAS//atras izquierd diagonal
//c=DERECHA//diagonal derecha atras 

//x=OFF

int flagDDB_DDF=0;
int flagDIB_DIF=0;
int flagGH_GA = 0;
int flagDE_IZ = 0;
int flagAD_AT = 0;
int flagOFF=0;

int M1_H_04=7;
int M1_A_05=6;
int M3_A_06=8;
int M3_H_07=9;
int M0_H_08=13;
int M0_A_09=12;
int M2_A_10=10;
int M2_H_11=11;
 void down(){// tecla s
  
  digitalWrite(M1_A_05,HIGH);
  digitalWrite(M3_H_07,HIGH);
  digitalWrite(M0_A_09,HIGH);
  digitalWrite(M2_H_11,HIGH);
  
    }
  
  void right()
  {// tecla d
    digitalWrite(M1_H_04,HIGH);
    digitalWrite(M3_A_06,HIGH);
    digitalWrite(M0_A_09,HIGH);
    digitalWrite(M2_H_11,HIGH);
  }
  
  
  void left()
  {// tecla a
    digitalWrite(M1_A_05,HIGH);
    digitalWrite(M3_H_07,HIGH);
    digitalWrite(M0_H_08,HIGH);
    digitalWrite(M2_A_10,HIGH);
  }
  
  void up()
  {// tecla w
    digitalWrite(M1_H_04,HIGH);
    digitalWrite(M3_A_06,HIGH);
    digitalWrite(M0_H_08,HIGH);
    digitalWrite(M2_A_10,HIGH);
  }
    
  void OFF()
  {
    for(int i=6, i<14,i++)
    { 
      digitalWrite(i,LOW);
    }
 }
 
  giro_r()
  {// tecla r
    digitalWrite(M1_H_04,HIGH);
    digitalWrite(M3_H_07,HIGH);
    digitalWrite(M0_H_08,HIGH);
    digitalWrite(M2_H_11,HIGH);
  }
  
  
  gito_t()
  { // tecla t
    digitalWrite(M1_A_05,HIGH);
    digitalWrite(M3_A_06,HIGH);
    digitalWrite(M0_A_09,HIGH);
    digitalWrite(M2_A_10,HIGH);
  }
  
  void right_up()
  {// tecla e
    digitalWrite(M1_H_04,HIGH);
    digitalWrite(M1_A_05,LOW);
    digitalWrite(M3_A_06,HIGH);
    digitalWrite(M3_H_07,LOW);
  }
  
  void left_down()
  { // tecla z
    digitalWrite(M1_H_04,LOW);
    digitalWrite(M1_A_05,HIGH);
    digitalWrite(M3_A_06,LOW);
    digitalWrite(M3_H_07,HIGH);
  }
  
  void ledt_up()
  {// tecla q
    digitalWrite(M0_H_08,HIGH);
    digitalWrite(M0_A_09,LOW);
    digitalWrite(M2_A_10,HIGH);
    digitalWrite(M2_H_11,LOW);
  }
  
  void right_up()
  {// tecla c
    digitalWrite(M0_H_08,LOW);
    digitalWrite(M0_A_09,HIGH);
    digitalWrite(M2_A_10,LOW);
    digitalWrite(M2_H_11,HIGH);
  }


void setup(){
  Serial.begin(9600);
  for (int i = 6; i < 14; i = i + 1)//motores
{ pinMode(i,OUTPUT);}
} 
 void loop(){
  if(Serial.available() > 0){
    char g = char(Serial.read());

  if(g=='s'){down();}
  if(g=='d'){right();}
  if(g=='a'){left();}
  if(g=='w'){down();} 
  if(g=='r'){giro_t();}
  if(g=='t'){giro_t();}
  if(g =='e'){right_up();}
  if(g =='z'){left_down();}
  if(g =='q'){left_up();}
  if(g =='c'){right_down();}
  if(g=='x'){OFF();}
  }}
    


 
