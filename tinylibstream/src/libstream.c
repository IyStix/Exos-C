#define _POSIX_C_SOURCE 200809L

#include "libstream.h"

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int flag(const char *mode)
{
    if (!strcmp(mode, "r"))
        return O_RDONLY;
    else if (!strcmp(mode, "w"))
        return O_WRONLY | O_CREAT | O_TRUNC;
    else if (!strcmp(mode, "r+"))
        return O_RDWR;
    else if (!strcmp(mode, "w+"))
        return O_RDWR | O_CREAT | O_TRUNC;
    else
        return -2;
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0)
        return NULL;

    int flags = flag(mode);

    if (flags == -2)
        return NULL;

    struct stream *stream = malloc(sizeof(struct stream));

    if (!stream)
        return NULL;

    stream->fd = fd;
    stream->error = 0;
    stream->flags = flags;
    stream->io_operation = STREAM_READING;
    stream->buffered_size = 0;
    stream->already_read = 0;

    stream->buffering_mode =
        isatty(fd) ? STREAM_LINE_BUFFERED : STREAM_BUFFERED;

    return stream;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int flags = flag(mode);
    if (flags == -2)
        return NULL;
    int fd = open(path, flags, 0666);
    if (fd == -1)
        return NULL;
    struct stream *stream = lbs_fdopen(fd, mode);
    if (!stream)
    {
        close(fd);
        return NULL;
    }
    return stream;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return 0;

    if (stream->io_operation == STREAM_WRITING && stream->buffered_size > 0)
    {
        ssize_t written =
            write(stream->fd, stream->buffer, stream->buffered_size);
        if (written == -1)
        {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->buffered_size = 0;
    }
    else if (stream->io_operation == STREAM_READING
             && stream->buffered_size > stream->already_read)
    {
        off_t offset = stream->already_read - stream->buffered_size;
        if (lseek(stream->fd, offset, SEEK_CUR) == -1)
        {
            stream->error = 1;
            return LBS_EOF;
        }
        stream->buffered_size = 0;
        stream->already_read = 0;
    }
    return 0;
}

int lbs_fclose(struct stream *stream)
{
    if (!stream)
        return LBS_EOF;

    int result = lbs_fflush(stream);
    if (result == LBS_EOF)
        return LBS_EOF;

    if (close(stream->fd) == -1)
    {
        free(stream);
        return LBS_EOF;
    }

    free(stream);
    return 0;
}

int lbs_fputc(int c, struct stream *stream)
{
    if (!stream_writable(stream))
    {
        stream->error = 1;
        return LBS_EOF;
    }

    if (stream->io_operation == STREAM_READING)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
        stream->io_operation = STREAM_WRITING;
    }

    stream->buffer[stream->buffered_size++] = c;

    if (stream->buffering_mode == STREAM_UNBUFFERED
        || (stream->buffering_mode == STREAM_LINE_BUFFERED
            && (c == '\n' || stream->buffered_size == LBS_BUFFER_SIZE))
        || stream->buffered_size == LBS_BUFFER_SIZE)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
    }

    return c & 0xFF;
}

int lbs_fgetc(struct stream *stream)
{
    if (!stream_readable(stream))
    {
        stream->error = 1;
        return LBS_EOF;
    }

    if (stream->io_operation == STREAM_WRITING)
    {
        if (lbs_fflush(stream) == LBS_EOF)
            return LBS_EOF;
        stream->io_operation = STREAM_READING;
    }

    if (stream->already_read == stream->buffered_size)
    {
        ssize_t bytes_read = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            if (bytes_read == -1)
                stream->error = 1;
            return LBS_EOF;
        }
        stream->buffered_size = bytes_read;
        stream->already_read = 0;
    }

    int result = stream->buffer[stream->already_read++];
    return result & 0xFF;
}
