### Connecting the Extension Board
<div align="center">
  <img width="50%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/Expansion%20board.jpg?raw=true">
  <p><em>Figure: Extension Board</em></p>
</div>

Using the provided cable (shown in the image below):
<p align="center">
  <img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/wire%20loom%20connector.jpg?raw=true">
</p>

1. Connect one end to the **JST connector J29** on the **extension board**.
2. Connect the other end to the **JST connector J19** on the **main board**.


### Connecting the SIM800C GSM Module
<div style="display: flex; justify-content: space-between; align-items: center;">
  <div style="text-align: center;">
    <img width="66.37%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/sim800%20front%20side.jpg?raw=true" alt="Sim800c Front Side">
    <p><em>Figure: Sim800c Module front side</em></p>
  </div>
  <div style="text-align: center;">
    <img width="50%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/sim800%20back%20side.jpg?raw=true" alt="Sim800c Back Side">
    <p><em>Figure: Sim800c Module back side</em></p>
  </div>
</div>

1. Connect the SIM800C GSM module to the **J8 connector** on the main board.
!!! Note
    Ensure correct orientation as shown in the image below.
<div align="center">
  <img width="60%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/sim800%20mainboard.jpeg?raw=true">
  <p><em>Figure: Sim800c Module connected to mainboard</em></p>
</div>
When the board is powered, the **status LED** on the GSM module will light up, and the **NETLIGHT** will blink according to the pattern described in the table below.
<div style="text-align: center;">
  <table style="margin: 0 auto; border-collapse: collapse; width: 60%;">
    <thead>
      <tr>
        <th style="border: 1px solid #000; padding: 8px; text-align: center;">Status</th>
        <th style="border: 1px solid #000; padding: 8px; text-align: center;">SIM800C Behavior</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td style="border: 1px solid #000; padding: 8px; text-align: center;">64ms On/ 800ms Off</td>
        <td style="border: 1px solid #000; padding: 8px;">Not registered to the network</td>
      </tr>
      <tr>
        <td style="border: 1px solid #000; padding: 8px; text-align: center;">64ms On/ 3000ms Off</td>
        <td style="border: 1px solid #000; padding: 8px;">Registered to the network</td>
      </tr>
      <tr>
        <td style="border: 1px solid #000; padding: 8px; text-align: center;">64ms On/ 300ms Off</td>
        <td style="border: 1px solid #000; padding: 8px;">GPRS communication is established</td>
      </tr>
    </tbody>
  </table>
  <p><em>Table: Sim800c status LED</em></p>
</div>


### Connecting the Ethernet Module
1. Connect the **W5500 Ethernet Shield LAN Network module** to the **J10 connector** on the Blink board, as shown in the image below.
2. This module is fully compatible with the Blink board.
<div style="display: flex; justify-content: space-between; align-items: center;">
  <div style="text-align: center;">
    <img width="60%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/Ethernet%20main%20board.jpeg?raw=true" alt="Ethernet Main Board">
    <p><em>Figure: Ethernet Main Board</em></p>
  </div>
  <div style="text-align: center;">
    <img width="60%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/Ethernet%20module.jpg?raw=true" alt="Ethernet Module">
    <p><em>Figure: W5500 Ethernet Module</em></p>
  </div>
</div>

### Connecting the RS485 Module
<div align="center">
  <img width="50%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/RS485.jpg?raw=true">
  <p><em>Figure: RS485 Module</em></p>
</div>
1. The RS485 module can be connected to either connector J25 or connector J23.
2. In the example shown in the image below, the RS485 is connected to connector J23.

<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/RS485%20main%20board.jpeg?raw=true">
  <p><em>Figure: RS485 Module connected to mainboard</em></p>
</div>

### Connecting the RS232 Module
<div align="center">
  <img width="50%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/RS232.jpg?raw=true">
  <p><em>Figure: RS232 Module</em></p>
