//
// Created by sergio on 21/11/21.
//

#ifndef C_GTK_SUBSCRIPTION_CLIENT_UTILS_H
#define C_GTK_SUBSCRIPTION_CLIENT_UTILS_H

//   -----------------------------------------------------
#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif
#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())
#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif
//   -----------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <gtk/gtk.h>


// REQUESTS TYPE
#define ADD     1
#define MSG     2
#define REMOVE  3
#define STATUS  4

struct requestStrc {
    int type;
    char content[100];
};

SOCKET scktRecv;
int serverConnected;


// Variables UI
GtkWidget *window;
GtkBuilder *builder;
GtkWidget *gtkStack;

// Vista "Login"
GtkWidget *gtkFixedLogin;
//GtkWidget *gtkLabelMsgs;

// Vista "Lista de usuarios disponibles"
GtkWidget *gtkFixedSelectUser;

// Vista "Chat"
GtkWidget *gtkFixedChat;


void startGUI();
void receiveConexions();
void sendConexion();
void processResponse(struct requestStrc request);
void onWindowDestroy();

#endif //C_GTK_SUBSCRIPTION_CLIENT_UTILS_H
