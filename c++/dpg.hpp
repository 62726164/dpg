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
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <string>

// Crypto++
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/pwdbased.h>  // for pbkdf2

// Boost
#include <boost/algorithm/string.hpp>  // for trims

// Local Includes
#include "global.hpp"
#include "jars.hpp"


const std::string do_PBKDF2( const std::string& sentence, const std::string& word )
{   
    // Use sentence and word as input to PBKDF2
    // Return hex encoded PBKDF2
    char random_bytes[64];

    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA512> pbkdf;
    pbkdf.DeriveKey(
                 // buffer that holds the derived key 
                 (byte *)random_bytes,
                 // Length of derived key in bytes
                 64,
                 // purpose byte. unused by this PBKDF implementation. 
                 0,
                 // sentence bytes (User provided) 
                 (const byte *)sentence.data(),
                 sentence.size(),
                 // word bytes (User provided. This is salt)
                 (const byte *)word.data(),
                 word.size(),
                 // iteration count
                 32768,
                 0 );

    // Hex Encode
    std::string result;
    CryptoPP::HexEncoder hexencoder;
    hexencoder.Attach( new CryptoPP::StringSink( result ) );
    hexencoder.Put( (byte*)random_bytes, sizeof(random_bytes) );
    hexencoder.MessageEnd();
    
    return result;
}


const std::string get_passwd( const std::string& sentence, const std::string& word, const std::uint32_t len )
{
    // Get PBKDF2 
    const std::string PBKDF2_hex = do_PBKDF2( sentence, word );

    // hex decode
    std::string raw_bytes;
    CryptoPP::HexDecoder hexdecoder;
    hexdecoder.Attach( new CryptoPP::StringSink( raw_bytes ) );
    hexdecoder.Put( (byte*)PBKDF2_hex.c_str(), PBKDF2_hex.size() );
    hexdecoder.MessageEnd();

    std::map<int, std::string> lower_map   = lower();
    std::map<int, std::string> upper_map   = upper();
    std::map<int, std::string> special_map = special();
    std::map<int, std::string> number_map  = numbers();

    std::queue<std::uint8_t> number_queue;

    std::string::const_iterator sit = raw_bytes.begin();
    for( sit = raw_bytes.begin(); sit != raw_bytes.end(); ++sit )
    {
        const std::uint8_t byte_number = reinterpret_cast<const std::uint8_t&>(*sit);
        number_queue.push( byte_number );

        if( DEBUG )
        {
            std::cout << "get_passwd() byte: " << (std::uint16_t)byte_number << "\n";
        }
    }

    // Randomly pick len-3 characters
    std::string result;
    std::uint32_t bits = 0;

    while( result.size() < (len-3) ) 
    {
        result += lower_map.find( number_queue.front() )->second; 
        number_queue.pop();
        bit_strength( LOWER.size(), bits );
    }

    // Add special, upper and number
    result += special_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( SPECIAL.size(), bits );

    result += upper_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( UPPER.size(), bits );

    result += number_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( NUMBERS.size(), bits );

    boost::trim( result );

    if( DEBUG ) 
    {
        std::cout << "get_passwd() bits: "             << bits                << "\n";
        std::cout << "get_passwd() result: "           << result              << "\n";
        std::cout << "get_passwd() LOWER size: "       << LOWER.size()        << "\n";
        std::cout << "get_passwd() UPPER size: "       << UPPER.size()        << "\n";
        std::cout << "get_passwd() NUMBERS size: "     << NUMBERS.size()      << "\n";
        std::cout << "get_passwd() SPECIAL size: "     << SPECIAL.size()      << "\n";
        std::cout << "get_passwd() lower_map size: "   << lower_map.size()    << "\n";
        std::cout << "get_passwd() upper_map size: "   << upper_map.size()    << "\n";
        std::cout << "get_passwd() special_map size: " << special_map.size()  << "\n";
        std::cout << "get_passwd() number_map size: "  << number_map.size()   << "\n";
        std::cout << "get_passwd() number_que size: "  << number_queue.size() << "\n";
        std::cout << "get_passwd() PBKDF2_hex: "       << PBKDF2_hex          << "\n";
        std::cout << "get_passwd() sentence: "         << sentence            << "\n";
        std::cout << "get_passwd() word: "             << word                << "\n";
        std::cout << "get_passwd() len: "              << len                 << "\n";
        std::cout << "----------------- "              << "\n";
    }

    return result;
}

