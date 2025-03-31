#include "main.h"

void choice()
{
    printf("---Телефонная книга---\n");
    printf("1.Добавить контакт\n");
    printf("2.Найти контакт\n");
    printf("3.Удалить контакт\n");
    printf("4.Редактировать контак\n");
    printf("5.Список контактов\n");
    printf("6.Выход\n");
    printf("----------------------\n");
    printf("\n");
}

void add_contact(Contact *contact, int *number)
{
    if (*number < MAX_CONTACT)
    {
        Contact new_contact = {0};

        printf("Введите имя\n");
        scanf("%s", new_contact.name.FirstName);

        printf("Введите Фамилию\n");
        scanf("%s", new_contact.name.LastName);

        printf("Введите Место работы(опциональго) - skip для пропуска\n");
        scanf("%s", new_contact.job_place.company);
        if (strcmp(new_contact.job_place.company, "skip") == 0)
        {
            strcpy(new_contact.job_place.company, "");
        }

        printf("Введите Должность(опциональго) - skip для пропуска\n");
        scanf("%s", new_contact.job_place.position);
        if (strcmp(new_contact.job_place.position, "skip") == 0)
        {
            strcpy(new_contact.job_place.position, "");
        }

        printf("Введите email(s)(опциональго) - skip для пропуска\n");
        for (int i = 0; i < COUNT_VALUE; i++)
        {
            printf("Введите email %d:\n", i + 1);
            scanf("%s", new_contact.contact_info.emails[i]);
            if (strcmp(new_contact.contact_info.emails[i], "skip") == 0)
            {
                strcpy(new_contact.contact_info.emails[i], "");
                break;
            }
        }

        printf("Введите номер(а) (опционально) - skip для пропуска\n");
        for (int i = 0; i < COUNT_VALUE; i++)
        {
            printf("Введите номер %d:\n", i + 1);
            scanf("%s", new_contact.contact_info.phone_number[i]);
            if (strcmp(new_contact.contact_info.phone_number[i], "skip") == 0)
            {
                strcpy(new_contact.contact_info.phone_number[i], "");

                break;
            }
        }

        printf("Введите соцсети (опционально) - skip для пропуска\n");
        for (int i = 0; i < COUNT_VALUE; i++)
        {
            printf("Введите соцсеть %d:\n", i + 1);
            scanf("%s", new_contact.contact_info.social_link[i]);
            if (strcmp(new_contact.contact_info.social_link[i], "skip") == 0)
            {
                strcpy(new_contact.contact_info.social_link[i], "");
                break;
            }
        }

        printf("Введите месенджеры (опционально) - skip для пропуска\n");
        for (int i = 0; i < COUNT_VALUE; i++)
        {
            printf("Введите соцсеть %d:\n", i + 1);
            scanf("%s", new_contact.contact_info.mesenger_profiles[i]);
            if (strcmp(new_contact.contact_info.mesenger_profiles[i], "skip") == 0)
            {
                strcpy(new_contact.contact_info.mesenger_profiles[i], "");
                break;
            }
        }

        contact[*number] = new_contact;
        (*number)++;
        printf("Контакт добавлен\n");
    }
    else
        printf("Список контактов переполнен\n");
}

void delete_contact(Contact *contact, int *number_contact)
{
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];
    printf("Введите Имя и Фамилию\n");
    scanf("%s %s", FirstName, LastName);

    for (int i = 0; i < *number_contact; i++)
    {
        if (strcmp(contact[i].name.FirstName, FirstName) == 0 &&
            strcmp(contact[i].name.LastName, LastName) == 0)
        {

            for (int j = i; j < *number_contact - 1; j++)
            {
                contact[j] = contact[j + 1];
            }
            (*number_contact)--;
            printf("Контакт удален\n");
            return;
        }
    }
    printf("Контакт не найден\n");
}

int show_list_contacts(Contact *contact, int number_contact)
{
    if (contact == NULL || number_contact == 0)
    {
        printf("-----------------------\n");
        printf("Список контактов пуст\n");
        printf("-----------------------\n\n");
        return 1;
    }

    printf("-----------------------\n");

    for (int i = 0; i < number_contact; i++)
    {
        printf("Имя: %s\n", contact[i].name.FirstName);
        printf("Фамилия: %s\n", contact[i].name.LastName);

        if (contact[i].job_place.company != "")
        {
            printf("Место работы: %s\n", contact[i].job_place.company);
        }

        if (contact[i].job_place.position != "")
        {
            printf("Должность: %s\n", contact[i].job_place.position);
        }

        printf("Телефон\n");
        for (int j = 0; j < COUNT_VALUE; j++)
        {
            printf("- %s\n", contact[i].contact_info.phone_number[j]);
        }

        printf("emails\n");
        for (int j = 0; j < COUNT_VALUE; j++)
        {
            printf("- %s\n", contact[i].contact_info.emails[j]);
        }

        printf("Cоциальные сети\n");
        for (int j = 0; j < COUNT_VALUE; j++)
        {
            printf("- %s\n", contact[i].contact_info.social_link[j]);
        }

        printf("Профили в месенджерах\n");
        for (int j = 0; j < COUNT_VALUE; j++)
        {
            printf("- %s\n", contact[i].contact_info.mesenger_profiles[j]);
        }
    }
    printf("-----------------------\n");
    printf("\n");
    return 0;
}

