// Copyright (c) 2015, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of this project nor the names of its contributors may
//       be used to endorse or promote products derived from this software
//       without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// e
#include "e/error.h"

using e::error;

error :: error()
	: m_msg()
	, m_msg_s()
	, m_loc_s()
	, m_file("")
	, m_line(0)
{
}

error :: error(const error &other)
	: m_msg(other.m_msg.str())
	, m_msg_s(other.m_msg_s)
	, m_loc_s(other.m_loc_s)
	, m_file(other.m_file)
	, m_line(other.m_line)
{
}

error :: ~error() throw ()
{
}

const char *
error :: loc()
{
	char buf[21];
	snprintf(buf, 21, "%lu", m_line);
	m_loc_s  = m_file;
	m_loc_s += ":";
	m_loc_s += buf;
	return m_loc_s.c_str();
}

const char *
error :: msg()
{
	m_msg_s = m_msg.str();
	return m_msg_s.c_str();
}

void
error :: set_loc(const char *file, size_t line)
{
	m_file = file;
	m_line = line;
}

std::ostream &
error :: set_msg()
{
	m_msg.str("");
	m_msg.clear();
	return m_msg;
}

error &
error :: operator = (const error &rhs)
{
	if (this != &rhs)
	{
		m_msg.str(rhs.m_msg.str());
		m_msg.clear();
		m_msg_s = rhs.m_msg_s;
		m_loc_s = rhs.m_loc_s;
		m_file = rhs.m_file;
		m_line = rhs.m_line;
	}
	return *this;
}
