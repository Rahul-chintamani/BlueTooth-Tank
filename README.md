
Bluetooth-Controlled Nerf Tank
---
This project is a Bluetooth-controlled tank that can move and fire Nerf bullets, all operated from a smartphone. Built using an Arduino Uno, an HC-05 Bluetooth module, and an L298N motor driver, this project explores robotics, wireless control, and motor-driven mechanisms in a structured and practical way.

📥 Download the App: https://play.google.com/store/apps/details?id=com.keuwl.arduinobluetooth

📧 Contact: chintamanirahul80@gmail.com



---
Project Overview
---
1. The tank is controlled via the Bluetooth Electronics app on an Android device.
2. The Arduino Uno processes Bluetooth signals received from the HC-05 module.
3. The L298N motor driver controls the DC motors, enabling movement in all directions.
4. A servo motor adjusts the Nerf gun’s aim vertically.
5. A solenoid or additional servo motor triggers the firing mechanism.

---
How It Works
---
1. Control the tank using the Bluetooth Electronics app on Android.

2. Arduino Uno receives Bluetooth signals from the HC-05 module.

3. L298N motor driver controls the DC motors, moving the tank forward, backward, left, and right.

4. A servo motor adjusts the Nerf gun’s aim (up/down).

5. A solenoid or extra servo fires the Nerf bullets.


---

Hardware Components
---
1. Arduino Uno – The microcontroller that processes commands
2. HC-05 Bluetooth Module – Enables wireless communication
3. L298N Motor Driver – Controls the motors for movement
4. DC Motors – Provide propulsion
5. Servo Motor – Adjusts the gun’s aim
6. Battery Pack – Powers the system

---
Signal & Electrical Flow-chart
---
``` mermaid
flowchart TB
a[POWER] ---> b(Arduino-uno) & c(L298 Motor Driver)
d(HC-05 Bluetooth Module)-->b
b --> d & c & g
c --> f(Motors)

a --> g(Servo Motors)
```
---
``` mermaid 
flowchart LR
-ve --> GND1 & GND3
GND2 --> GND1
+ve --> 12V 
+ve ---> VIN
+5V1 --> +5V2 --> +5V3
TX1 --> RX2
TX2 --> RX1
Digital-Pins --> IN & ENA

    subgraph L298N
    IN ~~~ ENA ~~~ GND3 ~~~ 12V ~~~ +5V3
    end
    subgraph Arduino Uno
        direction TB    
        Digital-Pins ~~~ +5V1 ~~~ GND1 ~~~ VIN ~~~ TX1 ~~~ RX1
    end

    subgraph Power Supply
        direction LR
        +ve ~~~ -ve
    end
    subgraph Bluetooth module
    TX2 ~~~ RX2 ~~~ +5V2 ~~~ GND2
    end

```
Assembly
---

1. 3D Printing the Model
Download the CAD model from the provided files and 3D print the components.
   Alternatively, if you have a custom-built model, the provided code will still function correctly for three SG90 servo motors and two DC motors.

2. Wiring and Connections
Follow the circuit diagram carefully to connect all components.
   Double-check all connections twice to ensure proper setup.
3. Important Safety Note
Do NOT connect a +12V power source directly to the HC-05 Bluetooth module, as it can only handle a maximum of +5V.
Ensure the Bluetooth module receives power within its safe operating range.
4. Servo Motor Configuration
The system uses three SG90 servo motors:
Two servos for controlling orientation.
One servo dedicated to launching Nerf bullets.
5. 3D Printed Components
If using the downloaded CAD model, refer to the images below for assembly guidance.
There are a total of four 3D-printable parts, designed to snap-fit together with respect to the servo motor placement.
Ensure that the servo mounts align correctly for smooth movement and proper firing operation. 



1.) HC-05 Bluetooth Module

i. VCC → 5V (Arduino Uno)

ii. GND → GND (Arduino Uno)

iii. TX → RX (Arduino Uno)

iv. RX → TX (Arduino Uno)

Important: Do NOT connect 12V directly to the HC-05, as it can only handle 5V max.

2.) DC Motors & L298N Motor Driver

i. Motor 1 (Right/Left Movement)IN1 → Arduino Pin2

ii. IN2 → Arduino Pin 3

iii. Enable Pin (Speed Control) → Arduino Pin 5

iv. Motor 2 (Forward/Backward Movement)IN3 → Arduino Pin4

v. IN4 → Arduino Pin 7

vi. Enable Pin (Speed Control) → Arduino Pin 6

vii. Power Connections (L298N Motor Driver)

viii.12V Power Input → Battery Pack (12V)

ix. GND → Common Ground (shared with Arduino)

x. 5V Output (from L298N) → Optional: Can power Arduino if needed

3.) Servo Motors

i. Servo 1 (Aiming - Slider A Control) → Arduino Pin 9

ii. Servo 2 (Aiming - Slider B Control) → Arduino Pin 10

iii. Servo 3 (Firing - Button T Control) → Arduino Pin 11



---

Troubleshooting & Tips
---
Bluetooth Not Connecting?

Check if HC-05 is in pairing mode (LED should blink).

Make sure the TX/RX pins are properly connected.


Motors Not Moving?

Ensure L298N is getting enough power (separate power source if needed).

Double-check Arduino pin connections.


Shooting Not Working?

while  using a servo, ensure the PWM signal is being sent.



---

Future Improvements 
---

I'm open to discussion and suggestions! Let me know how this can be improved.


---

📷 Demo Video & Images

![IMG1](https://github.com/user-attachments/assets/f955eba1-2043-4cc6-b281-e734bbfca7dc)


https://github.com/user-attachments/assets/785c896a-60ae-474f-8bfa-e7aaecc23034



![circuit_image(1)](https://github.com/user-attachments/assets/f85ec554-28e1-4136-afae-93219d9bc209)
---

Time to Nerf Battle! Have fun
