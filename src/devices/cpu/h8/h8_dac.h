// license:BSD-2-Clause
// copyright-holders:Lubomir Rintel

#ifndef MAME_CPU_H8_H8_DAC_H
#define MAME_CPU_H8_H8_DAC_H

#pragma once

#include "h8.h"

class h8_dac_device : public device_t {
public:
	h8_dac_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);
	h8_dac_device(const machine_config &mconfig, const char *tag, device_t *owner)
		: h8_dac_device(mconfig, tag, owner, 0)
	{
	}

	void dadr0_w(u8 data);
	u8 dadr0_r();
	void dadr1_w(u8 data);
	u8 dadr1_r();
	void dacr_w(u8 data);
	u8 dacr_r();

protected:
	u8 m_dadr0;
	u8 m_dadr1;
	u8 m_dacr;

	virtual void device_start() override ATTR_COLD;
	virtual void device_reset() override ATTR_COLD;
};

DECLARE_DEVICE_TYPE(H8_DAC, h8_dac_device)

#endif // MAME_CPU_H8_H8_DAC_H
