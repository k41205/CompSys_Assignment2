# Description

This Arduino sketch was developed as part of a university exam focusing on Internet of Things (IoT) applications. It is specifically tailored for use with the MKR IoT Carrier board and is designed to leverage the board's capabilities in monitoring environmental conditions. The project showcases how to effectively gather data on temperature, humidity, and atmospheric pressure using the MKR IoT Carrier's integrated sensors.

Upon collecting the data, the sketch establishes a connection to WiFi using the credentials provided and uploads the sensor readings to a ThingSpeak channel. This allows for real-time data visualization and analysis, demonstrating a practical application of IoT in environmental monitoring. The utilization of ThingSpeak as an IoT analytics platform service exemplifies how IoT devices can interact with cloud services to store and process data.

To facilitate the development and deployment of this project, the sketch incorporates several libraries:

Arduino_MKRIoTCarrier: To interface with the MKR IoT Carrier board's sensors and features.
WiFiNINA: To manage WiFi connectivity on boards that support this module.
WiFiClient: To create a client that can connect to specified internet addresses and send/receive data.

This project serves as an example of integrating hardware sensors, wireless connectivity, and cloud services in creating an IoT solution capable of real-time environmental monitoring. It provides a foundational framework for students and enthusiasts to explore the potential of IoT in data collection and analysis.

## ThingSpeak Channel View

All the data perceived from the sensor were sent to ThingSpeak to store the data:

![image](https://github.com/k41205/comp-sys-assignment-2/assets/93975067/bd9080e0-06eb-4bfb-bb8a-c613f199eadc)

## Website

Here I consumed a ThingSpeak API to read the last readings, gathered from the sensor, by clicking on the button "Thing Speak Reading":

![image](https://github.com/k41205/comp-sys-assignment-2/assets/93975067/51c0cc4b-3224-4ac8-b56a-667fe1a9e640)
