#ifndef MEM_H_
#define MEM_H_
#define new(obj) malloc(sizeof(*(obj)))
#define array(obj, len) malloc(sizeof(*(obj)) * len)
#define string(len) malloc(sizeof(char*) * (len + 1))
#endif
