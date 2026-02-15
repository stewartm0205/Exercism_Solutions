#include "circular_buffer.h"

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

circular_buffer_t * new_circular_buffer(size_t capacity){
    circular_buffer_t * cb = malloc(sizeof(circular_buffer_t));  
    cb->capacity = capacity;
    cb->count = 0;
    cb->read_pos = 0;
    cb->write_pos = cb->read_pos;
    cb->values = malloc(capacity*sizeof(buffer_value_t));
    return cb;

}
int16_t read(circular_buffer_t* buffer, buffer_value_t* read_value){
    if (buffer->count == 0) { 
        errno=ENODATA;
        return 1;
    }
    *read_value = buffer->values[buffer->read_pos];
    buffer->values[buffer->read_pos]=-1; // clear after read
    buffer->count--;
    buffer->read_pos++;
    if (buffer->read_pos ==  buffer->capacity) buffer->read_pos=0;
    return 0;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t write_value){
    if (buffer->count == buffer->capacity) {
        errno = ENOBUFS;
        return 1;
    }    
    buffer->count++;
    buffer->values[buffer->write_pos]=write_value;
    buffer->write_pos++;
    if (buffer->write_pos ==  buffer->capacity) buffer->write_pos=0;
    return 0;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t write_value){
    if (buffer->count < buffer->capacity) {
        return write(buffer, write_value);
    }
    buffer->values[buffer->read_pos]=-1;
    buffer->read_pos++;
    if (buffer->read_pos ==  buffer->capacity) buffer->read_pos=0;
    buffer->values[buffer->write_pos]=write_value;
    buffer->write_pos++;
    if (buffer->write_pos == buffer->capacity) buffer->write_pos=0;
    return 0;
}

void clear_buffer(circular_buffer_t* buffer){
    buffer->count=0;
    buffer->read_pos = buffer->capacity/2;
    buffer->write_pos = buffer->read_pos;
}
void delete_buffer(circular_buffer_t* buffer){
    free(buffer);
}
