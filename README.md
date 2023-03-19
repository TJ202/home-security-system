# Implementation of a home security system
This repository outlines the simulation of a Home Security System using Arduino UNO and Five General Purpose Input/Output devices.

## Abstract
Most home security systems work on the same basic principle of securing entry points and weak links in a home. Home safety systems involving smoke and fire detection work on the principle of spotting and reporting of unusual events. Regardless of the size of the home, the number of doors and windows, or interior rooms, the only difference is in the number of security components deployed in the home. 
In this project, we have developed a home security application which can be monitored and operated remotely by a primary control panel. 

## Componenets
_The components involved in the home security system are:_
- A primary _control panel_ which can be used for remote operation and monitoring of security system
- _Gas_ and _temperature_ sensors
- _Motion_ and _proximity_ sensors
- _Led_ to blink when a dangerous situation is detected
- _Piezo buzzer_ which makes a loud noise to alert when a dangerous situation is detected
- _LCD_ to display temperature
- _Servo motor_ to trigger the sprinklers on detection of a fire

## System Diagram on <a href="https://www.tinkercad.com/">Tinkercad</a>
_To run the simulation of the following circuit,_
- Paste the contents of the [INO file](home_security_system_code.ino) into the Code Editor of your project, or 
- [Tinker the project](https://www.tinkercad.com/things/1XtbIEpOgQz) after signing up

![image](https://github.com/TJ202/home-security-system/blob/main/Home%20Security%20System.png)

## Future Work
There is scope for a development of a mobile phone companion app where any incidents can be logged to a database. Additionally, using a time and date module, incidents can be time-stamped and the security system can be configured to operate during certain time intervals and/or a certain day. Moreover, live alerts can be sent to the user through mobile phone notifications through the companion app. 

