/*
*   Copyright (C) 2016,2017 by Jonathan Naylor G4KLX
*   Copyright (C) 2018 by Manuel Sanchez EA7EE
*   Copyright (C) 2018 by Andy Uribe CA6JAU
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#if !defined(GPS_H)
#define	GPS_H

#include "APRSWriter.h"

#include <string>

class CGPS {
public:
	CGPS(const std::string& callsign, const std::string& suffix, const std::string& password, const std::string& address, unsigned int port);
	~CGPS();

	void setInfo(unsigned int txFrequency, unsigned int rxFrequency, float latitude, float longitude, int height, const std::string& desc);

	bool open();

	void data(const unsigned char* source, const unsigned char* data, unsigned char fi, unsigned char dt, unsigned char fn, unsigned char ft, unsigned int tg_qrv);

	void clock(unsigned int ms);

	void reset();

	void close();

private:
	CAPRSWriter    m_writer;
	unsigned char* m_buffer;
	bool           m_sent;
	unsigned int   m_tg_qrv;

	void transmitGPS(const unsigned char* source);
};

#endif
