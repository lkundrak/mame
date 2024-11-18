set -e
set -x

# rm build/linux_gcc/obj/x64/Release/emu.h.gch
#cp excmd/eeprom.bin nvram/v120/lom_eeprom
#rm -f nvram/v120/lom_eeprom
#dd if=/dev/zero bs=1k count=8 of=nvram/v120/lom_eeprom
time make -j16 SUBTARGET=v120 SOURCES=src/mame/sun/v120.cpp xREGENIE=1 SYMBOLS=1 TOOLS=1
./v120 -window v120 $*

:<<:
00000000  0a 1d 00 3e 00 00 00 00  4a 07 00 00 00 00 00 00  |...>....J.......|
00000010  0a 08 00 00 00 00 00 00  00 20 00 00 00 00 00 00  |......... ......|
00000020  00 00 ff ff ff ff ff ff  ff ff ff ff ff ff ff ff  |................|
00000030  ff ff ff ff ff ff ff ff  ff ff ff ff ff ff ff ff  |................|
*
00002000
:
