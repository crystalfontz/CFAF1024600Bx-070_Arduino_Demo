//============================================================================
//
// Some demo routines for Crystalfontz CFA10108 EVE accelerated displays.
//
// These routines _could_ be made into classes. But in real life, there are
// not resources available to instantiate more than one of them at a time.
// Because of this I have just kept them simple and hopefully
// more understandable.
//
// The format is:
//   variables (global but limited in scope to this file)
//   init()
//   draw()
//   move()
//
// 2022-02-28 Brent A. Crosby / Crystalfontz America, Inc.
// https://www.crystalfontz.com/products/eve-accelerated-tft-displays.php
//===========================================================================
//This is free and unencumbered software released into the public domain.
//
//Anyone is free to copy, modify, publish, use, compile, sell, or
//distribute this software, either in source code form or as a compiled
//binary, for any purpose, commercial or non-commercial, and by any
//means.
//
//In jurisdictions that recognize copyright laws, the author or authors
//of this software dedicate any and all copyright interest in the
//software to the public domain. We make this dedication for the benefit
//of the public at large and to the detriment of our heirs and
//successors. We intend this dedication to be an overt act of
//relinquishment in perpetuity of all present and future rights to this
//software under copyright law.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//
//For more information, please refer to <http://unlicense.org/>
//============================================================================
#include <Arduino.h>
#include <SPI.h>
#include <stdarg.h>
// Definitions for our circuit board and display.
#include "CFA10108_defines.h"
// Transparent Rotating Logo for this display
#include "Round_Logos.h"

#if BUILD_SD
#include <SD.h>
#endif

// The very simple EVE library files
#include "EVE_base.h"
#include "EVE_draw.h"

// Our demonstrations of various EVE functions
#include "demos.h"

