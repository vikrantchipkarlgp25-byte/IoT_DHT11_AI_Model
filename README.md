# Smart Environment Monitoring System (DHT11 + AI Integration)

## Overview
This project demonstrates an Internet of Things (IoT) based environment monitoring system that collects data from a **DHT11 temperature and humidity sensor**, transmits it through the **RobotNinja IoT API**, and displays the data on both a **mobile dashboard app** and a **web-based dashboard**.

Additionally, the collected data is used to train a simple **AI model** to analyze environmental patterns and make basic predictions about room conditions.

---

## Objectives
- Develop a real-time dashboard app that displays sensor data.
- Build a web-based dashboard for data visualization.
- Integrate an AI model to analyze and predict environmental states.
- Support data integration from multiple microcontrollers.

---

## Components and Tools Used

### Hardware:
- ESP8266 NodeMCU Microcontroller  
- DHT11 Temperature and Humidity Sensor  
- Breadboard  
- Jumper Wires  

### Software:
- Arduino IDE  
- RobotNinja IoT API  
- MIT App Inventor / Thunkable (for mobile dashboard)  
- HTML, CSS, JavaScript (for web dashboard)  
- Python (for AI model training)  

---

## System Architecture
1. The **DHT11 sensor** measures temperature and humidity.  
2. The **ESP8266** microcontroller sends this data to the **RobotNinja API**.  
3. The **mobile app** retrieves the data and displays it in real time.  
4. The **web-based dashboard** visualizes the collected data.  
5. Multiple devices can simultaneously send data to the same system.  
6. The **AI model** processes historical data and provides environmental predictions.

---

## Setup Instructions

### Hardware Setup
1. Connect the DHT11 sensor to ESP8266 (DATA → D4, VCC → 3V, GND → GND).  
2. Upload the Arduino code (available in the `/code` directory) using Arduino IDE.  
3. Update Wi-Fi and API credentials before uploading.  

### Mobile Dashboard
1. Import the `.aia` file in MIT App Inventor / Thunkable.  
2. Set your API credentials and test live data transmission.  
3. View sensor data in real time through your mobile device.  

### Web Dashboard
1. Open the `/web-dashboard` folder.  
2. Configure the API endpoint in the `script.js` file.  
3. Host locally using a simple HTTP server (e.g., `python -m http.server`) or deploy on any free hosting service of your choice.

---

## AI Model Integration
The AI model uses historical temperature and humidity data to predict environmental states such as:  
- **Comfortable**  
- **Too Hot**  
- **Too Humid**  

This model is trained using a basic supervised learning algorithm that classifies data based on threshold conditions and past trends.

---

## Features
- Real-time data collection from DHT11 sensor.  
- Web dashboard for visualization of temperature and humidity.  
- Multi-device data integration.  
- AI-based environment prediction system.  

---

## Project Structure
📂 IoT_DHT11_AI_Model  
┣ 📁 DHT11_Hardware_Code  
┃ ┣ 📄 DHT11_Hardware_Code.ino  
┃ ┗ 📄 Password.h  
┣ 📁 Videos for Explanation  
┃ ┣ 📄 Me_Explaining_the_Project.mp4  
┃ ┗ 📄 Trinetra's Final Video.mp4  
┣ 📄 .gitignore  
┣ 📄 README.md  
┣ 📄 index.html  
┗ 📄 your-logo.png  

---

## Evaluation Criteria
| Component | Marks |
|------------|-------|
| Functionality of Dashboard App | 60 |
| Web Dashboard Design and Implementation | 20 |
| Hosting and Accessibility | 20 |
| Multi-Microcontroller Integration | 20 |

---

## Submission Details
- **GitHub Repository:** *[Insert your repo link here]*  
- **Web Dashboard Link:** *[Insert hosting or local instructions]*  
- **Mobile App (.aia file):** https://x.thunkable.com/projectPage/68f47e6ad2117f94eaa50e1c  

---

## Learning Outcomes
- Understanding the flow of IoT systems.  
- Working with cloud APIs and microcontrollers.  
- Developing cross-platform dashboards.  
- Implementing AI in an IoT-based setup.  
- Experience in debugging and project integration.  

---

## Author
**Name:** Vikrant Vinayak Chipkar  
**Institution:** Shikha Academy  
**Course:** IoT Project – Final Assignment  
