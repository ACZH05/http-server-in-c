BUILD_DIR = build
TARGET = $(BUILD_DIR)/my_server

all: $(BUILD_DIR) $(TARGET)
	
$(BUILD_DIR):
	@mkdir $@
	
$(TARGET): $(BUILD_DIR)/main.o $(BUILD_DIR)/server.o
	gcc $^ -o $@

$(BUILD_DIR)/main.o: src/main.c
	gcc -c $< -o $@

$(BUILD_DIR)/server.o: src/server.c
	gcc -c $< -o $@

run:
	@$(TARGET)

clean:
	rd /s /q $(BUILD_DIR)