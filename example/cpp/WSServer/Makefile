GPP = g++
LIBS = -lpthread -ltinyws -lwebsockets -lpthread
CFLAGS = -DDEBUG
SRCS = WebSMirrorServer.cpp WSServer.cpp runtime.cpp
OBJS = WebSMirrorServer.o WSServer.o runtime.o

all : WSServer

.cpp.o :
	${GPP} ${CFLAGS} -c $< 

WSServer : $(OBJS)
	$(GPP) -g -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ WSServer