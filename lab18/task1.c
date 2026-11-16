#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define cls() printf("\033[H\033[J")

typedef struct Pet Pet;
struct Pet{
    char name[20];
    int hunger;
    int boredom;

    void (*feed)(Pet *p);
    void (*play)(Pet *p);
    void (*show_status)(const Pet *p);
    void (*draw_pet)(const struct Pet *p);

    void (*cycle)(Pet *p);
};

void init_pet(Pet *p, const char* name);
void play_pet(Pet* p);
void feed_pet(Pet* p);
void show_pet(const Pet *p);
void draw_pet(const Pet *p);

void cycle_pet(Pet *p);

int main()
{
    Pet tamo;

    char tmp_name[20];
    printf("Привет!\nВведи имя для своего тамогочи:");
    fgets(tmp_name, 20, stdin);
    tmp_name[strlen(tmp_name) - 1] = '\0';

    cls();

    init_pet(&tamo, tmp_name);

    tamo.cycle(&tamo);

    return 0;
}

void init_pet(Pet *p, const char* name)
{
    for (int i = 0; i < 20; i++)
    {
        p->name[i] = name[i];
    }

    p->hunger = 0;
    p->boredom = 0;

    p->feed = feed_pet;
    p->play = play_pet;
    p->show_status = show_pet;
    p->draw_pet = draw_pet;

    p->cycle = cycle_pet;
}

void feed_pet(Pet *p)
{
    p->hunger -= 20;
    if (p->hunger < 0) p->hunger = 0;
}

void play_pet(Pet *p)
{
    p->boredom -= 15;
    if (p->hunger < 0) p->hunger = 0;
}

void show_pet(const Pet *p)
{
    printf("\nТамогочи %s\nГолод: %d\nСкука: %d\n", p->name, p->hunger, p->boredom);
}

void draw_pet(const Pet *p)
{
    if (p->hunger > 70)
    {
        printf("  (O__O)\n"
               "   / | \\  *Ням-ням?*\n"
               "  (  :  )\n");
    }
    else if (p->boredom > 70)
    {
        printf("  ( T__T )\n"
               "   / | \\  *Хнык...*\n"
               "  (  :  )\n");
    }
    else
    {
        printf("  ( ^__^ )\n"
               "  \\( | )/ *Ура!*\n"
               "  (  :  )\n");
    }
}

void cycle_pet(Pet *p)
{
    while (p->boredom < 100 && p->hunger < 100)
    {
        int uin;
        cls();
        p->draw_pet(p);
        p->show_status(p);
        printf("\nЧто вы хотите сделать?\n"
               "1. Покормить %s\n"
               "2. Поиграть с %s\n"
               "3. Пропустить ход\n"
               "4. Выйти из игры\n\n",
               p->name, p->name);

        scanf("%d", &uin);

        switch (uin)
        {
        case 1: p->feed(p); break;
        case 2: p->play(p); break;
        case 3: break;
        case 4: exit(0);
        default: break;
        }

        p->hunger  += 20; if (p->hunger  > 100) p->hunger  = 100;
        p->boredom += 15; if (p->boredom > 100) p->boredom = 100;
    }
    printf("\nИгра окончена.\n");
}
