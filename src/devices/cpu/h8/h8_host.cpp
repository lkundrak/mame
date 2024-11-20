// license:bsd-2-clause
// copyright-holders:lubomir rintel

#include "emu.h"
#include "h8_host.h"

DEFINE_DEVICE_TYPE(H8_HOST, h8_host_device, "h8_host", "H8 Host Interface")

h8_host_device::h8_host_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock) :
	device_t(mconfig, H8_HOST, tag, owner, clock),
	m_cpu(*this, finder_base::DUMMY_TAG),
	m_idr(0), m_odr(0), m_str(0)
{
}

void h8_host_device::idr_w(u8 data)
{
	logerror("idr_w %02x\n", data);
	m_idr = data;
}

u8 h8_host_device::idr_r()
{
	logerror("idr_r %02x\n", m_idr);
	return m_idr;
}

void h8_host_device::odr_w(u8 data)
{
	logerror("odr_w %02x\n", data);
	m_odr = data;
}

u8 h8_host_device::odr_r()
{
	logerror("odr_r %02x\n", m_odr);
	return m_odr;
}

void h8_host_device::str_w(u8 data)
{
	logerror("str_w %02x\n", data);
	m_str = data;
}

u8 h8_host_device::str_r()
{
	logerror("str_r %02x\n", m_str);
	return m_str;
}

void h8_host_device::device_start()
{
	save_item(NAME(m_idr));
	save_item(NAME(m_odr));
	save_item(NAME(m_str));
}

void h8_host_device::device_reset()
{
	m_idr = 0x00;
	m_odr = 0x00;
	m_str = 0x00;
}
