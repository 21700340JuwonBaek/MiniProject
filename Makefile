TARGET = Market
DTARGET = debug_Market
CC = gcc
OBJ = market.c product.o manager.o

$(TARGET) :  $(OBJ)
	$(CC) -o $@ $^

$(DTARGET) : $(OBJ)
	$(CC) -DDEBUG -o $@ $^

clean : 
	rm *.o $(TARGET) $(DTARGET) 


