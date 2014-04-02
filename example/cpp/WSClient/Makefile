GPP = g++
LIBS = -lpthread -ltinyws -lwebsockets -lpthread
CFLAGS = -DDEBUG
SRCS = Lifecicle.cpp ClockLinux.cpp WebSClient.cpp WSClient.cpp runtime.cpp
OBJS = Lifecicle.o ClockLinux.o WebSClient.o WSClient.o runtime.o

all : WSClient

.cpp.o :
	${GPP} ${CFLAGS} -c $< 

WSClient : $(OBJS)
	$(GPP) -g -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ WSClient