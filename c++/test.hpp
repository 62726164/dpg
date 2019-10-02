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

#include <string>

// Static test sentences and words
const std::string ts0 = "";
const std::string tw0 = "";
const std::string ts1 = "A test sentence.";
const std::string tw1 = "test_word";
const std::string ts2 = "When was the last time we danced?";
const std::string tw2 = "google";

// ts0 AND tw0 
const std::string test0_PBKDF2                = "D4EC188C3D17227A3EC8E1891E6EAB225EA340ECE1E4E6F472ED9197DC907B79C122CF27E560762C7A2215BC50699BB2523A08C6A1147FF84813B504EA9C3A6F";
const std::string test0_big_spaced_password   = "epj prh cms jbk ssn csd apb #G6";
const std::string test0_small_spaced_password = "epj prh cms .B3";
const std::string test0_spaced_passphrase     = "sit wig bot lug elm bob con !S2";
const std::string test0_big_password          = "epjprhcmsjbkssncsdapb#G6";
const std::string test0_small_password        = "epjprhcms.B3";
const std::string test0_passphrase            = "sitwigbotlugelmbobcon!S2";

// ts1 AND tw1
const std::string test1_PBKDF2                = "A22F93266867B6F41C423A60F4D177F8B46A16FAFBE63E6668C05B1B5B77C3F6C6BB7D3BAFBE85A353D5CABB855A8F87A8E51B06E115A2EEDA2A7D58564395FE";
const std::string test1_big_spaced_password   = "ctd gjh gep cma ebh jem gmn ^S8";
const std::string test1_small_spaced_password = "ctd gjh gep !M2";
const std::string test1_spaced_passphrase     = "nip dig meg coy ill icy pea #P4";
const std::string test1_big_password          = "ctdgjhgepcmaebhjemgmn^S8";
const std::string test1_small_password        = "ctdgjhgep!M2";
const std::string test1_passphrase            = "nipdigmegcoyillicypea#P4";

// ts2 and tw2
const std::string test2_PBKDF2                = "D1BD9927CB86A4861F993E57188FAC0458BE85DF4E3A5E2C9CA95693D9C80899E891F7AE89CDFD87624B26B1823587C9C5F5189DCAD110D42415BF07E510CF09";
const std::string test2_big_spaced_password   = "brk hng egt ksh jtp ejs fts !S6";
const std::string test2_small_spaced_password = "brk hng egt ,S9";
const std::string test2_spaced_passphrase     = "shy ray mow cub sat let not ^T3";
const std::string test2_big_password          = "brkhngegtkshjtpejsfts!S6";
const std::string test2_small_password        = "brkhngegt,S9";
const std::string test2_passphrase            = "shyraymowcubsatletnot^T3";

