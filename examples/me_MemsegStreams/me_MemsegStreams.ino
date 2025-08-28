// [me_MemsegStreams] test

/*
  Author: Martin Eden
  Last mod.: 2025-08-28
*/

/*
  We will send data from memory (RAM) to UART

  We have [me_MemsegStreams] to treat indexable segment of memory
  as input stream. Interface of [me_Uart] supports output stream.
*/

#include <me_MemsegStreams.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

#include <me_MemorySegment.h>
#include <me_Streams.h>
#include <me_WorkMemory.h>
#include <me_Uart.h>

/*
  Copy data from memory to output stream
*/
void MemToStreamTest()
{
  TAddressSegment TestDataSeg =
    me_MemorySegment::Freetown::FromAsciiz("TEST DATA\n");

  me_MemsegStreams::TAddrsegInputStream Input_MemStream;
  me_Streams::TOutputStream Output_UartStream;

  Input_MemStream.Init(TestDataSeg, me_WorkMemory::Op_GetByte);
  Output_UartStream.Init(me_Uart::Op_PutByte);

  me_Streams::CopyStreamTo(&Input_MemStream, &Output_UartStream);
}

void setup()
{
  Console.Init();

  Console.Print("[me_MemsegStreams] test");
  MemToStreamTest();
  Console.Print("Done");
}

void loop()
{
}

/*
  2025-08-25
*/
