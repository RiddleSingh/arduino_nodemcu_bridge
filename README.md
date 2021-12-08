# ESE111 Arduino NodeMCU Bridge
Author: Bhagath Cheela <br />
In this example project, we collect the data from pulse sensor using Arduino UNO and transfer this to NodeMCU using I2C. And from the Node MCU, the data is then uploaded to adafruit io (Make sure that you update the config file with your IO key if you try to run this project).
## Parts Required
- 1 x NodeMCU 8266
- 1 x Arduino UNO

## Connections
I2C used to communicate data between Arduino and NodeMCU
|Arduino UNO| NodeMCU|
|:---------:|:------:|
|  A5       |  D2    |
|  A4       |  D1    |
|  GND      |  GND   |

![Picture1](https://user-images.githubusercontent.com/47292036/145168244-9d314053-d8ed-4a8e-aad0-9481635cc431.png)
 [source1](https://www.electronicwings.com/nodemcu/nodemcu-i2c-with-arduino-ide) <br />
 [source2](https://github.com/ese-detkin-lab/ese218-lab7-adafruit.git)
## Setup Instructions for Node MCU
1. Download or clone the github repo to your computer. 
2. Follow [these instructions](https://docs.google.com/document/d/17QhpRgrozE3ZZsFBizJNyipnE-AXzO-qaewx7TUlNto/edit#heading=h.c6uv5nikp79h) setup your NodeMCU.
3. In the Arduino IDE, install the following libraries:
    - Adafruit IO Arduino
    ![image](https://user-images.githubusercontent.com/13370293/141794987-151290ae-77a6-4a9b-80d6-f9b93450d9e4.png)
4. Flash the code in this repo onto the NodeMCU. You can do this by opening up ese111_nodemcu_bridge.ino in the ese111_nodemcu_bridge folder.
5. Create an account at [io.adafruit](https://io.adafruit.com/).
6. Click **My Key**
  ![image](https://user-images.githubusercontent.com/13370293/141810450-eb952459-161e-4549-b77d-d8c24b09f5e5.png)
7. Going back to the Arduino IDE, modify config.h so it has the appropriate username and key.
  ![image](https://user-images.githubusercontent.com/13370293/141795754-0cc49a75-e0c7-4a65-9f48-768a1c3b0d46.png)
8. Back to the io.adafruit.com website, click on Dashboard > Welcome Dashboard (or a new one that you made). Under the gear icon on the right hand side, select **Create New Block** > **Line Chart**.  
  ![image](https://user-images.githubusercontent.com/13370293/141811275-90756bc9-85ad-4972-82bd-63e98c0e584f.png)
9. Create a new feed called "pulse" (all lowercase). Select it and click "Next step >"
10. In order to export data as a csv, follow [these instructions](https://io.adafruit.com/blog/tips/2016/09/12/exporting-data/).

## Sensor Connection
|Arduino UNO| Pulse Sesnor|
|:---------:|:-----------:|
|  A0       |  BLACK      |
|  5V       |  RED        |
|  GND      |  GND        |

## Setup Instructions for Arduino UNO
1. Open the ese111_arduino_bridge.ino file in the ese111_arduino_bridge folder
2. In the Arduino IDE, install the following libraries:
    - PulseSensor Playground
![pulse sensor](https://user-images.githubusercontent.com/47292036/144721332-1dd29e71-14e6-48fb-b14b-08f669ebaf6e.png)
3. Verify the correct COM port is selected
4. Verify that the bord selected in "Arduino Uno"
5. Upload the program. 
