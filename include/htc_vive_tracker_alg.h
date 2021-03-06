// Copyright (C) 2010-2011 Institut de Robotica i Informatica Industrial, CSIC-UPC.
// Author 
// All rights reserved.
//
// This file is part of iri-ros-pkg
// iri-ros-pkg is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// IMPORTANT NOTE: This code has been generated through a script from the 
// iri_ros_scripts. Please do NOT delete any comments to guarantee the correctness
// of the scripts. ROS topics can be easly add by using those scripts. Please
// refer to the IRI wiki page for more information:
// http://wikiri.upc.es/index.php/Robotics_Lab

#ifndef _htc_vive_tracker_alg_h_
#define _htc_vive_tracker_alg_h_

#include <iri_htc_vive_tracker/HtcViveTrackerConfig.h>
#include <math.h>


//include htc_vive_tracker_alg main library
#include "htc_vive_tracker.h"

/**
 * \brief IRI ROS Specific Driver Class
 *
 *
 */
class HtcViveTrackerAlgorithm
{
  protected:
   /**
    * \brief define config type
    *
    * Define a Config type with the HtcViveTrackerConfig. All driver implementations
    * will then use the same variable type Config.
    */
    pthread_mutex_t access_;    


    // private attributes and methods

    CHtc_Vive_Tracker htc_vive_;
  public:
   /**
    * \brief define config type
    *
    * Define a Config type with the HtcViveTrackerConfig. All driver implementations
    * will then use the same variable type Config.
    */
    typedef iri_htc_vive_tracker::HtcViveTrackerConfig Config;
    const std::string BASE_NAME = "iri_wam_link_base";
    const std::string WORLD_NAME = "chaperone";
    const std::string DEVICE_NOT_FOUND_MSG = "Device not found";


   /**
    * \brief config variable
    *
    * This variable has all the driver parameters defined in the cfg config file.
    * Is updated everytime function config_update() is called.
    */
    Config config_;

   /**
    * \brief constructor
    *
    * In this constructor parameters related to the specific driver can be
    * initalized. Those parameters can be also set in the openDriver() function.
    * Attributes from the main node driver class IriBaseDriver such as loop_rate,
    * may be also overload here.
    */
    HtcViveTrackerAlgorithm(void);

   /**
    * \brief Lock Algorithm
    *
    * Locks access to the Algorithm class
    */
    void lock(void) { pthread_mutex_lock(&this->access_); };

   /**
    * \brief Unlock Algorithm
    *
    * Unlocks access to the Algorithm class
    */
    void unlock(void) { pthread_mutex_unlock(&this->access_); };

   /**
    * \brief Tries Access to Algorithm
    *
    * Tries access to Algorithm
    * 
    * \return true if the lock was adquired, false otherwise
    */
    bool try_enter(void) 
    { 
      if(pthread_mutex_trylock(&this->access_)==0)
        return true;
      else
        return false;
    };

   /**
    * \brief config update
    *
    * In this function the driver parameters must be updated with the input
    * config variable. Then the new configuration state will be stored in the 
    * Config attribute.
    *
    * \param new_cfg the new driver configuration state
    *
    * \param level level in which the update is taken place
    */
    void config_update(Config& config, uint32_t level=0);

    // here define all htc_vive_tracker_alg interface methods to retrieve and set
 
    bool InitVR(bool verbose);
    bool GetDevicePositionQuaternion(const std::string & device_name, double (&pose)[3], double (&quaternion)[4]);
    bool GetDevicePositionEuler(const std::string & device_name, double (&pose)[3], double &roll, double & pitch, double & yaw);
    Velocity GetDeviceVelocity(const std::string & device_name);

    bool GetDeviceNames(std::vector<std::string>&device_names);

    Dimension GetChaperoneDimensions();
    bool PollEvents();

    bool IsDeviceDetected (const std::string device_name);
    float GetBatteryLevel(const std::string & device_name);
    vr::EVRButtonId GetPressedButton(const std::string & device_name);

    
    bool TriggerHapticPulse(const std::string & device_name, uint32_t strength);

    // the driver parameters

   /**
    * \brief Destructor
    *
    * This destructor is called when the object is about to be destroyed.
    *
    */
    ~HtcViveTrackerAlgorithm(void);

    
    // Calls the initialization functions for HTC vive. 

	
};

#endif
