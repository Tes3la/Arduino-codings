int X = A0;
int Y = A1;
int SW = 12;
int LED = 2;


void setup()
{
 pinMode(12,INPUT);
 pinMode(A0,INPUT);
 pinMode(A1, INPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 digitalWrite(12,HIGH);
 Serial.begin(9600);
}

void loop()
{
  int X_data = analogRead(A0);
  int Y_data = analogRead(A1);
  int SW_data = digitalRead(12);
  Serial.print("X_data:");
  Serial.print(X_data);
  Serial.print("\t");
  Serial.print("Y_data:");
  Serial.print(Y_data);
  Serial.print("\t");
  Serial.print("SW_data:");
  Serial.println(SW_data);
  delay(100);

if(Y_data <= 480)
{
  int brightness_L = map(Y_data, 480,0,0,255);
  analogWrite(2,brightness_L);
}
else if(Y_data >= 560 )
{
  int brightness_R = map(Y_data,540,0,255,0);
  analogWrite(3,brightness_R);
}
else if(X_data <=480)
{
  int brightness_D = map(X_data,480,0,0,255);
  analogWrite(4,brightness_D);
}
else if(X_data >= 540)
{
  int brightness_F = map(X_data,540,0,255,0);
  analogWrite(5,brightness_F);
}
else
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}





}
   
