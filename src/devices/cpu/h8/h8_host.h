// license:bsd-2-clause
// copyright-holders:lubomir rintel

#ifndef MAME_CPU_H8_H8_HOST_H
#define MAME_CPU_H8_H8_HOST_H

#pragma once

#include "h8.h"

class h8_host_device : public device_t {
public:
	h8_host_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock = 0);
	template<typename T> h8_host_device(const machine_config &mconfig, const char *tag, device_t *owner, T &&cpu)
		: h8_host_device(mconfig, tag, owner)
	{
		m_cpu.set_tag(std::forward<T>(cpu));
	}

	void idr_w(u8 data);
	u8 idr_r();
	void odr_w(u8 data);
	u8 odr_r();
	void str_w(u8 data);
	u8 str_r();

protected:
	required_device<h8_device> m_cpu;

	u8 m_idr;
	u8 m_odr;
	u8 m_str;

	virtual void device_start() override ATTR_COLD;
	virtual void device_reset() override ATTR_COLD;
};

DECLARE_DEVICE_TYPE(H8_HOST, h8_host_device)

#endif // MAME_CPU_H8_H8_HOST_H
