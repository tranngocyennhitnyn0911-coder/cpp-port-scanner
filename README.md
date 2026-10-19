# C++ Network Port Scanner

A lightweight, efficient C++ port scanner built using Windows Sockets API (Winsock2). Designed for basic network security auditing and identifying open ports on target servers.

## 🚀 Features
- Multi-port scanning support (FTP, SSH, HTTP, HTTPS, etc.).
- Low-level network socket implementation via `Winsock2`.
- Clear diagnostic outputs for Open/Closed ports.

## 🛠️ Built With
- **Language:** C++
- **Libraries:** `winsock2.h`, `ws2tcpip.h`
- **Compiler:** MinGW / GCC (Linked with `ws2_32`)

## 💻 How to Run
1. Clone or download the repository.
2. Compile using G++ / Code::Blocks:
   ```bash
   g++ duan.cpp -o duan -lws2_32
