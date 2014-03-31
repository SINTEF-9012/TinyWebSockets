GPP = g++
LIBS = -lpthread -ltinyws -lwebsockets -lpthread
CFLAGS = -DDEBUG
SRCS = WebSMirrorServer.cpp Test.cpp WebSClient.cpp ClockLinux.cpp testWS.cpp runtime.cpp
OBJS = WebSMirrorServer.o Test.o WebSClient.o ClockLinux.o testWS.o runtime.o

all : testWS

.cpp.o :
	${GPP} ${CFLAGS} -c $< 

testWS : $(OBJS)
	$(GPP) -g -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ testWS