//===========================================================================
#if (0 != PROGRAM_FLASH_FROM_USD)
uint16_t Initialize_Flash_From_uSD(uint16_t FWol,
                                   uint32_t RAM_G_Unused_Start,
                                   uint32_t *Flash_Sector)
  {
  uint32_t
    F_Sec_backgrnd_a8z;
  uint32_t
    F_Len_backgrnd_a8z;
  uint32_t
    F_Sec_bi_bird_a8z;
  uint32_t
    F_Len_bi_bird_a8z;
  uint32_t
    F_Sec_bi_cat_a8z;
  uint32_t
    F_Len_bi_cat_a8z;
  uint32_t
    F_Sec_bi_dog_a8z;
  uint32_t
    F_Len_bi_dog_a8z;
  uint32_t
    F_Sec_bi_horse_a8z;
  uint32_t
    F_Len_bi_horse_a8z;
  uint32_t
    F_Sec_bs_bird_a8z;
  uint32_t
    F_Len_bs_bird_a8z;
  uint32_t
    F_Sec_bs_cat_a8z;
  uint32_t
    F_Len_bs_cat_a8z;
  uint32_t
    F_Sec_bs_dog_a8z;
  uint32_t
    F_Len_bs_dog_a8z;
  uint32_t
    F_Sec_bs_horse_a8z;
  uint32_t
    F_Len_bs_horse_a8z;
  uint32_t
    F_Sec_i_bat_0_a8z;
  uint32_t
    F_Len_i_bat_0_a8z;
  uint32_t
    F_Sec_i_bat_1_a8z;
  uint32_t
    F_Len_i_bat_1_a8z;
  uint32_t
    F_Sec_i_bat_2_a8z;
  uint32_t
    F_Len_i_bat_2_a8z;
  uint32_t
    F_Sec_i_bat_3_a8z;
  uint32_t
    F_Len_i_bat_3_a8z;
  uint32_t
    F_Sec_i_bat_4_a8z;
  uint32_t
    F_Len_i_bat_4_a8z;
  uint32_t
    F_Sec_i_bat_5_a8z;
  uint32_t
    F_Len_i_bat_5_a8z;
  uint32_t
    F_Sec_i_disk_a8z;
  uint32_t
    F_Len_i_disk_a8z;
  uint32_t
    F_Sec_i_fold_a8z;
  uint32_t
    F_Len_i_fold_a8z;
  uint32_t
    F_Sec_i_gear_a8z;
  uint32_t
    F_Len_i_gear_a8z;
  uint32_t
    F_Sec_i_home_a8z;
  uint32_t
    F_Len_i_home_a8z;
  DBG_GEEK("Writing flash BLOB to flash sector %ld . . . ",*Flash_Sector);
  //Write_BLOB_to_Flash_Sector_0() needs to know where unused RAM_G
  //starts so it does not overwrite anything, but only uses RAM_G
  //temporarily, so it does not change RAM_G_Unused_Start.
  FWol=Write_BLOB_to_Flash_Sector_0(FWol,
                                    RAM_G_Unused_Start,
                                    Flash_Sector);
  DBG_GEEK("done.\n");
  DBG_GEEK_Decode_Flash_Status(EVE_REG_Read_8(EVE_REG_FLASH_STATUS));
  // I use .a4z and .a8z as a file extensions for a zlib compressed ATSC
  // files. .a4z is 4x4 (higher quality, larger) and .a8z is 8x8 (lower
  // quality, smaller). I typically just use the "thorough" setting in
  // Eve Asset Builder.
  // For this 1024 x 600 display the BT817 struggles with the 4x4 block
  // size. The 8x8 works fine and still looks great.
  // Since ATSC is already compressed, zlib does not do much, but
  // the uSD is slow and the decompression is free thanks to the EVE.
  //Write_uSD_File_To_Flash() needs to know where unused RAM_G
  //starts so it does not overwrite anything, but only uses RAM_G
  //temporarily, so it does not change RAM_G_Unused_Start.

  
  DBG_GEEK("Writing \"backgrnd.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_backgrnd_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "backgrnd.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_backgrnd_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bi_bird.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bi_bird_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bi_bird.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bi_bird_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bi_cat.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bi_cat_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bi_cat.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bi_cat_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bi_dog.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bi_dog_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bi_dog.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bi_dog_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bi_horse.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bi_horse_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bi_horse.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bi_horse_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bs_bird.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bs_bird_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bs_bird.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bs_bird_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bs_cat.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bs_cat_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bs_cat.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bs_cat_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bs_dog.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bs_dog_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bs_dog.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bs_dog_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"bs_horse.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_bs_horse_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "bs_horse.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_bs_horse_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_0.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_0_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_0.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_0_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_1.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_1_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_1.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_1_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_2.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_2_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_2.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_2_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_3.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_3_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_3.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_3_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_4.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_4_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_4.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_4_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_bat_5.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_bat_5_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_bat_5.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_bat_5_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_disk.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_disk_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_disk.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_disk_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_fold.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_fold_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_fold.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_fold_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_gear.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_gear_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_gear.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_gear_a8z);
  DBG_GEEK("done.\n");
  
  DBG_GEEK("Writing \"i_home.a8z\" to flash sector = %ld . . . ",*Flash_Sector);
  F_Sec_i_home_a8z=*Flash_Sector;
  FWol=Inflate_uSD_File_To_Flash(FWol,
                                 "i_home.a8z",
                                 RAM_G_Unused_Start,
                                 Flash_Sector,
                                 &F_Len_i_home_a8z);
  DBG_GEEK("done.\n");

  //Dump the flash sectors to the console, so we can copy those into the source
  //and use them to access the flash. Yes, I realize this is hokey, properly
  //we could write some kind of file system or at least a directory to the flash.
  DBG_STAT("\n#define F_SEC_BACKGRND_A8Z  (%ldUL)\n",F_Sec_backgrnd_a8z);
  DBG_STAT("#define F_LEN_BACKGRND_A8Z  (%ldUL) // sectors: %ld\n",F_Len_backgrnd_a8z,(F_Len_backgrnd_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BI_BIRD_A8Z   (%ldUL)\n",F_Sec_bi_bird_a8z);
  DBG_STAT("#define F_LEN_BI_BIRD_A8Z   (%ldUL) // sectors: %ld\n",F_Len_bi_bird_a8z,(F_Len_bi_bird_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BI_CAT_A8Z    (%ldUL)\n",F_Sec_bi_cat_a8z);
  DBG_STAT("#define F_LEN_BI_CAT_A8Z    (%ldUL) // sectors: %ld\n",F_Len_bi_cat_a8z,(F_Len_bi_cat_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BI_DOG_A8Z    (%ldUL)\n",F_Sec_bi_dog_a8z);
  DBG_STAT("#define F_LEN_BI_DOG_A8Z    (%ldUL) // sectors: %ld\n",F_Len_bi_dog_a8z,(F_Len_bi_dog_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BI_HORSE_A8Z  (%ldUL)\n",F_Sec_bi_horse_a8z);
  DBG_STAT("#define F_LEN_BI_HORSE_A8Z  (%ldUL) // sectors: %ld\n",F_Len_bi_horse_a8z,(F_Len_bi_horse_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BS_BIRD_A8Z   (%ldUL)\n",F_Sec_bs_bird_a8z);
  DBG_STAT("#define F_LEN_BS_BIRD_A8Z   (%ldUL) // sectors: %ld\n",F_Len_bs_bird_a8z,(F_Len_bs_bird_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BS_CAT_A8Z    (%ldUL)\n",F_Sec_bs_cat_a8z);
  DBG_STAT("#define F_LEN_BS_CAT_A8Z    (%ldUL) // sectors: %ld\n",F_Len_bs_cat_a8z,(F_Len_bs_cat_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BS_DOG_A8Z    (%ldUL)\n",F_Sec_bs_dog_a8z);
  DBG_STAT("#define F_LEN_BS_DOG_A8Z    (%ldUL) // sectors: %ld\n",F_Len_bs_dog_a8z,(F_Len_bs_dog_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_BS_HORSE_A8Z  (%ldUL)\n",F_Sec_bs_horse_a8z);
  DBG_STAT("#define F_LEN_BS_HORSE_A8Z  (%ldUL) // sectors: %ld\n",F_Len_bs_horse_a8z,(F_Len_bs_horse_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_0_A8Z   (%ldUL)\n",F_Sec_i_bat_0_a8z);
  DBG_STAT("#define F_LEN_I_BAT_0_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_0_a8z,(F_Len_i_bat_0_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_1_A8Z   (%ldUL)\n",F_Sec_i_bat_1_a8z);
  DBG_STAT("#define F_LEN_I_BAT_1_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_1_a8z,(F_Len_i_bat_1_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_2_A8Z   (%ldUL)\n",F_Sec_i_bat_2_a8z);
  DBG_STAT("#define F_LEN_I_BAT_2_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_2_a8z,(F_Len_i_bat_2_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_3_A8Z   (%ldUL)\n",F_Sec_i_bat_3_a8z);
  DBG_STAT("#define F_LEN_I_BAT_3_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_3_a8z,(F_Len_i_bat_3_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_4_A8Z   (%ldUL)\n",F_Sec_i_bat_4_a8z);
  DBG_STAT("#define F_LEN_I_BAT_4_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_4_a8z,(F_Len_i_bat_4_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_BAT_5_A8Z   (%ldUL)\n",F_Sec_i_bat_5_a8z);
  DBG_STAT("#define F_LEN_I_BAT_5_A8Z   (%ldUL) // sectors: %ld\n",F_Len_i_bat_5_a8z,(F_Len_i_bat_5_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_DISK_A8Z    (%ldUL)\n",F_Sec_i_disk_a8z);
  DBG_STAT("#define F_LEN_I_DISK_A8Z    (%ldUL) // sectors: %ld\n",F_Len_i_disk_a8z,(F_Len_i_disk_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_FOLD_A8Z    (%ldUL)\n",F_Sec_i_fold_a8z);
  DBG_STAT("#define F_LEN_I_FOLD_A8Z    (%ldUL) // sectors: %ld\n",F_Len_i_fold_a8z,(F_Len_i_fold_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_GEAR_A8Z    (%ldUL)\n",F_Sec_i_gear_a8z);
  DBG_STAT("#define F_LEN_I_GEAR_A8Z    (%ldUL) // sectors: %ld\n",F_Len_i_gear_a8z,(F_Len_i_gear_a8z+4095)>>12);
  DBG_STAT("#define F_SEC_I_HOME_A8Z    (%ldUL)\n",F_Sec_i_home_a8z);
  DBG_STAT("#define F_LEN_I_HOME_A8Z    (%ldUL) // sectors: %ld\n",F_Len_i_home_a8z,(F_Len_i_home_a8z+4095)>>12);
 
  DBG_STAT("//Total sectors = 4096, free sectors = %ld\n",4096UL - (F_Sec_i_home_a8z+((F_Len_i_home_a8z+4095)>>12)));
  DBG_STAT("//Total flash = 16777216, free flash = %ld\n\n",16777216UL - ((F_Sec_i_home_a8z+((F_Len_i_home_a8z+4095)>>12))<<12));
  //Give the updated write pointer back to the caller
  return(FWol);
  }
#endif //PROGRAM_FLASH_FROM_USD
//===========================================================================
#if TOUCH_DEMO
uint16_t Add_Touch_Dot_To_Display_List(uint16_t FWol,
                                       uint16_t touch_x,
                                       uint16_t touch_y)
  {
  //See if we are touched at all. Coordinates will be large if not.
  if(touch_x<1200)
    {
    // Set the variable color of the touched dot to green.
    FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_COLOR_RGB(0x00,0xFF,0x00));
    // Make it solid
    FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_COLOR_A(0xFF));

    // Draw the touch dot -- a 60px point (filled circle)
    FWol=EVE_Point(FWol,
                     touch_x*16,
                     touch_y*16,
                     60*16);
    }
  //Give the updated write pointer back to the caller
  return(FWol);
  }
#endif //TOUCH_DEMO
//===========================================================================
#if (0 != BMP_DEMO)

//The images are in flash. Initialize_Bitmap_Demo() will copy them into
//RAM_G, storing the RAM_G addresses here.

// All this stuff should be properly done with an array of structures.
// The structure should hold the flash sector, RAM_G addressm, x&y size
// and position etc. That way all this silly linear code could be done
// as loops.

uint32_t
  RAM_G_bi_bird_a8z;
uint32_t
  RAM_G_bi_cat_a8z;
uint32_t
  RAM_G_bi_dog_a8z;
uint32_t
  RAM_G_bi_horse_a8z;
uint32_t
  RAM_G_bs_bird_a8z;
uint32_t
  RAM_G_bs_cat_a8z;
uint32_t
  RAM_G_bs_dog_a8z;
uint32_t
  RAM_G_bs_horse_a8z;
uint32_t
  RAM_G_i_bat_0_a8z;
uint32_t
  RAM_G_i_bat_1_a8z;
uint32_t
  RAM_G_i_bat_2_a8z;
uint32_t
  RAM_G_i_bat_3_a8z;
uint32_t
  RAM_G_i_bat_4_a8z;
uint32_t
  RAM_G_i_bat_5_a8z;
uint32_t
  RAM_G_i_disk_a8z;
uint32_t
  RAM_G_i_fold_a8z;
uint32_t
  RAM_G_i_gear_a8z;
uint32_t
  RAM_G_i_home_a8z;
  
//---------------------------------------------------------------------------
uint16_t Initialize_Bitmap_Demo(uint16_t FWol,
                                uint32_t *RAM_G_Unused_Start)
  {
  //5.79 CMD_FLASHREAD
  //This command reads data from flash into main memory.
  // void cmd_flashread(uint32_t dest,
  //                    uint32_t src,
  //                    uint32_t num);
  // void Gpu_CoCmd_FlashRead(Gpu_Hal_Context_t *phost,uint32_t dest, uint32_t src, uint32_t num)
  //   {
  //   Gpu_CoCmd_StartFunc(phost,CMD_SIZE*4);
  //   Gpu_Copro_SendCmd(phost, CMD_FLASHREAD);
  //   Gpu_Copro_SendCmd(phost, dest);
  //   Gpu_Copro_SendCmd(phost, src);
  //   Gpu_Copro_SendCmd(phost, num);
  //   Gpu_CoCmd_EndFunc(phost,(CMD_SIZE*4));
  //   }
  DBG_GEEK("\nCopy \"bi_bird.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bi_bird_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bi_bird_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BI_BIRD_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BI_BIRD_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BI_BIRD_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bi_cat.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bi_cat_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bi_cat_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BI_CAT_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BI_CAT_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BI_CAT_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bi_dog.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bi_dog_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bi_dog_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BI_DOG_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BI_DOG_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BI_DOG_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bi_horse.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bi_horse_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bi_horse_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BI_HORSE_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BI_HORSE_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BI_HORSE_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bs_bird.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bs_bird_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bs_bird_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BS_BIRD_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BS_BIRD_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BS_BIRD_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bs_cat.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bs_cat_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bs_cat_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BS_CAT_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BS_CAT_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BS_CAT_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bs_dog.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bs_dog_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bs_dog_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BS_DOG_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BS_DOG_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BS_DOG_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"bs_horse.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_bs_horse_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_bs_horse_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_BS_HORSE_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_BS_HORSE_A8Z);
  *RAM_G_Unused_Start+=F_LEN_BS_HORSE_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);



  DBG_GEEK("Copy \"i_bat_0.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_0_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_0_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_0_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_0_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_0_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_bat_1.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_1_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_1_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_1_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_1_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_1_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_bat_2.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_2_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_2_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_2_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_2_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_2_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_bat_3.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_3_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_3_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_3_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_3_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_3_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_bat_4.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_4_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_4_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_4_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_4_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_4_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_bat_5.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_bat_5_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_bat_5_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_BAT_5_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_BAT_5_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_BAT_5_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_disk.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_disk_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_disk_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_DISK_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_DISK_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_DISK_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_fold.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_fold_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_fold_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_FOLD_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_FOLD_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_FOLD_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_gear.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_gear_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_gear_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_GEAR_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_GEAR_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_GEAR_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  DBG_GEEK("Copy \"i_home.a8z\" from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where it is.
  RAM_G_i_home_a8z=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     RAM_G_i_home_a8z,
                     // source in flash, must be 64-byte aligned
                     (F_SEC_I_HOME_A8Z)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     F_LEN_I_HOME_A8Z);
  *RAM_G_Unused_Start+=F_LEN_I_HOME_A8Z;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  // Update the ring buffer pointer so the graphics processor starts executing
  EVE_REG_Write_16(EVE_REG_CMD_WRITE, (FWol));

  //Pass our updated offset back to the caller
  return(FWol);
  }
//---------------------------------------------------------------------------
uint16_t Add_RAM_G_Bitmap_To_Display_List(uint16_t FWol,
                                          uint32_t handle,
                                          uint32_t x_pos,
                                          uint32_t y_pos,
                                          uint32_t x_siz,
                                          uint32_t y_siz,
                                          uint32_t ram_g_address,
                                          uint32_t image_format)
  {
  //Make sure the EVE has the idea of which bitmap it
  //should be working on.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BITMAP_HANDLE(handle));
  // Set the drawing color to white
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_A(255));
  //Pull the image from RAM_G onto the screen
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));
  FWol=RAMG_SETBITMAP(FWol,ram_g_address,image_format,x_siz,y_siz);
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));
  //Render the bitmap it to the current frame
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_VERTEX2F((x_pos*16),(y_pos*16)));
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_END());                       
  return(FWol);
  }
//---------------------------------------------------------------------------
uint16_t Add_Flash_Bitmap_To_Display_List(uint16_t FWol,
                                          uint32_t handle,
                                          uint32_t x_pos,
                                          uint32_t y_pos,
                                          uint32_t x_siz,
                                          uint32_t y_siz,
                                          uint32_t flash_sector,
                                          uint32_t image_format)
  {
  //Pull the ASTC image from flash onto the screen

  // Set the drawing color to white
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_A(255));
  //Make sure the EVE has the idea of which bitmap it
  //should be working on.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BITMAP_HANDLE(handle));
  FWol=FLASH_SETBITMAP(FWol,flash_sector,image_format,x_siz,y_siz);

  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));
  //Render the bitmap it to the current frame
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_VERTEX2F((x_pos*16),(y_pos*16)));
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_END());

  //Pass our updated offset back to the caller
  return(FWol);
  }
#endif // (0 != BMP_DEMO)
//===========================================================================
#if (0 != MARBLE_DEMO)
//Keep track of the Marble
int32_t
  marble_x_pos;
int32_t
  marble_x_vel;
int32_t
  marble_y_pos;
int32_t
  marble_y_vel;
int32_t
  marble_rotation;
int32_t
  marble_spin;
uint32_t
  Marble_RAM_G_Address;
uint32_t
  marble_width;
uint32_t
  marble_height;
uint8_t
  marble_bitmap_handle;
//---------------------------------------------------------------------------
//Requires uSD
uint16_t Initialize_Marble_Demo(uint16_t FWol,
                                uint32_t *RAM_G_Unused_Start,
                                uint8_t next_bitmap_handle_available)
  {
  //Keep track of our bitmap handle
  marble_bitmap_handle=next_bitmap_handle_available;

  //Start somewhere reasonable
  marble_x_pos=LCD_WIDTH*(16/2);
  marble_x_vel=48;
  marble_y_pos=LCD_HEIGHT*(16/2);
  marble_y_vel=-32;
  marble_rotation=0;
  marble_spin=0;

  //5.79 CMD_FLASHREAD
  //This command reads data from flash into main memory.
  // void cmd_flashread(uint32_t dest,
  //                    uint32_t src,
  //                    uint32_t num);
  // void Gpu_CoCmd_FlashRead(Gpu_Hal_Context_t *phost,uint32_t dest, uint32_t src, uint32_t num)
  //   {
  //   Gpu_CoCmd_StartFunc(phost,CMD_SIZE*4);
  //   Gpu_Copro_SendCmd(phost, CMD_FLASHREAD);
  //   Gpu_Copro_SendCmd(phost, dest);
  //   Gpu_Copro_SendCmd(phost, src);
  //   Gpu_Copro_SendCmd(phost, num);
  //   Gpu_CoCmd_EndFunc(phost,(CMD_SIZE*4));
  //   }
  DBG_GEEK("Copy marble from flash to RAM_G start: %lu",*RAM_G_Unused_Start);
  //Remember where the marble is.
  Marble_RAM_G_Address=*RAM_G_Unused_Start;
  //You have to know ahead of time how big the image is and what
  //format it is in. EVE_Load_File_To_RAM_G just moves the data.
  marble_width=240;
  marble_height=240;

  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_FLASHREAD,
                     // destination in RAM_G, must be 4-byte aligned
                     Marble_RAM_G_Address,
                     // source in flash, must be 64-byte aligned
                     (FLASH_SECTOR_MARBLE)<<12,
                     // number of bytes to write, must be 4-byte aligned
                     FLASH_LENGTH_MARBLE);

  *RAM_G_Unused_Start+=FLASH_LENGTH_MARBLE;
  DBG_GEEK(" end: %lu\n",(*RAM_G_Unused_Start)-1);

  // Update the ring buffer pointer so the graphics processor starts executing
  EVE_REG_Write_16(EVE_REG_CMD_WRITE, (FWol));

  //Pass our updated offset back to the caller
  return(FWol);
  }
//---------------------------------------------------------------------------
#if TOUCH_DEMO
void Force_Marble_Position(uint32_t x,uint16_t y)
  {
  marble_x_pos=x;
  marble_y_pos=y;
  }
#endif //TOUCH_DEMO
//---------------------------------------------------------------------------
uint16_t Add_Marble_To_Display_List(uint16_t FWol)
  {
  //========== PUT BLUE MARBLE ON SCREEN ==========
  //Make sure the EVE has the idea of which bitmap it
  //should be working on.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BITMAP_HANDLE(marble_bitmap_handle));
  // Set the drawing color to white
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_COLOR_A(255));

  //Pull the uncompressed bitmap from RAM_G onto the screen
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));

  FWol=EVE_Cmd_Dat_3(FWol,
                     EVE_ENC_CMD_SETBITMAP,
                     Marble_RAM_G_Address,
                     //Width (high word), Format (low word)
                     ((uint32_t)marble_width << 16) | EVE_FORMAT_COMPRESSED_RGBA_ASTC_8x8_KHR,
                     //Height (low word) (high word unused)
                     marble_height); //height

   //Rotate the bitmap
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_CMD_LOADIDENTITY);
  //Translate to the center
  FWol=EVE_Cmd_Dat_2(FWol,
                       EVE_ENC_CMD_TRANSLATE,
                       +(to_16_16_fp(marble_width,0)/2),
                       +(to_16_16_fp(marble_height,0)/2));
  //The actual rotate command
  FWol=EVE_Cmd_Dat_1(FWol,
                       EVE_ENC_CMD_ROTATE,
                       to_16_16_fp(marble_rotation,0)/360);
  //Undo the translation
  FWol=EVE_Cmd_Dat_2(FWol,
                       EVE_ENC_CMD_TRANSLATE,
                       -(to_16_16_fp(marble_width,0)/2),
                       -(to_16_16_fp(marble_height,0)/2));
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_CMD_SETMATRIX);
  //Render the bitmap it to the current frame
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_VERTEX2F(
                         (marble_x_pos-(marble_width*(16/2))),
                         (marble_y_pos-(marble_height*(16/2)))));
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_END());

  //Reset the matrix . . otherwise further things (like text) in this
  //display list will be goofed.
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_CMD_LOADIDENTITY);
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_CMD_SETMATRIX);

  return(FWol);
  }
