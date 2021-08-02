

██╗░░░██╗░██████╗███████╗██████╗░  ███╗░░░███╗░█████╗░███╗░░██╗██╗░░░██╗░█████╗░██╗░░░░░
██║░░░██║██╔════╝██╔════╝██╔══██╗  ████╗░████║██╔══██╗████╗░██║██║░░░██║██╔══██╗██║░░░░░
██║░░░██║╚█████╗░█████╗░░██████╔╝  ██╔████╔██║███████║██╔██╗██║██║░░░██║███████║██║░░░░░
██║░░░██║░╚═══██╗██╔══╝░░██╔══██╗  ██║╚██╔╝██║██╔══██║██║╚████║██║░░░██║██╔══██║██║░░░░░
╚██████╔╝██████╔╝███████╗██║░░██║  ██║░╚═╝░██║██║░░██║██║░╚███║╚██████╔╝██║░░██║███████╗
░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚══════╝

------------------------------------------
TCP Server/Client programs
------------------------------------------
Written on Mac OS.
Author: Eyþór Óli Borgþórsson.

a) Compile all by writing the following command: make all
b) Open a terminal window and start running server on a valid port
c) Open a new terminal window and run client. Specify server ip address and port.
d) To monitor communication you can use tcpdump in the third terminal window (man tcpdump for better info).

 ██╗
███║
╚██║
 ██║
 ██║
 ╚═╝
    
Simple TCP Server/Client

- Client connects to server, sends message and closes connection. User input not supported.

******
Server: server.cpp    Compile: g++ -std=c++11 server.cpp -o <sname>    run: ./<sname> <port>
Client: client.cpp    Compile: g++ -std=c++11 client.cpp -o <cname>    run: ./<cname> <server_ip> <port>
******

----------------------------------------------

██████╗ 
╚════██╗
█████╔╝
██╔═══╝ 
███████╗
╚══════╝

Standard TCP Server/Client: I/O stream communication

- Client connects to server. User sends commands to server through command line.

******
Server: server.cpp    Compile: g++ -std=c++11 server_mod.cpp -o <sname>    run: ./<sname> <port>
Client: client.cpp    Compile: g++ -std=c++11 client_mod.cpp -o <cname>    run: ./<cname> <server_ip> <port>
******

HOW TO USE command line:

Client_mod:
Command line requests:
Supports SYS commands. F.x.
SYS ls, SYS, echo "Hello"

Server_mod:
Returns output if command is valid.
Returns "Command invalid, no output" if command is indvalid.
Returns "Unknown command from client:" if SYS is not used.

