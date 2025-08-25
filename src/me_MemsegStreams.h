//

/*
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_Streams.h>
#include <me_MemorySegment.h>

namespace me_MemsegStreams
{
  class TMemsegInputStream : public me_Streams::TInputStream
  {
    public:
      TBool Init(
        me_MemorySegment::TMemorySegment MemSeg,
        TOperation UnitReader
      );

      TBool Read(TUnit * Unit) override;

    private:
      me_MemorySegment::TSegmentIterator Rator;
      TOperation ReadUnit;
  };

  class TMemsegOutputStream : public me_Streams::TOutputStream
  {
    public:
      TBool Init(
        me_MemorySegment::TMemorySegment MemSeg,
        TOperation UnitWriter
      );

      TBool Write(TUnit Unit) override;

    private:
      me_MemorySegment::TSegmentIterator Rator;
      TOperation WriteUnit;
  };
}

/*
  2025-08-25
*/
