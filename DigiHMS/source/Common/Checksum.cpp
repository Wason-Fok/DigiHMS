#include "Checksum.h"

qint8 CRC8(const char* data, const qint32 length)
{
	qint8 crc = 0xff;
	for (qint32 i = 0; i < length; i++)
	{
		crc ^= data[i];
		for (qint32 j = 0; j < 8; j++)
		{
			if ((crc & 0x80) != 0)
			{
				crc = (qint8)((crc << 1) ^ 0x31);
			}
			else
			{
				crc <<= 1;
			}
		}
	}
}

qint16 CRC16(const char* data, const qint32 length)
{
	qint8 x;
	qint16 crc = 0xFFFF;

	for (qint32 i = 0; i < length; ++i)
	{
		x = crc >> 8 ^ data[i];
		x ^= x >> 4;
		crc = (crc << 8) ^ ((qint16)(x << 12)) ^ ((qint16)(x << 5)) ^ ((qint16)x);
	}

	return crc;
}

qint32 CRC32(const char* data, const qint32 length)
{
	qint32 mask;
	qint32 crc = 0xFFFFFFFF;
	for (qint32 i = 0; i < length; ++i)
	{
		crc = crc ^ data[i];
		for (qint32 j = 8; j >= 0; j--)
		{
			mask = -(crc & 1);
			crc = (crc >> 1) ^ (0xEDB88320 & mask);
		}
	}

	return ~crc;
}
