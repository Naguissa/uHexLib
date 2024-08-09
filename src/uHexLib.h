/**
 * \class uHexLib
 * \brief Arduino (and standard C) tiny and cross-device compatible hexadecimal coding/decoding library.
 *
 * You have this new type used as return type of encoding, which has 2 bytes, named 'a' and 'b':
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
#ifndef _uHexLib_h_
    #define _uHexLib_h_

    #include <Arduino.h>

    typedef struct uHexLib2Bytes {
        char a;
        char b;
    } uHexLib2Bytes;

    class uHexLib {
        public:
            static uHexLib2Bytes encode(const char);
            static uint16_t encode(const char [], char []);
            static char decode(const char, const char);
            static uint16_t decode(const char [], char []);
        private:
            // Purely static methods
            uHexLib();
    };

#endif