//---------------------------------------------------------------------------
void Move_Marble(void)
  {
  //We need the radius, not diameter, and in native x16 units
  uint16_t
    move_marble_width;
  move_marble_width=marble_width*(16/2);
  uint16_t
    move_marble_height;
  move_marble_height=marble_height*(16/2);

  //Move X, bouncing
  if(marble_x_vel < 0)
    {
    //Going left. OK to move again?
    if(0 < (marble_x_pos-(move_marble_width)+marble_x_vel))
      {
      //it will be onscreen after decrease
      marble_x_pos+=marble_x_vel;
      }
    else
      {
      //It would be too small, bounce.
      marble_x_pos=move_marble_width+(move_marble_width-(marble_x_pos+marble_x_vel));
      //Turn around.
      marble_x_vel=-marble_x_vel;
      marble_spin=marble_y_vel;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((marble_x_pos+(move_marble_width)+marble_x_vel) < (int32_t)LCD_WIDTH*16)
      {
      //it will be on screen after increase
      marble_x_pos+=marble_x_vel;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_x_ctr;
      max_x_ctr=(int32_t)LCD_WIDTH*16-move_marble_width;
      marble_x_pos=max_x_ctr-(max_x_ctr-(marble_x_pos+marble_x_vel));
      //Turn around.
      marble_x_vel=-marble_x_vel;
      marble_spin=-marble_y_vel;
      }
    }

  //Move Y, bouncing
  if(marble_y_vel < 0)
    {
    //Going left. OK to move again?
    if(0 < (marble_y_pos-(move_marble_height)+marble_y_vel))
      {
      //it will be onscreen after decrease
      marble_y_pos+=marble_y_vel;
      }
    else
      {
      //It would be too small, bounce.
      marble_y_pos=move_marble_height+(move_marble_height-(marble_y_pos+marble_y_vel));
      //Turn around.
      marble_y_vel=-marble_y_vel;
      marble_spin=-marble_x_vel;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((marble_y_pos+(move_marble_height)+marble_y_vel) < (int32_t)LCD_HEIGHT*16)
      {
      //it will be on screen after increase
      marble_y_pos+=marble_y_vel;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_y_ctr;
      max_y_ctr=(int32_t)LCD_WIDTH*16-move_marble_height;
      marble_y_pos=max_y_ctr-(max_y_ctr-(marble_y_pos+marble_y_vel));
      //Turn around.
      marble_y_vel=-marble_y_vel;
      marble_spin=marble_x_vel;
      }
    }
  //Do the twist.
  marble_rotation+=(marble_spin)/16;
  if(360 < marble_rotation)
    marble_rotation-=360;
  else
    if(marble_rotation < 0)
      marble_rotation+=360;

  }
#endif // (0 != MARBLE_DEMO)
//===========================================================================
#if (0 != BOUNCE_DEMO)
//Keep track of the ball
int32_t
  x_position;
int32_t
  x_velocity;
int32_t
  y_position;
int32_t
  y_velocity;
int32_t
  ball_size;
int32_t
  ball_delta;
//Cycle the color around
uint8_t
  r;
uint8_t
  g;
uint8_t
  b;
uint8_t
  transparency;
uint8_t
  transparency_direction;
//---------------------------------------------------------------------------
void Initialize_Bounce_Demo(void)
  {
  //Choose some starting color
  r=0xff;
  g=0x00;
  b=0x80;

  //Start ghostly, getting more solid.
  transparency=0;
  transparency_direction=1;

  // Define a default point x-location (1/16 anti-aliased)
  x_position = (LCD_WIDTH/2 * 16);
  x_velocity = 3*16;
  // Define a default point y-location (1/16 anti-aliased)
  y_position = (LCD_HEIGHT/2 * 16);
  y_velocity = -2*16;
  //Start small.
  ball_size=50*1;
  ball_delta=1*16;
  }
//---------------------------------------------------------------------------
uint16_t Add_Bounce_To_Display_List(uint16_t FWol)
  {
  // Set the variable color of the bouncing ball
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_COLOR_RGB(r,g,b));
  // Make it transparent
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_COLOR_A(transparency));

  // Draw the ball -- a point (filled circle)
  FWol=EVE_Point(FWol,
                   x_position,y_position,ball_size);

  //========== RUBBER BAND TETHER ==========
  //Draw the rubberband.
  //Maximum stretched would be LCD_WIDTH/2 + LCD_WIDTH/2 (manhatten) make that
  //1 pixels wide, make the minimum 10 pixels wide
  uint16_t
    rubberband_width;
  uint16_t
    x_distance;
  if((x_position/16)<(LCD_WIDTH/2))
    x_distance=(LCD_WIDTH/2)-(x_position/16);
  else
    x_distance=(x_position/16)-(LCD_WIDTH/2);
  uint16_t
    y_distance;
  if((y_position/16)<(LCD_HEIGHT/2))
    y_distance=(LCD_HEIGHT/2)-(y_position/16);
  else
    y_distance=(y_position/16)-(LCD_HEIGHT/2);

  //Straight math does not make it skinny enough. This seems like it should
  //underlow often, but in real life never goes below 1. Need to dissect.
  rubberband_width=10-((9+1)*(x_distance+y_distance))/((LCD_WIDTH/2)+(LCD_HEIGHT/2));
  //Check for underflow just in case.
  if(rubberband_width&0x8000)
    rubberband_width=1;

  //Now that we know the rubberband width, drawing it is simple.
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_COLOR_RGB(200,0,0));
  //(transparency set above still in effect)
  FWol=EVE_Line(FWol,
                  LCD_WIDTH/2,LCD_HEIGHT/2,
                  x_position/16,y_position/16,
                  rubberband_width);
  return(FWol);
  }
