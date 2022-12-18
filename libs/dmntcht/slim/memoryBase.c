#include "memoryBase.h"
#include <dmntcht.h>

Result dmntchtMemoryBase(DmntMemoryBase *base) {
  DmntCheatProcessMetadata metadata;
  Result rc = dmntchtGetCheatProcessMetadata(&metadata);

  if (R_SUCCEEDED(rc)) {
    base->main_nso = metadata.main_nso_extents.base;
    base->heap = metadata.heap_extents.base;
    base->alias = metadata.alias_extents.base;
    base->title_id = metadata.title_id;
  }

  return rc;
}