</div>
1. The RS232 module can be connected to either **connector J25** or **connector J23**.
2. In the example shown in the image below, the RS232 is connected to **J25**, which uses **UART1**, the same debugging port used for flashing firmware onto the Blink board.

<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/RS232%20main%20board.jpeg?raw=true">
  <p><em>Figure: RS232 Module connected to mainboard</em></p>
</div>
!!! Important
    To prevent interruptions when uploading firmware while the RS323 module is connected to **J25**, disconnect the jumpers from **connector J27** as shown in the image below.

<p align="center">
  <img width="10%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/J27%20jumper%20remove.jpg?raw=true">
</p>

### Connecting the Analog Board
<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/analog%20board.jpg?raw=true">
  <p><em>Figure: Analog Board</em></p>
</div>
Connect the provided analog board to the **J9 connector** (10-pin straight male header).

!!! Note 
    Always connect the analog board with correct orientation as shown in the image below.
#### Analog Board Overview
1. The analog board has 8 inputs labeled **AI_1 to AI_8**.
2. A 10V power source is available, with pins labeled **GND** and **+10V**. This can be used for various sensor applications, such as a potential divider to adjust motor speed.
#### Analog Sensor Calculation

The behavior of the analog sensor can be determined using the equation below:

> analog value=(4096* Vin)/Vref

* > Vin = analog input voltage
* > Vref = reference voltage -> 10V


<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/Main%20board%20-%20Analog%20board.jpeg?raw=true">
  <p><em>Figure: Analog Board connected to mainboard</em></p>  
</div>

### Connecting Display
The Blink board supports I~2~C-compatible displays, which can be connected to **connector J1**. The pin order on J22 is as follows: **SCL**, **SDA**, **Power**, and **GND**.

The power supply can be switched between **3.3V** and **4.2V**:

1. By default, **jumper J1** is set to 3.3V.
2. To use 4.2V, remove the 3.3V jumper connection and solder the other side of J1 to enable the 4.2V supply.
Refer to the image below for detailed instructions on switching the power supply.
<p align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/Main%20board%20-%20Analog%20board.jpeg?raw=true">
</p>

### working with I/0
The Blink board main board provides **8 digital inputs** and **8 digital outputs** to read signals from external hardware and control various loads. The I/O pins support voltage levels from **5V to 24V**. The extension board follows the same design principles as the main board, with indicator LEDs to show active I/O. When an LED is **ON**, the corresponding input or output is receiving a positive signal.
#### connecting input devices
1. The inputs are galvanically isolated with optoisolators, protecting the board from interference from external signals.
2. Connect the **-ve lead** (wire) to **COM**. If the device shares a ground with the board, use a jumper wire to connect **GND** to **COM**.
Refer to the image below for wiring guidance:

<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/input%20main%20board.jpg?raw=true">
  <p><em>Figure: Input interface</em></p>
</div>

#### connecting output devices
Outputs are also galvanically isolated.
Connect the **-ve lead** to **COM** and the **+VE lead** to **Drive**.
If the board and the external device share power, use two jumper wires:

1. Connect **COM** to **GND**.
2. Connect **Drive** to **24V**.
For the extension board, only Drive is provided, so external power must be supplied.
<div align="center">
  <img width="40%" src="https://github.com/blinky-iot/Blink-board/blob/Resources/images/output%20main%20board.jpg?raw=true">
  <p><em>Figure: Output interface</em></p>
</div>
### Main board I/O (Low-Voltage)
In addition to the 16 I/O pins, the board has **3.3V-only I/O pins**. These pins are **not high-voltage tolerant** and lack circuit protection. Applying a voltage higher than 3.3V will damage the microcontroller.

| Connetor    | PINS        |
| ----------- | ------------|
| j18       |      D35, D34,VN/D39,VN/D36   |
| j20       |      D26, D25,D33/PC,D32     |
| j24       |      D14    |
!!!Note 
      Some of the pins mentioned above cannot be used based on the conditions in the table below

| PINS    | USE       |
| ----------- | ------------|
| D33/PC      |      when sim800 is not being used   |
