DIR=$(shell pwd)/../pcDuino-c

INCS = -I.\
        -I$(DIR) \
        -I$(DIR)/hardware \
        -I$(DIR)/hardware/arduino \
        -I$(DIR)/hardware/arduino/cores \
        -I$(DIR)/hardware/arduino/cores/arduino \
        -I$(DIR)/hardware/arduino/variants \
        -I$(DIR)/hardware/arduino/variants/sunxi \
        -I$(DIR)/libraries \
        -I$(DIR)/libraries/Serial \
        -I$(DIR)/libraries/SPI \
	-I$(DIR)/libraries/Wire \
	-I$(DIR)/libraries/LiquidCrystal \
	-I$(DIR)/libraries/PN532_SPI 

LIBS=$(DIR)/libarduino.a
TARGET=.

OBJS = mq2-sample

all: 
	@mkdir -p $(TARGET)
	@for i in $(OBJS); do echo "$(CXX) $(INCS) $$i.c -o $(TARGET)/$$i $(LIBS)" && $(CXX) $(INCS) $$i.c -o $(TARGET)/$$i $(LIBS); done

clean:
	@for i in $(OBJS); do rm -f $(TARGET)/$$i; done
