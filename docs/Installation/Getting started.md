Connect power to the board via terminal block labeled J17 as shown in the image below.
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/docs/images/power%20connection.jpeg?raw=true"><br>
<em>_+ve wire to go to the +24V mark and -ve wire to be connected to the GND mark._</em>
</p>

<p>The recommended input voltage range is 5V-24V.<br>
Led D58 and D59 on the main board will come on to indicate that the board is receiving 4.2V and 3.3V respectively.<br>
Make sure that you have installed arduino IDE in your computer. Read more on <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/">arduino IDE installation</a><br>
clone the blink board repository in any prefered location on your computer, run your first example<br>
Flash the firmware to the main board via FT232RL FTDI USB To TTL Module.</p>
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/docs/images/FTDI%20usb%20ttl%20J17%20main%20board.jpg?raw=true"><br>
<em>FTDI board on the left, the blink board on the right</em>
</p><br>
The FTDI should be connected via jumper wires to the male header pins labeled J26 on the main board as shown in the image above.<br>
Match the labels on the connector J26 to those on the FTDI as follows:

| J26         | FTDI        |
| ----------- | ------------|
| `RTS`       |      RTS    |
| `DTR`       |      DTR    |
| `TXD`       |      RXD    |
| `RXD`       |      TXD    |
| `GND`       |      CND    |

!!! Note
    For any connection on the board make sure the terminal block is fully opened before inserting the wire
<p align="center"><img width="30%" src="https://github.com/blinky-iot/Blink-board/blob/docs/images/proper%20wire%20connection.jpg?raw=true"></p>
