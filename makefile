CC = g++

CFLAGS = -Wall

SRCS = TradCalendar.cpp NumDaysCalendar.cpp driver.cpp

HDRS = TradCalendar.h NumDaysCalendar.h Calendar.h

OBJS = $(SRCS:.cpp=.o)

EXEC = calendar

run: clean $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(EXEC) $(CFLAGS)

$(OBJS): $(@:.o=.cpp) $(HDRS)
	$(CC) $(@:.o=.cpp) -c $(CFLAGS)

clean:
	rm -f $(EXEC)
	rm -f $(OBJS)