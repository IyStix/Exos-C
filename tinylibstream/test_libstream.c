#include "libstream.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEST_FILE "test_file.txt"
#define TEST_DATA "Hello, Tiny Libstream!"
#define BUFFER_SIZE 1024

void test_fopen_fclose(void);
void test_fdopen(void);
void test_fputc_fgetc(void);
void test_fflush(void);
void test_buffering_modes(void);
void test_error_handling(void);

void test_fopen_fclose(void)
{
    struct stream *stream = lbs_fopen(TEST_FILE, "w");
    assert(stream != NULL);
    assert(lbs_fclose(stream) == 0);

    stream = lbs_fopen(TEST_FILE, "r");
    assert(stream != NULL);
    assert(lbs_fclose(stream) == 0);

    assert(lbs_fopen("non_existent_directory/file.txt", "r") == NULL);
    
    printf("test_fopen_fclose: PASSED\n");
}

void test_fdopen(void)
{
    int fd = open(TEST_FILE, O_RDONLY);
    assert(fd != -1);
    
    struct stream *stream = lbs_fdopen(fd, "r");
    assert(stream != NULL);
    assert(lbs_fclose(stream) == 0);

    assert(lbs_fdopen(-1, "r") == NULL);
    
    printf("test_fdopen: PASSED\n");
}

void test_fputc_fgetc(void)
{
    struct stream *stream = lbs_fopen(TEST_FILE, "w+");
    assert(stream != NULL);

    for (size_t i = 0; i < strlen(TEST_DATA); i++)
    {
        assert(lbs_fputc(TEST_DATA[i], stream) == TEST_DATA[i]);
    }

    assert(lbs_fflush(stream) == 0);
    
    // Reset file position to beginning
    lseek(stream->fd, 0, SEEK_SET);

    for (size_t i = 0; i < strlen(TEST_DATA); i++)
    {
        assert(lbs_fgetc(stream) == TEST_DATA[i]);
    }

    assert(lbs_fgetc(stream) == LBS_EOF);
    assert(lbs_fclose(stream) == 0);
    
    printf("test_fputc_fgetc: PASSED\n");
}

void test_fflush(void)
{
    struct stream *stream = lbs_fopen(TEST_FILE, "w");
    assert(stream != NULL);

    for (size_t i = 0; i < strlen(TEST_DATA); i++)
    {
        assert(lbs_fputc(TEST_DATA[i], stream) == TEST_DATA[i]);
    }

    assert(lbs_fflush(stream) == 0);
    assert(lbs_fclose(stream) == 0);

    // Verify data was written
    char buffer[BUFFER_SIZE];
    int fd = open(TEST_FILE, O_RDONLY);
    assert(fd != -1);
    ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    assert(bytes_read == (ssize_t)strlen(TEST_DATA));
    assert(memcmp(buffer, TEST_DATA, strlen(TEST_DATA)) == 0);
    close(fd);
    
    printf("test_fflush: PASSED\n");
}

void test_buffering_modes(void)
{
    struct stream *stream = lbs_fopen(TEST_FILE, "w");
    assert(stream != NULL);

    // Test unbuffered mode
    lbs_setbufmode(stream, STREAM_UNBUFFERED);
    assert(lbs_fputc('A', stream) == 'A');
    assert(stream->buffered_size == 0); // Should be flushed immediately

    // Test line buffered mode
    lbs_setbufmode(stream, STREAM_LINE_BUFFERED);
    assert(lbs_fputc('B', stream) == 'B');
    assert(stream->buffered_size == 1);
    assert(lbs_fputc('\n', stream) == '\n');
    assert(stream->buffered_size == 0); // Should be flushed after newline

    // Test fully buffered mode
    lbs_setbufmode(stream, STREAM_BUFFERED);
    for (int i = 0; i < LBS_BUFFER_SIZE; i++)
    {
        assert(lbs_fputc('C', stream) == 'C');
    }
    assert(stream->buffered_size == 0); // Should be flushed when buffer is full

    assert(lbs_fclose(stream) == 0);
    
    printf("test_buffering_modes: PASSED\n");
}

void test_error_handling(void)
{
    struct stream *stream = lbs_fopen(TEST_FILE, "r");
    assert(stream != NULL);

    // Try to write to read-only stream
    assert(lbs_fputc('A', stream) == LBS_EOF);
    assert(lbs_ferror(stream) != 0);

    lbs_clearerr(stream);
    assert(lbs_ferror(stream) == 0);

    assert(lbs_fclose(stream) == 0);

    // Try to read from write-only stream
    stream = lbs_fopen(TEST_FILE, "w");
    assert(stream != NULL);
    assert(lbs_fgetc(stream) == LBS_EOF);
    assert(lbs_ferror(stream) != 0);

    assert(lbs_fclose(stream) == 0);
    
    printf("test_error_handling: PASSED\n");
}

int main(void)
{
    test_fopen_fclose();
    test_fdopen();
    test_fputc_fgetc();
    test_fflush();
    test_buffering_modes();
    test_error_handling();

    printf("All tests passed successfully!\n");
    return 0;
}
