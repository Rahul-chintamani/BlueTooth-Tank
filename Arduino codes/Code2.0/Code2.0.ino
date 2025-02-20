#include <Servo.h>  // Include Servo library for servo control

// ------------------- Pin Definitions -------------------
// Define pins for Motor 1
int motor1Pin1 = 2;    // Direction pin 1 for Motor 1
int motor1Pin2 = 3;    // Direction pin 2 for Motor 1
int motorEnablePin1 = 5;  // Enable (PWM) pin for Motor 1

// Define pins for Motor 2
int motor2Pin1 = 4;    // Direction pin 1 for Motor 2
int motor2Pin2 = 7;    // Direction pin 2 for Motor 2
int motorEnablePin2 = 6;  // Enable (PWM) pin for Motor 2

// Define pins for Motor 3
int motor3Pin1 = 8;    // Direction pin 1 for Motor 3
int motor3Pin2 = 9;    // Direction pin 2 for Motor 3
int motorEnablePin3 = 10; // Enable (PWM) pin for Motor 3

// Define pins for Motor 4
int motor4Pin1 = 11;   // Direction pin 1 for Motor 4
int motor4Pin2 = 12;   // Direction pin 2 for Motor 4
int motorEnablePin4 = 13; // Enable (PWM) pin for Motor 4

// Servo objects
Servo servo1;  // Servo controlled by Slider A
Servo servo2;  // Servo controlled by Slider B
Servo servo3;  // Continuous rotation servo (Button T)

// -------------------- Timing --------------------
int update_interval = 100;  // Time interval (ms) for panel updates
unsigned long last_time = 0;  // Time of last update

// ------------------ Variables -------------------
char data_in;           // Data received from serial link
int slider_value;       // Generic slider value
int last_slider_value_A = -1;  // Last value for Slider A
int last_slider_value_B = -1;  // Last value for Slider B

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Attach servos
  servo1.attach(A0);  // For example, attach servo 1 on analog pin A0
  servo2.attach(A1);  // For example, attach servo 2 on analog pin A1
  servo3.attach(A2);  // For example, attach servo 3 on analog pin A2 (continuous rotation)

  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motorEnablePin1, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motorEnablePin2, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motorEnablePin3, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(motorEnablePin4, OUTPUT);

  // Initialize all motors off
  stopAllMotors();

  // ------------------ Clear Panel & Setup UI ------------------
  Serial.println("*.kwl");
  Serial.println("clear_panel()");
  Serial.println("set_grid_size(8,5)");
  
  // Add buttons (T, L, R, D, F)
  Serial.println("add_button(0,2,27,T,t)"); // T = clockwise on servo3, t = stop
  Serial.println("add_button(5,3,4,L,l)");  // L = left, l = stop
  Serial.println("add_button(7,3,5,R,r)");  // R = right, r = stop
  Serial.println("add_button(6,3,3,D,d)");  // D = backward, d = stop
  Serial.println("add_button(6,2,2,F,f)");  // F = forward, f = stop

  // Add sliders
  Serial.println("add_slider(0,0,7,0,360,179,A,a,0)");   // Slider A
  Serial.println("add_slider(0,1,7,0,360,180,B,b,0)");   // Slider B
  Serial.println("add_slider(0,2,7,0,255,127,S,s,0)");   // Slider S (speed)

  Serial.println("set_panel_notes(,,,)");  
  Serial.println("run()");
  Serial.println("*");
}

void loop() {
  // --------- Check if Bluetooth data is available ---------
  if (Serial.available()) {
    data_in = Serial.read();  // Read one character

    // ------------------ Continuous Rotation Servo (T button) ------------------
    if (data_in == 'T') {     // Press button T
      servo3.write(180);      // Rotate servo clockwise
    }
    if (data_in == 't') {     // Release button T
      servo3.write(90);       // Stop servo (neutral)
    }

    // ------------------ Motor Directions ------------------
    // R, L, F, D will now affect ALL FOUR motors:
    
    // Right
    if (data_in == 'R') {
      moveRight();
    }
    // Stop right
    if (data_in == 'r') {
      stopAllMotors();
    }

    // Left
    if (data_in == 'L') {
      moveLeft();
    }
    // Stop left
    if (data_in == 'l') {
      stopAllMotors();
    }

    // Forward
    if (data_in == 'F') {
      moveForward();
    }
    // Stop forward
    if (data_in == 'f') {
      stopAllMotors();
    }

    // Backward
    if (data_in == 'D') {
      moveBackward();
    }
    // Stop backward
    if (data_in == 'd') {
      stopAllMotors();
    }

    // ------------------ Servo 1 (Slider A) ------------------
    if (data_in == 'A') {
      slider_value = Serial.parseInt();
      if (slider_value != last_slider_value_A) {
        // Map [0..360] to [0..180] for servo angle
        int angle = map(slider_value, 0, 360, 0, 180);
        servo1.write(angle);
        last_slider_value_A = slider_value;
      }
    }

    // ------------------ Servo 2 (Slider B) ------------------
    if (data_in == 'B') {
      slider_value = Serial.parseInt();
      if (slider_value != last_slider_value_B) {
        // Map [0..360] to [0..180] for servo angle
        int angle = map(slider_value, 0, 360, 0, 180);
        servo2.write(angle);
        last_slider_value_B = slider_value;
      }
    }

    // ------------------ Motor Speed (Slider S) ------------------
    if (data_in == 'S') {
      slider_value = Serial.parseInt();  
      // slider_value = 0..255
      // If you need a 0..255 PWM, you can use it directly,
      // or map it to 0..255 again (redundant):
      int motor_speed = constrain(slider_value, 0, 255);

      analogWrite(motorEnablePin1, motor_speed);
      analogWrite(motorEnablePin2, motor_speed);
      analogWrite(motorEnablePin3, motor_speed);
      analogWrite(motorEnablePin4, motor_speed);
    }
  }

  // ------------------ Periodic Updates (if any) ------------------
  unsigned long t = millis();
  if ((t - last_time) > update_interval) {
    last_time = t;
    // Add any repeated status updates here if you want
    // e.g., sending sensor values back, etc.
  }
}

// ====================================================
//                Motor Control Helpers
// ====================================================

// Stop all 4 motors
void stopAllMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);

  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
}

// Move all 4 motors forward
void moveForward() {
  // Motor 1 forward
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);

  // Motor 2 forward
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  // Motor 3 forward
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);

  // Motor 4 forward
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}

// Move all 4 motors backward
void moveBackward() {
  // Motor 1 backward
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);

  // Motor 2 backward
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

  // Motor 3 backward
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);

  // Motor 4 backward
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}

// Move all 4 motors to turn RIGHT
// For a differential drive approach: 
//   Left side motors forward, right side motors backward
void moveRight() {
  // Motor 1 forward
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);

  // Motor 2 backward
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

  // Motor 3 forward
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);

  // Motor 4 backward
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}

// Move all 4 motors to turn LEFT
// For a differential drive approach: 
//   Left side motors backward, right side motors forward
void moveLeft() {
  // Motor 1 backward
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);

  // Motor 2 forward
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  // Motor 3 backward
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);

  // Motor 4 forward
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}