const std::string get_passphrase( const std::string& sentence, const std::string& word, const std::uint32_t len )
{
    // Get PBKDF2 
    const std::string PBKDF2_hex = do_PBKDF2( sentence, word );

    // hex decode
    std::string raw_bytes;
    CryptoPP::HexDecoder hexdecoder;
    hexdecoder.Attach( new CryptoPP::StringSink( raw_bytes ) );
    hexdecoder.Put( (byte*)PBKDF2_hex.c_str(), PBKDF2_hex.size() );
    hexdecoder.MessageEnd();

    std::map<int, std::string> word_map    = words();
    std::map<int, std::string> upper_map   = upper();
    std::map<int, std::string> special_map = special();
    std::map<int, std::string> number_map  = numbers();

    std::queue<std::uint8_t> number_queue;

    std::string::const_iterator sit = raw_bytes.begin();
    for( sit = raw_bytes.begin(); sit != raw_bytes.end(); ++sit )
    {
        const std::uint8_t byte_number = reinterpret_cast<const std::uint8_t&>(*sit);
        number_queue.push( byte_number );

        if( DEBUG )
        {
            std::cout << "get_passphrase() byte: " << (std::uint16_t)byte_number << "\n";
        }
    }

    // Randomly pick len words
    std::string result;
    std::uint32_t bits = 0;
    
    std::uint32_t i = 0;
    while( i < len ) 
    {
        result += word_map.find( number_queue.front() )->second; 
        number_queue.pop();
        ++i;
        bit_strength( word_map.size(), bits );
    }

    // Add special, upper and number
    result += special_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( SPECIAL.size(), bits );

    result += upper_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( UPPER.size(), bits );

    result += number_map.find( number_queue.front() )->second; 
    number_queue.pop();
    bit_strength( NUMBERS.size(), bits );

    boost::trim( result );

    if( DEBUG ) 
    {
        std::cout << "get_passphrase() bits: "             << bits                << "\n";
        std::cout << "get_passphrase() result: "           << result              << "\n";
        std::cout << "get_passphrase() WORDS size: "       << WORDS.size()        << "\n";
        std::cout << "get_passphrase() UPPER size: "       << UPPER.size()        << "\n";
        std::cout << "get_passphrase() NUMBERS size: "     << NUMBERS.size()      << "\n";
        std::cout << "get_passphrase() SPECIAL size: "     << SPECIAL.size()      << "\n";
        std::cout << "get_passphrase() word_map size: "    << word_map.size()     << "\n";
        std::cout << "get_passphrase() upper_map size: "   << upper_map.size()    << "\n";
        std::cout << "get_passphrase() special_map size: " << special_map.size()  << "\n";
        std::cout << "get_passphrase() number_map size: "  << number_map.size()   << "\n";
        std::cout << "get_passphrase() number_que size: "  << number_queue.size() << "\n";
        std::cout << "get_passphrase() PBKDF2_hex: "       << PBKDF2_hex          << "\n";
        std::cout << "get_passphrase() sentence: "         << sentence            << "\n";
        std::cout << "get_passphrase() word: "             << word                << "\n";
        std::cout << "get_passphrase() len: "              << len                 << "\n";
        std::cout << "--------------------- "              << "\n";
    }

    return result;
}

std::string readable( const std::string& password )
{
    std::uint32_t x = 0;
    std::string readablePassword = "";

    while( x < password.length() )
    {
        readablePassword += password.substr(x, 3) + " ";
        if (DEBUG)
        {
            std::cout << "readable() part: " << readablePassword << "\n";
        }
        x += 3;
    }

    boost::trim( readablePassword );

    if (DEBUG)
    {
        std::cout << "readable() password: "         << password         << "\n";
        std::cout << "readable() readablePassword: " << readablePassword << "\n";
    }

    return readablePassword;
}

