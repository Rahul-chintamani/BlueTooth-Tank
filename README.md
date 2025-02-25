
Bluetooth-Controlled Nerf Tank 🚀🔫

This is a Bluetooth-controlled tank that can move and shoot Nerf bullets, all from your phone! Using an Arduino Uno, an HC-05 Bluetooth module, and an L298N motor driver, this project is a fun way to explore robotics, wireless control, and motor-driven mechanisms.

📥 Download the App: https://play.google.com/store/apps/details?id=com.keuwl.arduinobluetooth

📧 Contact: chintamanirahul80@gmail.com


---

How It Works

1.1️⃣ Control the tank using the Bluetooth Electronics app on Android.
2.2️⃣ Arduino Uno receives Bluetooth signals from the HC-05 module.
3.3️⃣ L298N motor driver controls the DC motors, moving the tank forward, backward, left, and right.
4.4️⃣ A servo motor adjusts the Nerf gun’s aim (up/down).
5.5️⃣ A solenoid or extra servo fires the Nerf bullets.


---

Hardware Components 🛠


---

Wiring Diagram & Setup 📝

1️⃣ HC-05 Bluetooth Module

VCC → 5V (Arduino Uno)

GND → GND

TX → RX (Arduino Uno)

RX → TX (Arduino Uno)


2️⃣ L298N Motor Driver & Motors

Motor Outputs → Connected to DC motors

12V Power Input → Battery Pack

GND → GND (shared with Arduino)

IN1, IN2, IN3, IN4 → Arduino digital pins


3️⃣ Servo for Aiming

VCC → 5V (Arduino)

GND → GND

Signal → PWM pin (Arduino)


4️⃣ Solenoid/Servo for Firing

Solenoid: Controlled via a transistor circuit

Servo: Connected like the aiming servo


5️⃣ Powering the System

Arduino Uno powered via battery (or USB during testing).

Motors & solenoid powered separately from L298N (ensure proper voltage).



---

How to Set It Up 🛠

1️⃣ Assemble the tank chassis and attach the motors, L298N, and HC-05 module.
2️⃣ Wire all components as per the diagram above.
3️⃣ Upload the Arduino code to the Uno.
4️⃣ Install the Bluetooth Electronics app and pair it with HC-05.
5️⃣ Start controlling your tank! 🚗💨🔫


---

Troubleshooting & Tips

✅ Bluetooth Not Connecting?

Check if HC-05 is in pairing mode (LED should blink).

Make sure the TX/RX pins are properly connected.


✅ Motors Not Moving?

Ensure L298N is getting enough power (separate power source if needed).

Double-check Arduino pin connections.


✅ Shooting Not Working?

If using a solenoid, check if the transistor is wired correctly.

If using a servo, ensure the PWM signal is being sent.



---

Future Improvements 🚀

I'm open to discussion and suggestions! Let me know how this can be improved.


---

📷 Demo Video & Images

![IMG1](https://github.com/user-attachments/assets/f955eba1-2043-4cc6-b281-e734bbfca7dc)


https://github.com/user-attachments/assets/785c896a-60ae-474f-8bfa-e7aaecc23034



![circuit_image(1)](https://github.com/user-attachments/assets/f85ec554-28e1-4136-afae-93219d9bc209)
---

🚀 Time to Nerf Battle! Have fun! 🔫🎯









