// Wrapping address segments as streams

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_Streams.h>
#include <me_MemorySegment.h>

namespace me_MemsegStreams
{
  // Address segment as input stream
  class TMemsegInputStream : public me_Streams::TInputStream
  {
    public:
      TBool Init(
        TAddressSegment AddrSeg,
        TOperation UnitReader
      );

      TBool Read(TUnit * Unit) override;

    private:
      me_MemorySegment::TSegmentIterator Rator;
      TOperation ReadUnit;
  };

  // Address segment as output stream
  class TMemsegOutputStream : public me_Streams::TOutputStream
  {
    public:
      TBool Init(
        TAddressSegment AddrSeg,
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
  2025-08-26
*/
