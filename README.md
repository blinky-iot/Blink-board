Introducing the Blink Board, a game-changing device designed to bring automation to both homes and industrial settings. This innovative board takes inspiration from PLCs (Programmable Logic Controllers), making it capable of handling a wide range of tasks with ease.
Powered by the versatile ESP32 microcontroller, the Blink Board offers flexibility for seamless integration into various household appliances for smart home solutions or managing industrial machinery settings.

One of its standout features is its compatibility with IoT (Internet of Things) technologies. With support for GSM, Wi-Fi, or Ethernet connectivity, users can conveniently monitor and control connected devices using a dedicated mobile app or web interface. This not only adds convenience but also enables real-time monitoring and optimization of processes.

In terms of functionality, the Blink Board excels in tasks ranging from simple on/off switching to more complex automation sequences. Its extensive input/output capabilities allow for smooth integration with sensors, actuators, and other devices. This versatility makes it suitable for various applications, including lighting control, HVAC systems, security systems, and more.

What sets the Blink Board apart is its user-friendly approach to programming and configuration. With ready-to-use examples provided, users of all technical levels can easily customize and deploy automation routines to meet their specific needs.

In summary, the Blink Board represents a significant advancement in automation technology, offering unmatched flexibility, connectivity, and ease of use. Whether it's optimizing energy usage in a smart home or enhancing production processes in an industrial facility, this innovative device is set to transform the way we interact with automated systems.

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

* **main board**

![main board](https://github.com/blinky-iot/Blink-board/blob/main/images/Main%20board.jpg?raw=true)

* **I/O expansion board**

![expansion board](https://github.com/blinky-iot/Blink-board/blob/main/images/Expansion%20board.jpg?raw=true)

* **RS232 expansion board**

![RS232](https://github.com/blinky-iot/Blink-board/blob/main/images/RS232.jpg?raw=true)

* **RS485 expansion board**

![RS485](https://github.com/blinky-iot/Blink-board/blob/main/images/RS485.jpg?raw=true)

* **Sim800 expansion board**

![sim800 front side](https://github.com/blinky-iot/Blink-board/blob/main/images/sim800%20front%20side.jpg?raw=true)

![sim800 back side](https://github.com/blinky-iot/Blink-board/blob/main/images/sim800%20back%20side.jpg?raw=true)

* **Analog expansion board**

![analog board](https://github.com/blinky-iot/Blink-board/blob/main/images/analog%20board.jpg?raw=true)


 ![Power connection](https://github.com/blinky-iot/Blink-board/blob/main/images/power%20connection.jpeg?raw=true)

_+ve wire to go to the +24V mark and -ve wire to be connected to the GND mark._

The recommended input voltage range is 5V-24V
Led D58 and D59 on the main board will come on to indicate the board is getting 4.2V and 3.3V respectively.
Flash firmware to the main board via FT232RL FTDI USB To TTL Module.

![Ftdi -> main board](https://github.com/blinky-iot/Blink-board/blob/main/images/FTDI%20usb%20ttl%20J17%20main%20board.jpg?raw=true)

The FTDI should be connected via jumper wires to the male header pins labeled J26 on the main board as shown in the image above. Match the labels on the connector J26 to those on the FTDI as follows
<table>
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
</table>

**NB:** For any connection on the board make sure the terminal block is fully opened before inserting the wire as shown below

![proper wire connection](https://github.com/blinky-iot/Blink-board/blob/main/images/proper%20wire%20connection.jpg?raw=true)

## Main board -> Extension board
Using the provided cable illustrated in the image below, connect the extension board to the Main board.

![jst connector](https://github.com/blinky-iot/Blink-board/blob/main/images/wire%20loom%20connector.jpg?raw=true)

One end of the connector should connect to the JST connector J29(extension board) and the other JST connector on J19(main board)


## Main board -> GSM
Connect the SIM800C GSM module to the J8 connector on the main board.
When the board is powered the status LED on the GSM module will come on.
The NETLIGHT will blink based on the table below
<table>
  <tr>
    <th>Status</th>
    <th>SIM800C Behavior</th>
  </tr>
  <tr>
    <td>64ms On/ 800ms Off</td>
    <td>Not registered to the network</td>
  </tr>
  <tr>
    <td>64ms On/ 3000ms Off</td>
    <td>Registered to the network</td>
  </tr>
  <tr>
    <td>64ms On/ 300ms Off</td>
    <td>GPRS communication is established</td>
  </tr>
</table>
NB:Please take note of the orientation as shown in the image below

![sim800 main board](https://github.com/blinky-iot/Blink-board/blob/main/images/sim800%20mainboard.jpeg?raw=true)

## Main board -> Ethernet
Connect the ethernet module to connector J10 as shown in the Image below

![Ethernet main board](https://github.com/blinky-iot/Blink-board/blob/main/images/Ethernet%20main%20board.jpeg?raw=true)

The module that works well with the Blink board is the W5500 Ethernet Shield LAN Network shown here below:

![Ethernet module](https://github.com/blinky-iot/Blink-board/blob/main/images/Ethernet%20module.jpg?raw=true)

## Main board -> RS485
RS485 can be connected to either connector J25 or J23
In the case shown in the image below the RS485 is connected to connector J23.
Once connector J23 is in use, the user has to communicate to the module via software serial as illustrated in the firmware examples provided.

![RS485 main board](https://github.com/blinky-iot/Blink-board/blob/main/images/RS485%20main%20board.jpeg?raw=true)

## Main board -> RS232
RS232 can be connected to either connector J25 or J23
In the case shown in the image below the RS232 is connected to J25.
Connector J25 uses UART1 which is the same debugging port used to flash the firmware onto the Blink board.

![RS232 main board](https://github.com/blinky-iot/Blink-board/blob/main/images/RS232%20main%20board.jpeg?raw=true)

To avoid interruption while uploading firmware to the board using the provided jumpers, disconnect them from connector J27 as shown below.

![J27 jumper removal](https://github.com/blinky-iot/Blink-board/blob/main/images/J27%20jumper%20remove.jpg?raw=true)

## Main board -> Analog board
With the analog board that is provided connect it to j9 connector(10 pi straight male header pin).
While connecting the analog board take note of the orientation as indicated in the image below
The analog board has 8 analog inputs labelled AI_1 ->AI_8, there is source voltage of 10V labled GND and +10V. The 10V source can be used with various sensor applications for example a simple potential divider to vary the speed of a motor
Analog sensor is governed by the equations below:
1. analog value=(1023 * Known voltage)/10
1. Voltage=(10 * Analog value)/1023 

The equation above can be used when working under different conditions of your code

![Analog board main board](https://github.com/blinky-iot/Blink-board/blob/main/images/Main%20board%20-%20Analog%20board.jpeg?raw=true)

## Main board ->I/O
### INPUT

![INPUT](https://github.com/blinky-iot/Blink-board/blob/main/images/input%20main%20board.jpg?raw=true)
### OUTPUT

![OUTPUT](https://github.com/blinky-iot/Blink-board/blob/main/images/output%20main%20board.jpg?raw=true)