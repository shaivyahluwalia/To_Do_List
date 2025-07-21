#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char description[100];
    int occupied;
} Task;

Task table[100];
int table_size;

void initializeTable() {
    for (int i = 0; i < table_size; i++) {
        table[i].occupied = 0;
    }
}

int hashFunction(int id) {
    return id % table_size;
}

void insertTask(int id, char* description) {
    int index = hashFunction(id);
    while (table[index].occupied) {
        index = (index + 1) % table_size;
        if (index == hashFunction(id)) {
            printf("Table is full!\n");
            return;
        }
    }
    table[index].id = id;
    strcpy(table[index].description, description);
    table[index].occupied = 1;
    printf("Task added!\n");
}

void deleteTask(int id) {
    int index = hashFunction(id);
    while (table[index].occupied) {
        if (table[index].id == id) {
            table[index].occupied = 0;
            printf("Task deleted!\n");
            return;
        }
        index = (index + 1) % table_size;
    }
    printf("Task not found!\n");
}

void displayTasks() {
    for (int i = 0; i < table_size; i++) {
         
            printf("Task %d: %s\n", table[i].id, table[i].description);
        
    }
}

int main() {
    int choice, id;
    char description[100];
    
    printf("Enter table size: ");
    scanf("%d", &table_size);
    initializeTable();
    
    while (1) {
        printf("\n1. Add Task\n2. Delete Task\n3. Display Tasks\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0;
                insertTask(id, description);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteTask(id);
                break;
            case 3:
                displayTasks();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
