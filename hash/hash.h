#ifndef hash_H
#define hash_H

typedef struct{
    char *key;
    char *value;

}hash_item;

typedef struct{
    int size;
    int count;
    hash_item** items;

}hash_table;

static hash_item* new_hash_item();

hash_table* new_hash_table();

static void destroy_item();

void destroy_table();

static int hash();

void hash_insert();

char* hash_search();

void hash_delete();

void hash_new_sized();

void hash_resize();

void hash_size_inc();

void hash_size_dec();

#endif