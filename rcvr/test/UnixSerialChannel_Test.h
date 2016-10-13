///////////////////////////////////////////////////////////////
///  This file defines a class that is used for testing
///  the Unix serial communication channel interface.
///
/// @author
///         $Author: Mike Moore $
///
/// Contact: mike.moore@so.engineering
///
/// Created on: Sunday June 12 2016
///
///////////////////////////////////////////////////////////////
#ifndef UNIX_SERIAL_CHANNEL_TEST_HH
#define UNIX_SERIAL_CHANNEL_TEST_HH

#include <limits.h>
#include "gtest/gtest.h"
#include "../CommCrc32.h"
#include "UnixSerialChannel.h"

///////////////////////////////////////////////////////////////
/// @class UnixSerialChannel_Test
/// @ingroup Communication
/// @brief Definition of test class for performing unit-tests
///        of the Unix serial communication channel interface.
///        This test uses a virtual comm port so that the
///        software can be tested without the need for an 
///        actual serial connection with a device.
///////////////////////////////////////////////////////////////
class UnixSerialChannel_Test : public testing::Test{

 public:
  //////////////////////////////////////////////////////////
  /// @brief The default c'tor constructs the UnixSerialChannel_Test
  ///        class.
  ////////////////////////////////////////////////////////////
  UnixSerialChannel_Test();
  //////////////////////////////////////////////////////////
  /// @brief The default d'tor destructs the UnixSerialChannel_Test
  ///        class.
  ////////////////////////////////////////////////////////////
  ~UnixSerialChannel_Test();

 protected:
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test setup routine.
  ////////////////////////////////////////////////////////////
  virtual void SetUp();
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test tear down routine.
  ////////////////////////////////////////////////////////////
  virtual void TearDown();
  ////////////////////////////////////////////////////////////
  /// @brief Helper function that returns true if a valid
  ///        header packet was received.
  ////////////////////////////////////////////////////////////
  bool ValidHeader();
  ////////////////////////////////////////////////////////////
  /// @brief Helper function that returns true if a valid
  ///        CRC checksum was received.
  ////////////////////////////////////////////////////////////
  bool ValidCrc(unsigned char * rcvdData);
  ////////////////////////////////////////////////////////////
  /// @brief Helper function that reads commands from the 
  ///        serial channel.
  ////////////////////////////////////////////////////////////
  void ReadCommands();
  ////////////////////////////////////////////////////////////
  /// @brief Helper function that writes telemetry to the 
  ///        serial channel.
  ////////////////////////////////////////////////////////////
  void WriteTelemetry();
  ////////////////////////////////////////////////////////////
  /// @brief Virtual comm port handle.
  ////////////////////////////////////////////////////////////
  int VirtualCommPortHandle;
  ////////////////////////////////////////////////////////////
  /// @brief Name of the virtual comm device.
  ///        Example: "/dev/pts/21"
  ////////////////////////////////////////////////////////////
  std::string VirtualCommPortName;
  ////////////////////////////////////////////////////////////
  /// @brief Instance of class under test.
  ////////////////////////////////////////////////////////////
  UnixSerialChannel TestArticle;
  ////////////////////////////////////////////////////////////
  /// @brief Test command and telemetry packets
  ////////////////////////////////////////////////////////////
  CommandPacket TestCommands;
  TelemetryPacket TestTelemetry;
  ////////////////////////////////////////////////////////////
  /// @brief Header placed on command packets sent to the 
  ///        Chup. Constant value used is SOE!
  ///        in hex : 0x534F4521
  ///        in dec : 1397703969
  ////////////////////////////////////////////////////////////
  uint32_t PacketHeader;
  ////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test tolerance for floating pt comparisons.
  ////////////////////////////////////////////////////////////
  float Tolerance;
};

#endif  // UNIX_SERIAL_CHANNEL_TEST_HH
