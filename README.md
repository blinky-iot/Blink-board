## <div align="center">Blink board 🚨</div>

Introducing the Blink Board, a game-changing device designed to bring automation to both homes and industrial settings. This innovative board takes inspiration from PLCs (Programmable Logic Controllers), making it capable of handling a wide range of tasks with ease.
Powered by the versatile ESP32 microcontroller, the Blink Board offers flexibility for seamless integration into various household appliances for smart home solutions or managing industrial machinery settings.

One of its standout features is its compatibility with IoT (Internet of Things) technologies. With support for GSM, Wi-Fi, or Ethernet connectivity, users can conveniently monitor and control connected devices using a dedicated mobile app or web interface. This not only adds convenience but also enables real-time monitoring and optimization of processes.

In terms of functionality, the Blink Board excels in tasks ranging from simple on/off switching to more complex automation sequences. Its extensive input/output capabilities allow for smooth integration with sensors, actuators, and other devices. This versatility makes it suitable for various applications, including lighting control, HVAC systems, security systems, and more.

What sets the Blink Board apart is its user-friendly approach to programming and configuration. With ready-to-use examples provided, users of all technical levels can easily customize and deploy automation routines to meet their specific needs.

In summary, the Blink Board represents a significant advancement in automation technology, offering unmatched flexibility, connectivity, and ease of use. Whether it's optimizing energy usage in a smart home or enhancing production processes in an industrial facility, this innovative device is set to transform the way we interact with automated systems.

## What can I do with Blink board?
We can use it to build:

* Industrial IoT (IIoT)
* Arduino based custom control systems.
* Industrial automation
* Home assistance

Pretty much anything else, because Blink board is open source

## Who is for?

The blink development board is not only a consumer product, but also designed for anyone who wants to use technology to create and innovate. It is a very simple, interesting and practical tool, you can use it to create the world around you

## Features
* ### Wireless connectivity
1. Bluetooth: v4.2
1. Wi-Fi: 802.11 b/g/n
1. GSM: sim800c
* ### Peripheral interfaces
1. 2 × 8-bit DACs
1. 1 x RS485(Max485 half duplex)
1. 1 x RS232(Max232)
1. 8 x Channel 10-bit analog(130-ksps VDD = VREF = 3.3V)
1. 1 x 10V source(analog use)
1. 16 x channel 8-bit output pins(3-24v isolated)
1. 16 x channel 8-bit input pins(3-24v isolated)
1. 1 x LCD/OLED display support
1. I2c Interface
1. 11 × programmable GPIOs(without GSM, RS485, RS232)
<details>
 <summary>Main parts</summary>
<div align="center">
Main Board
<p><img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/Main%20board.jpg?raw=true"></p><br>
I/O expansion board
<p><img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/Expansion%20board.jpg?raw=true"></p><br>
RS232 expansion board
<p><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/RS232.jpg?raw=true"></p><br>
RS485 expansion board
<p><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/RS485.jpg?raw=true"></p><br>
Sim800 expansion board
<p><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/sim800%20front%20side.jpg?raw=true">
<img width="22.6%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/sim800%20back%20side.jpg?raw=true"></p><br>
Analog expansion board
<p><img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/analog%20board.jpg?raw=true"></p>
</div>
 </details>
<details>
 <summary>Quick start</summary>
Connect power to the board via terminal block labeled J17 as shown in the image below.
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/power%20connection.jpeg?raw=true"><br>
<em>_+ve wire to go to the +24V mark and -ve wire to be connected to the GND mark._</em>
</p>
<p>The recommended input voltage range is 5V-24V.<br>
Led D58 and D59 on the main board will come on to indicate that the board is receiving 4.2V and 3.3V respectively.<br>
Make sure that you have installed arduino IDE in your computer. Read more on <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/">arduino IDE installation</a><br>
clone the blink board repository in any prefered location on your computer, run your first example<br>
Flash the firmware to the main board via FT232RL FTDI USB To TTL Module.</p>
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/FTDI%20usb%20ttl%20J17%20main%20board.jpg?raw=true"><br>
<em>FTDI board on the left, the blink board on the right</em>
</p><br>
The FTDI should be connected via jumper wires to the male header pins labeled J26 on the main board as shown in the image above.<br>
Match the labels on the connector J26 to those on the FTDI as follows:
<table align="center">
  <tr>
    <th>J26</th>
    <th>FTDI</th>
  </tr>
  <tr>
    <td>RTS</td>
    <td>RTS</td>
  </tr>
  <tr>
    <td>DTR</td>
    <td>DTR</td>
  </tr>
  <tr>
    <td>TXD</td>
    <td>RXD</td>
  </tr>
  <tr>
    <td>RXD</td>
    <td>TXD</td>
  </tr>
  <tr>
    <td>GND</td>
    <td>GND</td>
  </tr>
</table><br>
> [!CAUTION]
For any connection on the board make sure the terminal block is fully opened before inserting the wire
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/main/images/proper%20wire%20connection.jpg?raw=true"></p>
</details>
