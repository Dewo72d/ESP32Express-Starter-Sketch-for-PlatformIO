

## ESP32Express Starter Sketch for PlatformIO

This repository provides a basic sketch for ESP32 using the `esp32express` library. It is designed as a quick start template for controlling hardware resources (e.g., LEDs, relays, sensors) and setting up a simple web server.

### Features

- Easy-to-use `esp32express` library for handling Wi-Fi and web server interactions.
- Basic API endpoints to control hardware and retrieve device information:
  - `/ping`: Returns the device's IP address and free heap size in JSON format.
  - `/on`: Activates a connected hardware resource and returns updated device information.
  - `/off`: Deactivates the hardware resource and returns updated device information.
- Built-in JSON support using `ArduinoJson`.
- Simplified Wi-Fi configuration and connection management.
- Ready-to-use template for various IoT applications.

---

### Requirements

- **Hardware**: ESP32 microcontroller with any GPIO-controlled hardware (e.g., LEDs, relays, actuators).
- **Software**: PlatformIO IDE or Arduino IDE.
- **Libraries**:
  - `esp32express`
  - `ArduinoJson`

You can install these libraries via PlatformIO's `lib_deps` configuration.

---

### Getting Started

#### 1. Clone this repository:
```bash
git clone https://github.com/Dewo72d/ESP32Express-Starter-Sketch-for-PlatformIO
```

#### 2. Set up PlatformIO

Ensure you have PlatformIO installed. Add the required libraries to your `platformio.ini` file:
```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
upload_speed = 115200
monitor_speed = 115200
lib_deps = bblanchon/ArduinoJson@^7.2.1
upload_protocol = esptool
```

#### 3. Update Wi-Fi Credentials

Replace the placeholders in `ssid` and `password` variables in the sketch with your Wi-Fi network credentials:
```cpp
const char *ssid = "your-ssid";
const char *password = "your-password";
```

#### 4. Customize GPIO Pin

Update the `RESOURCE_PIN` definition in the sketch to match the GPIO pin connected to your hardware resource:
```cpp
#define RESOURCE_PIN 4  // Change 4 to the pin connected to your device
```

#### 5. Build and Upload

Compile and upload the sketch to your ESP32 device using PlatformIO:
```bash
pio run --target upload
```

#### 6. Open Serial Monitor

Monitor your device's output for Wi-Fi connection status and IP address:
```bash
pio device monitor
```

---

### API Endpoints

#### `/ping`
- **Description**: Returns the device's IP address and free heap memory.
- **Method**: `GET`
- **Response**: JSON
```json
{
  "ip": "192.168.0.20",
  "heap": "123456"
}
```

#### `/on`
- **Description**: Activates the connected resource (e.g., turns on an LED, powers a relay).
- **Method**: `GET`
- **Response**: JSON
```json
{
  "ip": "192.168.0.20",
  "heap": "123456"
}
```

#### `/off`
- **Description**: Deactivates the connected resource (e.g., turns off an LED, disables a relay).
- **Method**: `GET`
- **Response**: JSON
```json
{
  "ip": "192.168.0.20",
  "heap": "123456"
}
```

---

### Code Overview

#### Key Components

- **`esp32express` Library**:
  Handles Wi-Fi connections and simplifies HTTP server setup.

- **`ArduinoJson`**:
  Used for creating and serializing JSON responses.

#### Sketch Details

1. **Wi-Fi Initialization**:
   The `Esp32express` library handles Wi-Fi configuration and connects using the provided credentials.

2. **Web Server Endpoints**:
   - The server is initialized on port `3000`.
   - Handlers for `/ping`, `/on`, and `/off` provide basic device controls and feedback.

3. **Device Information**:
   The `get_json_data()` function collects and serializes the device's IP and heap size.

---

### Usage Example

1. Connect your ESP32 to the same Wi-Fi network as your computer.
2. Access the device's API endpoints using a browser or tools like `curl` or Postman.

Example `curl` requests:
```bash
curl http://<device-ip>:3000/ping
curl http://<device-ip>:3000/on
curl http://<device-ip>:3000/off
```

---

### Extending the Project

- **Add More Endpoints**:
  Use the `server.on()` method to define new routes for interacting with additional devices or sensors.
- **Control Multiple Resources**:
  Add more GPIO pins and map them to specific API endpoints.
- **Expand JSON Responses**:
  Include more device information (e.g., uptime, sensor readings) in the `get_json_data()` function.
