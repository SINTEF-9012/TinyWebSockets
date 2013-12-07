SRCS = run.cpp ./sockets/Socket.cpp ./sockets/WebSocket.cpp ./libs/Log.cpp ./libs/Utility.cpp ./client-server/WebSocketServer.cpp
OBJS = run.o ./sockets/Socket.o ./sockets/WebSocket.o ./libs/Log.o ./libs/Utility.o ./client-server/WebSocketServer.o

GNUTLS := #-lgnutls
LIBS = $(GNUTLS) -lpthread -lwebsockets
CFLAGS = -DDEBUG -Wall

GPP = g++

%.o : %.cpp
	$(GPP) $(CFLAGS) -c -o $@ $<
	
run : $(OBJS)
	$(GPP) -o $@ $(OBJS) $(LIBS) -lm
	
clean :
	rm -rf $(OBJS) run
	