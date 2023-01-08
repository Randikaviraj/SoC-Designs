/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu0' in SOPC Builder design 'SoC'
 * SOPC Builder design path: D:/CO503AdvancedEmbeddedSystems/Newfolder/Hardware_fifo_Multi_Processor/SoC.sopcinfo
 *
 * Generated: Mon Jan 09 00:19:30 IST 2023
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x80820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0x14
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x40020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0x14
#define ALT_CPU_NAME "cpu0"
#define ALT_CPU_RESET_ADDR 0x40000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x80820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0x14
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x40020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0x14
#define NIOS2_RESET_ADDR 0x40000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x81048
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x81048
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x81048
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "SoC"


/*
 * fifo_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_in altera_avalon_fifo
#define FIFO_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_IN_BASE 0x81050
#define FIFO_IN_BITS_PER_SYMBOL 16
#define FIFO_IN_CHANNEL_WIDTH 8
#define FIFO_IN_ERROR_WIDTH 8
#define FIFO_IN_FIFO_DEPTH 16
#define FIFO_IN_IRQ -1
#define FIFO_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_IN_NAME "/dev/fifo_in"
#define FIFO_IN_SINGLE_CLOCK_MODE 1
#define FIFO_IN_SPAN 4
#define FIFO_IN_SYMBOLS_PER_BEAT 2
#define FIFO_IN_TYPE "altera_avalon_fifo"
#define FIFO_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_IN_USE_AVALONST_SINK 0
#define FIFO_IN_USE_AVALONST_SOURCE 0
#define FIFO_IN_USE_BACKPRESSURE 1
#define FIFO_IN_USE_IRQ 1
#define FIFO_IN_USE_PACKET 1
#define FIFO_IN_USE_READ_CONTROL 0
#define FIFO_IN_USE_REGISTER 0
#define FIFO_IN_USE_WRITE_CONTROL 1


/*
 * fifo_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_in_csr altera_avalon_fifo
#define FIFO_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_IN_CSR_BASE 0x81000
#define FIFO_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_IN_CSR_ERROR_WIDTH 8
#define FIFO_IN_CSR_FIFO_DEPTH 16
#define FIFO_IN_CSR_IRQ -1
#define FIFO_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_IN_CSR_NAME "/dev/fifo_in_csr"
#define FIFO_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_IN_CSR_SPAN 32
#define FIFO_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_IN_CSR_USE_IRQ 1
#define FIFO_IN_CSR_USE_PACKET 1
#define FIFO_IN_CSR_USE_READ_CONTROL 0
#define FIFO_IN_CSR_USE_REGISTER 0
#define FIFO_IN_CSR_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER0
#define ALT_TIMESTAMP_CLK TIMER0


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x81048
#define JTAG_UART_0_IRQ 16
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_data_memory configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_data_memory altera_avalon_onchip_memory2
#define ONCHIP_DATA_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_DATA_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_DATA_MEMORY_BASE 0x60000
#define ONCHIP_DATA_MEMORY_CONTENTS_INFO ""
#define ONCHIP_DATA_MEMORY_DUAL_PORT 0
#define ONCHIP_DATA_MEMORY_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_DATA_MEMORY_INIT_CONTENTS_FILE "onchip_data_memory"
#define ONCHIP_DATA_MEMORY_INIT_MEM_CONTENT 1
#define ONCHIP_DATA_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_DATA_MEMORY_IRQ -1
#define ONCHIP_DATA_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_DATA_MEMORY_NAME "/dev/onchip_data_memory"
#define ONCHIP_DATA_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_DATA_MEMORY_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_DATA_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_DATA_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_DATA_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_DATA_MEMORY_SIZE_VALUE 98304u
#define ONCHIP_DATA_MEMORY_SPAN 98304
#define ONCHIP_DATA_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_DATA_MEMORY_WRITABLE 1


/*
 * onchip_instrucrion_memory0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_instrucrion_memory0 altera_avalon_onchip_memory2
#define ONCHIP_INSTRUCRION_MEMORY0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_INSTRUCRION_MEMORY0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_INSTRUCRION_MEMORY0_BASE 0x40000
#define ONCHIP_INSTRUCRION_MEMORY0_CONTENTS_INFO ""
#define ONCHIP_INSTRUCRION_MEMORY0_DUAL_PORT 0
#define ONCHIP_INSTRUCRION_MEMORY0_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_INSTRUCRION_MEMORY0_INIT_CONTENTS_FILE "onchip_instrucrion_memory0"
#define ONCHIP_INSTRUCRION_MEMORY0_INIT_MEM_CONTENT 1
#define ONCHIP_INSTRUCRION_MEMORY0_INSTANCE_ID "NONE"
#define ONCHIP_INSTRUCRION_MEMORY0_IRQ -1
#define ONCHIP_INSTRUCRION_MEMORY0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_INSTRUCRION_MEMORY0_NAME "/dev/onchip_instrucrion_memory0"
#define ONCHIP_INSTRUCRION_MEMORY0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_INSTRUCRION_MEMORY0_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_INSTRUCRION_MEMORY0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_INSTRUCRION_MEMORY0_SINGLE_CLOCK_OP 0
#define ONCHIP_INSTRUCRION_MEMORY0_SIZE_MULTIPLE 1
#define ONCHIP_INSTRUCRION_MEMORY0_SIZE_VALUE 98304u
#define ONCHIP_INSTRUCRION_MEMORY0_SPAN 98304
#define ONCHIP_INSTRUCRION_MEMORY0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_INSTRUCRION_MEMORY0_WRITABLE 1


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x81040
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1673199811
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer0 altera_avalon_timer
#define TIMER0_ALWAYS_RUN 0
#define TIMER0_BASE 0x81020
#define TIMER0_COUNTER_SIZE 32
#define TIMER0_FIXED_PERIOD 0
#define TIMER0_FREQ 50000000u
#define TIMER0_IRQ 1
#define TIMER0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER0_LOAD_VALUE 49999ull
#define TIMER0_MULT 0.0010
#define TIMER0_NAME "/dev/timer0"
#define TIMER0_PERIOD 1
#define TIMER0_PERIOD_UNITS "ms"
#define TIMER0_RESET_OUTPUT 0
#define TIMER0_SNAPSHOT 1
#define TIMER0_SPAN 32
#define TIMER0_TICKS_PER_SEC 1000u
#define TIMER0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
