package org.hopto.raspberryddns.aquarium;

/**
 * Created by android on 24/05/2018.
 */

class MisureElemMinute {
    String time_min;
    private int index;
    float temp_min;
    float ph_min;
    float lev_min;
    float lig_min;
    Boolean fan_min;
    Boolean pot_min;
    Boolean co2_min;

    MisureElemMinute(String time_min) {
        this.time_min = time_min + "0";
        this.temp_min = (float)0;
        this.ph_min = (float)0;
        this.lev_min = (float)0;
        this.lig_min = (float)0;
        this.fan_min = false;
        this.pot_min = false;
        this.co2_min = false;
        this.index = 0;
    }

    void addMisure(String temp, String ph, String lev, String lig, String fan, String pot, String co2){
        try {
            temp_min = (temp_min*index+Float.parseFloat(temp))/(float)(index+1);
            ph_min = (ph_min*index+Float.parseFloat(ph))/(float)(index+1);
            lev_min = (lev_min*index+Float.parseFloat(lev))/(float)(index+1);
            lig_min = (lig_min*index+Float.parseFloat(lig))/(float)(index+1);
            fan_min |= (fan.equals("1"));
            pot_min |= (pot.equals("1"));
            co2_min |= (co2.equals("1"));
            index++;
        }catch(Exception ignored){

        }
    }

}
