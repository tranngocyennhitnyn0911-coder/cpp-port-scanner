#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "[!] Loi khoi tao Winsock!" << endl;
        return 1;
    }

    string target_host = "scanme.nmap.org";
    vector<int> ports_to_scan = {21, 22, 80, 443, 8080};
    cout << "==========================================" << endl;
    cout << "Bat dau quet muc tieu: " << target_host << endl;
    cout << "==========================================" << endl;

    for (int port : ports_to_scan) {
        // Tạo Socket
        SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock == INVALID_SOCKET) {
            continue;
        }
        sockaddr_in clientService;
        clientService.sin_family = AF_INET;
        clientService.sin_addr.s_addr = inet_addr("45.33.32.156");
        clientService.sin_port = htons(port);
        int result = connect(sock, (SOCKADDR*)&clientService, sizeof(clientService));
        if (result == SOCKET_ERROR) {
            cout << "[-] Cong " << port << ": Dong hoac bi chan (Closed)" << endl;
        } else {
            cout << "[+] Cong " << port << ": DANG MO (Open)" << endl;
        }
        closesocket(sock);
    }

    WSACleanup();
    cout << "==========================================" << endl;
    cout << "Hoan tat quet he thong!" << endl;

    return 0;
}
