/**
 * \class uHexLib
 * \brief Arduino (and standard C) tiny and cross-device compatible hexadecimal coding/decoding library.
 *
 * You have this new type used as return type of encoding, which has 2 chars, named 'a' and 'b':
 *      * uHexLib2Bytes: { char a; char b; }
 *
 * You have uHexLib class with following static methods:
 *	* *uHexLib2Bytes uHexLib::encode(const char);* : Given one char it encodes it to 2 base64 chars and returns the struct
 *	* *char uHexLib::decode(const char inA, const char inB);* : Given two base64 chars it decodes and returns them as 1 char
 *
 *	* *uint16_t uHexLib::encode(const char in[], char out[], uint16_t optionalInLength = 0);* : Given one char array it encodes it to other twice the size in base64. You can optionally specify input array size.
 *	* *uint16_t  uHexLib::decode(const char in[], char out[], uint16_t optionalInLength = 0);* : Given one base64 char array it decodes it to other half the size. You can optionally specify input array size.
 *
 * @file uHexLib.cpp
 * @copyright Naguissa
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uHexLib">https://github.com/Naguissa/uHexLib</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 2.2.0
 */
#include "uHexLib.h"

uHexLib::uHexLib() {}

uHexLib2Bytes uHexLib::encode(const char in) {
    uHexLib2Bytes hexEncodeRet;
    char part = in >> 4;
    // MSB
    hexEncodeRet.a = (
        (part < 10) ?
        ('0' + part) :
        ('A' - 10 + part)
    );
    // LSB
    part = in & 0b00001111;
    hexEncodeRet.b = (
        (part < 10) ?
        ('0' + part) :
        ('A' - 10 + part)
    );
    return hexEncodeRet;
}

char uHexLib::_decodeHalf(const char in) {
    if (in >= '0' && in <= '9') return (in - '0');
    if (in >= 'A' && in <= 'F') return (in - 'A' +10);
    if (in >= 'a' && in <= 'f') return (in - 'a' +10);
    return 0;
}



char uHexLib::decode(const char inA, const char inB) {
    return (_decodeHalf(inA) << 4) + _decodeHalf(inB);
}


uint16_t uHexLib::encode(const char original[], char encoded[], uint16_t originalLength) {
    uint16_t i;
    uHexLib2Bytes res;
    for (
        i = 0;
        (original[i] != 0 && originalLength == 0) || i < originalLength;
        i++
    ) {
        res = uHexLib::encode(original[i]);
        encoded[2*i] = res.a;
        encoded[2*i + 1] = res.b;
    }
    encoded[2*i] = 0;
    return i;
}

uint16_t uHexLib::decode(const char original[], char decoded[], uint16_t originalLength) {
    uint16_t i;
    for (
        i = 0;
        (original[2*i] != 0 && originalLength == 0) || i < originalLength;
        i++
    ) {
        decoded[i] = uHexLib::decode(original[2*i], original[2*i + 1]);
    }
    decoded[i] = 0;
    return i;
}
