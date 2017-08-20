#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
    //Enable AUX SERVO OUTPUT channels
    hal.rcout->enable_ch(CH_9);
    hal.rcout->enable_ch(CH_10);
    hal.rcout->enable_ch(CH_11);
    hal.rcout->enable_ch(CH_12);
    hal.rcout->enable_ch(CH_13);
    hal.rcout->enable_ch(CH_14);
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
    user_debug_param=user_debug_param+user_sign;
    if (user_debug_param>2200)
    {
       user_sign=-1;
    }

    if (user_debug_param<1500)
    {
        user_sign=1;
    }

    hal.rcout->write((CH_9), user_debug_param);

}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here

    //if (hal.rcin->new_input()) {
//          vtol_servo_cmd=hal.rcin->read(CH_6);
//
//          elevon_servo_enable=hal.rcin->read(CH_7);
//          rx_ch2= (float) hal.rcin->read(CH_2);
//          rx_ch1= (float) hal.rcin->read(CH_1);  //CH_1:Roll
//
//          //to limit channel 6
//          if(vtol_servo_cmd<1000)
//          {
//              vtol_servo_cmd=1000;
//          }
//
//          if(vtol_servo_cmd>1800)
//          {
//              vtol_servo_cmd=1800;
//          }
//
//          //1500: yatay
//          //2300: dikey
//
//          rf=3300-vtol_servo_cmd+g.rf_trim;
//          rb=3300-vtol_servo_cmd+g.rb_trim;
//          lf=3300-vtol_servo_cmd+g.lf_trim;
//          lb=3300-vtol_servo_cmd+g.lb_trim;
//
//          if (elevon_servo_enable>1600)
//          {
//              servo1_cmd=(int)((-(rx_ch1-1500.0f)*0.5f) + ((rx_ch2-1500.0f)*0.5f) + 1500.0f);
//              servo2_cmd=(int)((-(rx_ch1-1500.0f)*0.5f) - ((rx_ch2-1500.0f)*0.5f) + 1500.0f);
//          }
//          else
//          {
//              servo1_cmd=1500;
//              servo2_cmd=1500;
//          }
//          hal.rcout->cork();
//          hal.rcout->write((CH_9), rf); // Copy input to Servos
//          hal.rcout->write((CH_10), rb); // Copy input to Servos
//          hal.rcout->write((CH_11), lf); // Copy input to Servos
//          hal.rcout->write((CH_12), lb); // Copy input to Servos
//          hal.rcout->write((CH_13), servo1_cmd); // Copy input to Servos
//          hal.rcout->write((CH_14), servo2_cmd); // Copy input to Servos
//          hal.rcout->push();

     //}
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif
