/* Orchid - WebRTC P2P VPN Market (on Ethereum)
 * Copyright (C) 2017-2019  The Orchid Authors
*/

/* GNU Affero General Public License, Version 3 {{{ */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
/* }}} */


#ifndef ORCHID_CAPTURE_HPP
#define ORCHID_CAPTURE_HPP

#include "link.hpp"

namespace orc {

class Capture :
    public Pipe,
    public BufferDrain
{
  public:
    U<Sync> sync_;

  protected:
    virtual Link *Inner() = 0;

    void Land(const Buffer &data) override;
    void Stop(const std::string &error) override;

  public:
    Capture();
    ~Capture();

    task<void> Send(const Buffer &data) override;

    task<void> Start(std::string ovpnfile, std::string username, std::string password);
};

}

#endif//ORCHID_CAPTURE_HPP
