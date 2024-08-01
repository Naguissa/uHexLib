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
#ifndef _uHexLib_h_
    #define _uHexLib_h_

    #include <Arduino.h>

    typedef struct uHexLib2Bytes {
        uint8_t a;
        uint8_t b;
    } uHexLib2Bytes;

    class uHexLib {
        public:
            static uHexLib2Bytes encode(const uint8_t);
            static uint8_t decode(const uint8_t, const uint8_t);
        private:
            // Purely static methods
            uHexLib();
    };

#endif
