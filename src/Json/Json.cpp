#include "Json.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void json_cevir(
    char* buffer,
    size_t bufferSize,
    uint8_t adet,
    ...
) {
    size_t idx = 0;
    buffer[idx++] = '{';

    va_list args;
    va_start(args, adet);

    for (uint8_t i = 0; i < adet; i++) {
        const char* key = va_arg(args, const char*);
        // bir sonraki argüman tipine bak, int mi string mi? 
        // Burada basitçe char* string mi kontrolü yok, çağıran bilsin.
        // Biz iki fonksiyon overload'u ile çözebiliriz veya her zaman char* string kullan
        void* val = va_arg(args, void*);
        if (((uintptr_t)val) < 0xFFFF) {
            // küçük sayıları int kabul et
            idx += snprintf(buffer + idx, bufferSize - idx, "\"%s\":%d", key, (int)val);
        } else {
            // string pointer ise
            idx += snprintf(buffer + idx, bufferSize - idx, "\"%s\":\"%s\"", key, (const char*)val);
        }

        if (i < adet - 1) buffer[idx++] = ',';
    }

    va_end(args);
    buffer[idx++] = '}';
    buffer[idx] = '\0';
}
