/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'cpu_2' in SOPC Builder design 'SoC'
 * SOPC Builder design path: D:/CO503AdvancedEmbeddedSystems/Newfolder/JFEG_MPSOC/SoC.sopcinfo
 *
 * Generated: Sat Jan 14 09:55:39 IST 2023
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

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

#include "altera_nios2_qsys_irq.h"
#include "altera_avalon_fifo.h"
#include "altera_avalon_jtag_uart.h"
#include "altera_avalon_timer.h"

/*
 * Allocate the device storage
 */

ALTERA_NIOS2_QSYS_IRQ_INSTANCE ( CPU_2, cpu_2);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_STAGE2_TO_3, fifo_stage2_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_STAGE3_TO_4, fifo_stage3_to_4);
ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG_UART_2, jtag_uart_2);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_2, timer_2);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
    ALTERA_NIOS2_QSYS_IRQ_INIT ( CPU_2, cpu_2);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    ALTERA_AVALON_TIMER_INIT ( TIMER_2, timer_2);
    ALTERA_AVALON_FIFO_INIT ( FIFO_STAGE2_TO_3, fifo_stage2_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_STAGE3_TO_4, fifo_stage3_to_4);
    ALTERA_AVALON_JTAG_UART_INIT ( JTAG_UART_2, jtag_uart_2);
}
