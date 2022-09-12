int trig=7;
int echo=8;
int led=6;
int LDR_Vo=A0;
int Vo;
void setup()
{
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(led,OUTPUT);
pinMode(LDR_Vo,INPUT);
Serial.begin(9600);
}

int distance_cal()
{
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig,LOW);
  delayMicroseconds(20);
float  time_taken=pulseIn(echo,HIGH);
  int distance_measured=0.0165*time_taken;
  return distance_measured;
  }

void loop()

{
int  dist=distance_cal();
 dist=distance_cal();

 //During Day
Vo=analogRead(LDR_Vo);
while(Vo>200)
{
  Vo=analogRead(LDR_Vo);
  Serial.print("Day_Vo:  ");
  Serial.println(Vo);
  digitalWrite(led,LOW);
  }

  // During Night
while (Vo<200 )
{
  Serial.print("Night_Vo:  ");
  Serial.println(Vo);
  Vo=analogRead(LDR_Vo);
 if (dist>20)
 {
  dist=distance_cal();
  Vo=analogRead(LDR_Vo);
  Serial.print("dist>20:  ");
  Serial.println(dist);
analogWrite(led,1);
 } 
  dist=distance_cal();
 if (dist<20)
 {
   dist=distance_cal();
   analogWrite(led,1);
  for(int i=0;i<200;i++)
  {
     dist=distance_cal();
  Serial.print("dist<20:  ");
  Serial.println(dist);
  analogWrite(led,i);
  delay(10);
  }
 
  }
 
  }

 
}
