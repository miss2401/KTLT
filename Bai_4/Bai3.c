//Name
//MSSV
//Class
//3.Tìm kiếm bằng bảng băm
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10   
#define EMPTY   -1        
#define DELETED   -2   
 
typedef struct {
    int key;
    int value;  
} HashItem;

typedef struct {
    HashItem table[TABLE_SIZE];
} HashMap;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initHashMap(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i].key = EMPTY;
        map->table[i].value = 0;
    }
}

int* search(HashMap *map, int key) {
    int index = hashFunction(key);
    int start_index = index;
    while (map->table[index].key != EMPTY) {
        if (map->table[index].key == key && map->table[index].key != DELETED) {
            return &map->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index)   
            break;
    }
    return NULL;
}

void insert(HashMap *map, int key, int value) {
    if (search(map, key) != NULL) {
        printf("Key %d da ton tai.\n", key);
        return;
    }
    int index = hashFunction(key);
    while (map->table[index].key != EMPTY && map->table[index].key != DELETED) {
        index = (index + 1) % TABLE_SIZE;
    }
    map->table[index].key = key;
    map->table[index].value = value;
}


void display(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (map->table[i].key == EMPTY)
            printf("EMPTY\n");
        else
            printf("(%d : %d)\n", map->table[i].key, map->table[i].value);
    }
}

int main() {
    HashMap map;

    initHashMap(&map);
    insert(&map, 5, 100);
    insert(&map, 15, 200); 
    insert(&map, 25, 300);
    insert(&map, 8, 400);
    display(&map);

    int* val = search(&map, 15);
    if (val != NULL)
        printf("\nGia tri cua key 15: %d\n", *val);
    else
        printf("\nKhong tim thay key 15.\n");

    return 0;
}