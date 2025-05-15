# Senior Software Verification Engineer Project v0.3 - TCP Server

This project is the take home coding assignment as part of the interview process for the Senior Software Verification Engineer role. 

### Assignement Requirements
Please write and check into a public facing repo:

In the language of your choice, build the following:
- A "sender" component that emits a "heartbeat" message over a TCP socket on
regular intervals.
- A "receiver" component that receives the messages and logs them.
- A test suite that tests whether the sender's messages are stable and correct. Include
both passing and failing tests.
Both components must run on a single server. 

Assume MacOS Sonoma/Sequoia or Ubuntu
~22.04 as the build environment as well as runtime environment.

Lastly, include proper documentation in a README le describing how to compile and run your
project, including expected environment and dependencies.


## Environment Setup and Dependencies
The TCP Server and Client application were designed and implemented to be ran on Ubuntu 22.04. The following dependencies are required for the project to run correctly.  

Ubuntu 22.04, C++, Qt, CMake, Doxygen

Ubuntu 22.04 can be installed by following the intructions in the following link.

[Ubuntu Installation Instructions](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview)

Once Ubuntu has been correctly installed, the following command can be run in the command terminal to install the required dependencies for the project. This has been tested on Ubuntu 22.04. Other versions of Ubuntu have not been tested at this time. 

`sudo apt install -y qtcreator qtbase5-dev cmake build-essential gcc-9 g++-9 doxygen`


## Building Instructions
The project is built and compiled using cmake. The following commands can be used to build and compile the TCP Server application and test applications. The building instructions should be ran from the project root in the terminal. 

Make and navigate to build directory: `mkdir build && cd build`

Build Project: `cmake .. && make -j$(nproc)`

## Running the TCP Application
The TCP Server application can be run with the following command from the build directory after compilation.

Run TCP Server Application: `./TCPApplication`

The application will return logs of the received TCP messages in two locations; in the terminal where the application was ran and a tcpLog.csv file in the build directory. 


## Running the Test Application 
The test application is built during the main build and complilation of the TCP Server application. It can be run with the following command from the build directory. 

Note: The test application should only be ran while the main application is not running. 

Run the TCP Test Application: `./TCPServerTest`

The test application verifies the integrety of the messages between the client and server. Two tests are provided, a passing and failing test. 



# PLCodingInterview
