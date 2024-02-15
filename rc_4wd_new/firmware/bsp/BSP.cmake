set(_core_sources .)
set(_core_linker_script ${BSP_ROOT}/STM32F100RBTX_FLASH.ld)

set(_core_includes .)

set(_core_defines USE_HAL_DRIVER STM32F100xB)

set(_core_commonflags -mcpu=cortex-m3)

set(_core_ID STM32F100RBTx)

