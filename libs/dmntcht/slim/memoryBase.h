#include <dmntcht.h>

typedef struct {
  u64 main_nso;
  u64 heap;
  u64 alias;
  u64 title_id;
} DmntMemoryBase;

Result dmntchtMemoryBase(DmntMemoryBase *base);
