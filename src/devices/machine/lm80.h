#ifndef MAME_MACHINE_LM80_H
#define MAME_MACHINE_LM80_H

#pragma once

#include "machine/i2chle.h"
class lm80_device :  public device_t, public i2c_hle_interface
{
public:
	lm80_device(const machine_config &mconfig, const char *tag, device_t *owner)
		: lm80_device(mconfig, tag, owner, 0)
	{
	}

	lm80_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

protected:
	virtual void device_start() override ATTR_COLD;

	virtual void write_data(u16 offset, u8 data) override;
	virtual u8 read_data(u16 offset) override;

	virtual const char *get_tag() override { return tag(); }
};

DECLARE_DEVICE_TYPE(LM80, lm80_device)

#endif // MAME_MACHINE_LM80_H
