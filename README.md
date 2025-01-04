# IoT-Based Temperature and Humidity Monitoring System

## Description
This project is an **IoT-based temperature and humidity monitoring system** using an **ESP32 microcontroller** and a **DHT22 sensor**. It collects real-time environmental data and transmits it to the **ThingSpeak cloud platform** for visualization and analysis. The system allows users to monitor temperature and humidity remotely, making it useful for smart home applications, weather monitoring, and industrial environments.

## Simulation
🎚️ Wokwi: https://wokwi.com/projects/400152858210581505  
🛜 ThingSpeak Data: https://thingspeak.com/channels/2572976/sharing

![image](https://github.com/user-attachments/assets/afd24360-4bf0-40fa-8fb1-fef7bf71d6bc)

## Tech Stack
- **ESP32** – Microcontroller for data processing and communication  
- **DHT22 Sensor** – Measures temperature and humidity  
- **Arduino IDE** – Development environment for coding and flashing ESP32  
- **Wokwi** – Online simulator for prototyping and debugging  
- **ThingSpeak API** – Cloud platform for storing and visualizing sensor data  

![image](https://github.com/user-attachments/assets/da1cb8dc-57a3-4be9-9b10-999a5ef2cea7)

## Features
✅ **Real-time Temperature and Humidity Monitoring** using DHT22  
✅ **Wi-Fi Integration** to send data to the cloud  
✅ **ThingSpeak Visualization** for remote monitoring and analytics  
✅ **Wokwi Simulation** for testing the system before hardware deployment  

## Usage
- The ESP32 reads temperature and humidity values from the DHT22 sensor.
- Data is sent to ThingSpeak every interval.
- Users can monitor real-time and historical data via the ThingSpeak Dashboard.