//---------------------------------------------------------------------------
void Bounce_Ball(void)
  {
  //Update the colors
  r++;
  g--;
  b+=2;

  //Cycle the transparancy
  if(transparency_direction)
    {
    //Getting more solid
    if(transparency!=255)
      {
      transparency++;
      }
    else
      {
      transparency_direction=0;
      }
    }
  else
    {
    //Getting more clear
    if(128<transparency)
      {
      transparency--;
      }
    else
      {
      transparency_direction=1;
      }
    }

  //========== BOUNCE THE BALL AROUND ==========

  #define MIN_POINT_SIZE (10*16)
//  #define MAX_POINT_SIZE (int32_t)(((LCD_WIDTH/2)-20)*16)
  #define MAX_POINT_SIZE (int32_t)(((LCD_HEIGHT/2)-20)*16)

  //Change the point (ball) size.
  if(ball_delta < 0)
    {
    //Getting smaller. OK to decrease again?
    if(MIN_POINT_SIZE < (ball_size+ball_delta))
      {
      //it will be bigger than min after decrease
      ball_size+=ball_delta;
      }
    else
      {
      //It would be too small, bounce.
      ball_size=MIN_POINT_SIZE+(MIN_POINT_SIZE-(ball_size+ball_delta));
      //Turn around.
      ball_delta=-ball_delta;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((ball_size+ball_delta) < MAX_POINT_SIZE)
      {
      //it will be smaller than max after increase
      ball_size+=ball_delta;
      }
    else
      {
      //It would be too big, bounce.
      ball_size=MAX_POINT_SIZE-(MAX_POINT_SIZE-(ball_size+ball_delta));
      //Turn around.
      ball_delta=-ball_delta;
      }
    }

  //Move X, bouncing
  if(x_velocity < 0)
    {
    //Going left. OK to move again?
    if(0 < (x_position-(ball_size)+x_velocity))
      {
      //it will be onscreen after decrease
      x_position+=x_velocity;
      }
    else
      {
      //It would be too small, bounce.
      x_position=ball_size+(ball_size-(x_position+x_velocity));
      //Turn around.
      x_velocity=-x_velocity;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((x_position+(ball_size)+x_velocity) < (int32_t)LCD_WIDTH*16)
      {
      //it will be on screen after increase
      x_position+=x_velocity;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_x_ctr;
      max_x_ctr=(int32_t)LCD_WIDTH*16-ball_size;
      x_position=max_x_ctr-(max_x_ctr-(x_position+x_velocity));
      //Turn around.
      x_velocity=-x_velocity;
      }
    }

  //Move Y, bouncing
  if(y_velocity < 0)
    {
    //Going left. OK to move again?
    if(0 < (y_position-(ball_size)+y_velocity))
      {
      //it will be onscreen after decrease
      y_position+=y_velocity;
      }
    else
      {
      //It would be too small, bounce.
      y_position=ball_size+(ball_size-(y_position+y_velocity));
      //Turn around.
      y_velocity=-y_velocity;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((y_position+(ball_size)+y_velocity) < (int32_t)LCD_HEIGHT*16)
      {
      //it will be on screen after increase
      y_position+=y_velocity;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_y_ctr;
      max_y_ctr=(int32_t)LCD_WIDTH*16-ball_size;
      y_position=max_y_ctr-(max_y_ctr-(y_position+y_velocity));
      //Turn around.
      y_velocity=-y_velocity;
      }
    }
  }
#endif // (0 != BOUNCE_DEMO)
//============================================================================
#if (0 != LOGO_DEMO)
//Remember where we put the logo image data in RAM_G
uint32_t
  Logo_RAM_G_Address;
//Remember how big the Logo image is.
uint32_t
  Logo_Width;
uint32_t
  Logo_Height;

// Keep track of the logo's orientation
uint16_t
  logo_rotate_degrees;
//Used to pause the logo between spinning sesions
uint16_t
  logo_rotate_pause;
uint8_t
  logo_bitmap_handle;
//----------------------------------------------------------------------------
//Test code to crash coprocessor ever other time it is called --
//for testing Reset_EVE_Coprocessor()
#if (0!=DEBUG_COPROCESSOR_RESET)
uint8_t
 first=0;
#endif // (0!=DEBUG_COPROCESSOR_RESET)

uint16_t Initialize_Logo_Demo(uint16_t FWol,
                              uint32_t *RAM_G_Unused_Start,
                              uint8_t next_bitmap_handle_available)
  {
  //Keep track of our bitmap handle
  logo_bitmap_handle=next_bitmap_handle_available;
  // No rotation to start.
  logo_rotate_degrees=0;
  // Don't spin the logo right away, delay ~8 seconds at 60 frames per second
  logo_rotate_pause=8*60;

  //Remember where we put the logo in RAM_G so we can access it later.
  Logo_RAM_G_Address=*RAM_G_Unused_Start;
#if (0==LOGO_PNG_0_ARGB2_1)
  //Load and expand our 24-bit PNG (true color, lossless, with
  //transparency) into RAM_G
  //An indexed PNG is smaller, but the EVE does not handle
  //indexed color PNGs.
  FWol=EVE_Load_PNG_to_RAM_G(FWol,
                               CFAM1024600xx_070S_PNG_LOGO,
                               LOGO_SIZE_PNG,
                               RAM_G_Unused_Start,
                               &Logo_Width,
                               &Logo_Height);
#endif // 0==LOGO_PNG_0_ARGB2_1

#if (1==LOGO_PNG_0_ARGB2_1)
  //Load and INFLATE our 8-bit A2R2G2B2 (lossless) image into RAM_G

  //You have to know before hand how big the logo is. The INFLATE
  //is not aware of the content or format of the data.
  Logo_Width=LOGO_WIDTH_ARGB2;
  Logo_Height=LOGO_HEIGHT_ARGB2;


//Test code to crash coprocessor ever other time it is called --
//for testing Reset_EVE_Coprocessor()
#if (0 != DEBUG_COPROCESSOR_RESET)
  if(0==first)
    {
    //good
    FWol=EVE_Inflate_to_RAM_G(FWol,
                              CFAM1024600xx_070S_ARGB2_LOGO,
                              LOGO_SIZE_ARGB2,
                              RAM_G_Unused_Start);
    DBG_GEEK("Good inflate\n");
    first=1;
    }
  else
    {
    //bad
    FWol=EVE_Inflate_to_RAM_G(FWol,
                              CFAM1024600xx_070S_ARGB2_LOGO+20,
                              LOGO_SIZE_ARGB2,
                              RAM_G_Unused_Start);
    DBG_GEEK("Bad inflate\n");
    first=0;
    }
#else //(0!=DEBUG_COPROCESSOR_RESET)

  FWol=EVE_Inflate_to_RAM_G(FWol,
                            CFAM1024600xx_070S_ARGB2_LOGO,
                            LOGO_SIZE_ARGB2,
                            RAM_G_Unused_Start);

#endif //(0!=DEBUG_COPROCESSOR_RESET)
                              
#endif // 1==LOGO_PNG_0_ARGB2_1
  //Pass our updated offset back to the caller
  return(FWol);
  }
//----------------------------------------------------------------------------
uint16_t Add_Logo_To_Display_List(uint16_t FWol)
  {
  //========== PUT LOGO ON SCREEN ==========
  // Set the drawing color to white
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_COLOR_A(255));
  //Make sure the EVE has the idea of which bitmap they it
  //should be working on.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BITMAP_HANDLE(logo_bitmap_handle));
  //Point to the uncompressed logo in RAM_G
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_BITMAP_SOURCE(Logo_RAM_G_Address));

#if 0==LOGO_PNG_0_ARGB2_1
  //Transparent PNG comes in as ARGB4, 2 bytes per pixel
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_BITMAP_LAYOUT(EVE_FORMAT_ARGB4,Logo_Width*2,Logo_Height));
#endif // 0==LOGO_PNG_0_ARGB2_1

#if 1==LOGO_PNG_0_ARGB2_1
  //ARGB2 comes in as EVE_FORMAT_ARGB2, 1 byte per pixel
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_BITMAP_LAYOUT(EVE_FORMAT_ARGB2,Logo_Width,Logo_Height));
#endif // 1==LOGO_PNG_0_ARGB2_1

  //In order to have a 240x240 logo rotate without clipping, we have
  //a 240*sqrt(2) x 240*sqrt(2) = 340 x 340 logo, with all the non
  //transparent content kept inside a 240 circle. Whatevs.
  FWol=EVE_Cmd_Dat_0(FWol,
                      EVE_ENC_BITMAP_SIZE(EVE_FILTER_BILINEAR,EVE_WRAP_BORDER,EVE_WRAP_BORDER,Logo_Width,Logo_Height));






   //Rotate the bitmap
  FWol=EVE_Cmd_Dat_0(FWol,
                      EVE_ENC_CMD_LOADIDENTITY);
  //Translate to the center
  FWol=EVE_Cmd_Dat_2(FWol,
                      EVE_ENC_CMD_TRANSLATE,
                      to_16_16_fp(Logo_Width,0)/2,
                      to_16_16_fp(Logo_Height,0)/2);
  //The actual rotate command
  FWol=EVE_Cmd_Dat_1(FWol,
                      EVE_ENC_CMD_ROTATE,
                      to_16_16_fp(logo_rotate_degrees,0)/360);
  //Undo the translation, and move to the center of the screen.
  FWol=EVE_Cmd_Dat_2(FWol,EVE_ENC_CMD_TRANSLATE,
                      (to_16_16_fp(-Logo_Width/2+0/2,0)),
                      (to_16_16_fp(-Logo_Height/2+0/2,0)));
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_CMD_SETMATRIX);
  //Render the bitmap to the current frame
  FWol=EVE_Cmd_Dat_0(FWol,
                      EVE_ENC_VERTEX2F((LCD_WIDTH-Logo_Width)*(16/2),(LCD_HEIGHT-Logo_Height)*(16/2)));


  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_END());


  // ROTATE THE LOGO -- MAINLY BECAUSE WE CAN.
  if(0 == logo_rotate_degrees)
    {
    //upright, stay here for logo_rotate_pause frames
    if(0 != logo_rotate_pause)
      {
      logo_rotate_pause--;
      }
    else
      {
      // ~ 7 seconds at 60 frames per second
      logo_rotate_pause=7*60;
      logo_rotate_degrees=1;
      }
    }
  else
    {
    if(logo_rotate_degrees<359)
      logo_rotate_degrees++;
    else
      logo_rotate_degrees=0;
    }
  //Reset the matrix . . otherwise further things (like text) in this
  //display list will be goofed.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_CMD_LOADIDENTITY);
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_CMD_SETMATRIX);
  //Pass our updated offset back to the caller
  return(FWol);
  }
