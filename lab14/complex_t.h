typedef struct complex_t complex_t;

struct complex_t
{
    int mat;
    int img;

    void (*print)(complex_t);
    complex_t (*add)(complex_t, complex_t);
    complex_t (*sub)(complex_t, complex_t);
    complex_t (*mul)(complex_t, complex_t);
};



complex_t c_create(int mat, int img);
void c_print(complex_t a);
complex_t c_add(complex_t a, complex_t b);
complex_t c_sub(complex_t a, complex_t b);
complex_t c_mul(complex_t a, complex_t b);



void c_print(complex_t a)
{
    if (a.img == 0)
    {
        printf("%d", a.mat);
    }
    else if (a.mat == 0)
    {
        if (a.img == 1)
            printf("i");
        else if (a.img == -1)
            printf("-i");
        else
            printf("%di", a.img);
    }
    else
    {
        printf("%d", a.mat);

        if (a.img > 0)
            printf(" + %di", a.img);
        else if (a.img < 0)
        {
            if (a.img == -1)
                printf(" - i");
            else
                printf(" - %di", -a.img);
        }
    }
}

complex_t c_add(complex_t a, complex_t b)
{
    return c_create(
        a.mat + b.mat,
        a.img + b.img
    );
}

complex_t c_sub(complex_t a, complex_t b)
{
    return c_create(
        a.mat - b.mat,
        a.img - b.img
    );
}

complex_t c_mul(complex_t a, complex_t b)
{
    return c_create(
        a.mat * b.mat - a.img * b.img,
        a.mat * b.img + a.img * b.mat
    );
}

complex_t c_create(int mat, int img)
{
    complex_t result = {
        .mat = mat,
        .img = img,
        .print = c_print,
        .add = c_add,
        .sub = c_sub,
        .mul = c_mul
    };

    return result;
}