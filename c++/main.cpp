/*
 * Copyright (c) 2016 Richard B Tilley <btilley@gatech.edu>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

// Standard Includes
#include <iostream>
#include <string>

// Local Includes
#include "dpg.hpp"
#include "global.hpp"
#include "test.hpp"

int main( int argc, char* argv[] )
{
    const std::string usage = "usage: dpg \"Type a sentence\" word";

    if ( argc != 3 )
    {
        std::cerr << usage << "\n";
        return 1;
    }

    if ( TEST )
    {
        run_tests();
    }

    const std::string sentence = argv[1];
    const std::string word = argv[2];

    // Big
    const std::string big_password = get_passwd( sentence, word, 24 );
    const std::string big_spaced_password = readable(big_password);
    
    // Small
    const std::string small_password = get_passwd( sentence, word, 12 );
    const std::string small_spaced_password = readable(small_password);
    
    // Words
    const std::string passphrase = get_passphrase( sentence, word, 7 );
    const std::string spaced_passphrase = readable(passphrase);

    std::cout << "\n-----BEGIN DPG MESSAGE-----\n";
    std::cout << big_password              << "\n"; 
    std::cout << small_password            << "\n"; 
    std::cout << passphrase                << "\n"; 
    std::cout << "---------------------------\n";
    std::cout << "---- Human Readable -------\n";
    std::cout << "---------------------------\n";
    std::cout << big_spaced_password       << "\n";
    std::cout << small_spaced_password     << "\n";
    std::cout << spaced_passphrase         << "\n";
    std::cout << "------END DPG MESSAGE------\n\n";

    return 0;
}   

