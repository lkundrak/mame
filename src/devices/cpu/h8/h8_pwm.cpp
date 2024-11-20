// license:BSD-2-Clause
// copyright-holders:Lubomir Rintel

/***************************************************************************

    H8 Pulse-Width Modulation

    TODO:
    - Implement. It's just a skeleton.

***************************************************************************/

#include "emu.h"
#include "h8_pwm.h"

DEFINE_DEVICE_TYPE(H8_PWM, h8_pwm_device, "h8_pwm", "H8 PWM")

h8_pwm_device::h8_pwm_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock) :
	device_t(mconfig, H8_PWM, tag, owner, clock),
	m_tcr(0), m_dtr(0), m_tcnt(0)
{
}

void h8_pwm_device::tcr_w(u8 data)
{
	logerror("tcr_w %02x\n", data);
	m_tcr = data;
}

u8 h8_pwm_device::tcr_r()
{
	logerror("tcr_r %02x\n", m_tcr);
	return m_tcr;
}

void h8_pwm_device::dtr_w(u8 data)
{
	logerror("dtr_w %02x\n", data);
	m_dtr = data;
}

u8 h8_pwm_device::dtr_r()
{
	logerror("dtr_r %02x\n", m_dtr);
	return m_dtr;
}

void h8_pwm_device::tcnt_w(u8 data)
{
	logerror("tcnt_w %02x\n", data);
	m_tcnt = data;
}

u8 h8_pwm_device::tcnt_r()
{
	logerror("tcnt_r %02x\n", m_tcnt);
	return m_tcnt;
}

void h8_pwm_device::device_start()
{
	save_item(NAME(m_tcr));
	save_item(NAME(m_dtr));
	save_item(NAME(m_tcnt));
}

void h8_pwm_device::device_reset()
{
	m_tcr = 0x38;
	m_dtr = 0xff;
	m_tcnt = 0x00;
}
