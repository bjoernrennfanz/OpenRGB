#include "Detector.h"
#include "RazerController.h"
#include "RazerDevices.h"
#include "RGBController.h"
#include "RGBController_Razer.h"
#include <hidapi/hidapi.h>

/******************************************************************************************\
*                                                                                          *
*   DetectRazerControllers                                                                 *
*                                                                                          *
*       Tests the USB address to see if a Razer controller exists there.                   *
*                                                                                          *
\******************************************************************************************/

void DetectRazerControllers(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);

    if( dev )
    {
        RazerController* controller = new RazerController(dev, info->path, info->product_id, name);

        RGBController_Razer* rgb_controller = new RGBController_Razer(controller);
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}   /* DetectRazerControllers() */

/*-----------------------------------------------------------------------------------------------------*\
| Keyboards                                                                                             |
\*-----------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_PU("Razer Blackwidow Chroma",                         DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_CHROMA_PID,            1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blackwidow Chroma V2",                      DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_CHROMA_V2_PID,         1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blackwidow Chroma Tournament Edition",      DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_CHROMA_TE_PID,         1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blackwidow Overwatch",                      DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_OVERWATCH_PID,         1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blackwidow X Chroma",                       DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_X_CHROMA_PID,          1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blackwidow X Chroma Tournament Edition",    DetectRazerControllers, RAZER_VID,  RAZER_BLACKWIDOW_X_CHROMA_TE_PID,       1,  2);
REGISTER_HID_DETECTOR_PU("Razer Cynosa Chroma",                             DetectRazerControllers, RAZER_VID,  RAZER_CYNOSA_CHROMA_PID,                1,  2);
REGISTER_HID_DETECTOR_PU("Razer Cynosa Chroma V2",                          DetectRazerControllers, RAZER_VID,  RAZER_CYNOSA_V2_PID,                    1,  2);
REGISTER_HID_DETECTOR_PU("Razer Deathstalker Chroma",                       DetectRazerControllers, RAZER_VID,  RAZER_DEATHSTALKER_CHROMA_PID,          1,  2);
REGISTER_HID_DETECTOR_PU("Razer Huntsman",                                  DetectRazerControllers, RAZER_VID,  RAZER_HUNTSMAN_PID,                     1,  2);
REGISTER_HID_DETECTOR_PU("Razer Huntsman Elite",                            DetectRazerControllers, RAZER_VID,  RAZER_HUNTSMAN_ELITE_PID,               1,  2);
REGISTER_HID_DETECTOR_PU("Razer Huntsman Tournament Edition",               DetectRazerControllers, RAZER_VID,  RAZER_HUNTSMAN_TE_PID,                  1,  2);
REGISTER_HID_DETECTOR_PU("Razer Ornata Chroma",                             DetectRazerControllers, RAZER_VID,  RAZER_ORNATA_CHROMA_PID,                1,  2);

/*-----------------------------------------------------------------------------------------------------*\
| Keypads                                                                                               |
\*-----------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_PU("Razer Orbweaver Chroma",                          DetectRazerControllers, RAZER_VID,  RAZER_ORBWEAVER_CHROMA_PID,             1,  2);
REGISTER_HID_DETECTOR_PU("Razer Tartarus Chroma",                           DetectRazerControllers, RAZER_VID,  RAZER_TARTARUS_CHROMA_PID,              1,  2);

/*-----------------------------------------------------------------------------------------------------*\
| Laptops                                                                                               |
\*-----------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_PU("Razer Blade Pro",                                 DetectRazerControllers, RAZER_VID,  RAZER_BLADE_PRO_LATE_2016_PID,          1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blade Pro (2017)",                          DetectRazerControllers, RAZER_VID,  RAZER_BLADE_PRO_2017_PID,               1,  2);
REGISTER_HID_DETECTOR_PU("Razer Blade Stealth",                             DetectRazerControllers, RAZER_VID,  RAZER_BLADE_STEALTH_PID,                1,  2);

/*-----------------------------------------------------------------------------------------------------*\
| Mice                                                                                                  |
\*-----------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_PU("Razer Deathadder Chroma",                         DetectRazerControllers, RAZER_VID,  RAZER_DEATHADDER_CHROMA_PID,            1,  2);
REGISTER_HID_DETECTOR_PU("Razer Deathadder V2",                             DetectRazerControllers, RAZER_VID,  RAZER_DEATHADDER_V2_PID,                1,  2);
REGISTER_HID_DETECTOR_PU("Razer Diamondback",                               DetectRazerControllers, RAZER_VID,  RAZER_DIAMONDBACK_CHROMA_PID,           1,  2);
REGISTER_HID_DETECTOR_PU("Razer Mamba Elite",                               DetectRazerControllers, RAZER_VID,  RAZER_MAMBA_ELITE_PID,                  1,  2);
REGISTER_HID_DETECTOR_PU("Razer Mamba Tournament Edition",                  DetectRazerControllers, RAZER_VID,  RAZER_MAMBA_TE_WIRED_PID,               1,  2);
REGISTER_HID_DETECTOR_PU("Razer Naga Chroma",                               DetectRazerControllers, RAZER_VID,  RAZER_NAGA_CHROMA_PID,                  1,  2);
REGISTER_HID_DETECTOR_PU("Razer Naga Epic Chroma",                          DetectRazerControllers, RAZER_VID,  RAZER_NAGA_EPIC_CHROMA_PID,             1,  2);

/*-----------------------------------------------------------------------------------------------------*\
| Accessories                                                                                           |
\*-----------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_PU("Razer Base Station Chroma",                       DetectRazerControllers, RAZER_VID,  RAZER_CHROMA_BASE_PID,                  1,  2);
REGISTER_HID_DETECTOR_PU("Razer Base Station V2 Chroma",                    DetectRazerControllers, RAZER_VID,  RAZER_BASE_STATION_V2_CHROMA_PID,       1,  2);
REGISTER_HID_DETECTOR_PU("Razer Chroma HDK",                                DetectRazerControllers, RAZER_VID,  RAZER_CHROMA_HDK_PID,                   1,  2);
REGISTER_HID_DETECTOR_PU("Razer Chroma Mug Holder",                         DetectRazerControllers, RAZER_VID,  RAZER_CHROMA_MUG_PID,                   1,  2);
REGISTER_HID_DETECTOR_PU("Razer Core",                                      DetectRazerControllers, RAZER_VID,  RAZER_CORE_PID,                         1,  2);
REGISTER_HID_DETECTOR_PU("Razer Firefly",                                   DetectRazerControllers, RAZER_VID,  RAZER_FIREFLY_PID,                      1,  2);
REGISTER_HID_DETECTOR_PU("Razer Firefly Hyperflux",                         DetectRazerControllers, RAZER_VID,  RAZER_FIREFLY_HYPERFLUX_PID,            1,  2);
REGISTER_HID_DETECTOR_PU("Razer Goliathus",                                 DetectRazerControllers, RAZER_VID,  RAZER_GOLIATHUS_CHROMA_PID,             1,  2);
REGISTER_HID_DETECTOR_PU("Razer Goliathus Extended",                        DetectRazerControllers, RAZER_VID,  RAZER_GOLIATHUS_CHROMA_EXTENDED_PID,    1,  2);
REGISTER_HID_DETECTOR_PU("Razer Kraken Kitty Edition",                      DetectRazerControllers, RAZER_VID,  RAZER_KRAKEN_KITTY_EDITION_PID,         1,  2);
REGISTER_HID_DETECTOR_PU("Razer Mouse Bungee V3 Chroma",                    DetectRazerControllers, RAZER_VID,  RAZER_MOUSE_BUNGEE_V3_CHROMA_PID,       1,  2);
REGISTER_HID_DETECTOR_PU("Razer Nommo Chroma",                              DetectRazerControllers, RAZER_VID,  RAZER_NOMMO_CHROMA_PID,                 1,  3);
REGISTER_HID_DETECTOR_PU("Razer Nommo Pro",                                 DetectRazerControllers, RAZER_VID,  RAZER_NOMMO_PRO_PID,                    1,  3);
