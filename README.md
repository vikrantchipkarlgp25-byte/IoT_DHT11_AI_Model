# Smart Environment Monitoring System (DHT11 + AI Integration)
Overview

This project demonstrates an Internet of Things (IoT) based environment monitoring system that collects data from a DHT11 temperature and humidity sensor, transmits it through the RobotNinja IoT API, and displays the data on both a mobile dashboard app and a web-based dashboard.

Additionally, the collected data is used to train a simple AI model to analyze environmental patterns and make basic predictions about room conditions.

Objectives

Develop a real-time dashboard app that displays sensor data.

Implement LED control via user input or sensor-based logic.

Build a web-based dashboard for data visualization.

Integrate an AI model to analyze and predict environmental states.

Support data integration from multiple microcontrollers.

Components and Tools Used
Hardware:

ESP8266 NodeMCU Microcontroller

DHT11 Temperature and Humidity Sensor

LED

Breadboard and Jumper Wires

Software:

Arduino IDE

RobotNinja IoT API

MIT App Inventor / Thunkable (for mobile dashboard)

HTML, CSS, JavaScript (for web dashboard)

Python (for AI model training)

System Architecture

The DHT11 sensor measures temperature and humidity.

The ESP8266 microcontroller sends this data to the RobotNinja API.

The mobile app retrieves the data and displays it in real time.

The user can control the LED manually or automatically based on thresholds.

The web-based dashboard visualizes the collected data.

Multiple devices can simultaneously send data to the same system.

The AI model processes historical data and provides environmental predictions.

Setup Instructions
Hardware Setup

Connect the DHT11 sensor to ESP8266 (DATA → D4, VCC → 3V, GND → GND).

Connect an LED to pin D1 through a 220Ω resistor.

Upload the Arduino code (available in the /code directory) using Arduino IDE.

Update Wi-Fi and API credentials before uploading.

Mobile Dashboard

Import the .aia file in MIT App Inventor (or open the shared project link).

Set your API credentials and test live data transmission.

Use the on-screen switch to toggle the LED.

Web Dashboard

Open the /web-dashboard folder.

Configure the API endpoint in the script.js file.

Host locally using a simple HTTP server (e.g., python -m http.server) or deploy on any free hosting service of your choice.

AI Model Integration

The AI model uses historical temperature and humidity data to predict environmental states such as:

Comfortable

Too Hot

Too Humid

This model is trained using a basic supervised learning algorithm that classifies data based on threshold conditions and past trends.

Features

Real-time data collection from DHT11 sensor.

LED control via app or automatic mode.

Web dashboard for visualization of temperature and humidity.

Multi-device data integration.

AI-based environment prediction system.

Project Structure
📂 SmartEnvironmentMonitor
 ┣ 📁 code
 ┃ ┗ 📄 arduino_code.ino
 ┣ 📁 web-dashboard
 ┃ ┣ 📄 index.html
 ┃ ┣ 📄 style.css
 ┃ ┗ 📄 script.js
 ┣ 📁 ai
 ┃ ┗ 📄 model_training.py
 ┣ 📄 README.md
 ┗ 📄 LICENSE

Evaluation Criteria
Component	Marks
Functionality of Dashboard App	60
Web Dashboard Design and Implementation	20
Hosting and Accessibility	20
Multi-Microcontroller Integration	20
Submission Details

GitHub Repository: [Insert your repo link here]

Web Dashboard Link: [Insert hosting or local instructions]

Mobile App (.aia file): [Insert MIT App Inventor share link]

Learning Outcomes

Understanding the flow of IoT systems.

Working with cloud APIs and microcontrollers.

Developing cross-platform dashboards.

Implementing AI in an IoT-based setup.

Experience in debugging and project integration.

Author

Name: Vikrant Vinayak Chipkar
Institution: Shikha Academy
Course: IoT Project – Final Assignment