void edit_contact(Contact *contact, int number_contact)
{
    char FirsName[MAX_LENGHT];
    char LastName[MAX_LENGHT];

    printf("Введите Имя и Фамилию для поиска контакта\n");
    scanf("%s %s", FirsName, LastName);

    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (strcmp(contact[i].name.FirstName, FirsName) == 0 && strcmp(contact[i].name.LastName, LastName) == 0)
        {
            char buf[MAX_LENGHT];
            printf("Введите новое имя или skip для пропуска\n");
            scanf("%s", buf);
            if (strcmp(buf, "skip") != 0)
            {
                strcpy(contact[i].name.FirstName, buf);
            }

            printf("Введите новую Фамилию или введите skip для пропуска\n");
            scanf("%s", buf);
            if (strcmp(buf, "skip") != 0)
            {
                strcpy(contact[i].name.LastName, buf);
            }

            printf("Введите новое Место или введите skip для пропуска\n");
            scanf("%s", buf);
            if (strcmp(buf, "skip") != 0)
            {
                strcpy(contact[i].job_place.company, buf);
            }

            printf("Введите новую Должность или введите skip для пропуска\n");
            scanf("%s", buf);
            if (strcmp(buf, "skip") != 0)
            {
                strcpy(contact[i].job_place.position, buf);
            }

            printf("Введите новые номера телефона, skip для пропуска\n");
            int count = 0;
            while (count < MAX_CONTACT)
            {
                printf("Телефон %d\n", count + 1);
                scanf("%s", buf);
                if (strcmp(buf, "skip") != 0)
                {
                    strcpy(contact[i].contact_info.phone_number[count], buf);
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }

            printf("Введите новые социальные сети, skip для пропуска\n");
            count = 0;
            while (count < MAX_CONTACT)
            {
                printf("социальная сеть %d\n", count + 1);
                scanf("%s", buf);
                if (strcmp(buf, "skip") != 0)
                {
                    strcpy(contact[i].contact_info.social_link[count], buf);
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }

            printf("Введите новые месенджеры, skip для пропуска\n");
            count = 0;
            while (count < MAX_CONTACT)
            {
                printf("месенджер %d\n", count + 1);
                scanf("%s", buf);
                if (strcmp(buf, "skip") != 0)
                {
                    strcpy(contact[i].contact_info.mesenger_profiles[count], buf);
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }

            printf("Контакт изменен\n");
        }
        else
        {
            printf("Контакт не найден\n");
        }
    }
    return;
}

void find_contact(Contact *contact, int number_contact)
{
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];
    int result = 0;

    printf("Введите Имя и Фамилию\n");
    scanf("%s %s", FirstName, LastName);

    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (strcmp(contact[i].name.FirstName, FirstName) == 0 && strcmp(contact[i].name.LastName, LastName) == 0)
        {
            result = 1;
            printf("------------------\n");
            printf("Имя: %s\n", contact[i].name.FirstName);
            printf("Фамилия: %s\n", contact[i].name.LastName);
            printf("Место работы: %s\n", contact[i].job_place.company);
            printf("Должность: %s\n", contact[i].job_place.position);

            printf("Номера телефонов\n");
            int count = 0;
            while (count < COUNT_VALUE)
            {
                printf("- %s\n", contact[i].contact_info.phone_number[count]);
                count++;
            }

            count = 0;
            printf("Почты: \n");
            while (count < COUNT_VALUE)
            {
                printf("- %s\n", contact[i].contact_info.emails[count]);
                count++;
            }

            count = 0;
            printf("социальные сети: \n");
            while (count < COUNT_VALUE)
            {
                printf("- %s\n", contact[i].contact_info.social_link[count]);
                count++;
            }

            count = 0;
            printf("месенджеры: \n");
            while (count < COUNT_VALUE)
            {
                printf("- %s\n", contact[i].contact_info.mesenger_profiles[count]);
                count++;
            }
        }
    }

    if (!result)
    {
        printf("Контакт не найден\n\n");
    }
}