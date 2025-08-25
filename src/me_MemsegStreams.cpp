//

/*
*/

#include <me_MemsegStreams.h>

#include <me_BaseTypes.h>

#include <me_MemorySegment.h>

using namespace me_MemsegStreams;

//

TBool TMemsegInputStream::Init(
  me_MemorySegment::TMemorySegment MemSeg,
  TOperation UnitReader
)
{
  if (!Rator.Init(MemSeg))
    return false;

  this->ReadUnit = UnitReader;

  return true;
}

TBool TMemsegInputStream::Read(
  TUnit * Unit
)
{
  TAddress ReadAddr;
  TAddress UnitAddr = (TAddress) Unit;

  if (!Rator.GetNextAddr(&ReadAddr))
    return false;

  if (!ReadUnit(UnitAddr, ReadAddr))
    return false;

  return true;
}

//

TBool TMemsegOutputStream::Init(
  me_MemorySegment::TMemorySegment MemSeg,
  TOperation UnitWriter
)
{
  if (!Rator.Init(MemSeg))
    return false;

  this->WriteUnit = UnitWriter;

  return true;
}

TBool TMemsegOutputStream::Write(
  TUnit Unit
)
{
  TAddress WriteAddr;
  TAddress UnitAddr = (TAddress) &Unit;

  if (!Rator.GetNextAddr(&WriteAddr))
    return false;

  if (!WriteUnit(UnitAddr, WriteAddr))
    return false;

  return true;
}

//

/*
  2025-08-25
*/
