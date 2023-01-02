#pragma once
#include <QtGlobal>

qint8  CRC8(const char* data, const qint32 length);
qint16 CRC16(const char* data, const qint32 length);
qint32 CRC32(const char* data, const qint32 length);
