CUR_DIR := $(shell pwd)

include $(TOP_DIR)/system.cfg

TARGET := chapter_2_sample

SRCFILE := $(wildcard $(CUR_DIR)/*.c)

INC_DIR := -I$(CUR_DIR) \
		   -I$(COMMON)

all:
	test -d $(OUTPUT) || mkdir $(OUTPUT)
	$(CC) $(SRCFILE) $(INC_DIR) -o $(TARGET)
	mv $(TARGET) $(OUTPUT)/
clean:
	rm -rf $(OUTPUT)


