/**
 * @file cpp_delete_item_example.cpp
 * @author Mislav Novakovic <mislav.novakovic@sartura.hr>
 * @author Michal Vasko <mvasko@cesnet.cz>
 * @brief Example usage of delete_item_example function.
 *
 * @copyright
 * Copyright 2016 - 2019 Deutsche Telekom AG.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>

#include "Session.hpp"

using namespace std;

int
main(int argc, char **argv)
{
    try {
        auto conn = std::make_shared<sysrepo::Connection>();

        auto sess = std::make_shared<sysrepo::Session>(conn);

        const char *xpath = "/ietf-interfaces:interfaces/interface[name='gigaeth0']/ietf-ip:ipv6/address[ip='fe80::ab8']";

        sess->delete_item(xpath);
        sess->apply_changes();

    } catch( const std::exception& e ) {
        cout << e.what() << endl;
    }

    return 0;
}
