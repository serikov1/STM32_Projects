cmake_minimum_required(VERSION 3.15)

project(rc_car_new LANGUAGES C CXX ASM)

find_bsp(C_STANDARD 99
    DISABLE_GNU_EXTENSIONS
    SOURCE bsp)



file(GLOB HAL_SOURCES  "${PROJECT_SOURCE_DIR}/../common/Drivers/STM32F1xx_HAL_Driver/Src/*.c")
file(GLOB HAL_HEADERS  "${PROJECT_SOURCE_DIR}/../common/Drivers/STM32F1xx_HAL_Driver/Inc/*.h")
file(GLOB CONF_SOURCES "${PROJECT_SOURCE_DIR}/../common/Core/Src/*.c")
file(GLOB CONF_HEADERS "${PROJECT_SOURCE_DIR}/../common/Core/Inc/*.h")


list(APPEND PROJECT_SOURCES


        "${PROJECT_SOURCE_DIR}/include/data_processing.h"
        "${PROJECT_SOURCE_DIR}/include/motor.h"

        "${PROJECT_SOURCE_DIR}/src/data_processing.c"
        "${PROJECT_SOURCE_DIR}/src/motor.c"

        "${PROJECT_SOURCE_DIR}/../common/Startup/startup_stm32f103c6tx.s"
        "${PROJECT_SOURCE_DIR}/../common/Core/Src/main.c"
        "${HAL_HEADERS}"
        "${HAL_SOURCES}"
        "${CONF_HEADERS}"
        "${CONF_SOURCES}")

list(APPEND INCLUDE_DIRS

    "${PROJECT_SOURCE_DIR}/include"

    "${PROJECT_SOURCE_DIR}/../common/Core/Inc"

    "${PROJECT_SOURCE_DIR}/../common/Drivers/STM32F1xx_HAL_Driver/Inc"
    "${PROJECT_SOURCE_DIR}/../common/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy"

    "${PROJECT_SOURCE_DIR}/../common/Drivers/CMSIS/Device/ST/STM32F1xx/Include"
    "${PROJECT_SOURCE_DIR}/../common/Drivers/CMSIS/Include"
    )

    
    
        set(NAME_FW "rc_car_new")

    add_bsp_based_executable(
    NAME rc_car_new
    SOURCES ${PROJECT_SOURCES}
    GENERATE_BIN
    GENERATE_MAP
    LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/bsp/STM32F103C6TX_FLASH.ld)

    
    target_include_directories(${NAME_FW} PUBLIC ${INCLUDE_DIRS})
set_source_files_properties(motor.h PROPERTIES HEADER_FILE_ONLY TRUE)
