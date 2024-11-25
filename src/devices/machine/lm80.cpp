#include "emu.h"
#include "lm80.h"

#include "logmacro.h"

DEFINE_DEVICE_TYPE(LM80, lm80_device, "lm80", "LM80 Hardware Monitor")

lm80_device::lm80_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock) :
	device_t(mconfig, LM80, tag, owner, clock),
	i2c_hle_interface(mconfig, *this, 0x28)
{
}

void lm80_device::device_start()
{
}

void lm80_device::write_data(u16 offset, u8 data)
{
	logerror("XXX LM80 READ {%d} {%x}\n", offset, data);
}

u8 lm80_device::read_data(u16 offset)
{
	logerror("XXX LM80 READ {%d}\n", offset);
	return 0x5a;
}
