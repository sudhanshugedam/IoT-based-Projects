# **Library Seat Availability System using IoT**

## 📌 Introduction

**The Library Seat Availability System is an IoT-based project designed to monitor the availability of library seats in real time.**

**The system uses IR sensors to detect whether seats are occupied or available. An ESP8266 NodeMCU processes the sensor data and sends the information to Firebase Realtime Database through Wi-Fi.**

**The seat information is displayed on a public web dashboard so that users can check seat availability remotely.**

---

## 🎯 Aim

**To develop an IoT-based Library Seat Availability System that detects occupied and available seats using IR sensors and displays the real-time status on a web dashboard.**

---

## 🛠️ Components Required

- **ESP8266 NodeMCU**
- **IR Obstacle Sensors × 2**
- **Breadboard**
- **Jumper Wires**
- **USB Cable**
- **5V USB Power Supply**
- **Computer/Laptop**
- **Smartphone Hotspot**

---

## 💻 Software and Technologies

- **Arduino IDE**
- **Embedded C/C++**
- **ESP8266 Wi-Fi**
- **Firebase Realtime Database**
- **Firebase Hosting**
- **HTML**
- **CSS**
- **JavaScript**

---

## ⚙️ Working Principle

**1. Two IR sensors are used to monitor two library seats.**

**2. Each IR sensor is connected to the ESP8266 NodeMCU.**

**3. When a person occupies a seat, the corresponding IR sensor detects the object.**

**4. The ESP8266 determines whether the seat is available or occupied.**

**5. The ESP8266 connects to the Internet through Wi-Fi.**

**6. Seat status is sent to Firebase Realtime Database.**

**7. The public web dashboard reads the latest Firebase data.**

**8. The dashboard displays the number of available seats and the status of each seat.**

---

## 🔌 Pin Connections

| **Component** | **ESP8266 Pin** |
|---|---|
| **IR Sensor 1 OUT** | **D5** |
| **IR Sensor 2 OUT** | **D6** |
| **IR Sensor 1 VCC** | **3.3V** |
| **IR Sensor 2 VCC** | **3.3V** |
| **IR Sensor 1 GND** | **GND** |
| **IR Sensor 2 GND** | **GND** |

---

## 🌐 System Architecture

```text
        IR Sensor 1
             │
             ▼
        ┌──────────┐
        │          │
        │ ESP8266  │
        │ NodeMCU  │
        │          │
        └──────────┘
             ▲
             │
        IR Sensor 2
             │
             ▼
           Wi-Fi
             │
             ▼
      Firebase Database
             │
             ▼
       Public Web
        Dashboard
```

---

## 🔥 Firebase

**Firebase Realtime Database is used to store the current seat status.**

**Example:**

```text
seats
 ├── seat1: true
 └── seat2: false
```

**Where:**

- **`true` = Available**
- **`false` = Occupied**

---

## 🌍 Live Website

**The project includes a public web dashboard for viewing seat availability.**

**Live Website:**

[**https://library-seat-availability.web.app**](https://library-seat-availability.web.app)

---

## 📊 Prototype

**The current prototype monitors two library seats using two IR sensors.**

### **Seat 1**

- **Available**
- **Occupied**

### **Seat 2**

- **Available**
- **Occupied**

**The system also calculates the total number of available seats.**

---

## ✨ Features

- **Real-time seat monitoring**
- **IR-based seat detection**
- **ESP8266 Wi-Fi connectivity**
- **Firebase cloud database**
- **Public web dashboard**
- **Automatic seat availability calculation**
- **Remote monitoring**
- **Low-cost IoT implementation**

---

## 📁 Project Structure

```text
Project-01-Library-Seat-Availability/
│
├── README.md
│
├── Code/
│   └── Library_Seat_Availability.ino
│
├── Circuit-Diagram/
│   └── circuit-diagram.png
│
└── Images/
    ├── hardware-setup.jpg
    ├── ir-sensor-test.jpg
    ├── firebase-database.jpg
    └── website-dashboard.jpg
```

---

## 🔮 Future Scope

- **Increase the number of monitored seats.**
- **Add user authentication.**
- **Improve database security.**
- **Add an administrator dashboard.**
- **Add occupancy statistics and reports.**
- **Add notifications when seats become available.**
- **Develop a mobile application for the system.**

---

## 👨‍💻 Project

**Project:** **Library Seat Availability System using IoT**

**Project Number:** **01**

**Platform:** **ESP8266 NodeMCU**

**Sensors:** **2 IR Obstacle Sensors**

**Database:** **Firebase Realtime Database**

**Web Hosting:** **Firebase Hosting**

**Hardware Prototype:** **2 Seats**