#endif // (0 != LOGO_DEMO)
//============================================================================
#if (0 != SOUND_DEMO)
//Remember where we put the audio data in RAM_G
uint32_t
  Audio_RAM_G_Address;
//Remember how big the audio data is.
uint32_t
  Audio_RAM_G_Length;
//Keep track of how many times we have played the sound.
uint8_t
  play_times;

//Play the sound in sync with the logo roatating
uint16_t
  sound_logo_rotate_degrees;
uint16_t
  sound_logo_rotate_pause;
//----------------------------------------------------------------------------
uint16_t Initialize_Sound_Demo(uint16_t FWol,
                               uint32_t *RAM_G_Unused_Start)
  {
  //Since the Arduino uSD card is slow, put up a please wait screen.
  FWol=EVE_Busy_SpinFF(FWol,
                       //clear color
                       EVE_ENC_CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                       //text color
                       EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF),
                       //spinner color
                       EVE_ENC_COLOR_RGB(0x00,0xFF,0x00),
#if (0 != SOUND_VOICE)
                       "Loading \"VOI_8K.RAW\" . . .");
#else
                       "Loading \"MUS_8K.RAW\" . . .");
#endif

  //Play the sound the number of times the user requested.
  play_times=SOUND_PLAY_TIMES;
  // Sync the sound start with the logo rotating
  sound_logo_rotate_degrees=0;
  sound_logo_rotate_pause=8*60;

  //Attempt to load our RAW audio file from the uSD into RAM_G
  Audio_RAM_G_Address=*RAM_G_Unused_Start;
  Audio_RAM_G_Length=0;

  //If the Audio_RAM_G_Length returned is 0, then it has probably failed.
  //Not much to do in the way of error recovery though, as the EVE
  //would just be instructed to play a 0-lenght RAM_G buffer, which
  //hopefully it handles gracefully.
  //By the way, it appears that the SD library reports all file names
  //in all upper case. So even though Windows file explorer, CMD,
  //and Power Shell all report the name as lower case, we need to
  //feed the SD library an all uppercase string.
  EVE_Load_File_To_RAM_G(Audio_RAM_G_Address,
#if (0 != SOUND_VOICE)
                     "VOI_8K.RAW",
#else
                     "MUS_8K.RAW",
#endif
                     &Audio_RAM_G_Length);

  //Keep track of the RAM_G memory allocation, force to 8-byte aligned
  *RAM_G_Unused_Start=(*RAM_G_Unused_Start+Audio_RAM_G_Length+0x07)&0xFFFFFFF8;

  //Pass our updated offset back to the caller
  return(FWol);
  }
