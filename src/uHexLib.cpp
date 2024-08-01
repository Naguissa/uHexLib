/**
 * \class uHexLib
 * \brief Arduino (and standard C) tiny and cross-device compatible hexadecimal coding/decoding library.
 *
 * You have this new type used as return type of encoding, which has 2 bytes, named 'a' and 'b':
 *      * uHexLib2Bytes: { uint8_t a; uint8_t b; }
 *
 * You have uHexLib class with following static methods:
 *	* *uHexLib2Bytes uHexLib::encode(const uint8_t);* : Given one byte it encodes it to 2 base64 bytes and returns the struct
 *	* *uint8_t uHexLib::decode(const uint8_t inA, const uint8_t inB);* : Given two base64 bytes it decodes and returns them as 1 byte
 *
 * @file uHexLib.cpp
 * @copyright Naguissa
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uHexLib">https://github.com/Naguissa/uHexLib</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 1.0.0
 */
#include "uHexLib.h"

uHexLib::uHexLib() {}

uHexLib2Bytes uHexLib::encode(const uint8_t in) {
    uHexLib2Bytes hexEncodeRet;
    switch (in >> 4) {
        case 0: hexEncodeRet.a = '0'; break;
        case 1: hexEncodeRet.a = '1'; break;
        case 2: hexEncodeRet.a = '2'; break;
        case 3: hexEncodeRet.a = '3'; break;
        case 4: hexEncodeRet.a = '4'; break;
        case 5: hexEncodeRet.a = '5'; break;
        case 6: hexEncodeRet.a = '6'; break;
        case 7: hexEncodeRet.a = '7'; break;
        case 8: hexEncodeRet.a = '8'; break;
        case 9: hexEncodeRet.a = '9'; break;
        case 10: hexEncodeRet.a = 'A'; break;
        case 11: hexEncodeRet.a = 'B'; break;
        case 12: hexEncodeRet.a = 'C'; break;
        case 13: hexEncodeRet.a = 'D'; break;
        case 14: hexEncodeRet.a = 'E'; break;
        case 15: default: hexEncodeRet.a = 'F'; break;
    }

    switch (in & 0b00001111) {
        case 0: hexEncodeRet.b = '0'; break;
        case 1: hexEncodeRet.b = '1'; break;
        case 2: hexEncodeRet.b = '2'; break;
        case 3: hexEncodeRet.b = '3'; break;
        case 4: hexEncodeRet.b = '4'; break;
        case 5: hexEncodeRet.b = '5'; break;
        case 6: hexEncodeRet.b = '6'; break;
        case 7: hexEncodeRet.b = '7'; break;
        case 8: hexEncodeRet.b = '8'; break;
        case 9: hexEncodeRet.b = '9'; break;
        case 10: hexEncodeRet.b = 'A'; break;
        case 11: hexEncodeRet.b = 'B'; break;
        case 12: hexEncodeRet.b = 'C'; break;
        case 13: hexEncodeRet.b = 'D'; break;
        case 14: hexEncodeRet.b = 'E'; break;
        case 15: default: hexEncodeRet.b = 'F'; break;
    }
    return hexEncodeRet;
}


byte uHexLib::decode(const uint8_t inA, const uint8_t inB) {
  byte ret = 0;
  switch (inA) {
    case '0': break;
    case '1': ret = 0b00010000; break;
    case '2': ret = 0b00100000; break;
    case '3': ret = 0b00110000; break;
    case '4': ret = 0b01000000; break;
    case '5': ret = 0b01010000; break;
    case '6': ret = 0b01100000; break;
    case '7': ret = 0b01110000; break;
    case '8': ret = 0b10000000; break;
    case '9': ret = 0b10010000; break;
    case 'A': ret = 0b10100000; break;
    case 'B': ret = 0b10110000; break;
    case 'C': ret = 0b11000000; break;
    case 'D': ret = 0b11010000; break;
    case 'E': ret = 0b11100000; break;
    case 'F': default: ret = 0b11110000; break;
  }

  switch (inB) {
    case '0': break;
    case '1': ret |= 0b00000001; break;
    case '2': ret |= 0b00000010; break;
    case '3': ret |= 0b00000011; break;
    case '4': ret |= 0b00000100; break;
    case '5': ret |= 0b00000101; break;
    case '6': ret |= 0b00000110; break;
    case '7': ret |= 0b00000111; break;
    case '8': ret |= 0b00001000; break;
    case '9': ret |= 0b00001001; break;
    case 'A': ret |= 0b00001010; break;
    case 'B': ret |= 0b00001011; break;
    case 'C': ret |= 0b00001100; break;
    case 'D': ret |= 0b00001101; break;
    case 'E': ret |= 0b00001110; break;
    case 'F': default: ret |= 0b00001111; break;
  }
  return ret;
}
