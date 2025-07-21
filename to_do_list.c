#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task
{
    char description[100];
    struct task *next;
};

struct task *head = NULL;

void insert_task()
{
    int n;
    printf("How many tasks do you want to add? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct task *new_task = (struct task *)malloc(sizeof(struct task));
        if (!new_task)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter task %d: ", i + 1);
        scanf(" %[^\n]", new_task->description);
        new_task->next = NULL;

        if (head == NULL)
        {
            head = new_task;
        }
        else
        {
            struct task *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_task;
        }
    }
}

void delete_task()
{
    int n;
    printf("How many tasks do you want to remove? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            printf("No tasks left to remove!\n");
            return;
        }
        struct task *temp = head;
        head = head->next;
        free(temp);
    }
}

void display_tasks()
{
    if (head == NULL)
    {
        printf("To-Do List is empty!\n");
        return;
    }
    struct task *temp = head;
    printf("\nTo-Do List:\n");
    while (temp != NULL)
    {
        printf("- %s\n", temp->description);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Tasks\n");
        printf("2. Remove Tasks\n");
        printf("3. View To-Do List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_task();
            break;
        case 2:
            delete_task();
            break;
        case 3:
            display_tasks();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