//----------------------------------------------------------------------------
void Start_Sound_Demo_Playing(void)
  {
  if(1 == sound_logo_rotate_degrees)
    {
    if(0 != play_times)
      {
      //Do not start unless the previous sound has completed
      //1-audio playback is going on
      //0-audio playback has finished
      if(0 == EVE_REG_Read_8(EVE_REG_PLAYBACK_PLAY))
        {
        //Remember that we played the sound
        play_times--;
#if (0 != SOUND_VOICE)
        DBG_GEEK("Playing: \"VOI_8K.RAW\".\n");
#else
        DBG_GEEK("Playing: \"MUS_8K.RAW\".\n");
#endif
#if 1 //Audio file
        //Point the EVE audio stuff at our RAM_G audio data. Let it go.
        EVE_REG_Write_32(EVE_REG_PLAYBACK_START,Audio_RAM_G_Address);
        EVE_REG_Write_32(EVE_REG_PLAYBACK_LENGTH,Audio_RAM_G_Length);
        EVE_REG_Write_32(EVE_REG_PLAYBACK_FREQ,8000);
        EVE_REG_Write_32(EVE_REG_PLAYBACK_FORMAT,EVE_ULAW_SAMPLES);
        EVE_REG_Write_32(EVE_REG_VOL_PB,0);
        EVE_REG_Write_32(EVE_REG_PLAYBACK_LOOP,0);
        EVE_REG_Write_32(EVE_REG_PLAYBACK_PLAY,1);
        //Ramp the volume to avoid the pop at the start of playback
        //This is optional.
        for(uint8_t vol=1; 255 != vol;vol++)
          {
          EVE_REG_Write_32(EVE_REG_VOL_PB,vol);
          }
#endif
#if 0 //Synthesizer

        //Triangle wave
        EVE_REG_Write_8(EVE_EVE_REG_VOL_SOUND,96);
        EVE_REG_Write_16(EVE_EVE_REG_SOUND,0x04);
        EVE_REG_Write_8(EVE_EVE_REG_PLAY,1);
        DBG_GEEK("Playing synth . . . ");

//while(0 != EVE_REG_Read_8(EVE_REG_PLAY));
 //       SerPrintFF(F("done.\n"));
#endif

        }
      }
    }
  // Sync the sound start with the logo rotating
  if(0 == sound_logo_rotate_degrees)
    {
    //upright, stay here for logo_rotate_pause frames
    if(0 != sound_logo_rotate_pause)
      {
      sound_logo_rotate_pause--;
      }
    else
      {
      // ~ 7 seconds at 60 frames per second
      sound_logo_rotate_pause=7*60;
      sound_logo_rotate_degrees=1;
      }
    }
  else
    {
    if(sound_logo_rotate_degrees<359)
      sound_logo_rotate_degrees++;
    else
      sound_logo_rotate_degrees=0;
    }
  }
