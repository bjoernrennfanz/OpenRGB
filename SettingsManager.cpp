/*-----------------------------------------*\
|  SettingsManager.cpp                      |
|                                           |
|  OpenRGB Settings Manager maintains a list|
|  of application settings in JSON format.  |
|  Other components may register settings   |
|  with this class and store/load values.   |
|                                           |
|  Adam Honse (CalcProgrammer1) 11/4/2020   |
\*-----------------------------------------*/

#include "SettingsManager.h"

#include <fstream>
#include <iostream>

SettingsManager::SettingsManager()
{

}

SettingsManager::~SettingsManager()
{

}

json SettingsManager::GetSettings(std::string settings_key)
{
    /*---------------------------------------------------------*\
    | Check to see if the key exists in the settings store and  |
    | return the settings associated with the key if it exists  |
    \*---------------------------------------------------------*/
    if(settings_data.contains(settings_key))
    {
        return(settings_data[settings_key]);
    }

    /*---------------------------------------------------------*\
    | If the settings store doesn't contain the key, create an  |
    | empty json and return it                                  |
    \*---------------------------------------------------------*/
    json empty;

    return(empty);
}

void SettingsManager::LoadSettings(std::string filename)
{
    /*---------------------------------------------------------*\
    | Open input file in binary mode                            |
    \*---------------------------------------------------------*/
    std::ifstream settings_file(filename, std::ios::in | std::ios::binary);

    /*---------------------------------------------------------*\
    | Read settings into JSON store                             |
    \*---------------------------------------------------------*/
    if(settings_file)
    {
        try
        {
            settings_file >> settings_data;
        }
        catch(std::exception e)
        {
            /*-------------------------------------------------*\
            | If an exception was caught, that means the JSON   |
            | parsing failed.  Clear out any data in the store  |
            | as it is corrupt.                                 |
            \*-------------------------------------------------*/
            settings_data.clear();
        }
    }
}
