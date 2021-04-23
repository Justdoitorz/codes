#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHOOSE   2

#if (CHOOSE == 0)

static uint32_t sl_uart_ok_frame(uint32_t delta)
{
	static uint32_t uart_ok_frame = 0;
	uart_ok_frame += delta;
	return uart_ok_frame;
}
uint32_t get_uart_ok_frame(void)
{
	return sl_uart_ok_frame(0);
}

uint32_t set_uart_ok_frame(uint32_t val)
{
	return sl_uart_ok_frame(val - get_uart_ok_frame());
}

uint32_t uart_ok_frame_inc(void)
{
	return sl_uart_ok_frame(1);
}

uint32_t uart_ok_frame_dec(void)
{
	return sl_uart_ok_frame(-1);
}


#elif (CHOOSE == 1)
static uint32_t sl_uart_ok_frame(uint32_t xor)
{
	static uint32_t uart_ok_frame = 0;
	uart_ok_frame ^= xor;
	return uart_ok_frame;
}

uint32_t get_uart_ok_frame(void)
{
	return sl_uart_ok_frame(0);
}

uint32_t set_uart_ok_frame(uint32_t val)
{
	return sl_uart_ok_frame(val^get_uart_ok_frame());
}

uint32_t uart_ok_frame_inc(void)
{
    uint32_t old = get_uart_ok_frame();
	return sl_uart_ok_frame((old+1)^old);
}

uint32_t uart_ok_frame_dec(void)
{
    uint32_t old = get_uart_ok_frame();
	return sl_uart_ok_frame((old-1)^old);
}
#else

static uint32_t sl_uart_ok_frame(int32_t op, uint32_t val)
{
	static uint32_t uart_ok_frame = 0;
    uart_ok_frame = val + op*uart_ok_frame;
	return uart_ok_frame;
}
uint32_t get_uart_ok_frame(void)
{
	return sl_uart_ok_frame(1, 0);
}

uint32_t set_uart_ok_frame(uint32_t val)
{
	return sl_uart_ok_frame(0, val);
}

uint32_t uart_ok_frame_inc(void)
{
	return sl_uart_ok_frame(1, 1);
}

uint32_t uart_ok_frame_dec(void)
{
	return sl_uart_ok_frame(1, -1);
}

#endif
int main()
{
    printf("%u\r\n", get_uart_ok_frame());
    set_uart_ok_frame(124556);
    printf("%u\r\n", get_uart_ok_frame());
    set_uart_ok_frame(1243);
    printf("%u\r\n", get_uart_ok_frame());
    uart_ok_frame_inc();
    printf("%u\r\n", get_uart_ok_frame());
    uart_ok_frame_dec();
    uart_ok_frame_dec();
    printf("%u\r\n", uart_ok_frame_dec());
    printf("%u\r\n", get_uart_ok_frame());
    return 0;
}
