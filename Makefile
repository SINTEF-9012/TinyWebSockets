SRCS = run.cpp ./sockets/WebSocket.cpp ./libs/Log.cpp ./libs/Utility.cpp ./client-server/WebSocketMirrorServer.cpp ./client-server/WebSocketFacade.cpp ./client-server/WebSocketClient.cpp
OBJS = run.o ./sockets/WebSocket.o ./libs/Log.o ./libs/Utility.o ./client-server/WebSocketMirrorServer.o ./client-server/WebSocketFacade.o ./client-server/WebSocketClient.o

SRCS_CLIENT = run_client.cpp ./sockets/WebSocket.cpp ./libs/Log.cpp ./libs/Utility.cpp ./client-server/WebSocketMirrorServer.cpp ./client-server/WebSocketFacade.cpp ./client-server/WebSocketClient.cpp
OBJS_CLIENT = run_client.o ./sockets/WebSocket.o ./libs/Log.o ./libs/Utility.o ./client-server/WebSocketMirrorServer.o ./client-server/WebSocketFacade.o ./client-server/WebSocketClient.o

GNUTLS := #-lgnutls
LIBS = $(GNUTLS) -lpthread -lwebsockets
CFLAGS = -DDEBUG -Wall -Wpointer-arith

GPP = g++

%.o : %.cpp
	$(GPP) $(CFLAGS) -c -o $@ $<

all : run run_client

run : $(OBJS)
	$(GPP) -o $@ $(OBJS) $(LIBS) -lm
	
run_client : $(OBJS_CLIENT)
	$(GPP) -o $@ $(OBJS_CLIENT) $(LIBS) -lm
	
clean :
	rm -rf $(OBJS) $(OBJS_CLIENT) run run_client
	