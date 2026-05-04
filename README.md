# 🌐 Práctica 5 – Parte C: Monitorización Web + OLED

## 🧠 Descripción

En esta parte final se ha implementado un sistema de monitorización que combina la lectura de datos del sensor AHT con su visualización en una pantalla OLED y su acceso a través de una página web. El ESP32 actúa como servidor web, permitiendo consultar la temperatura y humedad desde cualquier dispositivo conectado a la misma red.

---

## 🎯 Objetivos

* Integrar sensor + pantalla + conectividad WiFi
* Crear un servidor web en el ESP32
* Mostrar datos en tiempo real en navegador
* Mantener visualización simultánea en OLED

---

## 🔌 Hardware utilizado

* ESP32-S3
* Pantalla OLED SSD1306 (`0x3C`)
* Sensor AHT10/AHT20 (`0x38`)
* Protoboard y cables

---

## 🔧 Conexiones

| Dispositivo | ESP32-S3 |
| ----------- | -------- |
| SDA         | GPIO 20  |
| SCL         | GPIO 21  |
| VCC         | 3.3V     |
| GND         | GND      |

---

## 🌐 Funcionamiento del sistema

El sistema realiza las siguientes tareas:

1. Se conecta a una red WiFi
2. Inicializa el sensor y la pantalla OLED
3. Lee temperatura y humedad periódicamente
4. Muestra los datos en la pantalla OLED
5. Levanta un servidor web en el ESP32
6. Permite consultar los datos desde un navegador

---

## 🖥️ Interfaz web

La página web muestra:

* 🌡️ Temperatura en tiempo real
* 💧 Humedad relativa
* Actualización automática de los datos

Ejemplo de acceso:

```id="web1"
http://192.168.1.xxx
```

---

## 💻 Librerías utilizadas

* `WiFi.h`
* `WebServer.h`
* `Adafruit SSD1306`
* `Adafruit GFX`
* `Adafruit AHTX0`
* `Wire`

---

## 🧪 Resultados

* ✔ Conexión WiFi estable
* ✔ Datos accesibles desde navegador
* ✔ Visualización simultánea en OLED
* ✔ Sistema funcional en tiempo real

---

## 🏁 Conclusión

Esta parte demuestra cómo el ESP32 puede integrarse en sistemas IoT, permitiendo la adquisición de datos y su visualización tanto local como remota. Se ha conseguido un sistema completo de monitorización accesible desde cualquier dispositivo conectado a la red.

---


---
