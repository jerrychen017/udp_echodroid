#ifndef INTERACTIVE_NET_INCLUDE_H
#define INTERACTIVE_NET_INCLUDE_H
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>

#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include <errno.h>

#include <sys/time.h>

#define PORT 9008
#define BUFF_SIZE 1000
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0
#define PACKET_SIZE 1400
#define NUM_SEND 10

enum PacketType {
    TIMING,
    REPORT,
    ECHO
};

typedef struct Packet {
    int type;
    char buffer[PACKET_SIZE + 8];
} Packet;

typedef struct TimingPacket {
    int type;
    int seq;
    char buffer[PACKET_SIZE];
} TimingPacket;

typedef struct ReportPacket {
    int type;
    int seq;
    float throughput;
} ReportPacket;

typedef struct EchoPacket {
    int type;
    int seq;
    float x;
    float y;
} EchoPacket;

#endif