#endif // (0 != SOUND_DEMO)
//============================================================================
#if (0 != MANUAL_BACKLIGHT_DEBUG)
// Changes backlight from 0 to 128 over 5% to 95% of axis
uint16_t Set_Backlight_From_Touch(uint16_t FWol,
                                  uint32_t touch_coordiante,
                                  uint32_t axis_range)
  {
  int32_t
    BL_Val;
  // 0 at 5%, 128 %95%
  BL_Val = ((((int32_t)touch_coordiante-(int32_t)(axis_range/20)))*((int32_t)128)) / ((int32_t)(axis_range*0.9));
  if(BL_Val < 0)
    {
    BL_Val=0;
    }
  if(128<BL_Val)
    {
    BL_Val=128;
    }
  //Write the actual value
  EVE_REG_Write_8(EVE_REG_PWM_DUTY,BL_Val);
  //Write to the console
  DBG_GEEK("BL Set to: %3d\n",BL_Val);
  //Write to the LCD
  //Solid text
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_COLOR_A(0xFF));
  // Make it Green
  FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_COLOR_RGB(0x80,0x80,0xFF));
  //Put the backlight value on the screen
  FWol=EVE_PrintF(FWol,
                  10,
                  10,
                  25,         //Font
                  0,          //Options
                  "Backlight: %3d",
                  BL_Val);
  return(FWol);
  }
#endif // (0 != MANUAL_BACKLIGHT_DEBUG)
//============================================================================
#if (0 != VIDEO_DEMO)
#define FLASH_VIDEO_WIDTH  ((uint16_t)400)
#define FLASH_VIDEO_HEIGHT ((uint16_t)240)
//Keep track of the frame
uint8_t
  video_frame_delay;
//Use these to bounce the video around the screen.
int32_t
  video_x_pos;
int32_t
  video_x_vel;
int32_t
  video_y_pos;
int32_t
  video_y_vel;
uint32_t
  RAM_G_video_completion_flag_Address;
uint32_t
  RAM_G_bitmap_Address;
uint8_t
  video_bitmap_handle;
//---------------------------------------------------------------------------
// Requires that the flash was previously programmed by using the uSD and
// the PROGRAM_FLASH_FROM_USD switch.
uint16_t Initialize_Video_Demo(uint16_t FWol,
                                uint32_t *RAM_G_Unused_Start,
                                uint8_t next_bitmap_handle_available)
  {
  //Keep track of our bitmap handle
  video_bitmap_handle=next_bitmap_handle_available;
  video_frame_delay=0;
  //these are in pixel/16
  video_x_pos=(LCD_WIDTH-FLASH_VIDEO_WIDTH)<<3;
  video_x_vel=14;
  video_x_pos=(LCD_HEIGHT-FLASH_VIDEO_HEIGHT)<<3;
  video_y_vel=20;
  //Reserve 4 bytes in RAM_G for the video decoder to store its
  //completion flag into.
  RAM_G_video_completion_flag_Address=*RAM_G_Unused_Start;
  *RAM_G_Unused_Start+=4;
  //Reserve an area of RAM_G for the bitmap to fit into. The video decoder
  //uses EVE_FORMAT_RGB565 so the area needed is 2x width * height
  RAM_G_bitmap_Address=*RAM_G_Unused_Start;
  *RAM_G_Unused_Start+=(FLASH_VIDEO_WIDTH * 2L) * FLASH_VIDEO_HEIGHT;  
  //Point the video decoder to the video which is stored in flash
  FWol=EVE_Cmd_Dat_1(FWol,
                     EVE_ENC_CMD_FLASHSOURCE,
                     FLASH_SECTOR_ICE_FPV_512x300<<12);
  //Initialize the video decoder based on the flash address that
  //we just wrote.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_CMD_VIDEOSTARTF);
  // Update the ring buffer pointer so the graphics processor starts executing
  EVE_REG_Write_16(EVE_REG_CMD_WRITE, (FWol));
  return(FWol);
  }
