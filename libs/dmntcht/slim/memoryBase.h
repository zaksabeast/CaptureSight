#include <dmntcht.h>

typedef struct {
  u64 main_nso;
  u64 heap;
} DmntMemoryBase;

Result dmntchtMemoryBase(DmntMemoryBase *base);
