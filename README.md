# Water Quality Monitoring System Using TDS and Turbidity Sensors with Arduino UNO

## 📌 Project Overview
This project implements a **real-time water quality monitoring system** using **Total Dissolved Solids (TDS) and Turbidity sensors** with an **Arduino UNO**. It measures water clarity and contamination levels, providing critical insights for **environmental monitoring, industrial applications, and public health**.

## 🎯 Objectives
- Measure **TDS** (Total Dissolved Solids) and **turbidity** levels in water.
- Display real-time sensor data on an **LCD screen**.
- Provide a **cost-effective and scalable** water quality assessment system.
- Enable **future expansion** with IoT-based remote monitoring.

## 🏗️ Hardware Requirements
- **Arduino UNO** (Microcontroller)
- **TDS Sensor** (Measures dissolved solids)
- **Turbidity Sensor** (Measures water clarity)
- **16x2 LCD Display** (Shows real-time data)
- **Breadboard & Jumper Wires** (For circuit connections)
- **LEDs & Resistors** (For visual indication)

## 🛠️ Circuit Diagram

![image](https://github.com/user-attachments/assets/ac9e3e76-b020-42ed-87f2-682c6590a17f)


## 📝 Design Formulas
- **TDS Calculation**:  
  \[
  TDS = K \times EC
  \]
  - *K = Calibration constant*
  - *EC = Electrical Conductivity (µS/cm)*

- **Turbidity Calculation**:  
  \[
  \text{Turbidity (NTU)} = \frac{V_{out} - V_{min}}{V_{max} - V_{min}} \times 1000
  \]

## 🚀 Implementation
1. **Connect** sensors, LCD, and Arduino on the breadboard.
2. **Calibrate** sensors using known water samples.
3. **Upload** the Arduino code.
4. **Monitor** real-time TDS & turbidity values on the LCD.