//---------------------------------------------------------------------------
#if (0 != TOUCH_DEMO)
uint16_t Add_Video_To_Display_List(uint16_t FWol,
                                   uint8_t points_touched_mask,
                                   int16_t *x_points,
                                   int16_t *y_points)
#else // (0 != TOUCH_DEMO)
uint16_t Add_Video_To_Display_List(uint16_t FWol)
#endif // (0 != TOUCH_DEMO)
  {
  // Set the drawing color to white
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=EVE_Cmd_Dat_0(FWol, EVE_ENC_COLOR_A(255));
  //Set up the bitmap
  FWol=EVE_Set_Bitmap(FWol,
                      //uint8_t  handle,
                      video_bitmap_handle,
                      //uint32_t source
                      RAM_G_bitmap_Address,
                      //uint8_t  format
                      EVE_FORMAT_RGB565,
                      //uint16_t width (of the window the bitmap can be seen through)
                      LCD_WIDTH,
                      //uint16_t height (of the window the bitmap can be seen through)
                      LCD_HEIGHT,
                      //uint16_t colstride
                      FLASH_VIDEO_WIDTH*2,
                      //uint16_t rowstride
                      FLASH_VIDEO_HEIGHT,
                      //uint8_t  filter
                      EVE_FILTER_NEAREST,
                      //uint8_t  wrapx
                      EVE_WRAP_BORDER,
                      //uint8_t  wrapy
                      EVE_WRAP_BORDER);
#if (0 != TOUCH_DEMO)
  //If there is only one point touched, center the video on
  //that point.
  if((0x01 == points_touched_mask))
    {
    video_x_pos=(int32_t)(((int32_t)x_points[0]<<4) - ((int32_t)FLASH_VIDEO_WIDTH<<3));
    video_y_pos=(int32_t)(((int32_t)y_points[0]<<4) - ((int32_t)FLASH_VIDEO_HEIGHT<<3));
    FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));     
    FWol=EVE_Cmd_Dat_0(FWol,
                       EVE_ENC_VERTEX2F(video_x_pos,
                                        video_y_pos));
    }
  else
    {
    //If there are exactly two points touched, position based on the
    //center between the two points, scale based on the X distance
    //between them.
    if(0x03 == points_touched_mask)
      {
      //Give it a stretch. Just use horiziontal to keep it sane.
      uint32_t
        x_left;
      uint32_t
        x_right;
      if(x_points[0] < x_points[1])
        {
        x_left=x_points[0];
        x_right=x_points[1];
        }
      else
        {
        x_left=x_points[1];
        x_right=x_points[0];
        }
      uint32_t
        scaled_width;
      scaled_width=x_right-x_left;
      uint32_t
        scaled_height;
      scaled_height=(((((uint32_t)scaled_width)*((uint32_t)FLASH_VIDEO_HEIGHT))/((uint32_t)FLASH_VIDEO_WIDTH)));
      // If scaleby is the same as LCD_WIDTH, the we want the video to
      // be LCD_WIDTH. The result has to be fixed point 16.16.
      uint32_t
        scale_factor;
      scale_factor=(scaled_width<<16)/FLASH_VIDEO_WIDTH;
      //Scale the bitmap, start with a NOP matrix
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_CMD_LOADIDENTITY);
      //The scale command. This scales the image from the 
      //upper-left of both the image and the screen.
      FWol=EVE_Cmd_Dat_2(FWol,
                         EVE_ENC_CMD_SCALE,
                         scale_factor,
                         scale_factor);
      //Implement the transformation      
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_CMD_SETMATRIX);
      //Now the image scaled correctly. We need to translate it so it is
      //centered at the average of the two touch points. The VERTEX2F
      //wants x16 inputs, which is a shift of 4, but we need the average
      //which is a /2 so combining these gives us a shift of 3.
      video_x_pos=(int32_t)(((int32_t)x_left<<4));
      video_y_pos=(int32_t)(((y_points[0]+y_points[1])<<3) - (scaled_height<<3));
      //Now we can place it on the screen
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));     
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_VERTEX2F(video_x_pos,
                                          video_y_pos));
      }
    else
      {
      //no points touched, just put it at the scrolling offset.
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));     
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_VERTEX2F(video_x_pos,video_y_pos));
      }
    }
#else // (0 != TOUCH_DEMO)
  //no points touched, just put it at the scrolling offset.
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_BEGIN(EVE_BEGIN_BITMAPS));     
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_VERTEX2F(video_x_pos,video_y_pos));
#endif // (0 != TOUCH_DEMO)
  //Close the bitmap BEGIN
  FWol=EVE_Cmd_Dat_0(FWol,
                     EVE_ENC_END());
  return(FWol);
  }
//---------------------------------------------------------------------------
uint16_t Update_Video_Frame(uint16_t FWol)
  {
  //Mainloop ticks along at the frame rate. The frame rate should be set
  //up for 60Hz. The video is encoded at 30Hz, so we need to get a new
  //video frame every other mainloop.
  if(1 <= video_frame_delay)
    {
    //reset frame counter.
    video_frame_delay=0;
    //Bounce the video around the screen.
    //Move X, bouncing
    if(video_x_vel < 0)
      {
      //Going left. OK to move again?
      if((video_x_pos+video_x_vel) < 0)
        {
        //It would be too small, turn it around.
        video_x_vel=-video_x_vel;
        }
      video_x_pos+=video_x_vel;
      }
    else
      {
      //Getting larger. OK to increase again?
      if((LCD_WIDTH*16) < (video_x_pos + (FLASH_VIDEO_WIDTH*16) + video_x_vel))
        {
        //It would be too large, turn it around.
        video_x_vel=-video_x_vel;
        }
      video_x_pos+=video_x_vel;
      }
    //Move Y, bouncing
    if(video_y_vel < 0)
      {
      //Going up. OK to move again?
      if((video_y_pos+video_y_vel) < 0)
        {
        //It would be too small, turn it around.
        video_y_vel=-video_y_vel;
        }
      }
    else
      {
      //Going down. OK to increase again?
      if((LCD_HEIGHT*16) < (video_y_pos + (FLASH_VIDEO_HEIGHT*16) + video_y_vel))
        {
        //It would be too large, turn it around.
        video_y_vel=-video_y_vel;
        }
      }
    video_y_pos+=video_y_vel;
    //The previous video frame render should be complete by now. Check
    //and see if rendering that frame completed the video.
    if(0 == EVE_REG_Read_32(RAM_G_video_completion_flag_Address))
      {
      DBG_GEEK("Video complete, looping.\n");
      //Rewind to the start of the video in flash.
      FWol=EVE_Cmd_Dat_1(FWol,
                         EVE_ENC_CMD_FLASHSOURCE,
                         FLASH_SECTOR_ICE_FPV_512x300<<12);
      FWol=EVE_Cmd_Dat_0(FWol,
                         EVE_ENC_CMD_VIDEOSTARTF);     
      }
    //Ask the EVE to render the next video frame into the area
    //we reserved for it in RAM_G
    FWol=EVE_Cmd_Dat_2(FWol,
                       EVE_ENC_CMD_VIDEOFRAME,
                       //Memory location to load the frame data, this will be located in RAM_G.
                       RAM_G_bitmap_Address,
                       //Completion pointer address, also in RAM_G
                       RAM_G_video_completion_flag_Address);
    }
  else
    {
    video_frame_delay++;
    }
  return(FWol);
  }
#endif // (0 != VIDEO_DEMO)
//===========================================================================
