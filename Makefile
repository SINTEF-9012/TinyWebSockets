LIB_SRCS = ./sockets/WebSocket.cpp ./libs/Log.cpp ./libs/Utility.cpp ./client-server/WebSocketMirrorServer.cpp ./client-server/WebSocketFacade.cpp ./client-server/WebSocketClient.cpp
SRCS = run.cpp $(LIB_SRCS)
LIB_OBJS = ./sockets/WebSocket.o ./libs/Log.o ./libs/Utility.o ./client-server/WebSocketMirrorServer.o ./client-server/WebSocketFacade.o ./client-server/WebSocketClient.o
OBJS = run.o $(LIB_OBJS)

STATIC_LIB_LOCATION = libtinyws.a
DYNAMIC_LIB_LOCATION = libtinyws.so.1.0

SRCS_CLIENT = run_client.cpp $(LIB_SRCS)
OBJS_CLIENT = run_client.o $(LIB_OBJS)

GNUTLS := #-lgnutls
LIBS = $(GNUTLS) -lpthread -lwebsockets
CFLAGS = -DDEBUG -Wall

GPP = g++
AR = ar
LD = ld

%.o : %.cpp
	$(GPP) $(CFLAGS) -c -o $@ $<

all : run run_client

run : $(OBJS)
	$(GPP) -o $@ $(OBJS) $(LIBS) -lm
	
staticlib : removeobj $(LIB_OBJS)
	$(AR) rvs $(STATIC_LIB_LOCATION) $(LIB_OBJS)

dynamiclib : removeobj setfpic $(LIB_OBJS)
	$(GPP) -shared -o $(DYNAMIC_LIB_LOCATION) $(LIB_OBJS)

run_client : $(OBJS_CLIENT)
	$(GPP) -o $@ $(OBJS_CLIENT) $(LIBS) -lm
	
clean :
	rm -rf $(OBJS) $(OBJS_CLIENT) run run_client

cleanlibs :
	rm -rf $(DYNAMIC_LIB_LOCATION) $(STATIC_LIB_LOCATION)

removeobj :
	rm -rf $(LIB_OBJS)
	
setfpic :
	$(eval CFLAGS := $(CFLAGS) -fPIC)
	
