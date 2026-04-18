int ledek[]={2,3,4,5,6,7,8,9,10};

int db=9;

int gomb=11;

int sebessegek[]={300, 150, 80};
int mod=0;
bool gombKorabban=HIGH;

void setup()
{
  for(int i=0; i<db; i++)
  {
    pinMode(ledek[i], OUTPUT);
  }
 pinMode(gomb, INPUT_PULLUP);

}

void mindenKi()
{
for(int i=0; i<db; i++)
  {
    digitalWrite(ledek[i], LOW);
  }

}

void gombKezelo()
{
 bool gombJelenleg=digitalRead(gomb);
  
  if(gombKorabban == HIGH && gombJelenleg== LOW)
  {
    mod++;
    
    if(mod > 2)
    {
      mod = 0;
    }
  
  
  }
  
  gombKorabban=gombJelenleg;
  

}


void loop()
{
  for(int i=0; i<db; i++)
  {
    gombKezelo();
    
    mindenKi();  
    
    digitalWrite(ledek[i], HIGH);
    digitalWrite(ledek[i+1], HIGH);
    
    delay(sebessegek[mod]);
    
  
  }
   for(int i=db-2; i>0; i--)
  {
    gombKezelo();
    
    mindenKi();  
    
    digitalWrite(ledek[i], HIGH);
    digitalWrite(ledek[i-1], HIGH);
    
    delay(sebessegek[mod]);
  
  }
  
  
  
  
  
}