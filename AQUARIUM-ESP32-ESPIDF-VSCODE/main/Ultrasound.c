
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <esp_log.h>
#include <driver/gpio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "Ultrasound.h"
#include "Globals.h"

uint32_t endTime;
uint32_t startTime;
uint16_t Prev_distance = 0;
uint16_t distance = 0;
static char tag[]="ultrasound";
bool enable1=false;

SemaphoreHandle_t xEcho = NULL;


// Similar to uint32_t system_get_time(void)
uint32_t get_usec() {

 struct timeval tv;

 //              struct timeval {
 //                time_t      tv_sec;     // seconds
 //                suseconds_t tv_usec;    // microseconds
 //              };

 gettimeofday(&tv,NULL);
 return (tv.tv_sec*1000000 + tv.tv_usec);


  //uint64_t tmp=get_time_since_boot();
  //uint32_t ret=(uint32_t)tmp;
  //return ret;
}

//
// Toggle trig pin and wait for input on echo pin 
//
/*
void ultraDistanceTask(void *params) {

    //gpio_pad_select_gpio(TRIG_PIN);
    //gpio_pad_select_gpio(ECHO_PIN);

    //gpio_set_direction(TRIG_PIN, GPIO_MODE_OUTPUT);
    //gpio_set_direction(ECHO_PIN, GPIO_MODE_INPUT);

        // HC-SR04P
        gpio_set_level(TRIG_PIN, 1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(TRIG_PIN, 0);
        uint32_t startTime1=get_usec();

        while (gpio_get_level(ECHO_PIN)==0 && get_usec()-startTime1 < 500*1000)
        {
            // Wait until echo goes high
        }

        startTime1=get_usec();

        while (gpio_get_level(ECHO_PIN)==1 && get_usec()-startTime1 < 500*1000)
        {
            // Wait until echo goes low again
        }

        if (gpio_get_level(ECHO_PIN) == 0)
        {
            uint32_t diff = get_usec() - startTime1; // Diff time in uSecs
            // Distance is TimeEchoInSeconds * SpeeOfSound / 2
            double distance = 340.29 * diff / (1000 * 1000 * 2); // Distance in meters
            printf("Distance is %f cm\n", distance * 100);
        }
        else
        {
            // No value
            printf("Did not receive a response!\n");
        }

}*/

void gpio_isr_handle(void* args){ //IRAM_ATTR
    //uint32_t gpio_num_isr = (uint32_t)args;
    if(enable1&&gpio_get_level(ECHO_PIN)==1){
    startTime=get_usec();
    //xSemaphoreGiveFromISR(xEcho,NULL);
    //printf(endTime);
    }
    if(enable1&&gpio_get_level(ECHO_PIN)==0){
    endTime=get_usec();
    xSemaphoreGiveFromISR(xEcho,NULL);
    //printf(endTime);
    }    
} 
/*
void echo_handle(void* args){
    for(;;){
        //if(xSemaphoreTake(xEcho,portMAX_DELAY)==pdTRUE){
            //ESP_LOGI(tag, "GET semaphore");
            //printf("ciao");
            //if(gpio_num_isr == ECHO_PIN){
                //endTime=get_usec();
            //}
        //}
    }
}*/

void ultra_init(void* args){

    ESP_LOGI(tag, "PINS initializing");

    gpio_pad_select_gpio(TRIG_PIN);
    gpio_pad_select_gpio(ECHO_PIN);

    gpio_set_direction(TRIG_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(ECHO_PIN, GPIO_MODE_INPUT);

    ESP_LOGI(tag, "INTERRUPT initializing");

    ESP_ERROR_CHECK(gpio_set_intr_type(ECHO_PIN,GPIO_INTR_ANYEDGE));
    ESP_ERROR_CHECK(gpio_install_isr_service(ESP_INTR_FLAG_IRAM));
    //gpio_intr_enable(ECHO_PIN);
    ESP_ERROR_CHECK(gpio_isr_handler_add(ECHO_PIN,gpio_isr_handle,(void*)ECHO_PIN));

    TaskHandle_t x=NULL;
    xEcho = xSemaphoreCreateBinary();
    //ESP_ERROR_CHECK(xTaskCreate(echo_handle,"echo_handle",8192,NULL,9,&x));
    //configASSERT(x);
    
    ESP_LOGI(tag, "ULTRASOUND initialized");

    ultra_trig(true);

}

uint16_t ultra_trig(bool firstTime){
    endTime = 0;
    startTime = 0;
    enable1=true;
    gpio_set_level(TRIG_PIN, 1);
    ets_delay_us(10);//vTaskDelay(1 / portTICK_PERIOD_MS);
    gpio_set_level(TRIG_PIN, 0);
    //startTime = get_usec();
    if(xSemaphoreTake(xEcho,10)==pdTRUE){ //la routine impiega 708mm
            //endTime=get_usec();
            //ESP_LOGI(tag, "GET semaphore2");
    }
    //xSemaphoreGive(xEcho);
    //vTaskDelay(500 / portTICK_PERIOD_MS);
    enable1=false;
    uint16_t vol = 0;
    if(endTime==0||startTime==0){
        ESP_LOGE(tag, "Not Respone Correctly -> MEASURE NOT SAVED");
    }
    else{
        int diff = endTime - startTime; // Diff time in uSecs
        vol = 340.29 * diff / (1000.0 * 2); // Distance in meters  
        if(firstTime) distance = vol;
        else distance = (63 * Prev_distance + 1 * vol)>>6;
        Prev_distance = distance;      
        //ESP_LOGI(tag, "time %i distance %i", diff, distance);
    }

    ESP_LOGI(tag, "read as %i %i", vol, distance);
    return Prev_distance;
}