// Run the test cases
void run_tests()
{
    std::string big_password;
    std::string big_spaced_password;
    std::string small_password;
    std::string small_spaced_password;
    std::string passphrase;
    std::string spaced_passphrase;
    std::string PBKDF2;

    // Test 0
    PBKDF2                = do_PBKDF2( ts0, tw0 );
    big_password          = get_passwd( ts0, tw0, 24 );
    big_spaced_password   = readable(big_password);
    small_password        = get_passwd( ts0, tw0, 12 );
    small_spaced_password = readable(small_password);
    passphrase            = get_passphrase( ts0, tw0, 7 );
    spaced_passphrase     = readable(passphrase);

    if ( PBKDF2 != test0_PBKDF2 )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << PBKDF2 << " " << PBKDF2.size() << "\n";
        std::cerr << "Expected: " << test0_PBKDF2 << " " << test0_PBKDF2.size() << "\n";
    }

    if ( big_password != test0_big_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_password << " " << big_password.size() << "\n";
        std::cerr << "Expected: " << test0_big_password << " " << test0_big_password.size() << "\n";
    }

    if ( big_spaced_password != test0_big_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_spaced_password << " " << big_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test0_big_spaced_password << " " << test0_big_spaced_password.size() << "\n";
    }

    if ( small_password != test0_small_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_password << " " << small_password.size() << "\n";
        std::cerr << "Expected: " << test0_small_password << " " << test0_small_password.size() << "\n";
    }

    if ( small_spaced_password != test0_small_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_spaced_password << " " << small_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test0_small_spaced_password << " " << test0_small_spaced_password.size() << "\n";
    }

    if ( passphrase != test0_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << passphrase << " " << passphrase.size() << "\n";
        std::cerr << "Expected: " << test0_passphrase << " " << test0_passphrase.size() << "\n";
    }

    if ( spaced_passphrase != test0_spaced_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << spaced_passphrase << " " << spaced_passphrase.size() << "\n";
        std::cerr << "Expected: " << test0_spaced_passphrase << " " << test0_spaced_passphrase.size() << "\n";
    }

    // Test 1
    PBKDF2                = do_PBKDF2( ts1, tw1 );
    big_password          = get_passwd( ts1, tw1, 24 );
    big_spaced_password   = readable(big_password);
    small_password        = get_passwd( ts1, tw1, 12 );
    small_spaced_password = readable(small_password);
    passphrase            = get_passphrase( ts1, tw1, 7 );
    spaced_passphrase     = readable(passphrase);

    if ( PBKDF2 != test1_PBKDF2 )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << PBKDF2 << " " << PBKDF2.size() << "\n";
        std::cerr << "Expected: " << test1_PBKDF2 << " " << test1_PBKDF2.size() << "\n";
    }

    if ( big_password != test1_big_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_password << " " << big_password.size() << "\n";
        std::cerr << "Expected: " << test1_big_password << " " << test1_big_password.size() << "\n";
    }

    if ( big_spaced_password != test1_big_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_spaced_password << " " << big_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test1_big_spaced_password << " " << test1_big_spaced_password.size() << "\n";
    }

    if ( small_password != test1_small_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_password << " " << small_password.size() << "\n";
        std::cerr << "Expected: " << test1_small_password << " " << test1_small_password.size() << "\n";
    }

    if ( small_spaced_password != test1_small_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_spaced_password << " " << small_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test1_small_spaced_password << " " << test1_small_spaced_password.size() << "\n";
    }

    if ( passphrase != test1_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << passphrase << " " << passphrase.size() << "\n";
        std::cerr << "Expected: " << test1_passphrase << " " << test1_passphrase.size() << "\n";
    }

    if ( spaced_passphrase != test1_spaced_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << spaced_passphrase << " " << spaced_passphrase.size() << "\n";
        std::cerr << "Expected: " << test1_spaced_passphrase << " " << test1_spaced_passphrase.size() << "\n";
    }

    // Test 2
    PBKDF2                = do_PBKDF2( ts2, tw2 );
    big_password          = get_passwd( ts2, tw2, 24 );
    big_spaced_password   = readable(big_password);
    small_password        = get_passwd( ts2, tw2, 12 );
    small_spaced_password = readable(small_password);
    passphrase            = get_passphrase( ts2, tw2, 7 );
    spaced_passphrase     = readable(passphrase);

    if ( PBKDF2 != test2_PBKDF2 )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << PBKDF2 << " " << PBKDF2.size() << "\n";
        std::cerr << "Expected: " << test2_PBKDF2 << " " << test2_PBKDF2.size() << "\n";
    }

    if ( big_password != test2_big_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_password << " " << big_password.size() << "\n";
        std::cerr << "Expected: " << test2_big_password << " " << test2_big_password.size() << "\n";
    }

    if ( big_spaced_password != test2_big_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << big_spaced_password << " " << big_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test2_big_spaced_password << " " << test2_big_spaced_password.size() << "\n";
    }

    if ( small_password != test2_small_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_password << " " << small_password.size() << "\n";
        std::cerr << "Expected: " << test2_small_password << " " << test2_small_password.size() << "\n";
    }

    if ( small_spaced_password != test2_small_spaced_password )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << small_spaced_password << " " << small_spaced_password.size() << "\n";
        std::cerr << "Expected: " << test2_small_spaced_password << " " << test2_small_spaced_password.size() << "\n";
    }

    if ( passphrase != test2_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << passphrase << " " << passphrase.size() << "\n";
        std::cerr << "Expected: " << test2_passphrase << " " << test2_passphrase.size() << "\n";
    }

    if ( spaced_passphrase != test2_spaced_passphrase )
    {
        std::cerr << "Test failed...\n";
        std::cerr << "Recieved: " << spaced_passphrase << " " << spaced_passphrase.size() << "\n";
        std::cerr << "Expected: " << test2_spaced_passphrase << " " << test2_spaced_passphrase.size() << "\n";
    }
}

