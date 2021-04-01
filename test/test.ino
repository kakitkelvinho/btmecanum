//  motor fl(4, 2, 5, A5);
byte command;
byte rate;


void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A5, INPUT);  
  Serial.begin(9600);
  Serial.println("BT serial initialized...");
  pinMode(0,INPUT);
  pinMode(1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available() > 1)
  {
    command = Serial.read();
    rate = Serial.read();

    Serial.println(command);
    Serial.println(rate);

    while (command == 1)
    {
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      analogWrite(5, rate);
    }
  }


  

}
