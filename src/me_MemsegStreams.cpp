// Address segments as streams implementation

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#include <me_MemsegStreams.h>

#include <me_BaseTypes.h>
#include <me_MemorySegment.h>

using namespace me_MemsegStreams;

// ( Address segment as input stream

/*
  Setup

  Requires address segment and read function.
*/
TBool TMemsegInputStream::Init(
  TAddressSegment AddrSeg,
  TOperation UnitReader
)
{
  if (!Rator.Init(AddrSeg))
    return false;

  this->ReadUnit = UnitReader;

  return true;
}

/*
  Read byte
*/
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

// )

// ( Address segment as output stream

/*
  Setup

  Requires segment and write function.
*/
TBool TMemsegOutputStream::Init(
  TAddressSegment AddrSeg,
  TOperation UnitWriter
)
{
  if (!Rator.Init(AddrSeg))
    return false;

  this->WriteUnit = UnitWriter;

  return true;
}

/*
  Write byte
*/
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

// )

/*
  2025-08-25
*/
