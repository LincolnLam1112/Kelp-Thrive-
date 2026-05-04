# 🌊 Kelp Health Simulator

An interactive educational tool that simulates how environmental conditions affect kelp ecosystems in real time. This project combines a browser-based visualization with physical hardware controls to create a hands-on learning experience for middle school students.

---

## 🎯 Project Overview

Kelp forests are highly sensitive to changes in their environment. Factors such as light, temperature, nutrients, and pollution all influence whether kelp thrives or declines.

This simulator transforms those concepts into an interactive system where users:
- Adjust environmental conditions
- React to sudden ocean events
- Maintain a healthy kelp ecosystem under pressure

The goal is to make complex environmental systems **intuitive, visual, and engaging**.

---

## 🧠 Key Features

- 🌿 **Real-Time Kelp Simulation**  
  Animated kelp responds dynamically to environmental changes

- ⚡ **Sudden Event System**  
  Random events (heatwaves, upwelling, pollution spikes) shift conditions and require quick reactions

- 🎮 **Game Mechanics**
  - Thrive score system
  - Combo multiplier for sustained performance
  - Timer-based rounds for competition

- 🎛️ **Dual Input Modes**
  - Manual controls (sliders in browser)
  - Hardware controls (physical knobs)

- 🔌 **Hardware Integration**
  - Particle Photon 2 microcontroller
  - Potentiometers for real-world input
  - USB serial communication with web app

---

## 🏗️ System Architecture


- **Hardware Layer**: Reads analog input from knobs  
- **Communication Layer**: Sends formatted data via serial  
- **Software Layer**: Parses input and updates simulation  
- **Visualization Layer**: Displays kelp health and environmental feedback  

---

## 💻 Technologies Used

- **Frontend**: HTML, CSS, JavaScript  
- **Hardware**: Particle Photon 2  
- **Communication**: Web Serial API  
- **Design**: SVG animations + CSS effects  

---

## 🚀 How to Run

### Software Only (No Hardware)
1. Download or clone this repository
2. Open `index.html` in a browser (Chrome recommended)
3. Use manual controls to adjust parameters

---

### With Hardware (Photon 2)
1. Connect Photon 2 via USB
2. Upload firmware from `/photon/`
3. Open `index.html` in Chrome
4. Click “Connect to Hardware”
5. Turn knobs to control the simulation in real time

---

## 📚 Educational Goals

This project helps students understand:
- How ecosystems depend on multiple interacting factors
- Why balance (not extremes) is important
- How environmental changes can have cascading effects
- The impact of human activity (pollution, climate change)

---

