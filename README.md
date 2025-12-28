# Trinetra – Smart Environment Monitoring and Recommendation System

## Overview
Trinetra is an IoT-based smart environment monitoring system designed to understand real-time environmental conditions and help users interpret what those conditions mean. The system collects temperature and humidity data using a **DHT11 sensor** connected to a **Wemos D1 Mini (ESP8266)** microcontroller.

The collected data is processed by a backend system that predicts the current environmental condition and provides **simple, actionable recommendations** (such as whether the environment is comfortable, too hot, or too humid). The results are displayed clearly on both a **web dashboard** and an **Android mobile application**.

This project demonstrates how basic IoT hardware combined with simple AI logic can be used to build a smart, useful, and beginner-friendly application.

---

## Objectives
- Collect real-time temperature and humidity data using IoT sensors  
- Transmit sensor data from the microcontroller to a backend system  
- Analyze data to predict current environmental conditions  
- Provide easy-to-understand recommendations for users  
- Display results on both a web dashboard and an Android app  
- Support data integration from multiple microcontrollers  

---

## Components and Tools Used

### Hardware
- Wemos D1 Mini / ESP8266 NodeMCU  
- DHT11 Temperature and Humidity Sensor  
- Breadboard  
- Jumper Wires  

### Software
- Arduino IDE  
- RobotNinja IoT API  
- MIT App Inventor / Thunkable (Android App)  
- HTML, CSS, JavaScript (Web Dashboard)  
- Python (Basic AI / prediction logic)  

---

## System Architecture
1. The DHT11 sensor measures temperature and humidity.  
2. The Wemos D1 Mini (ESP8266) sends sensor data to the backend via the RobotNinja API.  
3. The backend processes incoming data and predicts the current environmental condition.  
4. A simple AI-based logic classifies the environment and generates recommendations.  
5. Results are displayed on:
   - An Android mobile app  
   - A web-based dashboard  
6. Multiple devices can send data to the same system simultaneously.

---

## Setup Instructions

### Hardware Setup
- Connect the DHT11 sensor:
  - DATA → D4  
  - VCC → 3V  
  - GND → GND  
- Upload the Arduino code from the `DHT11_Hardware_Code` folder using Arduino IDE  
- Update Wi-Fi credentials and API keys before uploading  

---

### Mobile Dashboard
- Import the `.aia` file into MIT App Inventor / Thunkable  
- Configure the API credentials  
- Run the app to view real-time sensor data and predictions  

---

### Web Dashboard
- Open the web dashboard folder or root directory  
- Update the API endpoint in `script.js` if needed  
- Host the page using **GitHub Pages** (no local server required, just push the HTML/CSS/JS files to your repository)

---

## AI / Prediction Logic
The AI model uses historical temperature and humidity data to classify environmental conditions into simple categories:

- **Comfortable**
- **Too Hot**
- **Too Humid**

Based on these predictions, the system provides **basic recommendations** to help users take suitable action.

---

## Features
- Real-time temperature and humidity monitoring  
- Web dashboard for clear data visualization  
- Android app for mobile access  
- Multi-microcontroller data integration  
- AI-based environmental condition prediction  
- Beginner-friendly IoT and AI implementation  

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

## Evaluation Criteria

| Component | Marks |
|-------------------------------|-------|
| Functionality of Dashboard App | 20    |
| Web Dashboard Design and Implementation | 40    |
| Hosting and Accessibility      | 20    |
| Multi-Microcontroller Integration | 20    |

---

## Submission Details

- **GitHub Repository:**  
  [https://github.com/vikrantchipkarlgp25-byte/IoT_DHT11_AI_Model.git](https://github.com/vikrantchipkarlgp25-byte/IoT_DHT11_AI_Model.git)

- **Web Dashboard:**  
  [https://vikrantchipkarlgp25-byte.github.io/IoT_DHT11_AI_Model/](https://vikrantchipkarlgp25-byte.github.io/IoT_DHT11_AI_Model/)

- **Mobile App (.aia file):**  
  [https://x.thunkable.com/projectPage/68f47e6ad2117f94eaa50e1c](https://x.thunkable.com/projectPage/68f47e6ad2117f94eaa50e1c)

---

## Learning Outcomes
- Understanding real-time IoT data flow  
- Working with sensors and microcontrollers  
- Cloud API integration  
- Developing web and mobile dashboards  
- Applying basic AI concepts in IoT projects  
- Hands-on experience in debugging and system integration  

---

## Author
**Name:** Vikrant Vinayak Chipkar  
**School:** Shikha Academy  
**Course:** IoT Project – Final Assignment
