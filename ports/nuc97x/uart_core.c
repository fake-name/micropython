#include <unistd.h>
#include "py/mpconfig.h"


#include "nuc970.h"
#include "sys.h"
#include "gpio.h"

#include "uart_core.h"


static void _sysPutRepChar(INT8 *c, INT count)
{
}

// Receive single character
int mp_hal_stdin_rx_chr(void) {
    return sysGetChar();
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {

    while (len--)
    {
        sysPutChar(*str);
        str++;
    }
}
