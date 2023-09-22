//Read digital value
#define LEFT_DETECT_LINE_SENSOR 5
#define RIGHT_DETECT_LINE_SENSOR 4
#define BACK_DETECT_LINE_SENSOR 3

//Motor DC
#define EN_A 6
#define IN_1 7
#define IN_2 8
#define EN_B 11
#define IN_3 9
#define IN_4 10

//Robot's Status
#define DELAY 1000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN_A, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(LEFT_DETECT_LINE_SENSOR, INPUT);
  pinMode(RIGHT_DETECT_LINE_SENSOR, INPUT);
  pinMode(BACK_DETECT_LINE_SENSOR, INPUT);
  runForward();
}

void loop() {
  // put your main code here, to run repeatedly:
  checkSensor();
}
void runForward() {
  analogWrite(EN_A, 90);
  analogWrite(EN_B, 90);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
}

void runBackward() {
  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void runRight() {
  analogWrite(EN_A, 150);
  analogWrite(EN_B, 75);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void runLeft() {
  analogWrite(EN_A, 75);
  analogWrite(EN_B, 150);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
}

void stop() {
  analogWrite(EN_A, 0);
  analogWrite(EN_B, 0);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void checkSensor() {
  boolean rightSensor = digitalRead(RIGHT_DETECT_LINE_SENSOR);
  boolean leftSensor = digitalRead(LEFT_DETECT_LINE_SENSOR);
  boolean backSensor = digitalRead(BACK_DETECT_LINE_SENSOR);
  // Serial.print("right: ");
  // Serial.println(rightSensor);
  // Serial.println("left: ");
  // Serial.print(leftSensor);
  // Serial.println("left: ");
  // Serial.println(backSensor);
  // delay(1000);
  if (rightSensor == 1 || leftSensor == 1 || backSensor == 1) {
    if (rightSensor) {
      runBackward();
      delay(400);
      // delay(DELAY);
       runLeft();
      delay(100);
    } else if (leftSensor) {
      runBackward();
      delay(400);
      // delay(DELAY);
       runRight();
      delay(100);
    } else if (rightSensor && leftSensor) {
      runBackward();
      // delay(DELAY);
    } else if (backSensor) {
      runForward();
    }
  } else 
      runForward();
  }