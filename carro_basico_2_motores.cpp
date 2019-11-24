
//motor izquierdo
//in1- 10 
//in2 - 9

//motor derecho
//in3--5
//in4---3

void setup() 
{
  for (int i = 3; i < 11; i = i + 1)
    {
     pinMode(i,OUTPUT);
    }
 }
 
 void avanzar(){
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW); 
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
 }
 
  void retroceder(){
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
 }
 
 void derecha(){
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
 }
 
 void izquierda(){
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW); 
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
 }
 
void loop()
{     
  avanzar();
  delay(3000); //esperar 1 segundo
  retroceder();
  delay(3000);
  derecha();
  delay(1000);
  izquierda();
  delay(1000);
}
