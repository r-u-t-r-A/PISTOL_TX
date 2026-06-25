// writes a byte of data in memory location addr

//#define debug
void EEPROM_write(unsigned int addr, byte eeprom_data)  {
  #ifdef debug
  SerialUSB.print("wr addr"); SerialUSB.println(addr);
  #endif
 Wire.beginTransmission(I2CEEPROM_ADDR);
    Wire.write(addr >> 8);
    Wire.write(addr & 0xFF);
    Wire.write(eeprom_data);
    Wire.endTransmission();
    delay(10);

}

// reads a byte of data from memory location addr
byte EEPROM_read(unsigned int addr)  {
  Wire.beginTransmission(I2CEEPROM_ADDR);
    Wire.write(addr >> 8);
    Wire.write(addr & 0xFF);
    Wire.endTransmission();
    Wire.requestFrom(I2CEEPROM_ADDR, (byte)1);
    byte data = 0;
    if (Wire.available())
    {
        data = Wire.read();
    }
    return data;
}

void EEPROM_update(unsigned int addr, byte to_write) { //to save write cycles of eeprom
  byte wrtitten = EEPROM_read(addr);
  if (to_write == wrtitten) {
    //do nothing, just skip
  } else {
    EEPROM_write(addr, to_write);
  }

}


void reset_eeprom() {

  EEPROM_write(0, 0); //nrf24 channel
  EEPROM_write(1, 127); //trim 1
  EEPROM_write(2, 127); //trim 2
  EEPROM_write(3, 127); //trim 3
  EEPROM_write(4, 127); //trim 4
  EEPROM_write(5, 0); //elrs RF
  EEPROM_write(6, 0); //elrs output power
  EEPROM_write(7, 0); //elrs RF
  EEPROM_write(8, 0); //elrs output power
  EEPROM_write(9, 0); //elrs RF
  EEPROM_write(10, 0); //elrs output power
  EEPROM_write(11, 0); //elrs RF
  EEPROM_write(12, 0); //elrs output power
  EEPROM_write(13, 0); 
}
