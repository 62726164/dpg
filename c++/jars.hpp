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

#include <cmath>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "charsets.hpp"
#include "global.hpp"

void bit_strength( std::uint32_t char_set_size, std::uint32_t& total )
{
    std::uint32_t bits_per_char = log( char_set_size ) / log(2);
    total = total + bits_per_char;
}

std::map<int, std::string> special()
{
    // 3 bits per pick
    std::map<int, std::string> mp;
    std::vector<std::string>::const_iterator vit = SPECIAL.begin();

    while( mp.size() < 256 )
    {
        for( vit = SPECIAL.begin(); vit != SPECIAL.end(); ++vit )
        {
            mp.insert(std::pair<int, std::string>(mp.size(), *vit));
        }
    }

    return mp;
}

std::map<int, std::string> numbers()
{
    // 3 bits per pick
    std::map<int, std::string> mp;
    std::vector<std::string>::const_iterator vit = NUMBERS.begin();

    while( mp.size() < 256 )
    {
        for( vit = NUMBERS.begin(); vit != NUMBERS.end(); ++vit )
        {
            mp.insert(std::pair<int, std::string>(mp.size(), *vit));
        }
    }

    return mp;
}

std::map<int, std::string> lower()
{
    // 4 bits per pick
    std::map<int, std::string> mp;
    std::vector<std::string>::const_iterator vit = LOWER.begin();

    while( mp.size() < 256 )
    {
        for( vit = LOWER.begin(); vit != LOWER.end(); ++vit )
        {
            mp.insert(std::pair<int, std::string>(mp.size(), *vit));
        }
    }

    return mp;
}

std::map<int, std::string> upper()
{
    // 4 bits per pick
    std::map<int, std::string> mp;
    std::vector<std::string>::const_iterator vit = UPPER.begin();

    while( mp.size() < 256 )
    {
        for( vit = UPPER.begin(); vit != UPPER.end(); ++vit )
        {
            mp.insert(std::pair<int, std::string>(mp.size(), *vit));
        }
    }

    return mp;
}

std::map<int, std::string> words()
{
    // 8 bits per pick
    std::map<int, std::string> mp;
    std::vector<std::string>::const_iterator vit = WORDS.begin();

    for( vit = WORDS.begin(); vit != WORDS.end(); ++vit )
    {
        mp.insert(std::pair<int, std::string>(mp.size(), *vit));
    }

    return mp;
}

