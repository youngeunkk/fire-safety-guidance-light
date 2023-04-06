int Led1 = 8;  // led 핀번호
int Led2 = 9;
int Led3 = 10;
int buzzer = 11;  // buzzer 핀번호
int smokeA0 = A5; // 연기감지센서 MQ2 핀번호

int sensorThres = 100;  // 연기감지센서 임계값

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);


  Serial.print("Pin A: ");
  Serial.println(analogSensor);


  if (analogSensor < 100)  // 임계값이 100보다 작을 때 led와 buzzer는 low
  {
    Write(Led1, LOW);  
    analogWrite(Led2, LOW);
    analogWrite(Led3, LOW);
    noTone(buzzer); 
    
  }
  else // 임계값이 100 이상일 때 led가 켜지고 부저작동
  {
    digitalWrite(Led1, HIGH);  
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    tone(buzzer, 1000, 400);
  }
  delay(100);
}

const int buttonPin = 2;
const int ledPin0 = 8;  //led pin 4개
const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
int buttonState = LOW;
int ledState = 0;
int prevButtonState = LOW;

void setup() {
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop(){
  buttonState = digitalRead(buttonPin);
  if (prevButtonState == LOW && buttonState == HIGH)
  {
    if(ledState == 0)
    {
      digitalWrite(ledPin0, HIGH);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      ledState=1;
    }
    else
    {
      digitalWrite(ledPin0, LOW);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      ledState=0;
    }
  }
  else
  {
  }
  prevButtonState = buttonState;
}

int Led1 = 8;
int Led2 = 9;
int Led3 = 10;
int buzzer = 11;
int flame = A1;
int sensorThres = 100;  // 불꽃감지센서

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(flame, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = digitalRead(flame);

  Serial.print("Pin A1: ");
  Serial.println(analogSensor);


  if (analogSensor > 0)  // 불꽃이 감지되면 시리얼 모니터 창에 Pin A1 값이 0으로 출력됩니다!                           
  {                            // 따라서 불꽃이 감지가 안되면 Pin A1 값이 1이 됩니다. 불꽃감지가 안된다면
    digitalWrite(Led1, LOW);  
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    noTone(buzzer);    
  }
  else  // 불꽃 감지가 된다면 led, buzzer 출력
  {
    digitalWrite(Led1, HIGH);  
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    tone(buzzer, 1000, 400);
  }
  delay(100);
}