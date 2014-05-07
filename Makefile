LIB_SRCS = ./sockets/WebSocket.cpp ./libs/Log.cpp ./libs/Utility.cpp ./client-server/WebSocketMirrorServer.cpp ./client-server/WebSocketFacade.cpp ./client-server/WebSocketClient.cpp
SRCS = run.cpp $(LIB_SRCS)
LIB_OBJS = ./sockets/WebSocket.o ./libs/Log.o ./libs/Utility.o ./client-server/WebSocketMirrorServer.o ./client-server/WebSocketFacade.o ./client-server/WebSocketClient.o
OBJS = run.o $(LIB_OBJS)

STATIC_LIB_LOCATION = libtinyws.a
DYNAMIC_LIB_LOCATION = libtinyws.so

SRCS_CLIENT = run_client.cpp $(LIB_SRCS)
OBJS_CLIENT = run_client.o $(LIB_OBJS)

GNUTLS := #-lgnutls
LIBS = $(GNUTLS) -lpthread -lwebsockets
CFLAGS = -DDEBUG -Wall

LIBWEBSOCKETS = ../libwebsockets
LIBWEBSOCKETS_BUILD_DIR = $(LIBWEBSOCKETS)/build

GPP = g++
AR = ar
LD = ld

%.o : %.cpp
	$(GPP) $(CFLAGS) -fPIC -c -o $@ $<

all : run run_client

run : $(OBJS)
	$(GPP) -o $@ $(OBJS) $(LIBS) -lm
	
staticlib : $(LIB_OBJS)
	$(AR) rvs $(STATIC_LIB_LOCATION) $(LIB_OBJS)

dynamiclib : $(LIB_OBJS)
	$(GPP) -shared -o $(DYNAMIC_LIB_LOCATION) $(LIB_OBJS)

run_client : $(OBJS_CLIENT)
	$(GPP) -o $@ $(OBJS_CLIENT) $(LIBS) -lm
	
clean :
	rm -rf $(OBJS) $(OBJS_CLIENT) run run_client

cleanlibs :
	rm -rf $(DYNAMIC_LIB_LOCATION) $(STATIC_LIB_LOCATION)

uninstall:
	rm -rf /usr/local/include/tinyws
	rm -f /usr/local/lib/$(STATIC_LIB_LOCATION)
	rm -f /usr/local/lib/$(DYNAMIC_LIB_LOCATION)

install: staticlib dynamiclib uninstall
	install -d /usr/local
	install -d /usr/local/lib
	install -d /use/local/include
	install -d /use/local/include/tinyws
	install -d /usr/local/include/tinyws/client-server
	install -d /usr/local/include/tinyws/libs
	install -d /usr/local/include/tinyws/sockets
	cp $(DYNAMIC_LIB_LOCATION) /usr/local/lib
	cp $(STATIC_LIB_LOCATION) /usr/local/lib
	cp -r ./client-server/*.h /usr/local/include/tinyws/client-server
	cp -r ./libs/*.h /usr/local/include/tinyws/libs
	cp -r ./sockets/*.h /usr/local/include/tinyws/sockets

testwebsockets:
	test -s $(LIBWEBSOCKETS_BUILD_DIR) || { echo "Cannot find built libwebsockets..."; exit 1; }
	
uninstallwebsockets:
	rm -rf /usr/local/include/libwebsockets
	rm -f /usr/local/lib/libwebsockets.so
	rm -f /usr/local/lib/libwebsockets.so.4.0.0
	rm -f /usr/local/lib/libwebsockets.a

installwebsockets: uninstallwebsockets testwebsockets
	install -d /usr/local
	install -d /usr/local/lib
	install -d /usr/local/include
	install -d /usr/local/include/libwebsockets
	install $(LIBWEBSOCKETS_BUILD_DIR)/lib/libwebsockets.so.4.0.0 /usr/local/lib/
	ln -s /usr/local/lib/libwebsockets.so.4.0.0 /usr/local/lib/libwebsockets.so
	install $(LIBWEBSOCKETS_BUILD_DIR)/lib/libwebsockets.a /usr/local/lib
	cp $(LIBWEBSOCKETS_BUILD_DIR)/lws_config.h /usr/local/include/libwebsockets/lws_config.h
	cp $(LIBWEBSOCKETS)/lib/libwebsockets.h /usr/local/include/libwebsockets/libwebsockets.h
