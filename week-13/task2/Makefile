BUILD_DIR := build
MAIN_EXEC := main

# Путь к CMake
CMAKE := cmake
MAKE := make

# Создание директории сборки
$(BUILD_DIR):
	@echo "Создание директории $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

# Генерация Makefile с помощью CMake
$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Запуск CMake..."
	cd $(BUILD_DIR) && $(CMAKE) ..

# Общая цель для сборки проекта
all: $(BUILD_DIR)/Makefile
	@echo "Сборка проекта..."
	cd $(BUILD_DIR) && $(MAKE)

# Запуск программы с передачей аргументов
run: all
	@echo "Запуск main..."
	@cd $(BUILD_DIR) && ./$(MAIN_EXEC) $(hash) $(length)

# Сборка и запуск
build_and_run: all run

# Очистка
clean:
	@echo "Очистка..."
	rm -rf $(BUILD_DIR)

clear: clean

.PHONY: all run clean build_and_run clear

