///////////////////////////////////////////////////////////////
///  This file defines a class that is used to implement the
///  Unix serial communication channel.
///
/// @author
///         $Author: Mike Moore $
///
/// Contact: mike.moore@so.engineering
///
/// Created on: Sunday June 12 2016
///
///////////////////////////////////////////////////////////////
#ifndef UNIX_SERIAL_CHANNEL_HH
#define UNIX_SERIAL_CHANNEL_HH

#include <termios.h>
#include <fcntl.h>
#include "CommChannel.h"
#include "../CommCrc32.h"

///////////////////////////////////////////////////////////////
/// @class UnixSerialChannel
/// @ingroup Communication
/// @brief Definition of class that implements a Unix serial
///        communication channel.
///////////////////////////////////////////////////////////////
class UnixSerialChannel : public CommChannel { 

 public:
  ////////////////////////////////////////////////////////////
  /// @brief The default c'tor constructs the UnixSerialChannel
  ///        class.
  ////////////////////////////////////////////////////////////
  UnixSerialChannel();
  ////////////////////////////////////////////////////////////
  /// @brief The default d'tor destructs the UnixSerialChannel
  ///        class.
  ////////////////////////////////////////////////////////////
  ~UnixSerialChannel();
  ////////////////////////////////////////////////////////////
  /// @brief Connect to the Unix serial comm port.
  /// @throws std::runtime_error
  ////////////////////////////////////////////////////////////
  void Connect();
  ////////////////////////////////////////////////////////////
  /// @brief Transmit the command packet.
  /// @throws std::runtime_error
  ////////////////////////////////////////////////////////////
  virtual void Tx();
  ////////////////////////////////////////////////////////////
  /// @brief Receive the telemetry packet.
  /// @throws std::runtime_error
  ////////////////////////////////////////////////////////////
  virtual void Rx();
  ////////////////////////////////////////////////////////////
  /// @brief Unix serial comm port name 
  ///        Example: "/dev/ttyUSB0"
  ////////////////////////////////////////////////////////////
  std::string PortName;

 protected:
  //////////////////////////////////////////////////////////
  /// @brief Validate the serial port connection.
  ////////////////////////////////////////////////////////////
  virtual void Validate();
  ////////////////////////////////////////////////////////////
  /// @brief Returns true if a valid header packet was received.
  ////////////////////////////////////////////////////////////
  bool ValidHeader();
  ////////////////////////////////////////////////////////////
  /// @brief Returns true if a valid CRC checksum was received.
  ////////////////////////////////////////////////////////////
  bool ValidCrc();
  ////////////////////////////////////////////////////////////
  /// @brief Prints out a warning message
  ////////////////////////////////////////////////////////////
  void reportWarning();
  ////////////////////////////////////////////////////////////
  /// @brief Comm port handle.
  ////////////////////////////////////////////////////////////
  int CommPortHandle;
 
 private:
  ////////////////////////////////////////////////////////////
  /// @brief Funciton that sets specific configurable attributes
  ///        of the serial channel. 
  ////////////////////////////////////////////////////////////
  void SetupSerialAttributes( int speed, int parity);
  ////////////////////////////////////////////////////////////
  /// @brief Used to turn on/off blocking reads
  ////////////////////////////////////////////////////////////
  void ToggleBlocking(int should_block);

};

#endif  // UNIX_SERIAL_CHANNEL_HH
