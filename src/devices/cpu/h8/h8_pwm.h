// license:BSD-2-Clause
// copyright-holders:Lubomir Rintel

#ifndef MAME_CPU_H8_H8_PWM_H
#define MAME_CPU_H8_H8_PWM_H

#pragma once

#include "h8.h"

class h8_pwm_device : public device_t {
public:
	h8_pwm_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock);
	h8_pwm_device(const machine_config &mconfig, const char *tag, device_t *owner)
		: h8_pwm_device(mconfig, tag, owner, 0)
	{
	}

	void tcr_w(u8 data);
	u8 tcr_r();
	void dtr_w(u8 data);
	u8 dtr_r();
	void tcnt_w(u8 data);
	u8 tcnt_r();

protected:
	u8 m_tcr;
	u8 m_dtr;
	u8 m_tcnt;

	virtual void device_start() override ATTR_COLD;
	virtual void device_reset() override ATTR_COLD;
};

DECLARE_DEVICE_TYPE(H8_PWM, h8_pwm_device)

#endif // MAME_CPU_H8_H8_PWM_H
