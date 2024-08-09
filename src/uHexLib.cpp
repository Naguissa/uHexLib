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
 *	* *uint16_t uHexLib::encode(const char in[], char out[]);* : Given one char it encodes it to 2 base64 chars and returns the struct
 *	* *uint16_t  uHexLib::decode(const char in[], char out[]);* : Given two base64 chars it decodes and returns them as 1 char
 *
 * @file uHexLib.cpp
 * @copyright Naguissa
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uHexLib">https://github.com/Naguissa/uHexLib</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 2.0.0
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


char uHexLib::decode(const char inA, const char inB) {
    // MSB
    char ret = (
        inA < 'A' ?
        (inA - '0') :
        (inA - 'A' + 10)
    );
    ret = ret << 4;
    // LSB
    ret += (
        inB < 'A' ?
        (inB - '0') :
        (inB - 'A' + 10)
    );
    return ret;
}


uint16_t uHexLib::encode(const char original[], char encoded[]) {
    uint16_t i;
    uHexLib2Bytes res;
    for (i = 0; original[i] != 0; i++) {
        res = uHexLib::encode(original[i]);
        encoded[2*i] = res.a;
        encoded[2*i + 1] = res.b;
    }
    encoded[2*i] = 0;
    return i;
}

uint16_t uHexLib::decode(const char original[], char decoded[]) {
    uint16_t i;
    for (i = 0; original[2*i] != 0; i++) {
        decoded[i] = uHexLib::decode(original[2*i], original[2*i + 1]);
    }
    decoded[i] = 0;
    return i;
}
