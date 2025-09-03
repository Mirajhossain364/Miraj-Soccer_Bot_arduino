#define lf 5   
#define lb 6         
                      
#define rf  11
#define rb 10
                    
int pwm = 255;
char ascicode;


void setup ()
{
  Serial.begin (9600);

  pwm = 255;

 pinMode (lf , OUTPUT);
 pinMode (lb , OUTPUT);
 pinMode (rf , OUTPUT);
 pinMode (rb , OUTPUT);

 
  
}


void forward()
{
  analogWrite (lf , pwm);
  analogWrite (lb , 0);
  
  
  analogWrite (rf , pwm);
  analogWrite (rb , 0);
  
  
}


void backward()
{
  analogWrite (lf , 0);
  analogWrite (lb , pwm);

  
  
  analogWrite (rf , 0);
  analogWrite (rb , pwm);
    

  
}

void right()
{
  analogWrite (lf , pwm);
  analogWrite (lb , 0);

  
  
  analogWrite (rf , 0);
  analogWrite (rb , pwm);
  
  
}


void left ()
{
  analogWrite (lf , 0);
  analogWrite (lb , pwm);

  


  
  analogWrite (rf , pwm);
  analogWrite (rb , 0);
   
  
}

void forwardright()
{
   analogWrite (lf , pwm);
  analogWrite (lb , 0);
  
  
  analogWrite (rf , 0);
  analogWrite (rb , 0);
  
  
}

void forwardleft()
{
   analogWrite (lf , 0);
  analogWrite (lb , 0);

  
  
  analogWrite (rf , pwm);
  analogWrite (rb , 0);
  
  
}

void backwardright()
{
  analogWrite (lf , 0);
  analogWrite (lb , pwm);

  
  
  analogWrite (rf , 0);
  analogWrite (rb , 0); 

  
}


void backwardleft ()
{
  analogWrite (lf , 0);
  analogWrite (lb , 0);

  

  
  analogWrite (rf , 0);
  analogWrite (rb , pwm);
    
  
}

void stop()
{
  analogWrite (lf , 0);
  analogWrite (lb , 0);

 

  
  analogWrite (rf , 0);
  analogWrite (rb , 0);
  
  
}


void loop()
{
  ascicode = Serial.read();

  Serial.println (ascicode );

   if(ascicode == '0'){
  pwm = 0; }
 else if(ascicode == '1'){
  pwm = 30; }
 else if(ascicode == '2'){
  pwm = 60; }
 else if(ascicode == '3'){
  pwm = 90; }
 else if(ascicode == '4'){
  pwm = 120; }
 else if(ascicode == '5'){
  pwm = 150; }
 else if(ascicode == '6'){
  pwm = 180; }
 else if(ascicode == '7'){
  pwm = 210; }
 else if(ascicode == '8'){
  pwm = 240; }
 else if(ascicode == '9'){
  pwm = 255; }
   

   switch (ascicode)
{
  case 'F' : forward()           ; break ;
  case 'B' : backward()          ; break ;
  case 'L' : left()              ; break ;
  case 'R' : right()             ; break ;
  case 'G' : forwardleft()       ; break ;
  case 'I' : forwardright()      ; break ;
  case 'H' : backwardleft()      ; break ;
  case 'J' : backwardright()     ; break ;
  case 'S' : stop()              ; break ;
  case 'D' : stop()              ; break ;
  default  :                       break ;
  
}
  
}
