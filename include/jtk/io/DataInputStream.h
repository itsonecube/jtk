// Saturday, June 09, 2018
// Monday, May 27, 2019

#ifndef JTK_IO_DATA_INPUT_STREAM_H
#define JTK_IO_DATA_INPUT_STREAM_H

#include <jtk/Configuration.h>
#include <jtk/io/InputStream.h>

/*******************************************************************************
 * DataInputStream                                                          *
 *******************************************************************************/

/**
 * @class DataInputStream
 * @ingroup jtk_io
 * @author Samuel Rowe
 * @since jtk 1.1
 */
struct jtk_DataInputStream_t {
    jtk_InputStream_t* m_inputStream;
    jtk_InputStream_t* m_sourceInputStream;
};

/**
 * @memberof DataInputStream
 */
typedef struct jtk_DataInputStream_t jtk_DataInputStream_t;

/* Constructor */

/**
 * @memberof DataInputStream
 */
jtk_DataInputStream_t* jtk_DataInputStream_new(jtk_InputStream_t* sourceInputStream);

/* Destructor */

/**
 * @memberof DataInputStream
 */
void jtk_DataInputStream_delete(jtk_DataInputStream_t* stream);

/* Available */

int32_t jtk_DataInputStream_getAvailable(jtk_DataInputStream_t* stream);

/* Close */

void jtk_DataInputStream_close(jtk_DataInputStream_t* stream);

/* Read */

/**
 * @memberof DataInputStream
 */
int32_t jtk_DataInputStream_read(jtk_DataInputStream_t* stream);

/**
 * @memberof DataInputStream
 */
int32_t jtk_DataInputStream_readBytes(jtk_DataInputStream_t* stream, uint8_t* buffer, int32_t size);

/**
 * @memberof DataInputStream
 */
int32_t jtk_DataInputStream_readBytesEx(jtk_DataInputStream_t* stream, uint8_t* buffer, int32_t size, int32_t index, int32_t limit);

/* Read Data */

/**
 * @memberof DataInputStream
 */
int16_t jtk_DataInputStream_readShort(jtk_DataInputStream_t* stream);

/**
 * @memberof DataInputStream
 */
int32_t jtk_DataInputStream_readInteger(jtk_DataInputStream_t* stream);

/**
 * @memberof DataInputStream
 */
int64_t jtk_DataInputStream_readLong(jtk_DataInputStream_t* stream);

/**
 * @memberof DataInputStream
 */
float jtk_DataInputStream_readFloat(jtk_DataInputStream_t* stream);

/**
 * @memberof DataInputStream
 */
double jtk_DataInputStream_readDouble(jtk_DataInputStream_t* stream);

/* Skip */

/**
 * @memberof DataInputStream
 */
int64_t jtk_DataInputStream_skip(jtk_DataInputStream_t* stream, int64_t count);

#endif /* JTK_IO_DATA_INPUT_STREAM_H */