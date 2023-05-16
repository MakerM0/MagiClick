<img src="documents/images/1.jpg" alt="20230217_151114" style="zoom: 50%;" />

# [MagiClick](https://hackaday.io/project/188183-magiclick-a-mechanical-button-with-screen)

[GitHub - MakerM0/MagiClick: A button](https://github.com/MakerM0/MagiClick)

The project uses [WCH's CH582F](https://www.wch.cn/products/CH583.html), a RISC-V chip, which supports BLE. The SDK comes with a multitasking system TMOS, which is very convenient for writing code.

The button can implement a variety of functions.
For example:

- Shutter via BLE
- Stopwatch
- Clock
- Pomodoro
- Music playback controller via BLE
- counter
- Random numbers
- 

It includes an expansion interface to support communication with I2C devices, such as temperature and humidity monitoring, light monitoring, etc.
You can achieve more depending on your needs.



## Guide

Power on: Press and hold the left button

Power off: In the function menu interface, hit the keys three times in a row

Switch function: On the function menu interface, press the side button to switch left and right

Return to the function options page: In general, press and hold the left or right button

Enter the function: The general situation is to press and hold the middle button

Use the apk under the software folder to synchronize time



## Firmware

IDE: [MounRiver Stuido](http://www.mounriver.com/download)

### How to download the firmware

TOOL: WCHISPStudio

While holding down the right button, press the left button to turn on the power, and you can enter the download mode



## Note

The current low-power strategy is to shut down the power directly. The time is not saved after the shutdown action. Please note.

In the future, standby mode will be adopted to maintain low power consumption and time functions.



## Mechanical

<img src="documents/images/3d.png" alt="20230217_151114" style="zoom: 100%;" />

The above file can be printed using a 3D printer.

The Glass cover must be transparent.

For Screen cover, black printing is recommended.

The screw hole is not used yet, please use glue to fix it.

I'll update the file that uses the screw holes when I'm free, hopefully not for too long.

## Images

![shutter](documents/images/shutter.gif)

![stopwatch](documents/images/stopwatch.gif)

![20230217_151114](documents/images/20230217_151114.jpg)



![20230217_151134](documents/images/20230217_151134.jpg)

![20230217_151212](documents/images/20230217_151212.jpg)

![20221205_160836](documents/images/20221205_160836.jpg)

![20221205_160847](documents/images/20221205_160847.jpg)

![20230215_182418](documents/images/20230215_182418.jpg)

![20230215_182433](documents/images/20230215_182433.jpg)

![20230215_182558](documents/images/20230215_182558.jpg)

## License 

(hardware/mechanical)https://creativecommons.org/licenses/by-nc-nd/4.0











