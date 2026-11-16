#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc;
    uint16_t e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno;
    uint16_t e_res[4];
    uint16_t e_oemid, e_oeminfo;
    uint16_t e_res2[10];
    uint32_t e_lfanew;
} DosHeader;
#pragma pack(pop)

static void print_few(const uint16_t *values, size_t count)
{
    for (size_t i = 0; i < count; ++i) printf(" %04X", values[i]);
}

static void print_header(const DosHeader *h)
{
    printf("Magic number (e_magic)          : 0x%04X  ('%c%c')\n", h->e_magic,
           (int)(h->e_magic & 0xFF), (int)((h->e_magic >> 8) & 0xFF));
    printf("Bytes on last page (e_cblp)     : 0x%04X\n", h->e_cblp);
    printf("Pages in file (e_cp)            : 0x%04X\n", h->e_cp);
    printf("Relocations (e_crlc)            : 0x%04X\n", h->e_crlc);
    printf("Size of header (e_cparhdr)      : 0x%04X\n", h->e_cparhdr);
    printf("Minimum memory (e_minalloc)     : 0x%04X\n", h->e_minalloc);
    printf("Maximum memory (e_maxalloc)     : 0x%04X\n", h->e_maxalloc);
    printf("Initial SS value (e_ss)         : 0x%04X\n", h->e_ss);
    printf("Initial SP value (e_sp)         : 0x%04X\n", h->e_sp);
    printf("Checksum (e_csum)               : 0x%04X\n", h->e_csum);
    printf("Initial IP value (e_ip)         : 0x%04X\n", h->e_ip);
    printf("Initial CS value (e_cs)         : 0x%04X\n", h->e_cs);
    printf("Table offset (e_lfarlc)         : 0x%04X\n", h->e_lfarlc);
    printf("Overlay number (e_ovno)         : 0x%04X\n", h->e_ovno);
    printf("Reserved (e_res)                :"); print_few(h->e_res, 4); printf("\n");
    printf("OEM Identifier (e_oemid)        : 0x%04X\n", h->e_oemid);
    printf("OEM Information (e_oeminfo)     : 0x%04X\n", h->e_oeminfo);
    printf("Reserved 2 (e_res2)             :"); print_few(h->e_res2, 10); printf("\n");
    printf("PE Address (e_lfanew)           : 0x%08X\n", h->e_lfanew);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Использование: <файл.exe>\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        printf("%s", argv[1]); return -1;
    }

    DosHeader header;
    if (fread(&header, sizeof(header), 1, file) != 1) {
        if (ferror(file)) printf("Читаю PE-заголовки");
        else printf("Файл слишком маленький (%zu). Он должен хотя бы %zu байт\n", sizeof(file), sizeof(header));
        fclose(file); return -1;
    }

    fclose(file);
    print_header(&header);
    return 0;
}
