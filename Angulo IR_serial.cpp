int reset=34;
int it= 20;
int i=0;
int pos_pivo;
int myTAG[14];
int *tag = myTAG;
int x=0;
int suma=0;
int myPIVO[14];
int myVAL[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int myIR[14]={54,55,56,57,58,59,60,61,62,63,64,65,66,67};
int myDIF[14]={65,20,10,22,18,10,10,10,10,20,22,18,70,45};
int myIRValue[]={25,90,110,120,142,160,170,190,200,210,230,252,270,340};

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
void print_pivo()
{
// para vr l pos_pivo
  Serial.print("pos_pivo: ");
  Serial.print(pos_pivo);
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
  
}

void loop()
{ //print_arr();
  
  if (i==it)
  {
    digitalWrite(42,LOW);
    i=0;
  
  }
  else
  { suma=0;
    int final=0;
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
    }print_tag();
    
    int b,e=0;
    
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
    }pivo();
    int c=-10;
    int d=0;
   // if (check_0()){
      for(int a=0;a<27;a++)
      {
        if(myPIVO[d]>=c)
        {
          c=myPIVO[d];
          pos_pivo=d;
        }
        d=pos_sig(d);
      }print_pivo();
    //}
    for(int a=0;a<14;a++)
      { myVAL[a]=0;}
    if(check_1())
    {
      int f=pos_pivo;
      while( (myTAG[f]==1 || myTAG[pos_ant(f)]==1))
      {
        myVAL[f]=1;
        f=pos_ant(f);
      }
    }val();
    //Serial.print(pos_pivo);Serial.println(myVAL[pos_pivo]);Serial.print(pos_ant(pos_pivo));Serial.println(myVAL[pos_ant(pos_pivo)]);
    int g=0;
    g=pos_pivo;
    while(myVAL[pos_ant(g)]==1)
      {
        suma=suma+myDIF[g];
        g=pos_ant(g);
        Serial.println();
        Serial.print("s ");
     Serial.print(suma);
      }
      
    x=suma/2;
    
     Serial.println();
    Serial.print("x  ");
    Serial.println(x);
    
    final=myIRValue[pos_pivo]-x;
    Serial.println(myIRValue[pos_pivo]);
    Serial.println(pos_pivo);
    Serial.print("final ");
    Serial.print(final);
    Serial.println();
    if(final<0)
      {final=final+360;}
  }
}
