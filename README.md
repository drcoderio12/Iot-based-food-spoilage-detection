

# IoT-Based Food Spoilage Detection System

This repository contains the code and circuit diagram for an IoT-based food spoilage detection system. The system leverages temperature, moisture, and MQ-135 gas sensors to monitor food freshness and detect spoilage. It aims to aid in reducing food waste by providing early warnings when food quality deteriorates.

## Overview

Food spoilage detection systems are essential for food storage and preservation, especially in scenarios like food donation systems or warehouses. This project uses IoT sensors to monitor critical factors like temperature, moisture, and gas levels around food items to detect spoilage. Based on sensor readings, the system categorizes food as "safe" or "spoiled" and displays the results on a web interface.

### Components Used
- **ESP32**: Microcontroller for data collection and wireless communication.
- **Temperature Sensor**: Measures the surrounding temperature to monitor storage conditions.
- **Moisture Sensor**: Monitors humidity levels that may affect food quality.
- **MQ-135 Gas Sensor**: Detects gases such as ammonia, which are released as food spoils.

## Repository Contents

- **Code**: IoT code to collect data from sensors and send it to a server for analysis.
- **Circuit Diagram**: Visual layout of the components and connections for easy replication.
  
## Features

- **Real-Time Monitoring**: Continuously monitors temperature, moisture, and gas levels to provide real-time data.
- **Spoilage Alerts**: Triggers an alert when the readings exceed threshold values, indicating potential spoilage.
- **Data Visualization**: Displays sensor data on a web interface to help track food quality status.

## Setup Instructions

1. **Circuit Assembly**: Refer to the circuit diagram to assemble the hardware setup using ESP32, temperature, moisture, and MQ-135 sensors.
2. **Code Upload**: Upload the provided IoT code to the ESP32 using the Arduino IDE.
3. **Threshold Adjustments**: Customize the threshold values for temperature, moisture, and gas levels in the code based on your use case.
4. **Server Setup**: Ensure a server (local or cloud-based) is set up to receive and display data from the ESP32 device.

## Usage

1. Power the ESP32 and connect it to a Wi-Fi network.
2. The device will start monitoring sensor data and sending it to the configured server.
3. Access the server interface to view real-time data and receive spoilage alerts if conditions indicate food is going bad.

## Future Enhancements

- **Additional Sensors**: Integrate more sensors for better accuracy.
- **Mobile App**: Create a mobile app for real-time alerts and remote monitoring.
- **Machine Learning**: Implement predictive algorithms to estimate spoilage timelines based on historical data.

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and share!

