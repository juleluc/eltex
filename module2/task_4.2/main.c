#include "main.h"


int main(){
    int value, pr;
    int choice;


    enqueue(1000, 54);
    enqueue(542, 15);
    enqueue(3, 200);
    enqueue(762, 255);
    enqueue(0, 147);
    enqueue(9, 121);

    while (1){

        display_menu();
        
        if (scanf("%d", &choice) != 1){
            printf("Некорректный ввод\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice){
        case 1:{
            printf("Вывести очередь\n");
            print_queue();
            break;
        }
        case 2:{

            printf("Введите значение и приоритет\n");
            if (scanf("%d %d", &value, &pr) != 2){
                printf("Некорректный ввод\n");
                continue;
            }
            enqueue(value, pr);
            print_queue();
            break;
        }
        case 3:{
            int deq_value = dequeue_first();
            if (deq_value != -1)
            {
                printf("Извлеченный первый элемент: %d\n\n", deq_value);
            }
            print_queue();
            break;
        }
        case 4:{
            printf("Введите приоритет\n");
            scanf("%d", &pr);
            dequeue_priority(pr);
            print_queue();
            break;
        }
        case 5:{
            printf("Введите приоритет\n");
            if (scanf("%d", &pr) != 1){
                printf("Некорректный ввод\n");
                while (getchar() != '\n');
                continue;
            }
            int deq_min_value = dequeue_min_priority(pr);
            if (deq_min_value != -1){
                printf("Извлеченный элемент с приоритетом >= %d: %d\n\n", pr, deq_min_value);
            }
            print_queue();
            break;
        }
        case 6:{
            while (head != NULL){
                dequeue_first();
            }
            break;
        }
        default:{
            printf("Выберите операцию из предложенного списка:\n\n");
            break;
        }
        }
    }

    return 0;
}

void display_menu(){
    printf("1.вывести очередь\n");
    printf("2.добавление элемента\n");
    printf("3.извлечение элемента: находящегося первым в очереди\n");
    printf("4.извлечение элемента: с указанным приоритетом\n");
    printf("5.извлечение элемента: с приоритетом не ниже чем заданный\n");
    printf("6.Выход\n\n");
}