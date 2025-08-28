// Wrapping address segments as streams

/*
  Author: Martin Eden
  Last mod.: 2025-08-28
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_MemsegStreams
{
  // [Adapter] Input stream = Address segment + Read function
  class TAddrsegInputStream : public IInputStream
  {
    public:
      TBool Init(
        TAddressSegment AddrSeg,
        TOperation UnitReader
      );

      TBool Read(TUnit * Unit) override;

    private:
      TAddressIterator Rator;
      TOperation ReadUnit;
  };

  // [Adapter] Output stream = Address segment + Write function
  class TAddrsegOutputStream : public IOutputStream
  {
    public:
      TBool Init(
        TAddressSegment AddrSeg,
        TOperation UnitWriter
      );

      TBool Write(TUnit Unit) override;

    private:
      TAddressIterator Rator;
      TOperation WriteUnit;
  };
}

/*
  2025-08-25
  2025-08-26
  2025-08-28
*/
