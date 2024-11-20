// license:BSD-2-Clause
// copyright-holders:Lubomir Rintel

/***************************************************************************

    H8 Digital to Analog converter

    TODO:
    - Implement, it's just a skeleton

***************************************************************************/

#include "emu.h"
#include "h8_dac.h"

DEFINE_DEVICE_TYPE(H8_DAC, h8_dac_device, "h8_dac", "H8 DAC")

h8_dac_device::h8_dac_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock) :
	device_t(mconfig, H8_DAC, tag, owner, clock),
	m_dadr0(0), m_dadr1(0), m_dacr(0)
{
}

void h8_dac_device::dadr0_w(u8 data)
{
	logerror("dadr0_w %02x\n", data);
	m_dadr0 = data;
}

u8 h8_dac_device::dadr0_r()
{
	logerror("dadr0_r %02x\n", m_dadr0);
	return m_dadr0;
}

void h8_dac_device::dadr1_w(u8 data)
{
	logerror("dadr1_w %02x\n", data);
	m_dadr1 = data;
}

u8 h8_dac_device::dadr1_r()
{
	logerror("dadr1_r %02x\n", m_dadr1);
	return m_dadr1;
}

void h8_dac_device::dacr_w(u8 data)
{
	logerror("dacr_w %02x\n", data);
	m_dacr = data;
}

u8 h8_dac_device::dacr_r()
{
	logerror("dacr_r %02x\n", m_dacr);
	return m_dacr;
}

void h8_dac_device::device_start()
{
	save_item(NAME(m_dadr0));
	save_item(NAME(m_dadr1));
	save_item(NAME(m_dacr));
}

void h8_dac_device::device_reset()
{
	m_dadr0 = 0x00;
	m_dadr1 = 0x00;
	m_dacr = 0x1f;
}
