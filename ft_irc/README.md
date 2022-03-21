## Introduction
Internet Relay Chat or IRC is a textual communication protocol on the Internet. 

It is instantaneous communication mainly in the form of discussions in groups via discussion channels, 

but can also be used for one-to-one communication.

IRC client programs connect to an IRC server to access a specific channel. 

IRC servers are connected between them to provide a global network with unique channels.


## Rules

* You must write an IRC server in C++ 98.
* If you need more C functions, you can use them but always prefer C++.
* The C++ standard must be C++ 98. Your project must compile with it.
* No external library, no Boost, etc...
* Try to always use the most "C++" code possible (for example use <cstring> over <string.h>).
* In the subject and the scale we will mention poll but you can use equivalent like select, kqueue, epoll.
* Communication between client and server must be done via TCP/IP(v4) or (v6)
* The server must be capable of handling multiple clients at the same time and never hang. Forking is not allowed, all I/O operations must be non blocking and use only 1 poll (or equivalent) for all (read, write, but also listen, ...)
